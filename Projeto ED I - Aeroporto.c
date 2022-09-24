/*
Projeto: Decolagem Aeroporto
Disciplina: Estrutura de Dados
Professor: Kenia Kodel Cox


Programa que simula a decolagem de um avião em um aeroporto utilizando filas.

Funções:
1- Inserir avião na fila de decolagem (ID, nome e hora) 
2- Remover avião da fila de decolagem pelo ID 
3- Consulta de um avião na fila de decolagem pelo ID e imprimir a posição dele na fila
4- Autorizar a decolagem de um avião e imprimir o avião que está decolando e o removendo da fila de decolagem
5- Imprimir a fila de decolagem
6- Informar o tamanho da fila de decolagem
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados do avião
typedef struct aviao{ 
    int id; //
    char nome[20]; 
    char hora[20]; 
}Aviao; 

// Estrutura para armazenar os dados da fila
typedef struct fila{ 
    Aviao aviao; 
    struct fila *prox; // 
}Fila;

//Função para criar a fila de decolagem
Fila *criaFila(){ //
    return NULL;
}

//Função para verificar se a fila está vazia
int filaVazia(Fila *fila){
    if(fila == NULL){
        return 1;
    }else{
        return 0;
    }
}

//Função para inserir um avião na fila de decolagem
Fila *insereFila(Fila *f, Aviao aviao){
    Fila *novo = (Fila*)malloc(sizeof(Fila)); 
    novo->aviao = aviao; 
    novo->prox = NULL; 
    if(filaVazia(f)){ 
    }else{ 
        Fila *aux = f; 
        while(aux->prox != NULL){  
            aux = aux->prox; 
        }
        aux->prox = novo; 
    }
    return f; 
}

//Função para remover um avião da fila de decolagem pelo ID
Fila *removeFila(Fila *f, int id){ 
    if(filaVazia(f)){ 
        printf("Fila vazia!\n");
    }else{ 
        Fila *aux = f; 
        Fila *ant = NULL; 
        while(aux != NULL && aux->aviao.id != id){ 
            ant = aux;
            aux = aux->prox; 
        }
        if(aux == NULL){ 
            printf("Aviao nao encontrado!\n"); 
        }else if(ant == NULL){ 
            f = aux->prox; 
            free(aux); 
        }else{ 
            ant->prox = aux->prox;
            free(aux); 
        }
    }
    return f;
}

//Função para consultar um avião na fila de decolagem pelo ID e imprimir a posição dele na fila
void consultaPosicao(Fila *f, int id){
    if(filaVazia(f)){ 
        printf("Fila vazia!\n");
    }else{ 
        Fila *aux = f; 
        int cont = 0; 
        while(aux != NULL && aux->aviao.id != id){ 
            cont++; 
            aux = aux->prox; 
        }
        if(aux == NULL){ 
            printf("Aviao nao encontrado!\n"); 
        }else{
            printf("Aviao %d esta na posicao %d da fila de decolagem!\n", id, cont);
        }
    }
}

//Função para autorizar a decolagem de um avião, informar o avião que está decolando, logo em seguida removendo-o da fila de decolagem e passar o próximo avião para decolar
Fila *decolagem(Fila *f){ 
    if(filaVazia(f)){ 
        printf("Fila vazia!\n");
    }else{ 
        Fila *aux = f; 
        printf("Aviao %d decolando!\n", aux->aviao.id); 
        f = aux->prox; 
        free(aux); 
    }
    return f; 
}



//Função para imprimir a fila de decolagem
void imprimeFila(Fila *f){
    if(filaVazia(f)){
        printf("Fila vazia!\n");
    }else{ 
        Fila *aux = f; 
        while(aux != NULL){ 
            printf("ID: %d - Nome: %s - Hora: %s \n ", aux->aviao.id, aux->aviao.nome, aux->aviao.hora); 
            aux = aux->prox; 
        }
        printf("\n");
    }
}

// Função para informar o tamanho da fila de decolagem
int tamanhoFila(Fila *f){
    int cont = 0;
    if(filaVazia(f)){
        printf("Fila vazia!\n");
    }else{
        Fila *aux = f;
        while(aux != NULL){ 
            cont++; 
            aux = aux->prox; 
        }
    }
    return cont;
}

//Função para liberar a memória alocada
void liberaFila(Fila *f){
    Fila *aux = f;
    while(aux != NULL){
        Fila *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
}

int main(){
    Fila *fila = criaFila();
    int opcao, id, total, tam;
    Aviao aviao;
    do{
        printf("1 - Inserir um aviao na fila de decolagem\n");
        printf("2 - Remover um aviao da fila de decolagem pelo ID\n");
        printf("3 - Consultar um aviao na fila de decolagem pelo ID e imprimir a posicao dele na fila\n");
        printf("4 - Autorizar a decolagem\n");
        printf("5 - Imprimir a fila de decolagem\n");
        printf("6 - Informar o tamanho da fila de decolagem\n");
        printf("7 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Informe o ID do aviao: ");
                scanf("%d", &aviao.id);
                printf("Informe o Nome da comapanhia aerea: ");
                scanf("%s", aviao.nome);
                printf("Informe a Hora de Decolagem: ");
                scanf("%s", aviao.hora);
                fila = insereFila(fila, aviao);
                printf("Aviao inserido com sucesso!\n");
                break;
            case 2:
                printf("Informe o ID do aviao: ");
                scanf("%d", &id);
                fila = removeFila(fila, id);
                printf("Aviao removido com sucesso!\n");
                break;
            case 3:
                printf("Informe o ID do aviao: ");
                scanf("%d", &id);
                consultaPosicao(fila, id);
                break;
            case 4: // Autoriza a decolagem  e imprimir a nova fila de decolagem
                fila = decolagem(fila);
                printf("Fila de decolagem atualizada: \n");
                imprimeFila(fila);
                
                break;
            case 5:
                imprimeFila(fila);
                break;
            case 6:
                tam = tamanhoFila(fila);
                printf("Tamanho da fila: %d\n", tam);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opcao != 7);
    liberaFila(fila);
    return 0;
}
