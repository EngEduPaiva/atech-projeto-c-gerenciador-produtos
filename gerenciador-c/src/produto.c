#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

static const char *ARQUIVO = "produtos.dat";

int salvarProduto(Produto *p) {
    FILE *f = fopen(ARQUIVO, "ab");
    if (!f) return -1;
    fwrite(p, sizeof(Produto), 1, f);
    fclose(f);
    return 0;
}

int listarProdutos() {
    FILE *f = fopen(ARQUIVO, "rb");
    if (!f) {
        printf("Nenhum produto cadastrado.\n");
        return 0;
    }
    Produto p;
    while (fread(&p, sizeof(Produto), 1, f)) {
        printf("ID: %d | Nome: %s | Valor: %.2f\n", p.id, p.nome, p.valor);
    }
    fclose(f);
    return 0;
}

int buscarProdutoPorId(int id, Produto *out) {
    FILE *f = fopen(ARQUIVO, "rb");
    if (!f) return -1;
    Produto p;
    while (fread(&p, sizeof(Produto), 1, f)) {
        if (p.id == id) {
            if (out) *out = p;
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1; // não encontrado
}

int atualizarProduto(int id, Produto *novo) {
    FILE *f = fopen(ARQUIVO, "r+b");
    if (!f) return -1;
    Produto p;
    long pos;
    while (fread(&p, sizeof(Produto), 1, f)) {
        if (p.id == id) {
            pos = ftell(f) - sizeof(Produto);
            fseek(f, pos, SEEK_SET);
            fwrite(novo, sizeof(Produto), 1, f);
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;
}

int removerProduto(int id) {
    FILE *f = fopen(ARQUIVO, "rb");
    if (!f) return -1;
    FILE *tmp = fopen("produtos_tmp.dat", "wb");
    if (!tmp) { fclose(f); return -1; }

    Produto p;
    int encontrado = 0;
    while (fread(&p, sizeof(Produto), 1, f)) {
        if (p.id == id) { encontrado = 1; continue; }
        fwrite(&p, sizeof(Produto), 1, tmp);
    }
    fclose(f);
    fclose(tmp);

    remove(ARQUIVO);
    rename("produtos_tmp.dat", ARQUIVO);
    return encontrado ? 0 : 1;
}
