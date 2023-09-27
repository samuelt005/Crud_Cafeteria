#include "global.h"

void menuProducts(int *currentIndex, productStruct *productsArray) {
    int running = 1;
    while (running == 1) {
        char input[10], *endInput;
        int selector;

        system("cls"); //Limpeza do terminal

        printf("-------------- GERENCIAR PRODUTOS --------------\n");
        printf("1 - Consultar Produtos\n");
        printf("2 - Cadastrar Novo Produto\n");
        printf("3 - Editar Produto\n");
        printf("4 - Excluir Produto\n");
        printf("0 - Voltar\n\n");
        printf("Selecione a op��o desejada:\n");
        fgets(input, sizeof(input), stdin); // L� uma linha de entrada como uma string

        selector = (int) strtol(input, &endInput, 10); // Converter a string em um n�mero inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de convers�o
            printf("Entrada inv�lida. Digite um n�mero.\n");
            sleep(2);
            continue; // Volta para o in�cio do menu
        }

        system("cls");

        switch (selector) {
            // Case para listar produtos
            case 1:
                system("cls");
                listProduct(currentIndex, productsArray);
                returnOption();
                system("cls");
                break;

                // Case para cadastrar produtos
            case 2:
                system("cls");
                registerProduct(currentIndex, productsArray);
                system("cls");
                break;

                // Case para editar produtos
            case 3:
                system("cls");
                // Verifica se existe algum produto no array
                if (*currentIndex == 0) {
                    printf("N�o h� produtos para serem editados!\n");
                    sleep(2);
                    break;
                }
                listProduct(currentIndex, productsArray);
                editProduct(currentIndex, productsArray);
                system("cls");
                break;

                //Case para excluir produtos
            case 4:
                system("cls");
                // Verifica se existe algum produto no array
                if (*currentIndex == 0) {
                    printf("N�o h� produtos para serem exclu�dos!\n");
                    sleep(2);
                    break;
                }
                listProduct(currentIndex, productsArray);
                deleteProduct(currentIndex, productsArray);
                system("cls");
                break;

                //Case para voltar
            case 0:
                printf("Voltando...\n");
                sleep(1);
                running = 0;
                break;

                //Case de op��o inv�lida
            default:
                printf("Op��o inv�lida!");
                sleep(2);
                break;
        } //End Switch
    }
}

void menuMain(int *currentIndex, productStruct *productsArray) {
    int running = 1;
    while (running == 1) {
        char input[10], *endInput;
        int selector;

        system("cls"); //Limpeza do terminal

        //Menu principal
        printf("---------------- MENU PRINCIPAL ----------------\n");
        printf("1 - Gerenciar Produtos\n");
        printf("2 - Gerenciar Pedidos\n");
        printf("0 - Sair\n\n");
        printf("Selecione a op��o desejada:\n");
        fgets(input, sizeof(input), stdin); // L� uma linha de entrada como uma string

        selector = (int) strtol(input, &endInput, 10); // Converter a string em um n�mero inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de convers�o
            printf("Entrada inv�lida. Digite um n�mero.\n");
            sleep(2);
            continue; // Volta para o in�cio do menu
        }

        system("cls");

        switch (selector) {
            // Case para gerenciar produtos
            case 1:
                system("cls");
                menuProducts(currentIndex, productsArray);
                system("cls");
                break;

                // Case para gerenciar pedidos
            case 2:
                system("cls");

                system("cls");
                break;

                //Case para encerrar o programa
            case 0:
                printf("Saindo... volte sempre! :)\n");
                sleep(2);
                free(productsArray);
                running = 0;
                break;

                //Case de op��o inv�lida
            default:
                printf("Op��o inv�lida!");
                sleep(2);
                break;
        } //End Switch
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Cria��o do array para receber os produtos antes do sistema entrar em loop
    int productsQty = 100, *ptrProductsQty, currentIndex = 0, *ptrCurrentIndex;
    ptrProductsQty = &productsQty;
    ptrCurrentIndex = &currentIndex;

    // Aloca mem�ria com a quantidade de definida
    productStruct *ptrProductsArray = (productStruct *) malloc(*ptrProductsQty * sizeof(productStruct));

    // Se n�o conseguir alocar dar� erro antes de iniciar o sistema
    if (ptrProductsArray == NULL) {
        printf("Falha na aloca��o de mem�ria.\n");
        return 1; // Sa�da do programa com erro
    }

    printf("Bem vindo ao sistema de gerenciamento de produtos e pedidos!\n\n");
    sleep(4);
    system("cls");

    menuMain(ptrCurrentIndex, ptrProductsArray);
}
