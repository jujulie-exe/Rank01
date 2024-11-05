

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft_ret, std_ret;

    ft_ret = ft_printf("Char test: %c\n", 'A');


    
	ft_ret = ft_printf("");
    
	
	std_ret = printf("Char test: %c\n", 'A');
    
    std_ret = printf("");
	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("String test: %s\n", "Hello, world!");
    std_ret = printf("String test: %s\n", "Hello, world!");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("Integer test: %d\n", 12345);
	ft_ret = ft_printf("Integer test MAX %d\n", INT_MAX);
	ft_ret = ft_printf("integer test MIN %d\n", INT_MIN);
	
    std_ret = printf("Integer test: %d\n", 12345);
	std_ret = printf("integer test MAX %d\n", INT_MAX);
	std_ret = printf("integer test MIN %d\n", INT_MIN);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("Signed int test: %i\n", -12345);
    std_ret = printf("Signed int test: %i\n", -12345);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("Unsigned int test: %u\n", 12345U);
    std_ret = printf("Unsigned int test: %u\n", 12345U);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("Hexadecimal lowercase: %x\n", 0xabcdef);
    std_ret = printf("Hexadecimal lowercase: %x\n", 0xabcdef);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("Hexadecimal uppercase: %X\n", 0xABCDEF);
    std_ret = printf("Hexadecimal uppercase: %X\n", 0xABCDEF);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

    int a = 42;
    ft_ret = ft_printf("Pointer test: %p\n", &a);
    std_ret = printf("Pointer test: %p\n", &a);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);
    ft_ret = ft_printf("Percentage test: %%\n");
    std_ret = printf("Percentage test: %%\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);
   ft_ret = ft_printf("Mixed test: char='%c', string='%s', int='%d', hex='%x', pointer='%p', unsigned='%u', percent='%%'\n",
                       'A', "Hello, world!", 12345, 0xabc, (void*)0xdeadbeef, 123456789U);
    std_ret = printf("Mixed test: char='%c', string='%s', int='%d', hex='%x', pointer='%p', unsigned='%u', percent='%%'\n",
                     'A', "Hello, world!", 12345, 0xabc, (void*)0xdeadbeef, 123456789U);
    
    printf("Return values: ft_printf = %d, printf = %d\n", ft_ret, std_ret);
	ft_ret = ft_printf("Incompatible modifier test: %s\n", "StringInsteadOfInt");
    std_ret = printf("Incompatible modifier test: %s\n", "StringInsteadOfInt");

    printf("Return values: ft_printf = %d, printf = %d\n", ft_ret, std_ret);

	ft_ret = ft_printf("Null char test: '%s'\n", "Hello\0World");
    std_ret = printf("Null char test: '%s'\n", "Hello\0World");

    printf("Return values: ft_printf = %d, printf = %d\n", ft_ret, std_ret);

	printf("TEST FINISH WEWEW  \n\n");

	system("leaks a.out");
	return (0);
}
