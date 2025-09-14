# Makefile in Foundation directory to test Exam code

CC = gcc
CFLAGS = -I../Exam -I.

# Find all .c files in both directories
EXAM_FILES = $(wildcard ../Exam/*.c)
FOUNDATION_FILES = $(wildcard *.c)

test: $(FOUNDATION_FILES) $(EXAM_FILES)
	@$(CC) $(CFLAGS) $(FOUNDATION_FILES) $(EXAM_FILES) -o test
	@./test
	@rm test

clean:
	rm -f test