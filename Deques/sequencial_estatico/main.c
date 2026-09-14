#include <stdio.h>
#include <string.h>
#include "deque.h"

int main(){

    Deque deque;
    Cliente cliente;
    int opcao;

    inicializarDeque(&deque);

    do{
        printf("\n===== DEQUE DE ATENDIMENTO =====\n");
        printf("1 - Adicionar cliente no inicio\n");
        printf("2 - Adicionar cliente no fim\n");
        printf("3 - Atender cliente do inicio\n");
        printf("4 - Remover cliente do fim\n");
        printf("5 - Ver primeiro cliente\n");
        printf("6 - Ver ultimo cliente\n");
        printf("7 - Listar deque\n");
        printf("8 - Verificar se o deque esta vazio\n");
        printf("9 - Verificar se o deque esta cheio\n");
        printf("10 - Limpar deque\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");

        if(scanf("%d", &opcao) != 1){
            printf("\nEntrada invalida! Digite um numero.\n");

            while(getchar() != '\n');

            continue;
        }

        getchar();

        if(opcao >= 0 && opcao <= 10){
            switch(opcao){
                case 1: 
                if(dequeCheio(&deque)){
                    printf("\nO deque esta cheio!\n");
                    break;
                }

                printf("\nDigite a senha do cliente: ");

                if(scanf("%d", &cliente.senha) != 1){
                    printf("\nSenha invalida! Digite somente numeros.\n");

                    while(getchar() != '\n');

                    continue;
                }

                if(getchar() != '\n'){
                    printf("\nSenha invalida! Digite somente numeros.\n");

                    while(getchar() != '\n');

                    continue;
                }

                printf("Digite o nome do cliente: ");

                fgets(cliente.nome, sizeof(cliente.nome), stdin);
                cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

                if(inserirInicio(&deque, cliente)){
                    printf("\nCliente adicionado no inicio com sucesso!\n");
                }else{
                    printf("\nNao foi possivel adicionar o cliente!\n");
                    printf("Tente novamente...\n");
                }

                break;

                case 2:
                if(dequeCheio(&deque)){
                    printf("\nO deque esta cheio!\n");
                    break;
                }

                printf("\nDigite a senha do cliente: ");

                if(scanf("%d", &cliente.senha) != 1){
                    printf("\nSenha invalida! Digite somente numeros.\n");

                    while(getchar() != '\n');

                    continue;
                }

                if(getchar() != '\n'){
                    printf("\nSenha invalida! Digite somente numeros.\n");

                    while(getchar() != '\n');

                    continue;
                }

                printf("Digite nome do cliente: ");

                fgets(cliente.nome, sizeof(cliente.nome), stdin);
                cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

                if(inserirFim(&deque, cliente)){
                    printf("\nCliente adicionado no fim com sucesso!\n");
                }else{
                    printf("\nNao foi possivel adicionar o cliente!\n");
                    printf("Tente novamente...\n");
                }
                
                break;

                case 3:
                if(removerInicio(&deque, &cliente)){
                    printf("\n===== CLIENTE ATENDIDO =====\n");
                    printf("Senha: %d\n", cliente.senha);
                    printf("Nome: %s\n", cliente.nome);
                }else{
                    printf("\nO deque esta vazio!\n");
                }

                break;

                case 4:
                if(removerFim(&deque, &cliente)){
                    printf("\n===== CLIENTE REMOVIDO DO FIM =====\n");
                    printf("Senha: %d\n", cliente.senha);
                    printf("Nome: %s\n", cliente.nome);
                }else{
                    printf("\nO deque esta vazio!\n");
                }

                break;

                case 5:
                if(frente(&deque, &cliente)){
                    printf("\n===== PRIMEIRO CLIENTE =====\n");
                    printf("Senha: %d\n", cliente.senha);
                    printf("Nome: %s\n", cliente.nome);
                }else{
                    printf("\nO deque esta vazio!\n");
                }

                break;

                case 6:
                if(tras(&deque, &cliente)){
                    printf("\n===== ULTIMO CLIENTE =====\n");
                    printf("Senha: %d\n", cliente.senha);
                    printf("Nome: %s\n", cliente.nome);
                }else{
                    printf("\nO deque esta vazio!\n");
                }

                break;

                case 7:
                listarDeque(&deque);
                break;

                case 8:
                if(dequeVazio(&deque)){
                    printf("\nO deque esta vazio!\n");
                }else{
                    printf("\nO deque nao esta vazio!\n");
                }

                break;

                case 9:
                if(dequeCheio(&deque)){
                    printf("\nO deque esta cheio!\n");
                }else{
                    printf("\nO deque nao esta cheio!\n");
                }

                break;

                case 10:
                limparDeque(&deque);

                printf("\nDeque limpo com sucesso!\n");
                
                break;

                case 0:
                printf("\nEncerrando o programa...\n");

                break;

            }
        }else{

            printf("\nOpcao invalida! Digite uma opcao entre 0 e 10.\n");
        }

    } while(opcao != 0);

    return 0;
}