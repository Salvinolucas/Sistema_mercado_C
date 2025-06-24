#ifndef PRODUTO_UNIDADE_H
#define PRODUTO_UNIDADE_H

//classe derivada da classe: "Produto"

class ProdutoUnidade : public Produto{
private:
	int embalagens_estoque;
	float valor_uni;

public:
	ProdutoUnidade(string = " ", long int = 0, int = 0, int = 0, int = 0, string = "", int = 0, float = 0);

	void set_embalagens_estoque(int);

	void set_valor_uni(float);

	int get_embalagens_estoque();

	float get_valor_uni();

	void novoprodutounidade();

	void impU() const;

	float calcula_preco_unidade(int, float);
};

#endif
