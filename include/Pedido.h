#ifndef Pedido_H
#define Pedido_H



class Pedido : public ProdutoQuilo, public ProdutoUnidade{
	private:
		long int num_pedido;
		vector<ProdutoQuilo> ListaVendaProdutoQuilo;
		vector<ProdutoUnidade> ListaVendaProdutoUnidade;
		float receita;

	public:
	    Pedido(long int = 0, float = 0);
		void adicionaVendaProdutoUnidade(ProdutoUnidade&);
		void adicionaVendaProdutoQuilo(ProdutoQuilo&);

		float despacha_valor_compraU(ProdutoUnidade&, int);
        float despacha_valor_compraQ(ProdutoQuilo&, float);

		void imprimeQuilo(/*const vector<ProdutoQuilo>& ListaVendaProdutoQuilo, */ ProdutoQuilo&);
		void imprimeUnidade(/*const vector<ProdutoUnidade>& listaVendaProdutoUnidade,*/ ProdutoUnidade&);
		void limpaPedido();

		float getReceita();
		void set_num_pedido (long int);
		long int get_num_pedido();
};

#endif
