#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...);

int main(void)
{
    int i;
    minscanf("%d", &i);
    printf("%d\n", i);
    char *a;
    minscanf("%s", a);
    printf("%s\n", a);
    float f;
    minscanf("%f", &f);
    printf("%f\n", f);
    int o;
    minscanf("%o", &o);
    printf("octal : %o, decimal : %d\n", o, o);
    int x;
    minscanf("%x", &x);
    printf("hex %x, decimal %d\n", x, x);
    return 0;
}

void minscanf(char *fmt, ...)
{
    va_list ap; 
    char *p, *sval;
    int *ival;
    float *dval;
    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
       	{
            continue;
        }

        switch (*++p)
       	{
            case 'd':
                ival = va_arg(ap, int *);
                char *d = "87";
                sscanf(d, "%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, float *);
                char *f = "6.49";
                sscanf(f, "%f", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                sscanf("program", "%s", sval);
                break;
            case 'o':
                ival = va_arg(ap, int *);
                char *o = "010";
                sscanf(o, "%o", ival);
                break;
            case 'x':
                ival = va_arg(ap, int *);
                char *x = "4d";
                sscanf(x, "%x", ival);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

