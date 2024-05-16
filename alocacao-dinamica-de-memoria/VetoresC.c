#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int *criaVetInt(int n){
	int *vet = (int *)malloc(n * sizeof(int));
	if (vet == NULL) {
		printf("Erro: não foi possível alocar memoria.\n");
		exit(EXIT_FAILURE);
	}
	return vet;
}

float *criaVetFloat(float f){
	float *vet = (float *)malloc(f * sizeof(float));
	if (vet == NULL) {
		printf("Erro: nao foi possivel alocar memoria.\n");
		exit(EXIT_FAILURE);
	}
	return vet;
}
