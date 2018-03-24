#include "bytes.h"

#include <stdlib.h>
#include <string.h>


bytes
bytes_of_string(char *s)
{
    bytes b;
    b.iov_base = (void *)s;
    b.iov_len = strlen(s);
    return b;
}

bytes
bytes_of_chars(char *s, size_t len)
{
    bytes b;
    b.iov_base = (void *)s;
    b.iov_len = len;
    return b;
}

void bytes_init(bytes *b)
{
    memset(b, 0, sizeof (bytes));
}

void
bytes_free(bytes *b)
{
    free(b->iov_base);
    bytes_init(b);
}
