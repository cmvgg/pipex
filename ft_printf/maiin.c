#include <stdio.h>

int main(void)
{
    int  hex;
    int                 p;
    char                *string;
    char                c;
    int                 num2;
    int        num;

    hex = 255;
    p = 0x345;
    string = "totoro";
    c = 'x';
    num2 = -400;
    num = 4294967295;
    ft_printf("%X, %d, %u, %u, %u, %u, %s, %p, %c\n", hex, num2, num, num, num, num, string, &p, c);
    printf("%X, %d, %u, %u, %u, %u, %s, %p, %c", hex, num2, num, num, num, num, string, &p, c);
}
/*
#include <sys/time.h>
int main() {

    struct timeval start, end;
    gettimeofday(&start, NULL);
    ft_printf("Hello, %s! This is a char: %c\n", "world", 'A');
   ft_printf("Pointer address: %p\n", (void*)0x1234);
   ft_printf("Hexadecimal numbers: %x and %#X\n", 255, 255);
   ft_printf("Decimal numbers: %i and %u\n", 0, 42);

    printf("time spent ==> %ld\n", (end.tv_sec - start.tv_sec) * 1000
        + (end.tv_usec - start.tv_usec) / 1000);
    return 0;
}*/
/*
int main()
{
        printf("%sg", "{} al$#@@@^&$$^#^@@^$*((&\n");
    ft_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&\n");

}*/

/*int main(void)
{
    ft_printf(0);
    printf("\nft\n");
    printf(0);
    return 0;
}*/
/*
#include <stdio.h>

int main(void)
{
    int n = -12345;
    unsigned int u = 4294967295;
    long long ll = 9223372036854775807LL;
    double d = 3.14159265358979323846;
    char *str = "Test\tString\n";
    void *ptr = &n;

    ft_printf("%%d: %d\n%%u: %u\n%%lld: %lld\n%%.9f: %.9f\n%%s: %s\n%%p: %p\n",
              n, u, ll, d, str, ptr);
    
    printf("%%d: %d\n%%u: %u\n%%lld: %lld\n%%.9f: %.9f\n%%s: %s\n%%p: %p\n",
           n, u, ll, d, str, ptr);
    
    return 0;
}*/
/*int main()
{
    char *str;
    int len;
    int i;

    for (i = 0; i < 100; i++)
    {
        len = rand() % 1000000;
        str = malloc(sizeof(char) * len);

        for (int j = 0; j < len; j ++)
        {
            str[j] = '\n';
        }

        
        ft_printf("%s", str);
        //printf("%s", str);
    }
}*/
/*
int main()

{
    char *str = "1234567890";
    int i;

    for (i = 0; i < 100; i++)
    {
        ft_printf("%-20.*s", i, str);
        //printf("%-20.*s", i, str);
    }
}*/

/*int main()
{
    char *str = malloc(sizeof(char) * 1000000);

    for (int i = 0; i < 1000000; i++)
    {
        str[i] = '\n';
    }
    //printf("%s", str);

    //printf("\nFT\n");
    ft_printf("%s", str);
}*/
/*
int main()
{
    ft_printf("%u", 4294967297);
    printf("%u", 4294967297);
}*/

/*
int main()
{
    int i;

    for (i = 0; i < 100; i++)
    {
        ft_printf("%d", i + 1000000000);
        //printf("%d", i + 1000000000);
    }
}*/
/*
int main()
{
    char *str = malloc(sizeof(char) * 100);
    int i;

    for (i = 0; i < 100; i++)
    {
        str[i] = rand() % 256;
    }

    ft_printf("%s", str);
    //printf("%s", str);
}*/

/*int main()
{
    ft_printf("%20.10f", 1.234567890);
    printf("%20.10f", 1.234567890);
}*/
/*
int main()
{
    char *str = "1234567890";
    int i;

    for (i = 0; i < 100; i++)
    {
        ft_printf("%-20.*s", i, str);
        printf("%-20.*s", i, str);
    }
}*/

/*int main()
{
    int *ptr;
    ptr = NULL;

    ft_printf("%p", ptr);
    printf("%p", ptr);
}*/
/*
int main()
{
    unsigned long long int max_int = 0xFFFFFFFFFFFF;
    unsigned long long int min_int = 0xFFFFFFFFFFFFFFFF;
    int max_short = 0xFFFF;
    int min_short = 0x8000;

    ft_printf("%llu, %llu, %d, %d\n", max_int, min_int, max_short, min_short);
    printf("%llu, %llu, %, %d", max_int, min_int, max_short, min_short);
}*/
/*
int main()
{
    int i;
    char string[] = "totoro";

    for (i = 0; i < 100; i++)
    {
        printf("%sx\n", string);
        ft_printf("%sx\n", string);
    }
}*/
/*
int main()
{
    ft_printf("%d.2f\n", 1234567890);
    printf("%d.2f", 1234567890);
}*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = malloc(sizeof(char) * 1000000);
    int i;

    for (i = 0; i < 1000000; i++)
    {
        str[i] = 'a';
    }

    ft_printf("%s", str);

    free(str);
    return (0);
}*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    for (i = 0; i < INT_MAX; i++)
    {
        printf("%d\n", i);
    }

    return (0);
}
*/