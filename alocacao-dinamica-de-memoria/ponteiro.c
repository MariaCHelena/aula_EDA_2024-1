#include <stdio.h>

int main(){
	int num = 2024;
	int *p;
	p = &num;

	printf("Valor de num: %d\n", num);
	printf("Valor de num: %d\n", *p);
	printf("Valor de p: %p\n", p);

	*p = 2023;

	printf("Valor de num atualizado por *p: %d\n", *p);
	printf("Valor de num: %d\n", num);

	return 0;
}
