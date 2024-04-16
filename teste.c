#include <stdio.h>
void trocaValores(float *ptr1, float *ptr2){
	float temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main(){
	float a = 3.14, b = 2.17;
	printf("Valores originais: a = %.2f, b = %.2f\n", a, b);
	trocaValores(&a, &b);
	printf("Valors trocados: a = %.2f, b = %.2f\n", a, b);
	return 0;
}
