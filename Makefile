CFLAGS =-std=c17 -Wall -Wextra -Wpedantic
SRCS   =$(wildcard *.c)
PROGS  =$(subst .c,,$(SRCS))

all:
	$(MAKE) $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) -f $(PROGS)
