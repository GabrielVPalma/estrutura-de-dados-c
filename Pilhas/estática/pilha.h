#ifndef PILHA_H
#define PILHA_H

#define MAX 10

typedef struct{
    char descricao[100];
} Acao;

typedef struct{
    Acao dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha);

int pilhaVazia(Pilha *pilha);

int pilhaCheia(Pilha *pilha);

int push(Pilha *pilha, Acao acao);

int pop(Pilha *pilha, Acao *acao);

int top(Pilha *pilha, Acao *acao);

void listarPilha(Pilha *pilha);

void limparPilha(Pilha *pilha);

#endif 