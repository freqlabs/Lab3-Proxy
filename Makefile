CFLAGS = -g -std=c11 -Wall -Werror -Isrc -I/usr/local/include
LDFLAGS = -L/usr/local/lib
LIBS = -lhttp_parser

srcs = $(wildcard src/*.c)
objs = $(srcs:.c=.o)

all: proxy

proxy: $(objs)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf $(objs) proxy

.PHONY: all clean
