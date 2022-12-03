//Nome: Bryan Jonathan Melo De Oliveira
#include <stdio.h>     //Para entrada e saida
#include <stdlib.h>    //
#include <math.h>      //Para calcular raiz e elevacao
#include <float.h>     //Para definicoes posteriores
#include <time.h>      //Para calcular o tempo do algoritmo

//Estrutura dos pontos
typedef struct 
{
   /* data */
   int x;
   int y;
} Point;

//Definir qual vai ser a coordenada pelo qual ele vai ordenar
int qualCoordenada = 0;
//Global devido a limitacao de retorno multiplo do c
int pontoMaisProximo1;
int pontoMaisProximo2;

//Algoritmo merge
void merge(Point vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    Point *vetAux;
    vetAux = (Point*)malloc(tam * sizeof(Point));
    
    //Determinar se e para ordenar de acordo com x ou com y
    if(qualCoordenada < 1){
    while(com1 <= meio && com2 <= fim){
        if(vetor[com1].x < vetor[com2].x) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
    }else{
    while(com1 <= meio && com2 <= fim){
        if(vetor[com1].y < vetor[com2].y) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
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

//Inicio do algoritmo mergeSort
void mergeSort(Point vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

/*void closestPairRec(Point Px[], Point Py[]){
    if((sizeof(Px)/sizeof(Point)) <= 3){
        for(int i = 0; i < sizeof(Px); i++){
           
        }
    }


}*/

int main(){
   // Define dados
   int quantidade_Pontos = 0;
   int escolha = 0;
   int ponto1 = 0;
   int ponto2 = 0;
   float distancia = 0;
   float menor_distancia = FLT_MAX;
   Point *pontos;
   Point *pontosx;
   Point *pontosy;
   // Define Timer
   clock_t start, end;
   double cpu_time_used;
   

   printf("Entrar com quantidade de Pontos:");
   scanf("%d", &quantidade_Pontos);
   
   printf("Em qual complexidade? O(n^2) = 0; O(n * log n) = 1; \n");
   scanf("%d", &escolha);

   if(escolha < 1){
        pontos = (Point*)malloc(quantidade_Pontos * sizeof(Point));
        for(int i = 0; i < quantidade_Pontos; i++){  
            pontos[i].x = rand() % (quantidade_Pontos+1);
            pontos[i].y = rand() % (quantidade_Pontos+1);
        }
        
        start = clock();
        for (int i = 0; i < quantidade_Pontos; i++){
            for (int j = 0; j < quantidade_Pontos; j++)
            {
                if (i != j)
                {
                    // Calcular a distacia euclidiana entre dois pontos
                    distancia = sqrt(pow(pontos[j].x - pontos[i].x, 2) + pow(pontos[j].y - pontos[i].y, 2));

                    if (distancia < menor_distancia)
                    {
                        ponto1 = i;
                        ponto2 = j;
                        menor_distancia = distancia;
                    }
                }
            }
        }
        //Terminar timer
        end = clock();
        //Calcular tempo em segundos
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        }else{
        //Criar dois vetores para serem ordenados de acordo com x e com y
        pontosx = (Point*)malloc(quantidade_Pontos * sizeof(Point));
        pontosy = (Point*)malloc(quantidade_Pontos * sizeof(Point));
        for(int i = 0; i < quantidade_Pontos; i++){
        pontosx[i].x = rand() % (quantidade_Pontos+1);
        pontosx[i].y = rand() % (quantidade_Pontos+1);
        pontosy[i].x = pontosx[i].x;
        pontosy[i].y = pontosx[i].y;
        }

        }

   
   /*
    * Primeiro fazemos um mergesort
   */
   /* mergeSort(pontosx, 0, quantidade_Pontos);
    qualCoordenada += 1; 
    mergeSort(pontosy, 0, quantidade_Pontos);
   */
   
     //Printar os pontos
    /*for(int i = 0; i < quantidade_Pontos; i++){
        printf("Ponto(%d) = (%d,%d)\n", i, pontos[i].x, pontos[i].y);
    }*/

    //Printar os pontos mais próximos   
    printf("Os pontos mais proximos sao o Ponto(%d) = (%d,%d) e Ponto(%d) = (%d,%d)\n E o tempo para execucao foi de %lf segundos", 
            ponto1, pontos[ponto1].x, pontos[ponto1].y, ponto2, pontos[ponto2].x, pontos[ponto2].y, cpu_time_used);
    
    if(escolha < 1){
        free(pontos);
    } else{
        free(pontosx);
        free(pontosy);
    }

    return 0;
}