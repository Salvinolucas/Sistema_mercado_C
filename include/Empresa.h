#ifndef Empresa_H
#define Empresa_H 

class Empresa { //Classe do ve�culo
	private:
		string nome_empresa;
		string endereco;
		double receita;
	
	public:
		Empresa (); //Construtor para vari�veis privadas		
		
		void set_nome_empresa (string);
		string get_nome_empresa ();
		
		void set_endereco (string);
		string get_endereco ();
		
		void set_receita (double);
		double get_receita ();		
};

#endif