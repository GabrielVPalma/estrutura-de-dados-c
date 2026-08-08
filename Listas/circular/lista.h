#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    int codigo;
    char nome[50];
    char setor[50];
} Funcionario;

typedef struct No
{
    Funcionario funcionario;
    struct No *prox;
} No;

typedef struct 
{
    No *inicio;
    No *fim;
} Lista;

void inicializarLista(Lista *lista);

int listaVazia(Lista *lista);

void inserirInicio(Lista *lista, Funcionario funcionario);

void inserirFim(Lista *lista, Funcionario funcionario);

void listarFuncionarios(Lista *lista);

No *buscarFuncionarios(Lista *lista);

int removerFuncionario(Lista *lista, int codigo);

void liberarLista(Lista *lista);

#endif
