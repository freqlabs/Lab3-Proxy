#ifndef _byte_string_h_
#define _byte_string_h_

#include <stdint.h>

#include "bytes.h"


/* A byte_string is a dynamically-sized array of bytes (struct iovec).
 * Each bytes is an iovec containing a section of the string.
 * A byte_string is useful for operating on large string buffers.
 */
typedef struct byte_string {
    bytes *data;
    size_t capacity, length;
} byte_string;

byte_string byte_string_of_bytes(bytes);

void byte_string_append(byte_string *, bytes);
void byte_string_append_string(byte_string *, char *);
void byte_string_concat(byte_string *, byte_string);
size_t byte_string_length(byte_string);

bytes bytes_of_byte_string(byte_string);

ssize_t write_byte_string(int fd, byte_string);

void byte_string_init(byte_string *);
void byte_string_free(byte_string *);

#endif // _byte_string_h_
