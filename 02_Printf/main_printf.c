

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft_ret, std_ret;

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	ft_ret += ft_printf("Char test: %c\n", 'A');
	ft_ret += ft_printf("");
	std_ret += printf("Char test: %c\n", 'A');
    	std_ret += printf("");
	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	printf("TEST X [STR]\n");
    	ft_ret += ft_printf("String test: %s\n", "Hello, world!");
	ft_ret += ft_printf("Null char test: '%s'\n", "Hello\0World");
    	ft_ret += ft_printf("String test NULL: %s\n", (char *)NULL);
    	ft_ret += ft_printf("String test NULL: %s\n", "");
    	std_ret += printf("String test: %s\n", "Hello, world!");
    	std_ret += printf("Null char test: '%s'\n", "Hello\0World");
    	std_ret += printf("String test NULL: %s\n", (char *)NULL);
    	std_ret += printf("String test NULL: %s\n", "");
    	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	printf("TEST [INTEGER]\n");
    	ft_ret += ft_printf("Integer test: %d\n", 12345);
	ft_ret += ft_printf("Integer test MAX %d\n", INT_MAX);
	ft_ret += ft_printf("integer test MIN %d\n", INT_MIN);
	ft_ret += ft_printf("Incompatible modifier test: %d\n", "StringInsteadOfInt");
    	std_ret += printf("Integer test: %d\n", 12345);
	std_ret += printf("integer test MAX %d\n", INT_MAX);
	std_ret += printf("integer test MIN %d\n", INT_MIN);
    	std_ret += printf("Incompatible modifier test: %d\n", "StringInsteadOfInt");
    	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	printf("TEST [BASE 10N {i}]\n");
    	ft_ret += ft_printf("Signed int test: %i\n", -12345);
    	std_ret += printf("Signed int test: %i\n", -12345);
    	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	printf("TEST [UNSIGNED INTEGER]\n");
    	ft_ret += ft_printf("Unsigned int test: %u\n", 12345U);
	ft_ret += ft_printf("Unsigned test INTMIN: %u\n", INT_MIN);
    	ft_ret += ft_printf("Unsigned int test MAX: %u\n", UINT_MAX);
    	std_ret += printf("Unsigned int test: %u\n", 12345U);
	std_ret += printf("Unsigned test INTMIN: %u\n", INT_MIN);
    	std_ret += printf("Unsigned int test MAX: %u\n", UINT_MAX);
    	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	printf("TEST [HEXADECIMAL x]\n");
    	ft_ret += ft_printf("Hexadecimal lowercase: %x\n", 0xabcdef);
    	ft_ret += ft_printf("Hexadecimal lowercase: %x\n", UINT_MAX);
    	ft_ret += ft_printf("Hexadecimal lowercase: %x\n", 16);
    	std_ret += printf("Hexadecimal lowercase: %x\n", 0xabcdef);
    	std_ret += printf("Hexadecimal lowercase: %x\n", UINT_MAX);
    	std_ret += printf("Hexadecimal lowercase: %x\n", 16);
    	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	printf("TEST [HEXADECIMAL X]\n");
    	ft_ret += ft_printf("Hexadecimal uppercase: %X\n", 0xABCDEF);
    	std_ret += printf("Hexadecimal uppercase: %X\n", 0xABCDEF);
    	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
    	int a = 42;
	char *s = "str random";
	printf("TEST [POINTER]\n");
  	ft_ret += ft_printf("Pointer test: %p\n",(void *) &a);
    	std_ret += printf("Pointer test: %p\n",(void *) &a);
    	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****

	std_ret = 0;
	ft_ret = 0;
	printf("TEST [PERCENTAGE]\n");
   	ft_ret += ft_printf("Percentage test: %%\n");
   	//ft_ret += ft_printf("Percentage test: %ixXcds%%uipmlq\n");
   	ft_ret += ft_printf("Percentage test: %%%%%%%%%%%%%%%%\n");
   	ft_ret += ft_printf("%h");
   	std_ret += printf("Percentage test: %%\n");
   	//std_ret += printf("Percentage test: %ixXcds%%uipmlq\n");
   	std_ret += printf("Percentage test: %%%%%%%%%%%%%%%%\n");
   	std_ret += printf("%h");
   	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);

/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	printf("TEST [NO ARG]\n");
	ft_ret = 0;
	ft_ret += ft_printf(" NO ARG TEST\n");
	ft_ret += ft_printf("");
	std_ret += printf(" NO ARG TEST\n");
    std_ret += printf("");
	printf("Return values: ft_printf = %d, printf = %d\n\n", ft_ret, std_ret);
/***********/////////////////////////////////////////////////////////////////****
	std_ret = 0;
	ft_ret = 0;
	printf("TEST [MIXED]\n");
   ft_ret += ft_printf("Mixed test: char='%c', string='%s', int='%d', hex='%x', pointer='%p', unsigned='%u', percent='%%'\n",'A', "Hello, world!", 12345, 0xabc, (void*)0, INT_MAX, 12312312);
   ft_ret += ft_printf("Mixed test: pointer='%p', unsigned='%u\n",(void*)0, UINT_MAX);
   ft_ret += ft_printf("Mixed test: char='%c', string='%s', hex='%x',unsigned='%u', percent='%%'\n",'A', "Hello, world!", 0xabc, UINT_MAX);
   std_ret += printf("Mixed test: char='%c', string='%s', int='%d', hex='%x', pointer='%p', unsigned='%u', percent='%%'\n",'A', "Hello, world!", 12345, 0xabc, (void*)0, INT_MAX, 123123123);
   std_ret += printf("Mixed test: pointer='%p', unsigned='%u\n",(void*)0, UINT_MAX);
   std_ret += printf("Mixed test: char='%c', string='%s', hex='%x',unsigned='%u', percent='%%'\n",'A', "Hello, world!", 0xabc, UINT_MAX);
    		printf("Return values: ft_printf = %d, printf = %d\n\n\n", ft_ret, std_ret);

	printf("TEST FINISH WEWEW  \n\n");

//	system("leaks a.out");
	return (0);
}
