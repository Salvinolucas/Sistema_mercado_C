#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

class Produto{
   public:
        string nome;
        string regrasConservacao;

        long int codigo;

        int validadeDia;
        int validadeMes;
        int validadeAno;

        Produto(string = " ", long int = 0, int = 0, int = 0, int = 0, string = " ");//nota: adicionei ao construtor a string de regras de conserva��o
       // ~Produto(); se acabar o produto, o destrutor seria usado

        void setNomeProduto(string);
        void setCodigoProduto(long int);

        void setRegrasConservacao(string);

        void setValidadeDia(int);
        void setValidadeMes(int);
        void setValidadeAno(int);

        string getNomeProduto() const;
        string getRegrasConservacao();
        long int getCodigoProduto();
        int getValidadeDia();
        int getValidadeMes();
        int getValidadeAno();



};


#endif // PRODUTO_H_INCLUDED
