CC = gcc
CFLAGS = -std=c11 -I../Exam -I.
LDFLAGS = -lm

# Find all .c files in both directories
EXAM_FILES = $(wildcard ../Exam/*.c)
FOUNDATION_FILES = $(wildcard *.c)

test: $(FOUNDATION_FILES) $(EXAM_FILES)
	@$(CC) $(CFLAGS) $(FOUNDATION_FILES) $(EXAM_FILES) -o test_exe $(LDFLAGS)
	@./test_exe
	@rm test_exe

clean:
	rm -f test