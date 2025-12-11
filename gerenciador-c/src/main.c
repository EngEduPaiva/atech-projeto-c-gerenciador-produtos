#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

void menu() {
    printf("--- Gerenciador de Produtos ---\n");
    printf("1 - Inserir produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar por ID\n");
    printf("4 - Atualizar produto\n");
    printf("5 - Remover produto\n");
    printf("0 - Sair\n");
}

int main() {
    int opc;
    Produto p;
    while (1) {
        menu();
        printf("Escolha: ");
        if (scanf("%d", &opc) != 1) break;
        getchar(); // consome newline
        if (opc == 0) break;
        switch (opc) {
            case 1:
                printf("ID: "); scanf("%d", &p.id); getchar();
                printf("Nome: "); fgets(p.nome, NOME_TAM, stdin);
                p.nome[strcspn(p.nome, "\n")] = 0;
                printf("Valor: "); scanf("%f", &p.valor); getchar();
                salvarProduto(&p);
                printf("Produto salvo.\n");
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                printf("ID: "); scanf("%d", &opc); getchar();
                if (buscarProdutoPorId(opc, &p) == 0) {
                    printf("Encontrado: %d %s %.2f\n", p.id, p.nome, p.valor);
                } else printf("Produto nao encontrado.\n");
                break;
            case 4:
                printf("ID a atualizar: "); scanf("%d", &opc); getchar();
                if (buscarProdutoPorId(opc, &p) == 0) {
                    Produto novo = p;
                    printf("Novo nome (enter para manter): ");
                    char buffer[NOME_TAM];
                    fgets(buffer, NOME_TAM, stdin);
                    buffer[strcspn(buffer, "\n")] = 0;
                    if (strlen(buffer) > 0) strncpy(novo.nome, buffer, NOME_TAM);
                    printf("Novo valor (0 para manter): ");
                    float v; scanf("%f", &v); getchar();
                    if (v > 0) novo.valor = v;
                    atualizarProduto(opc, &novo);
                    printf("Atualizado.\n");
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
            case 5:
                printf("ID a remover: "); scanf("%d", &opc); getchar();
                if (removerProduto(opc) == 0) printf("Removido.\n"); else printf("Nao encontrado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }
    printf("Encerrando...\n");
    return 0;
}
