#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int smallerIndex(int *vet, int tam, int ini){
	int min = ini, j;
	for(j=ini+1; j<tam; j++){
		if(vet[min] > vet[j])
			min = j;
	}
	return min;
}

int selectionSort(int *vet, int tam){
	int i, min, aux;
	for(i = 0; i < tam; i++){
		min = smallerIndex(vet, tam, i);
		aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
}

int separa (int v[], int p, int r){
	int c = v[r];
	int t, j = p;
	for (int k = p; k < r; ++k){
		if (v[k] <= c){
			t = v[j], v[j] = v[k], v[k] = t;
			j++;
		}
	}
	t = v[j], v[j] = v[r], v[r] = t;
	return j;
}

void quicksort (int v[], int p, int r){
	if (p < r){
		int j = separa (v, p, r);
		quicksort(v, p, j-1);
		quicksort(v, j+1, r);
	}
}

void insertionSort(int list[], int n){
	int i, j;
	int next;
	for (i=1; i < n; i++){
		next = list[i];
		for (j = i - 1; j >= 0 && next < list[j]; j--)
			list[j+1] = list[j];
		list[j+1] = next;
	}
}

void bubbleSort(int vet[], int tam){
	int i, j, temp;
	for(i = tam-1; i > 0; i--){
		for(j = 0; j < i; j++)
			if(vet[j] > vet[j+1]){
				temp = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = temp;
			}
	}
}

void intercala (int p, int q, int r, int v[]){
	int *w;
	w = malloc((r-p) * sizeof(int));
	int i = p, j = q;
	int k = 0;

	while (i < q && j < r){
		if (v[i] <= v[j])
			w[k++] = v[i++];
		else
			w[k++] = v[j++];
	}
	while (i < q)
		w[k++] = v[i++];
	while (j < r)
		w[k++] = v[j++];

	for (i = p; i < r; i++)
		v[i] = w[i-p];
	free(w);
}

void mergesort(int p, int r, int v[]){
	if (p < r-1){
		int q = (p + r)/2;
		mergesort(p, q, v);
		mergesort(q, r, v);
		intercala(p, q, r, v);
	}
}

int main(){
	int vet[5570], tam = 5570, count, pos, countPV = 0;
	FILE *f;
	char ch, line[1024];
	clock_t ti, tf;

 	f = fopen("data.csv", "r");

	int temp = 0, isFirst = 0;
	pos = -1;
	count = 0;
	while(1){
		ch = fgetc(f);
		if(ch == EOF)
			break;
		if(count < 4){
			if(ch == 59)
				count++;
		} else {
			if(ch == 10){
				count = 0;
				if(pos != -1){
					isFirst = 1;
				}
				if(isFirst){
					vet[pos] = temp;
				}
				temp = 0;
				pos++;
			} else {
				int char_int = ch - '0';
				if(char_int >= 0)
					temp = temp * 10 + char_int;
			}
		}
	}

	puts("Imprimindo o Vetor\n");

	puts("\n================================\n");

	for (int i = 0; i < tam; i++)
	{
		printf("%d ", vet[i]);
	}

	puts("\n\nVetor Ordenado\n");

	puts("\n================================\n");

	ti = clock();

	//selectionSort(vet, tam);

	//quicksort(vet, 0, tam - 1);

	//insertionSort(vet, tam);

	//bubbleSort(vet, tam);

	//mergesort(0, tam, vet);

	tf = clock() - ti;

	for (int i = 0; i < tam; i++)
	{
		printf("%d ", vet[i]);
	}

	printf("\n\n%d tiques\n%.6lf segundos.\n", (int)tf, (double)tf/CLOCKS_PER_SEC);

	fclose(f);

	return 0;
}
