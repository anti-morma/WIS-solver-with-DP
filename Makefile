CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99

# Default target
all: scheduler

# Compilation rule
scheduler: main.c activities.c activities.h
	$(CC) $(CFLAGS) -o scheduler main.c activities.c

# Clean rule
clean:
	rm -f scheduler
