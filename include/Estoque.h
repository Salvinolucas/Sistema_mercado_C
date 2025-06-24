#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

class Estoque {
private:
    vector<ProdutoUnidade> listaPro_unidade;
    vector<ProdutoQuilo> listaPro_quilo;

public:
    Estoque();
    void ordena_produtos();

    bool pesquisaPro_quilo();
    bool pesquisaPro_unidade();

    void inserirPro_Unidade(ProdutoUnidade&);
    void inserirPro_quilo(ProdutoQuilo&);

    void retirarPro_quilo();
    void retirarPro_unidade();

    void inserirprodutounidade();
    void inserirprodutoquilo();

    void imprimeListaU() const;
    void imprimeListaQ() const;

    void atualizaEstoqueQ(float, ProdutoQuilo&);
    void atualizaEstoqueU(int, ProdutoUnidade&);

    void realizarvenda(long int, long int, float, int, ProdutoQuilo&, ProdutoUnidade&);

    ~Estoque();

};

#endif // ESTOQUE_H_INCLUDED
