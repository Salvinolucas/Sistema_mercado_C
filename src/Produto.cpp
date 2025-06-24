#include "Produto.h"

void Produto::setNomeProduto(string nome){
    this->nome = nome;
    }

void Produto::setCodigoProduto(long int codigo){
    this->codigo = codigo;
    }

void Produto::setRegrasConservacao(string regra){
    this->regrasConservacao = regra;
    }

void Produto::setValidadeDia(int dia){
    if (dia >= 1 && dia <= 31){
        this->validadeDia = dia;
        }
    //else
    //{cout << "data invalida" << endl;}
    }

void Produto::setValidadeMes(int mes){
    if (mes >= 1 && mes <= 12){
        this->validadeMes = mes;
        }
    //else
    //{cout << "data invalida" << endl;}
    }

void Produto::setValidadeAno(int ano){
    this->validadeAno= ano;
    }

string Produto::getNomeProduto() const{
    return nome;
    }

string Produto::getRegrasConservacao(){
    return regrasConservacao;
    }

int Produto::getValidadeAno(){
    return validadeAno;
    }

int Produto::getValidadeDia(){
    return validadeDia;
    }

int Produto::getValidadeMes(){
    return validadeMes;
    }

long int Produto::getCodigoProduto(){
    return codigo;
    }

Produto::Produto(string nome, long int codigo, int validadeDia, int validadeMes, int validadeAno, string regrasConservacao){
    //nota: adicionei ao construtor a string de regras de conservação
    setNomeProduto(nome);
    setCodigoProduto(codigo);
    setValidadeDia(validadeDia);
    setValidadeMes(validadeMes);
    setValidadeAno(validadeAno);
    setRegrasConservacao(regrasConservacao);
    }
