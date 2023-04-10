#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
int main(){
	char nome[MAX_CHAR_NOME];
	//int idxBusca;
	int numComp=0;
	int *cont= &numComp;
	printf("%d\n",*cont);

	const unsigned int N3 =50000;
	const unsigned int N2 =10000;
	const unsigned int N1 =100;
	int vetor3[N3];
	int vetor2[N2];
	int vetor1[N1];
	int vetorcopia3[N3];
	int vetorcopia2[N2];
	int vetorcopia1[N1];
	int *p,*q,*r,*a,*b,*c;
	a=vetor1;
	b=vetor2;
	c=vetor3;
	p=vetorcopia1;
	q=vetorcopia2;
	r=vetorcopia3;
// x é o elemento a ser buscado, 0 é retornado -1
	int x=0;
    colocaelementos(vetor1,N1);
	colocaelementos(vetor2,N2);
	colocaelementos(vetor3,N3);

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	
	// Busca  Sequencial
	printf("Testes da Busca Sequencial:");
	printf("\n");
	tempoBuscaSequencial(vetor1,N1,x,cont);
	tempoBuscaSequencial(vetor2,N2,x,cont);
	tempoBuscaSequencial(vetor3,N3,x,cont);
	printf("\n");
	
	// Busca Binária
	printf("Testes da Busca Binária:");
	printf("\n");
	tempoBuscaBinaria(vetor1,N1,x,cont);
    tempoBuscaBinaria(vetor2,N2,x,cont);
    tempoBuscaBinaria(vetor3,N3,x,cont);
	printf("\n");

	geraaleatorio(a,N1);
    geraaleatorio(b,N2);
    geraaleatorio(c,N3);
	copiavetor(vetor1,p,N1);
	copiavetor(vetor2,q,N2);
	copiavetor(vetor3,r,N3);
	
	// Insertion Sort
	printf("Testes do Insertion Sort:");
	printf("\n");
    tempoInsertionSort(p,N1);
	tempoInsertionSort(q,N2);
	tempoInsertionSort(r,N3);
	printf("\n");

	copiavetor(vetor1,p,N1);
    copiavetor(vetor2,q,N2);
    copiavetor(vetor3,r,N3);
	
	// Seleciton Sort
	printf("Testes do Selection Sort:");
	printf("\n");
	tempoSelectionSort(p,N1);
	tempoSelectionSort(q,N2);
	tempoSelectionSort(r,N3);
	printf("\n");

    copiavetor(vetor1,p,N1);
    copiavetor(vetor2,q,N2);
    copiavetor(vetor3,r,N3);
	
	// Merge Sort
	printf("Testes do MergeSort:");
	printf("\n");
    tempoMergeSort(p,N1);
    tempoMergeSort(q,N2);
    tempoMergeSort(r,N3);
	printf("\n");

	copiavetor(vetor1,p,N1);
    copiavetor(vetor2,q,N2);
    copiavetor(vetor3,r,N3);
	
	// QuickSort
	printf("Testes do QuickSort:");
	printf("\n");
    tempoQuickSort(p,N1);
    tempoQuickSort(q,N2);
    tempoQuickSort(r,N3);
	printf("\n");

	return 0;
}
