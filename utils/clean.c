#include <stdlib.h> 
#include <string.h> 
void clean(void *x, int len) 
{ 
	memset(x, 0x00, len); 
	free(x); 
} 

