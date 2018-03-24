#ifndef _proxy_priv_h_
#define _proxy_priv_h_

#include <stdbool.h>

#include <netinet/in.h>


#define LISTEN_BACKLOG 8 // FIXME: what is a good value for this?

// minimum recommended supported request line length
// https://tools.ietf.org/html/rfc7230#section-3.1.1
#define REQUEST_LINE_MIN_BUFLEN 8000

#define RECV_BUFLEN (REQUEST_LINE_MIN_BUFLEN*2)

enum { SUCCESS = 0, FAILURE = -1 };

struct proxy {
    int sockfd;
    bool verbose;
    struct sockaddr_in client;
};

#endif // _proxy_priv_h_
