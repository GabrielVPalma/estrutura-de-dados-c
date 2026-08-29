#include <stdio.h>
#include "pilha.h"

void inicializarPilha(Pilha *pilha){
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha){
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha){
    return pilha->topo == MAX - 1;
}

int push(Pilha *pilha, Acao acao){
    if(pilhaCheia(pilha)){
        return 0;
    }

    pilha->topo++;
    
    pilha->dados[pilha->topo] = acao;

    return 1;
}

int pop(Pilha *pilha, Acao *acao){
    if(pilhaVazia(pilha)){
        return 0;
    }

    *acao = pilha->dados[pilha->topo];

    pilha->topo--;

    return 1;
}

int top(Pilha *pilha, Acao *acao){
    if(pilhaVazia(pilha)){
        return 0;
    }

    *acao = pilha->dados[pilha->topo];

    return 1;
}

void listarPilha(Pilha *pilha){
    if(pilhaVazia(pilha)){
        printf("\nPilha vazia!\n");
        return;
    }

    printf("\n===== HISTORICO DE ACOES =====\n");

    for(int i = pilha->topo; i >= 0; i--){
        printf("[%d] %s\n", i, pilha->dados[i].descricao);
    }
}

void limparPilha(Pilha *pilha){
    pilha->topo = -1;
}