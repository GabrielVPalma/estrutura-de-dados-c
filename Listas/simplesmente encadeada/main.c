#include <stdio.h>
#include "lista.h"

int main(){

    int codigo_busca;
    int codigo_remover;
    char opcao;

    do{
    Lista lista;
    
    Produto p1 = {106, "Teclado", 150.00};
    Produto p2 = {107, "Mouse", 80.00};
    Produto p3 = {108, "Monitor", 980.00};
    Produto p4 = {109, "Headset", 350.00};

    inicializarLista(&lista);

    printf("Inserindo produtos...\n");
    
    inserirInicio(&lista, p1);
    inserirFim(&lista, p2);
    inserirFim(&lista, p3);
    inserirInicio(&lista, p4);

    listarProdutos(&lista);

    printf("Informe o codigo do produto que deseja buscar: ");
    scanf("%d", &codigo_busca);

    No *resultado = buscarProduto(&lista, codigo_busca);

    if(resultado != NULL){
        printf("Produto encontrado!\n");
        printf("Nome: %s\n", resultado->produto.nome);
        printf("Preco: R$ %.2f\n", resultado->produto.preco);

    }else{
        printf("Produto nao encontrado!\n");
        printf("Tente novamente com um codigo valido...\n");
    }

    printf("Informe o codigo do produto que deseja remover: ");
    scanf("%d", &codigo_remover);

    printf("\nRemovendo o produto de codigo %d\n", codigo_remover);

    if(removerProduto(&lista, codigo_remover)){
        printf("Produto removido com sucesso!\n");
    }else{
        printf("Produto nao encontrado!\n");
        printf("Tente novamente com um codigo valido...\n");
    }

    listarProdutos(&lista);

    liberarLista(&lista);

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);

} while(opcao == 's' || opcao == 'S');

    printf("Programa encerrado...\n");
    
    return 0;
}