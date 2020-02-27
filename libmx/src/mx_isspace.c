#include "libmx.h"

bool mx_isspace(int c) {
    bool b;
    if ((c == '\t')  || (c == '\n') || (c == '\v') 
        || (c == '\f') || (c == '\r') || (c == ' '))
    {
        b = 1;
    }
    else
        b = 0;
    return (b);
}
