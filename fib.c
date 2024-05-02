#include <stdio.h>

int fibonacci(int n){
	if (n <= 1){
		return n;	
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);	
	}
}

int main(){
	int number, result, aux1 = 0, aux2 = 1;
	scanf("%d", &number);

	result = fibonacci(number);
	printf("resultado: %d\n", result);
	return 0;
}
