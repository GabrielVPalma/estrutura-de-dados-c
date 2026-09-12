#ifndef DEQUE_H
#define DEQUE_H

#define MAX 5

typedef struct{
    int senha;
    char nome[50];
} Cliente;

typedef struct{
    Cliente elementos[MAX];
    int inicio;
    int fim;
} Deque;

void inicializarDeque(Deque *deque);

int inserirInicio(Deque *deque, Cliente cliente);

int inserirFim(Deque *deque, Cliente cliente);

int removerInicio(Deque *deque, Cliente *cliente);

int removerFim(Deque *deque, Cliente *cliente);

// Consulta o primeiro cliente sem removê-lo
int frente(Deque *deque, Cliente *cliente);

// Consulta o ultimo cliente sem removê-lo
int tras(Deque *deque, Cliente *cliente);

int dequeVazio(Deque *deque);

int dequeCheio(Deque *deque);

void listarDeque(Deque *deque);

void limparDeque(Deque *deque);

#endif