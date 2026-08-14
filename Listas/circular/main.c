#include <stdio.h>
#include "lista.h"

int main(){

    int codigo_busca;
    int codigo_remover;
    char opcao;

    do{
        Lista lista;

        Funcionario f1 = {102, "Gabriel", "TI"};
        Funcionario f2 = {103, "Ana", "RH"};
        Funcionario f3 = {104, "Carlos", "Financeiro"};
        Funcionario f4 = {105, "Bruno", "Marketing"};

        inicializarLista(&lista);

        printf("\n ===== LISTA CIRCULAR =====\n");
        printf("\nInserindo funcionarios...\n");

        inserirInicio(&lista, f1);
        InserirInicio(&lista, f2);
        InserirFim(&lista, f3);
        InserirFim(&lista, f4);

        listarFuncionarios(&lista);

        printf("\nInforme o codigo do funcionario que deseja buscar: ");
        scanf("%d", &codigo_busca);

        No *resultado = buscarFuncionarios(&lista, codigo_busca);

        if(resultado != NULL){
            printf("\nFuncionario encontrado com sucesso!\n");
            printf("Codigo: %d\n", resultado->funcionario.codigo);
            printf("Nome  : %s\n", resultado->funcionario.nome);
            printf("Setor : %s\n", resultado->funcionario.setor);
        }else{
            printf("\nFuncionario nao encontrado!\n");
            printf("Tente novamente com um codigo valido...\n");
        }

        printf("\nInforme o codigo do funcionario que deseja remover: ");
        scanf("%d", &codigo_remover);

        if(removerFuncionario(&lista, codigo_remover)){
            printf("\nFuncionario removido com sucesso!\n");
        }else{
            printf("\nFuncionario nao encontrado!\n");
            printf("Tente novamente com um codigo valido...\n");
        }

        listarFuncionarios(&lista);

        liberarLista(&lista);

        printf("\nDeseja executar novamente? (s/n): ");
        scanf(" %c", &opcao);

    } while(opcao == 's' || opcao =='S');

    printf("\nPrograma encerrado...\n");

    return 0;
}