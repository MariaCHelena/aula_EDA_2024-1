#include <stdio.h>
int main(){
	int numero, *ptr;
	numero = 79417;
	printf("Valor da variável: %d\n", numero);
	ptr = &numero;
	*ptr = 80;
	printf("Valor da variável: %d\n", numero);
	printf("Valor do ponteiro: %p\n", ptr);
	return 0;
}
