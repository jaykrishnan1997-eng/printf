#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft;
    int og;

    // Basic specifiers
    ft = ft_printf("char: %c\n", 'A');
    og = printf("char: %c\n", 'A');
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("string: %s\n", "hello");
    og = printf("string: %s\n", "hello");
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("int: %d\n", 42);
    og = printf("int: %d\n", 42);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("int: %i\n", 42);
    og = printf("int: %i\n", 42);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("unsigned: %u\n", 42u);
    og = printf("unsigned: %u\n", 42u);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("hex lower: %x\n", 255);
    og = printf("hex lower: %x\n", 255);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("hex upper: %X\n", 255);
    og = printf("hex upper: %X\n", 255);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("percent: %%\n");
    og = printf("percent: %%\n");
    ft_printf("ft:%d og:%d\n\n", ft, og);

    // Pointer
    int x = 42;
    ft = ft_printf("pointer: %p\n", &x);
    og = printf("pointer: %p\n", &x);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    // Edge cases - numbers
    ft = ft_printf("zero: %d\n", 0);
    og = printf("zero: %d\n", 0);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("negative: %d\n", -42);
    og = printf("negative: %d\n", -42);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("INT_MAX: %d\n", INT_MAX);
    og = printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("INT_MIN: %d\n", INT_MIN);
    og = printf("INT_MIN: %d\n", INT_MIN);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    og = printf("UINT_MAX: %u\n", UINT_MAX);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("negative as unsigned: %u\n", -1);
    og = printf("negative as unsigned: %u\n", -1);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("hex zero: %x\n", 0);
    og = printf("hex zero: %x\n", 0);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("hex UINT_MAX lower: %x\n", UINT_MAX);
    og = printf("hex UINT_MAX lower: %x\n", UINT_MAX);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("hex UINT_MAX upper: %X\n", UINT_MAX);
    og = printf("hex UINT_MAX upper: %X\n", UINT_MAX);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    // Edge cases - strings
    ft = ft_printf("empty string: %s\n", "");
    og = printf("empty string: %s\n", "");
    ft_printf("ft:%d og:%d\n\n", ft, og);

    // Edge cases - pointers
    ft = ft_printf("null pointer: %p\n", (void *)NULL);
    og = printf("null pointer: %p\n", (void *)NULL);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("ULONG_MAX pointer: %p\n", (void *)ULONG_MAX);
    og = printf("ULONG_MAX pointer: %p\n", (void *)ULONG_MAX);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    // Edge cases - format string structure
    ft = ft_printf("\n");
    og = printf("\n");
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("percent at end: %%\n");
    og = printf("percent at end: %%\n");
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("100%%done %d\n", 42);
    og = printf("100%%done %d\n", 42);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("%d%%\n", 100);
    og = printf("%d%%\n", 100);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    // Multiple and consecutive specifiers
    ft = ft_printf("multi: %d %s %c %x\n", 42, "hi", 'Z', 255);
    og = printf("multi: %d %s %c %x\n", 42, "hi", 'Z', 255);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("consecutive: %d%d%d\n", 1, 2, 3);
    og = printf("consecutive: %d%d%d\n", 1, 2, 3);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("%d is the answer\n", 42);
    og = printf("%d is the answer\n", 42);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    ft = ft_printf("the answer is %d\n", 42);
    og = printf("the answer is %d\n", 42);
    ft_printf("ft:%d og:%d\n\n", ft, og);

    return (0);
}