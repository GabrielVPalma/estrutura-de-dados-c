#include <stdio.h>
#include "deque.h"

void inicializarDeque(Deque *deque){
    deque->inicio = 0;
    deque->fim = 0;
}

int inserirInicio(Deque *deque, Cliente cliente){
    if(dequeCheio(deque)){
        return 0;
    }

    // Deslocar os elementos uma posição para a direita
    for(int i = deque->fim; i > deque->inicio; i--){
        deque->elementos[i] = deque->elementos[i - 1];
    }

    deque->elementos[deque->inicio] = cliente;
    deque->fim++;

    return 1;
}

int inserirFim(Deque *deque, Cliente cliente){
    if(dequeCheio(deque)){
        return 0;
    }

    deque->elementos[deque->fim] = cliente;
    deque->fim++;

    return 1;
}

int removerInicio(Deque *deque, Cliente *cliente){
    if(dequeVazio(deque)){
        return 0;
    }

    *cliente = deque->elementos[deque->inicio];

    //Deslocar os elementos uma posição para a esquerda
    for(int i = deque->inicio; i < deque->fim - 1; i++){
        deque->elementos[i] = deque->elementos[i + 1];
    }

    deque->fim--;

    return 1;
}

int removerFim(Deque *deque, Cliente *cliente){
    if(dequeVazio(deque)){
        return 0;
    }

    deque->fim--;

    *cliente = deque->elementos[deque->fim];

    return 1;
}

int frente(Deque *deque, Cliente *cliente){
    if(dequeVazio(deque)){
        return 0;
    }

    *cliente = deque->elementos[deque->inicio];

    return 1;
}

int tras(Deque *deque, Cliente *cliente){
    if(dequeVazio(deque)){
        return 0;
    }

    *cliente = deque->elementos[deque->fim - 1];

    return 1;
}

int dequeVazio(Deque *deque){
    return deque->inicio == deque->fim;
}

int dequeCheio(Deque *deque){
    return deque->fim == MAX;
}

void listarDeque(Deque *deque){
    if(dequeVazio(deque)){
        printf("\nO deque esta vazio!\n");
        return;
    }
    
    printf("\n===== DEQUE =====\n");

    for(int i = deque->inicio; i < deque->fim; i++){
        printf("Senha: %d | Nome: %s\n", deque->elementos[i].senha, deque->elementos[i].nome);
    }
}

void limparDeque(Deque *deque){
    deque->inicio = 0;
    deque->fim = 0;
}