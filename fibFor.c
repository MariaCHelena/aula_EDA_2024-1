#include <stdio.h>

int main(){
	int number, result, aux1 = 0, aux2 = 1;
	scanf("%d", &number);
	if(number <= 1){
		result = number;
	} else {
		for(int i = 2; i < number; i++){
			result = aux1 + aux2;
			aux1 = aux2;
			aux2 = result;
		}
	}

	printf("resultado: %d\n", result);
	return 0;
}
