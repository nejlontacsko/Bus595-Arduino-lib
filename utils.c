#include "utils.h"

int _findChar(char* haystack, char needle)
{
	int ret = -1;
	for (int i = 0; haystack[i] > 0; i++)
		if (haystack[i] == needle)
		{
			ret = i;
			break;			
		}
	return ret;
}

int _findInt(int* haystack, int needle, int len)
{
	int ret = -1;
	for (int i = 0; i < len; i++)
		if (haystack[i] == needle)
		{
			ret = i;
			break;
		}
	return ret;
}