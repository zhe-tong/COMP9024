CC     = gcc
CFLAGS = -Wall -Werror -O0 -g

ifneq ($(shell which dcc),)
	CC = dcc
endif

BINS   = DLL_driver
SRCS   = DLL_driver.c DLL.c
HEADS  = DLL.h

.PHONE: all clear

all: $(BINS)

$(BINS): $(SRCS) $(HEADS)
	$(CC) $(CFLAGS) -o $(BINS) $(SRCS)

clear:
	rm -f $(BINS)
