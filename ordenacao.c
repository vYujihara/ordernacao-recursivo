#include "ordenacao.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Vinícius Yuji Hara", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

unsigned int getGRR(){
	return 2021163;
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();
// Coloca elementos para as duas Buscas
void colocaelementos(int *pont,int tam){
	for (int y=0; y<tam; y++)
        *(pont+y)=y+1;
}
// Gera vetor aleatorio para as ordenações
void geraaleatorio(int *pont,int tam){
	srand(time(NULL));
	for (int y=0; y<tam; y++)
		*(pont+y)=rand() % 50000;
}
// Copia os vetores para testar outras ordenações
void copiavetor(int vetor[],int *arr,int tam){
	for (int y=0; y<tam; y++)
		*(arr+y)=vetor[y];
}

// Busca Sequencial
int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes){
	if (tam == 0)
        return -1;
    else{
		*numComparacoes=*numComparacoes+1;
        if (valor == vetor[tam-1])
            return tam-1;
        else
            return buscaSequencial(vetor, tam-1, valor, numComparacoes);
	}
}

// Busca Binária
int buscaBinaria_rec(int vetor [], int a, int b, int valor, int *numComparacoes){
	if (a > b)
		return -1;
	int m=(a+b)/2; // Sempre arredonda para baixo
	*numComparacoes=*numComparacoes+1;
	if ( valor == vetor[m])
		return m;
	*numComparacoes=*numComparacoes+1;
	if (valor < vetor[m])
		return buscaBinaria_rec(vetor,a,m-1,valor,numComparacoes);
	else
		return buscaBinaria_rec(vetor,m+1,b,valor,numComparacoes);
}
int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	int a=0;
	int b=tam-1;
	return buscaBinaria_rec(vetor,a,b,valor,numComparacoes);
}

void troca(int* p, int a,int b){
	int x=p[a];
	p[a]=p[b];
	p[b]=x;
}
// Insertion Sort	
void insertionSort_rec(int* p,int a,int b,int* numComparacoes){
	//Base
	if (a>=b) 
		return;
	insertionSort_rec(p,a,b-1,numComparacoes);
	int elemento=p[b];
	int i=b-1;
// Move todos os elementos maiores que o p[b] elementos
/* Se o elemento a ser inserido for menor que o elemento da parte ordenada 
Para o laço */
	while (i>=0 && p[i]>elemento){ 
		*numComparacoes=*numComparacoes+1;
		p[i+1]=p[i];
		i--;	
	}
	p[i+1]=elemento;
}
	
int insertionSort(int vetor[], int tam){	
	int a=0;
	int b=tam-1;
	int*p=vetor;
	int numComp=0;
	int *numComparacoes=&numComp;
	insertionSort_rec(p,a,b,numComparacoes);
	return *numComparacoes;
}
// Selection Sort
int minimo(int* p, int a, int b,int* numComparacoes){
	int m=a;
	int i=a;
	while (i<b){
		i=i+1;
		*numComparacoes=*numComparacoes+1;
		if (p[i]<p[m])
			m=i;
	}
	return m;
}		

void selectionSort_rec(int* p, int a, int b, int* numComparacoes){
   	// Base
	 if (a>=b)
        return;
    else{
	//troca 'a' com o menor elemento
        troca(p,a,minimo(p,a,b,numComparacoes));
        selectionSort_rec(p,a+1,b,numComparacoes);
		return;
	}
}
int selectionSort(int vetor[], int tam){
	int *p=vetor;
	int a=0;
    int b=tam-1;
    int numComp=0;
    int *numComparacoes=&numComp;
    selectionSort_rec(p,a,b,numComparacoes);
    return *numComparacoes;
}
// Merge Sort
// funcao intercala pega 2 vetores ordenados e retorna em um vetor ordenado
void intercala(int* p, int a, int m, int b, int* numComparacoes){
	int vaux[b-a];
	if (a>=b)
		return;
	int i=a;
	int j=m+1;
	for (int k=0;k<=b-a;k++){
		*numComparacoes=*numComparacoes+1;
		if (j>b || (i<=m && p[i]<=p[j])){
			vaux[k]=p[i];
			i=i+1;
		}
		else {
			vaux[k]=p[j];
			j=j+1;
		}
	}
	for (int x=0;x<=b-a;x++)
		p[a+x]=vaux[x];
}
void mergeSort_rec(int* p, int a, int b, int* numComparacoes){
	if (a>=b)
		return;
	int m=(a+b)/2; // arrendonda sempre pra baixo
	mergeSort_rec(p,a,m,numComparacoes);
	mergeSort_rec(p,m+1,b,numComparacoes);
	intercala(p,a,m,b,numComparacoes);
}
int mergeSort(int vetor[], int tam){
	int *p=vetor;
	int a=0;
	int b=tam-1;
    int numComp=0;
    int *numComparacoes=&numComp;
	mergeSort_rec(p,a,b,numComparacoes);
	return *numComparacoes;	
}
// Quick Sort
// 
int particiona(int* p, int a, int b, int x, int* numComparacoes){
	int m=a-1;
	for (int i=a;i<=b;i++){
		*numComparacoes=*numComparacoes+1;
		if (p[i]<=x){
			m=m+1;
			troca(p,m,i);
		}
	}
	return m;
}
void quickSort_rec(int *p, int a, int b, int* numComparacoes){
	if (a>=b)
		return;
	else{
		int m=particiona(p,a,b,p[b],numComparacoes);
		quickSort_rec(p,a,m-1,numComparacoes);
		quickSort_rec(p,m+1,b,numComparacoes);
	}
}
int quickSort(int vetor[], int tam){
    int *p=vetor;
    int a=0;
    int b=tam-1;
    int numComp=0;
    int *numComparacoes=&numComp;
    quickSort_rec(p,a,b,numComparacoes);
    return *numComparacoes;
}

// Funções de tempo e comparação
void tempoBuscaSequencial (int vetor[], int tam, int num, int* cont){
	clock_t start, end;
	double total;
	start = clock();
    int idxBusca = buscaSequencial(vetor, tam,num, cont);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f", total);
    printf("\n Busca Sequecial vetor[%d]. Índice:%d, Comparações: %d",tam, idxBusca, *cont);
    printf("\n");
	*cont=0;
}
void tempoBuscaBinaria (int vetor[], int tam, int num, int* cont){
	clock_t start, end;
	double total;
    start = clock();
    int idxBusca = buscaBinaria(vetor, tam,num, cont);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f", total);
    printf("\n Busca Binária vetor[%d]. Índice:%d, Comparações: %d",tam, idxBusca, *cont);
    printf("\n");
    *cont=0;
}

void tempoInsertionSort(int vetor[],int tam){
	clock_t start, end;
	double total;
    start = clock();
	int* p=vetor;
    int comparacoes = insertionSort(p,tam);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f", total);
    printf("\n Insertion Sort vetor[%d].Comparações: %d",tam, comparacoes);
    printf("\n");
}
void tempoSelectionSort(int vetor[],int tam){
    clock_t start, end;
    double total;
    start = clock();
    int* p=vetor;
    int comparacoes = selectionSort(p,tam);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f", total);
    printf("\n Selection Sort vetor[%d].Comparações: %d",tam, comparacoes);
    printf("\n");
}
void tempoMergeSort(int vetor[],int tam){
    clock_t start, end;
    double total;
    start = clock();
    int* p=vetor;
    int comparacoes = mergeSort(p,tam);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f", total);
    printf("\n Merge Sort vetor[%d].Comparações: %d",tam, comparacoes);
    printf("\n");
}
void tempoQuickSort(int vetor[],int tam){
    clock_t start, end;
    double total;
    start = clock();
    int* p=vetor;
    int comparacoes = quickSort(p,tam);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f", total);
    printf("\n Quick Sort vetor[%d].Comparações: %d",tam, comparacoes);
    printf("\n");
}
