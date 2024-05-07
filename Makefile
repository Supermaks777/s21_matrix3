LIB_SRC_DIR			= ./lib
FLAGS_CC 			= -Werror -Wall -Wextra -std=c11
FLAGS_CC_DEV 		= -Wall -Wextra -std=c11 -Wno-stringop-overread
FUNC_FILES 			= ./functions/*.c
TEST_FILES			= ./tests/s21_test.h ./tests/s21_*.c
FLAGS_GL			= --coverage
FLAGS_GCOV			= -fprofile-arcs -ftest-coverage

ifeq ($(shell uname),Linux)
    FLAGS_CHECK = -lcheck  -lm -lrt -lpthread -lsubunit
else
    FLAGS_CHECK = -lcheck -lm -lpthread
endif

all: build_o s21_matrix.a

clang:
	# cp ../materials/linters/.clang-format .
	clang-format --style=Google -n functions/*.c tests/*.c tests/*.h *.h

clang_replace:
	# cp ../materials/linters/.clang-format .
	clang-format --style=Google -i functions/*.c tests/*.c tests/*.h *.h

build_o:
	gcc $(FLAGS_CC) -c $(FUNC_FILES) 

build_o_for_test:
	gcc $(FLAGS_CC) $(FLAGS_GCOV) $(FLAGS_GL) -c $(FUNC_FILES) 

test: $(TEST_FILES) s21_matrix.a
	rm -rf *.o s21_matrix_test.gcda
	gcc $(FLAGS_CC_DEV) $(FLAGS_GL) $(FLAGS_GCOV) $^ -o s21_matrix_test $(FLAGS_CHECK) 
	./s21_matrix_test

build_lib:
	ar rcs s21_matrix.a *.o

build_lib_for_test:
	ar rcs s21_matrix.a *.o

s21_matrix.a:
	gcc $(FLAGS_CC) -c $(FUNC_FILES) 
	make build_lib
	rm -rf *.o

gcov_report: clean build_o_for_test build_lib test
	lcov -o tests.info -c -d .   
	genhtml -o report tests.info
	open report/index.html
	make clean_except_report

gcov_report_M1:
	gcc $(FLAGS_CC_DEV) $(FLAGS_GL) $(FLAGS_GCOV) $(FUNC_FILES) $(TEST_FILES) -o s21_matrix_test $(FLAGS_CHECK) 
	./s21_matrix_test
	lcov -o tests.info -c -d .   
	genhtml -o report tests.info
	open report/index.html
	make clean_except_report

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *test
	rm -rf report

clean_except_a:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.info
	rm -rf report

clean_except_report:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *test

rebuild:
	make clean
	make


win:
	gcc main.c ./functions/s21_*.c -o test_win
	./test_win.exe

mac:
	gcc main.c ./functions/s21_*.c -o test_mac
	./test_mac

test_another: tests/unit_test.c s21_matrix.a
	rm -rf *.o s21_matrix_test.gcda
	gcc $(FLAGS_CC_DEV) $(FLAGS_GL) $(FLAGS_GCOV) $^ -o s21_matrix_test $(FLAGS_CHECK) 
	./s21_matrix_test


test_another2: tests/unit_tests.c s21_matrix.a
	rm -rf *.o s21_matrix_test.gcda
	gcc $(FLAGS_CC_DEV) $(FLAGS_GL) $(FLAGS_GCOV) $^ -o s21_matrix_test $(FLAGS_CHECK) 
	./s21_matrix_test

test_another3: tests/matrix_test.c s21_matrix.a
	rm -rf *.o s21_matrix_test.gcda
	gcc $(FLAGS_CC_DEV) $(FLAGS_GL) $(FLAGS_GCOV) $^ -o s21_matrix_test $(FLAGS_CHECK) 
	./s21_matrix_test

valgrind_log:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./s21_matrix_test
	grep ERROR valgrind_log.txt
