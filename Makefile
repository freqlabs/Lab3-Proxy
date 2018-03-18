CFLAGS = -g -std=c11 -Isrc -Wall -Werror

srcs = $(wildcard src/*.c)
objs = $(srcs:.c=.o)

proxy: $(objs)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -rf $(objs) proxy
