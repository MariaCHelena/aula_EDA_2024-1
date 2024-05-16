#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int main(){
	int tamanhoInt = 5;
	float tamanhoFloat = 4;
	
	int *vetInt = criaVetInt(tamanhoInt);
	float *vetFloat = criaVetFloat(tamanhoFloat);

	for (int i = 0; i < tamanhoInt; i++){
		*(vetInt + i) = i;
		printf("%d\n", *(vetInt + i));
	}

	for (int i = 0; i < tamanhoFloat; i++){
		*(vetFloat + i) = i;
		printf("%f\n", *(vetFloat + i));
	}

	free(vetInt);
	free(vetFloat);

	return 0;
}
