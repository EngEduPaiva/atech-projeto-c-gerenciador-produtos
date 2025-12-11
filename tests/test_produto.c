// Teste simples sem framework — valida fluxo basico
#include <stdio.h>
#include <string.h>
#include "..\src/produto.h"

int main() {
    Produto p;
    p.id = 999;
    strncpy(p.nome, "Produto Teste", NOME_TAM);
    p.valor = 12.34f;

    salvarProduto(&p);

    Produto out;
    if (buscarProdutoPorId(999, &out) == 0) {
        printf("TEST OK: Encontrou %d %s %.2f\n", out.id, out.nome, out.valor);
        return 0;
    }
    printf("TEST FAIL\n");
    return 1;
}
