#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

//a função getNome deve colocar o seu nome dentro da chamada
//seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

//Assum que os vetores estão ordenados ao chamar as funções de busca
//As funções de busca não devem alterar o vetor
//O retorno das funções de busca é o índice do elemento no vetor,
//ou -1 caso o elemeno não exista no vetor
//Você deve armazenar no ponteiro int* numComparacoes o número de comparações
//envolvendo elementos do vetor feito pelo seu algoritmo na chamada

void colocaelementos(int vetor[],int tam);
void geraaleatorio (int *pont, int tam);
void copiavetor (int vetor[], int vetorcopia[], int tam);
//a busca sequencial é a busca ingênua
int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes);

//busca binária no vetor
int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes);
int buscaBinaria_rec(int vetor[],int a,int b, int valor, int * numComparacoes);
//Cada uma das funções deve ordenar o vetor passado como parâmetro
//O retorno das funções de ordenação é o número de comparações
//entre elementos do vetor

// Insertion Sort
int insertionSort(int vetor[], int tam);
void insertionSort_rec(int *p,int a,int b,int* numComparacoes);
//void insere (int *p, int a, int b,int* numComparacoes);
//void troca (int *p, int a, int b);
//int buscaSequencial_insert(int *p,int a, int b, int valor, int* numComparacoes;

// Selection Sort
int selectionSort(int vetor[], int tam);
void selectionSort_rec(int *p,int a,int b,int* numComparacoes);
int minimo(int* p, int a, int b,int* numComparacoes);

// Merge Sort
int mergeSort(int vetor[], int tam);
void mergeSort_rec(int *p, int a, int b, int* numComparacoes);
void intercala(int *p, int a,int m, int b, int* numComparacoes);

//Quick Sort
int quickSort(int vetor[], int tam);
void quickSort_rec(int *p, int a, int b, int* numComparacoes);
int particiona(int *p, int a, int b, int x,int* numComparacoes);


void tempoBuscaSequencial (int vetor[], int tam, int num, int* cont);
void tempoBuscaBinaria (int vetor[], int tam, int num, int* cont);
void tempoInsertionSort(int vetor[], int tam);
void tempoSelectionSort(int vetor[], int tam);
void tempoMergeSort(int vetor[], int tam);
void tempoQuickSort(int vetor[], int tam);


#endif // ORDENACAO_H_
