//Nome: Bryan Jonathan Melo De Oliveira
#include<stdio.h>
#include <stdlib.h>

struct Point;

//Estrutura dos pontos
typedef struct 
{
   /* data */
   int x;
   int y;
   struct Point *closest;
} Point;

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main(){
   int n, x, y;
   

   
   printf("Entrar com quantidade de Pontos (limite: 128 pontos):");
   scanf("%d", &n);

   Point points[n];

   for(int i = 0; i < n; i++){
    //printf("Entrar com coordenada x e y:");
    //scanf("%d%d", &x, &y);   
    points[i].x = rand() % (n+1);
    points[i].y = rand() % (n+1);
    points[i].closest = malloc(sizeof(Point));
   }
   

   //quicksortRec(0, n-1);

   for(int j = 0; j < n; j++){
    printf("j = (%d,%d) and closest Point = %x\n", points[j].x, points[j].y, points[j].closest);
   }

}