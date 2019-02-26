// Copyright (c) 2009-2014 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

#if defined(HAVE_CONFIG_H)
#include "config/ilcoin-config.h"
#endif

#include <cstring>

#if HAVE_DECL_STRNLEN == 0
size_t strnlen( const char *start, size_t max_len)
{
    const char *end = (const char *)memchr(start, '\0', max_len);

    return end ? (size_t)(end - start) : max_len;
}
#endif // HAVE_DECL_STRNLEN
