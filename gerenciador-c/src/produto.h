#ifndef PRODUTO_H
#define PRODUTO_H

#define NOME_TAM 64

typedef struct {
    int id;
    char nome[NOME_TAM];
    float valor;
} Produto;

// Funções CRUD
int salvarProduto(Produto *p);
int listarProdutos();
int buscarProdutoPorId(int id, Produto *out);
int atualizarProduto(int id, Produto *novo);
int removerProduto(int id);

#endif // PRODUTO_H
