#ifndef __DEBUG_H__
#define __DEBUG_H__

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#endif
