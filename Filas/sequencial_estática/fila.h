#ifndef FILA_H
#define FILA_H

#define MAX 5

typedef struct{
    int senha;
    char nome[50];
} Cliente;

typedef struct{
    Cliente elementos[MAX];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *fila);

//Adiciona um cliente ao final da fila
int enfileirar(Fila *fila, Cliente cliente);

//Remove o primeiro cliente da fila
int desenfileirar(Fila *fila, Cliente *cliente);

//Consulta o primeiro cliente sem removê-lo
int frente(Fila *fila, Cliente *cliente);

int filaVazia(Fila *fila);

int filaCheia(Fila *fila);

void listarFila(Fila *fila);

//Remove todos os elementos da fila
void limparFila(Fila *fila);

#endif