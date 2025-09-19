CC = gcc
CFLAGS = -DMODE_UNIT_TEST -std=c11 -I../Exam -I../Foundation -I.
LDFLAGS = -lm

# Find all .c files
EXAM_FILES = $(wildcard ../Exam/*.c)
FOUNDATION_FILES = $(wildcard ../Foundation/*.c)
TEST_FILES = $(wildcard test_*.c)

# Default target runs all tests
test: $(TEST_FILES:.c=.run)

# Pattern rule to compile and run each test file
%.run: %.c $(EXAM_FILES) $(FOUNDATION_FILES)
	@echo "$<"
	@$(CC) $(CFLAGS) $< $(EXAM_FILES) $(FOUNDATION_FILES) -o test_exe $(LDFLAGS)
	@./test_exe
	@rm test_exe
	@echo ""

# Run a specific test (e.g., make test_f_general_math)
test_%: test_%.c $(EXAM_FILES) $(FOUNDATION_FILES)
	@echo "Running $@..."
	@$(CC) $(CFLAGS) $< $(EXAM_FILES) $(FOUNDATION_FILES) -o test_exe $(LDFLAGS)
	@./test_exe
	@rm test_exe

clean:
	rm -f test_exe *.o