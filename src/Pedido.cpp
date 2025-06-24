#include "Pedido.h"

Pedido::Pedido(long int num, float receita) {
    this->receita = receita;
    set_num_pedido(num);

}

void Pedido::set_num_pedido (long int num) {
	num_pedido = num;
}

long int Pedido::get_num_pedido () {
	return num_pedido;
}

float Pedido::getReceita(){
    return receita;
    }

float Pedido::despacha_valor_compraU(ProdutoUnidade& U, int quantidadeU) {
   // cout << "despacha_valor_compra funciona" << endl;
    float valorCompra;
    valorCompra = U.calcula_preco_unidade(quantidadeU, U.get_valor_uni());
    receita = receita + valorCompra;
    return receita;
}

float Pedido::despacha_valor_compraQ(ProdutoQuilo& Q, float quantidadeQ) {
   // cout << "despacha_valor_compra funciona" << endl;
    float valorCompra;
    valorCompra = Q.calcula_preco_quilo(quantidadeQ, Q.get_valor_k());
    receita = receita + valorCompra;
    return receita;
}

void Pedido::imprimeQuilo(/*const vector<ProdutoQuilo>&*/ProdutoQuilo& Q){
     //   cout << "imprimeQuilo Funciona com sucesso" << endl;
        cout << "Lista de produtos em quilo vendidos: " << endl;
        for (int i = 0 ; i < ListaVendaProdutoQuilo.size() ; i++){
            cout << "Nome: " << Q.getNomeProduto() << endl;
            cout << "Valor: " << Q.get_valor_k() << endl;
            cout << "Massa no estoque: " <<Q.get_massa_estoque() << endl;
        }
}

void Pedido::imprimeUnidade(/*const vector<ProdutoUnidade>&*/ProdutoUnidade& U){
   //cout << "imprimeUnidade funcionando com sucesso" << endl;
    cout << "Lista de produtos em unidade vendidos: " << endl;
    for (int i = 0 ; i < ListaVendaProdutoUnidade.size() ; i++){
        cout << "Nome: " << U.getNomeProduto() << endl;
        cout << "Valor: " << U.get_valor_uni() << endl;
        cout << "Embalagens no estoque: " << U.get_embalagens_estoque();
    }
}

void Pedido::limpaPedido(){
    //cout << "limpaPedido funcionando com sucesso" << endl;
    ListaVendaProdutoQuilo.clear();
    ListaVendaProdutoUnidade.clear();
    }

void Pedido::adicionaVendaProdutoQuilo(ProdutoQuilo& Q){
    //cout << "adicionaVendaProdutoQuilo funcionando com sucesso" << endl;
    ListaVendaProdutoQuilo.push_back(Q);
}

void Pedido::adicionaVendaProdutoUnidade(ProdutoUnidade& U){
    //cout << "adicionaVendaProdutoUnidade funcionando com sucesso" << endl;
    ListaVendaProdutoUnidade.push_back(U);
    }
