#include <stdio.h>
#include <limits.h>

int main()
{
	printf("Sono l'intmin %d\n", INT_MIN);
	printf("Sono l'intmin + 1 %d\n", INT_MIN - 1);
	printf("Sono l'intmax %d\n", INT_MAX);
	printf("sono l'intmax + 1 %d\n\n\n", INT_MAX + 1);
	
	
	printf("TEST UNSIGEND [U]\n");
	printf("sono il numero non firmato in base 10 %u\n", UINT_MAX);
	printf("sono il numero non firmato in base 10 + 1 %u\n", UINT_MAX + 1);
	printf("sono il numero non firmato in base 10 - 1 %u\n", UINT_MAX - 1);
	printf("sono il numero non firmato in base 10 (intmin) %u\n\n", INT_MIN);

	printf("TEST HEXADECIMAL [x] \n");
	printf("sono il [max hex]%x\n",UINT_MAX);
	printf("sono il max [hex + 1] %x\n",UINT_MAX + 1);
	printf("sono il max [hex - 1] %x\n",UINT_MAX - 1);
	printf("sono il hex [0] %x\n",0);
	printf("sono il hex [stringa vuota] %x\n","");
	printf("sono il hex [stringa di digit] %x\n numeri in string", "12321321");
	printf("sono il hex [stringa di char] %x\n", "sono una stringa che non deve essere qui");

}

