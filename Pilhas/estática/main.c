#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(){

    Pilha pilha;
    Acao acao;
    int opcao;

    inicializarPilha(&pilha);

    do{
        printf("\n===== HISTORICO DE ACOES =====\n");
        printf("1 - Adicionar acao\n");
        printf("2 - Desfazer ultima acao\n");
        printf("3 - Consultar ultima acao\n");
        printf("4 - Listar historico\n");
        printf("5 - Limpar historico\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
            printf("\nDigite a descricao da acao: ");
            fgets(acao.descricao, sizeof(acao.descricao), stdin);
            
            acao.descricao[strcspn(acao.descricao, "\n")] = '\0';

            if(push(&pilha, acao)){
                printf("Acao adicionada com sucesso!\n");
            }else{
                printf("Nao foi possivel adicionar a acao. A pilha esta cheia!\n");
            }

            break;

            case 2:
            
        }
    }







    return 0;
}