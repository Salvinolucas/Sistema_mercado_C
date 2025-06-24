#include "ProdutoUnidade.h"

ProdutoUnidade::ProdutoUnidade(string nome, long int codigo, int validadeDia, int validadeMes, int validadeAno, string regrasConservacao, int embalagens_estoque, float valor_uni){
    setNomeProduto(nome);
    setCodigoProduto(codigo);
    setValidadeDia(validadeDia);
    setValidadeMes(validadeMes);
    setValidadeAno(validadeAno);
    setRegrasConservacao(regrasConservacao);
	set_embalagens_estoque(embalagens_estoque);
	set_valor_uni(valor_uni);
}


void ProdutoUnidade::set_embalagens_estoque(int embalagens_estoque){
	this->embalagens_estoque = embalagens_estoque;
}

void ProdutoUnidade::set_valor_uni(float valor_uni){
	this->valor_uni = valor_uni;
}

int ProdutoUnidade::get_embalagens_estoque(){
	return this-> embalagens_estoque;
}

float ProdutoUnidade::get_valor_uni(){
	return this-> valor_uni;
}

float ProdutoUnidade::calcula_preco_unidade(int qtd, float valor_uni){
	return qtd * valor_uni;
}

void ProdutoUnidade::novoprodutounidade(){
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
    cout << "insira quantas embalagens há no estoque: ";
    cin >> embalagens_estoque;
    fflush(stdin);
    cout << "Insira o preco do produto: ";
    cin >> valor_uni;

}

void ProdutoUnidade::impU()const{
	cout<<endl;
	cout << "nome: " << nome <<endl;
	cout << "codigo: " << codigo <<endl;
	cout << "regras de conservacao: " << regrasConservacao <<endl;
	cout << "validade: " << validadeDia << "  /  " << validadeMes << "  /  " << validadeAno << endl;
    cout << "quantidade de embalagens no estoque: " << embalagens_estoque << endl;
    cout << "valor da unidade:  " << valor_uni << endl;
}
