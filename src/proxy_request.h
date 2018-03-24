#ifndef _proxy_request_h_
#define _proxy_request_h_

#include <stdbool.h>

#include "proxy_priv.h"

/*
 * Process a client request.
 * Returns true to indicate proxy_request() should be called again,
 * or false to indicate the connection has been closed.
 * Exits on error.
 */
bool proxy_request(struct proxy *proxy);

#endif // _proxy_request_h_
