#include <stdio.h>
#include <stdlib.h>

int smallerIndex(int *vet, int tam, int ini){
	int min = ini, j;
	for(j=ini+1; j<tam; j++){
		if(vet[min] > vet[j])
			min = j;
	}
	return min;
}

void selectionSort(int *vet, int tam){
	int i, min, aux;
	for(i = 0; i < tam; i++){
		min = smallerIndex(vet, tam, i);
		aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
}

void printVet(int *vet, int tam, char *label){
	printf("%s\n", label);
	for(int i = 0; i < tam; i++){
		printf("%d ", vet[i]);
	}
	puts(" ");

}

void getField(int *vet, int *pos, char *label){
	int countField = 0, temp = 0;
	for(int i = 0; i < 1024; i++){
		if(count < 4){
			if(label[i] == 59)
				count++;
		} else {
			if(label[i] == 10)
				break;
			temp = temp * 10 + label[i];
		}
	}
	vet[*pos];
	*pos++;
}

int main(){
	int vet[], tam, count = 1, pos;
	FILE *f;
	char file[50], ch, line[1024];
	
	printf("Digite qual arquivo que deseja ler:\n");
	scanf("%s", file);

 	f = fopen(file, "r");

  	while(1){
		ch = fgetc(f);
		if(ch == EOF)
			break;
		if(ch == 10){
			count++;
		}
	}

	vet = malloc(count * sizeof int);
  	
	while(fgets(line, 1024, f)){
		if(ch == EOF)
			break;
		putchar(ch);
		if(ch == 10){
			count++;
		}
	}

	fclose(f);
	
	printVet(vet, tam, "Vetor desordenado");
	
	selectionSort(vet, tam);
	
	printVet(vet, tam, "Vetor ordenado");

	puts("");

	return 0;
}
