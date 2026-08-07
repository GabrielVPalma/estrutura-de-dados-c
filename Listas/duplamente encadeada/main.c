#include <stdio.h>
#include "lista.h"

int main(){

    int codigo_busca;
    int codigo_remover;
    char opcao;

    do{
        Lista lista;

        Livro l1 = {106, "Clean Code", "Robert C. Martin", 2008};
        Livro l2 = {107, "Estruturas de Dados", "Nivio Ziviani", 2004};
        Livro l3 = {108, "Algoritmos", "Thomas H. Cormen", 2009};
        Livro l4 = {109, "Programacao em C", "Stephen Kochan", 2014};

        inicializarLista(&lista);

        printf("\n===== LISTA DUPLAMENTE ENCADEADA =====\n");

        printf("\nInserindo livros...\n");

        inserirInicio(&lista, l1);
        inserirFim(&lista, l2);
        inserirFim(&lista, l3);
        inserirInicio(&lista, l4);

        listarInicioFim(&lista);

        listarFimInicio(&lista);

        printf("\nInforme o codigo do livro que deseja buscar: ");
        scanf("%d", &codigo_busca);

        No *resultado = buscarLivro(&lista, codigo_busca);

        if (resultado != NULL)
        {
            printf("\nLivro encontrado!\n");
            printf("Codigo: %d\n", resultado->livro.codigo);
            printf("Titulo: %s\n", resultado->livro.titulo);
            printf("Autor : %s\n", resultado->livro.autor);
            printf("Ano   : %d\n", resultado->livro.ano);
        }
        else
        {
            printf("\nLivro nao encontrado!\n");
            printf("Tente novamente com um codigo valido...\n");
        }

        printf("\nInforme o codigo do livro que deseja remover: ");
        scanf("%d", &codigo_remover);

        printf("\nRemovendo o livro de codigo %d\n", codigo_remover);

        if (removerLivro(&lista, codigo_remover))
        {
            printf("\nLivro removido com sucesso!\n");
        }
        else
        {
            printf("\nLivro nao encontrado!\n");
            printf("Tente novamente com um codigo valido...\n");
        }

        printf("\nLista atualizada:\n");

        listarInicioFim(&lista);

        listarFimInicio(&lista);

        liberarLista(&lista);

        printf("\nDeseja executar novamente? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    printf("\nPrograma encerrado...\n");

    return 0;
}
    
