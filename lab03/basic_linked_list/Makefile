CC     = gcc
CFLAGS = -Wall -Werror -O0 -g
SRCS   = LinkedList.c
HEADS  = LinkedList.h

ifneq ($(shell which dcc),)
	CC = dcc
endif

.PHONE: all clear

all: LinkedList_driver

LinkedList_driver: LinkedList_driver.c $(SRCS) $(HEADS)
	$(CC) $(CFLAGS) -o LinkedList_driver LinkedList_driver.c $(SRCS)

clear:
	rm -f $(BIN)
