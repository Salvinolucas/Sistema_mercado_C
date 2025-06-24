#ifndef PRODUTO_QUILO_H
#define PRODUTO_QUILO_H

//classe derivada da classe: "Produto"

class ProdutoQuilo : public Produto{
private:

	float massa_estoque;
	float valor_quilo;

public:
	ProdutoQuilo(string = " ", long int = 0, int = 0, int = 0, int = 0, string = " ", float = 0, float = 0);

	void set_massa_estoque(float);
	void set_valor_k(float);

	float get_massa_estoque();
	float get_valor_k();

	void impQ() const;

	void novoprodutoquilo();

	float calcula_preco_quilo(float, float);
};

#endif
