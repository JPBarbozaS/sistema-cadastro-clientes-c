#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Cliente {
    char nome[50];
    int idade;
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Cliente clientes[100];
    int totalClientes = 0;

    int opcao;

    do {
        printf("\n1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            if (totalClientes >= 100) {
                printf("Limite de clientes atingido!\n");
                break;
            }

            printf("Digite seu nome: ");
            getchar(); // limpa buffer
            fgets(clientes[totalClientes].nome, 50, stdin);
            clientes[totalClientes].nome[strcspn(clientes[totalClientes].nome, "\n")] = '\0';

            printf("Digite sua idade: ");
            scanf("%d", &clientes[totalClientes].idade);

            totalClientes++;

            printf("Cliente cadastrado com sucesso!\n");
            break;

        case 2: {
            printf("Lista de clientes:\n");

            int i;
            for (i = 0; i < totalClientes; i++) {
                printf("Nome: %s\n", clientes[i].nome);
                printf("Idade: %d\n\n", clientes[i].idade);
            }

            if (totalClientes == 0) {
                printf("Nenhum cliente cadastrado.\n");
            }

            break;
        }

        case 3: {
            printf("Buscar cliente.\n");

            char nomeBusca[50];
            printf("Digite o nome que deseja buscar: ");
            getchar();
            fgets(nomeBusca, 50, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

            int encontrado = 0;
            int i;

            for (i = 0; i < totalClientes; i++) {
                if (strcmp(clientes[i].nome, nomeBusca) == 0) {
                    printf("Cliente encontrado!\n");
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Idade: %d\n", clientes[i].idade);

                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Cliente nao encontrado.\n");
            }

            break;
        }

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
