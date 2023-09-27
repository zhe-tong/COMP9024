CC     = gcc
CFLAGS = -Wall -Werror -O0 -g

ifneq ($(shell which dcc),)
	CC = dcc
endif

BINS   = graph_driver
SRCS   = graph_driver.c graph.c complete.c
HEADS  = graph.h lib_graph.h

.PHONE: all clear

all: $(BINS)

$(BINS): $(SRCS) $(HEADS)
	$(CC) $(CFLAGS) -o $(BINS) $(SRCS)

clear:
	rm -f $(BINS)
