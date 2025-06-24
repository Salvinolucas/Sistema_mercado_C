#include "Empresa.h"

Empresa :: Empresa () { //Inicialização das variáveis privadas
	nome_empresa = "";
	endereco = "";
	receita = 0;
}


void Empresa :: set_nome_empresa (string nome_empresa) {
	this -> nome_empresa = nome_empresa;
}

void Empresa :: set_endereco (string endereco) {
	this -> endereco = endereco;
}

void Empresa :: set_receita (double atualiza_receita) {
	receita = receita + atualiza_receita;
}

string Empresa :: get_nome_empresa () {
	return nome_empresa;
}

string Empresa :: get_endereco () {
	return endereco;
}

double Empresa :: get_receita () {
	return receita;
}
