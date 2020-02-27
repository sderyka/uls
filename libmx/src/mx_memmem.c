#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len < big_len && little_len > 0 && big_len > 0) {
    	unsigned char *big1 = (unsigned char *)big;
    	unsigned char *little1 = (unsigned char *)little;
    	unsigned char *p = big1;
    	for (size_t count = 0; count <= (big_len - little_len); count++) {
			size_t j = 0;
			for (size_t i = 0; p[i] == little1[i]; i++) {
				j++;
			}
			if (j == little_len)
				return p;
			(p)++;
		}
    }
    return NULL;
}
