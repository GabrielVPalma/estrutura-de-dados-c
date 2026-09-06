#include <stdio.h>
#include <string.h>
#include "fila.h"

int main(){

    Fila fila;
    Cliente cliente;
    int opcao;

    inicializarFila(&fila);

    do{

        printf("\n===== FILA DE ATENDIMENTO =====\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Atender cliente\n");
        printf("3 - Ver proximo cliente\n");
        printf("4 - Listar fila\n");
        printf("5 - Verificar se a fila esta vazia\n");
        printf("6 - Verificar se a fila esta cheia\n");
        printf("7 - Limpar fila\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");

        if(scanf("%d", &opcao) != 1){
            printf("\nEntrada invalida! Digite um numero.\n");

            while(getchar() != '\n');

            continue;
        }

        getchar();

        if(opcao >= 0 && opcao <= 7){
            switch(opcao){

                case 1:

                    if(filaCheia(&fila)){
                        printf("\nA fila esta cheia!\n");
                        break;
                    }
                    
                    printf("\nDigite a senha do cliente: ");
                    scanf("%d", &cliente.senha);
                    getchar();

                    printf("Digite o nome do cliente: ");
                    fgets(cliente.nome, sizeof(cliente.nome), stdin);
                    cliente.nome[strcspm(cliente.nome, "\n")] = '\0';
                    
                    if(enfileirar(&fila, cliente)){
                        printf("\nCliente adicionado com sucesso!\n");
                    }else{
                        printf("\nErro ao enfileirar o cliente!\n");
                        printf("Tente novamente...\n");
                    }

                    break;
                }
        }
    }




    return 0;
}