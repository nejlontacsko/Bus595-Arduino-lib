#include "utils.h"

int _find(char* haystack, char needle)
{
	int ret = 0;
	for (int i = 0; haystack[i] > 0; i++)
		if (haystack[i] == needle)
		{
			ret = i;
			break;			
		}
	return ret;
}