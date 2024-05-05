#include <stdio.h>
#include <stdlib.h>

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

int main(){
	int n = 2;
	int *endereco;
       	endereco = criaVetInt(n);
	endereco[0] = 10; 

	// printf("%p\n", &endereco);
	printf("%d\n", endereco[0]);
	
	return 0;
}
