#include <stdio.h>

int ackermannRecursivo(int m, int n){
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return ackermannRecursivo(m - 1, 1);
	else
		return ackermannRecursivo(m -1, ackermannRecursivo(m, n - 1));
}

int main(){
	int a, b, resultado;
	puts("Digite um numero:");
	scanf("%d", &a);
	puts("Digite outro numero:");
	scanf("%d", &b);
	resultado = ackermannRecursivo(a, b);
	printf("O resultado da funcao eh: %d\n", resultado);
	return 0;
}
