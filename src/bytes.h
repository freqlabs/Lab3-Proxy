#ifndef _bytes_h_
#define _bytes_h_

#include <sys/types.h>
#include <sys/uio.h>


typedef struct iovec bytes;

bytes bytes_of_string(char *);
bytes bytes_of_chars(char *, size_t);

void bytes_init(bytes *);
void bytes_free(bytes *);

#endif // _bytes_h_
