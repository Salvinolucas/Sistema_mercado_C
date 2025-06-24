#include "ProdutoQuilo.h"

ProdutoQuilo::ProdutoQuilo(string nome, long int codigo, int validadeDia, int validadeMes, int validadeAno,string regrasConservacao, float massaEstoque, float valorKilo) {
    setNomeProduto(nome);
    setCodigoProduto(codigo);
    setValidadeDia(validadeDia);
    setValidadeMes(validadeMes);
    setValidadeAno(validadeAno);
    setRegrasConservacao(regrasConservacao);
    set_massa_estoque(massaEstoque);
    set_valor_k(valorKilo);
}

void ProdutoQuilo::set_massa_estoque(float massaEstoque) {
    this->massa_estoque = massaEstoque;
}

void ProdutoQuilo::set_valor_k(float valorKilo) {
    this->valor_quilo = valorKilo;
}

float ProdutoQuilo::get_massa_estoque() {
    return massa_estoque;
}

float ProdutoQuilo::get_valor_k() {
    return valor_quilo;
}

float ProdutoQuilo::calcula_preco_quilo(float massaGramas, float valorKilo) {
    return (massaGramas / 1000) * valorKilo;
}

void ProdutoQuilo::impQ()const{
	cout<<endl;
	cout << "nome: " << nome <<endl;
	cout << "codigo: " << codigo <<endl;
	cout << "regras de conservacao: " << regrasConservacao <<endl;
	cout << "validade: " << validadeDia << "  /  " << validadeMes << "  /  " << validadeAno << endl;
    cout << "quantidade de massa no estoque: " << massa_estoque << endl;
    cout << "valor da quilo:  " << valor_quilo << endl;
}


void ProdutoQuilo::novoprodutoquilo(){
    cout << "\nDigite nome : ";
	fflush(stdin); // limpa o buffer de entrada
	getline(cin, nome);
	cout << "\nDigite as regras de conservaçao : ";
	fflush(stdin); // limpa o buffer de entrada
	getline(cin, regrasConservacao);
	cout << "\nDigite o Numero do Registro : ";
	cin >> codigo;
	fflush(stdin);
	cout << "Digite o dia da validade: ";
	cin >> validadeDia;
	fflush(stdin);
	cout << "digite o mes: ";
	cin >> validadeMes;
	fflush(stdin);
    cout << "digite o ano: ";
    cin >> validadeAno;
    fflush(stdin);
    cout << "insira quantos quilos há no estoque: ";
    cin >> massa_estoque;
    fflush(stdin);
    cout << "Insira o preco do quilo: ";
    cin >> valor_quilo;
}
