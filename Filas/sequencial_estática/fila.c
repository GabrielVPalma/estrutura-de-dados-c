#include <stdio.h>
#include "fila.h"

void inicializarFila(Fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
}

int enfileirar(Fila *fila, Cliente cliente){
    if(filaCheia(fila)){
        return 0;
    }

    fila->elementos[fila->fim] = cliente;
    fila->fim++;

    return 1;
}

int desenfileirar(Fila *fila, Cliente *cliente){
    if(filaVazia(fila)){
        return 0;
    }

    *cliente = fila->elementos[fila->inicio];
    fila->inicio++;

    return 1;
}

int frente(Fila *fila, Cliente *cliente){
    if(filaVazia(fila)){
        return 0;
    }

    *cliente = fila->elementos[fila->inicio];

    return 1;
}

int filaVazia(Fila *fila){
    return fila->inicio == fila->fim;
}

int filaCheia(Fila *fila){
    return fila->fim == MAX;
}

int listarFila(Fila *fila){
    if(filaVazia(fila)){
        printf("\nA fila esta vazia!\n");
        return;
    }

    printf("\n===== FILA DE ATENDIMENTO =====\n");

    for(int i = fila->inicio; i < fila->fim; i++){
        printf("Senha: %d | Nome: %s\n", fila->elementos[i].senha, fila->elementos[i].nome);
    }
}

void limparFila(Fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
}