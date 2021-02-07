#ifndef UTILS_H_
#define UTILS_H_

#include <string.h>

#define STRINGIFY_2(a) #a
#define STRINGIFY(a) STRINGIFY_2(a)

#define DO_PRAGMA(x) _Pragma (#x)

#define STRLEN(s) (sizeof(s)/sizeof(s[0]))

#define ASTERISK_FORMAT(n) "%." #n "s"

#define STRCATL(target, buffer, string, limit) \
	sprintf(buffer, ASTERISK_FORMAT(limit), string); \
	strcat(target, buffer)

int _findChar(char*, char);

int _findInt(int*, int, int);

#endif