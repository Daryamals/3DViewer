CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++20
GTEST_FLAGS = -lgtest -lgtest_main -pthread

SRC_DIR = ../src
MODEL_SRC = $(SRC_DIR)/model/model.cpp
TEST_SRC = $(SRC_DIR)/tests/s21_test.cpp

GTEST_DIR = ../lib/googletest/googletest
GTEST_SRC = $(GTEST_DIR)/src/gtest-all.cc
GTEST_MAIN_SRC = $(GTEST_DIR)/src/gtest_main.cc

GTEST_INCLUDES = -I$(GTEST_DIR)/include -I$(GTEST_DIR)

MODEL_OBJ = model.o
GTEST_OBJ = gtest-all.o
GTEST_MAIN_OBJ = gtest_main.o
TEST_EXEC = final_test

all: $(TEST_EXEC)

$(TEST_EXEC): $(MODEL_OBJ) $(GTEST_OBJ) $(GTEST_MAIN_OBJ)
	$(CC) $(FLAGS) $(GTEST_INCLUDES) $(MODEL_OBJ) $(GTEST_OBJ) $(GTEST_MAIN_OBJ) $(TEST_SRC) -o $(TEST_EXEC)

$(MODEL_OBJ): $(MODEL_SRC)
	$(CC) $(FLAGS) -c $(MODEL_SRC)

$(GTEST_OBJ): $(GTEST_SRC)
	$(CC) $(FLAGS) $(GTEST_INCLUDES) -c $(GTEST_SRC) -o $(GTEST_OBJ)

$(GTEST_MAIN_OBJ): $(GTEST_MAIN_SRC)
	$(CC) $(FLAGS) $(GTEST_INCLUDES) -c $(GTEST_MAIN_SRC) -o $(GTEST_MAIN_OBJ)

test: all
	./$(TEST_EXEC)

clean:
	rm -rf *.o $(TEST_EXEC) *.gcda *.gcno *.info report

gcov_report:
	$(CC) $(FLAGS) --coverage $(GTEST_INCLUDES) $(MODEL_SRC) $(TEST_SRC) $(GTEST_SRC) $(GTEST_MAIN_SRC) -o $(TEST_EXEC)
	./$(TEST_EXEC)
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	start ./report/index.html

.PHONY: all test clean gcov_report