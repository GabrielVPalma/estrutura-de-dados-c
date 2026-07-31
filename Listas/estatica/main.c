#include <stdio.h>
#include "lista.h"

int main(){

    Lista lista;
    int opcao = -1;

    inicializarLista(&lista);

    while(opcao != 0){

        printf("\n===== GERENCIADOR DE NOTAS=====\n");
        printf("1 - Inserir nota no final\n");
        printf("2 - Inserir nota em uma posicao\n");
        printf("3 - Remover nota em uma posicao\n");
        printf("4 - Buscar nota\n");
        printf("5 - Exibir todas as notas\n");
        printf("6 - Calcualar media\n");
        printf("7 - Mostrar maior nota\n");
        printf("8 - Mostrar menor nota\n");
        printf("9 - Mostrar quantidade de notas\n");
        printf("10 - Verificar se a lista esta vazia\n");
        printf("11 - Verificar se a lista esta cheia\n");
        printf("0 - Sair\n");
        printf("===========================================\n");


        printf("Escolha uma opcao: "); //Inserir no final;
        scanf("%d", &opcao);

        if(opcao == 1){

            float nota;

            printf("Digite a nota: ");
            scanf("%f", &nota);

            if(inserirFinal(&lista, nota)){
                printf("Nota inserida com sucesso!\n");
            }else{
                printf("Falha na insercao! A lista esta cheia.\n");
                printf("Tente novamente...\n");
            }
        }

        else if(opcao == 2){ //Inserir em uma posição;
            
            float nota;
            int posicao;

            printf("Digite a nota: ");
            scanf("%f", &nota);

            printf("Digite a posicao: ");
            scanf("%d", &posicao);

            if(inserirPosicao(&lista, nota, posicao)){
                printf("Nota inserida com sucesso!\n");
            }else{
                printf("Falha na insercao! Lista cheia ou posicao invalida.\n");
                printf("Tente novamente...\n");

            }
        }

        else if(opcao == 3){ //Remover nota;

            int posicao;

            printf("Digite a posicao que deseja remover: ");
            scanf("%d", &posicao);

            if(removerPosicao(&lista, posicao)){
                printf("Nota removida com sucesso!\n");
            }else{
                printf("Falha na remocao! Lista vazia ou posicao invalida.\n");
                printf("Tente novamente...\n");
            }
        }

        else if(opcao == 4){ //Buscar nota;

            float nota;
            int posicao;

            printf("Digite a nota que deseja buscar: ");
            scanf("%f", &nota);

            posicao = buscarNota(&lista, nota);

            if(posicao != -1){
                printf("Nota encontrada com sucesso na posicao %d.\n", posicao);
            }else{
                printf("Nota nao encontrada!\n");
                printf("Tente novamente com uma nota valida...\n");
            }
        }

        else if(opcao == 5){ //Exibir lista;
            imprimirLista(&lista);
        }

        else if(opcao == 6){ //Calcular Media;
            if(listaVazia(&lista)){
                printf("Falha ao calcular a media! A lista esta vazia.\n");
            }else{
                printf("Media das notas: %.2f\n", calcularMedia(&lista));
            }
        }

        else if(opcao == 7){ //Maior nota;
            if(listaVazia(&lista)){
                printf("Falha ao buscar a maior nota, a lista esta vazia.\n");
            }else{
                printf("Maior nota: %.2f\n", maiorNota(&lista));
            }
        }

        else if(opcao == 8){ //Menor nota;
            if (listaVazia(&lista)){
                printf("Falha ao buscar a menor nota, a lista esta vazia.\n");
            }else{
                printf("Menor nota: %.2f\n", menorNota(&lista));
            }
        }

        else if(opcao == 9){ //Quantidade de notas;
            printf("Quantidade de notas: %d\n", lista.tamanho);
        }

        else if(opcao == 10){ //Verificar se esta vazia;
            if(listaVazia(&lista)){
                printf("A lista esta vazia.\n");
            }else{
                printf("A lista nao esta vazia.\n");
            }
        }

        else if(opcao == 11){ //Verificar se esta cheia;
              if(listaCheia(&lista)) {
                printf("A lista esta cheia.\n");
            }else{
                printf("A lista nao esta cheia.\n");
            }
        }

        else if(opcao == 0){ //Sair;
            printf("Encerrando o programa...\n");
        }else{
            printf("Opcao invalida! Tente novamente com uma opcao valida...\n");
        }
    } 
    
    return 0;
}