#ifndef LISTA_H
#define LISTA_H

#define MAX 100

typedef struct {
    float notas[MAX];
    int tamanho;
} Lista;

void inicializarLista(Lista *lista);
int listaVazia(Lista *lista);
int listaCheia(Lista *lista);
int inserirFinal(Lista *lista, float nota);
int inserirPosicao(Lista *lista, float nota, int posicao);
int removerPosicao(Lista *lista, int posicao);
int buscarNota(Lista *lista, float nota);
void imprimirLista(Lista *lista);
float calcularMedia(Lista *lista);
float maiorNota(Lista *lista);
float menorNota(Lista *lista);

#endif