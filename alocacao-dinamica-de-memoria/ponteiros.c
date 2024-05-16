#include <stdio.h>
int endVar(){
	int numero = 79417;
	int *ptr;

	ptr = &numero;

	printf("Endereco de 'numero': %p\n", ptr);
	printf("Valor de 'numero': %d\n", *ptr);

	return 0;
}

int trocaValores(int *ptr1, int *ptr2){
	int temp = *ptr1;
	*ptr1 = *ptr2;
       	*ptr2 = temp;	
	return 0;
}

int main(){
	int numero, *ptr;
	numero = 79417;
	printf("Valor da variável: %d\n", numero);
	ptr = &numero;
	*ptr = 80;
	printf("Valor da variável: %d\n", numero);
	printf("Valor do ponteiro: %p\n", ptr);
	
	endVar();

	int n1 = 10, n2 = 20;

	printf("Valores atuais\nnum1: %d\nnum2: %d\n", n1, n2);

	trocaValores(&n1, &n2);

	printf("Valores trocados\nnum1: %d\nnum2: %d\n", n1, n2);

	return 0;
}
