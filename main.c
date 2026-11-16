#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produtos
{
    int id;
    char nome[50];
    float preco;
    int quant;
};

 int main(){
    int opcao;
    struct produtos estoque[10];
    int totalProdutos=0;
 
    do{
        printf("\n=== Sistema de Estoque===\n");
        printf("1. Cadastrar produtos\n");
        printf("2. Listar produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (totalProdutos >=10)
            {
            printf("O estoque esta cheio!\n");
            } else{

            printf("ID: ");
            scanf("%d", &estoque[totalProdutos].id);
            while (getchar() !='\n');

            printf("Nome: ");
            fgets(estoque[totalProdutos].nome, 50, stdin);
            estoque[totalProdutos].nome[strcspn(estoque[totalProdutos].nome, "\n")] = '\0';

            printf("Preco: R$ ");
            scanf("%f", &estoque[totalProdutos].preco);

            printf("Quantidade: ");
            scanf("%d", &estoque[totalProdutos].quant);

            totalProdutos++;

            printf("Produto cadastrado com sucesso!\n");
            }
            break;
           
        
        case 2:
            if (totalProdutos==0)
            {
                printf("Nenhum produto cadastrado no momento!\n");
            } else {
                printf("\n-- Lista de produtos --\n");
                for (int i = 0; i < totalProdutos; i++){

                printf("produto %d:\n", i+1);

                printf("  ID: |%d\n", estoque[i].id);

                printf("  Nome: %s\n", estoque[i].nome);

                printf("  preco: R$ %.2f\n", estoque[i].preco);

                printf("  quantidade: %d\n", estoque[i].quant);

                printf("--------------------------\n");

                }
            }
            break;
           
        case 0:
            printf("Saindo do sistema...\n");
            break;
        
        default:
            printf("Opcao invalida\n");
        }

    } while (opcao !=0);
    
    return 0;
}