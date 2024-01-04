#include "ft_printf.h"

int git_n_after_p(char * format)
{
    int x =0;
    int re =0;
    while(format[x])
    {
        while(format[x] && format[x] != '.')
            x++;
        while(format[x] && format[x] == '.')
            x++;
        while(format[x] && (format[x] >= '0' && format[x] <= '9'))
            re = (re * 10) + (format[x++] - '0');
        return re;
    }
    
    return re;
}