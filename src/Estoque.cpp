#include "Estoque.h"

Estoque::Estoque(){//viabilizar a criação de dois arquivos "estoqueU.txt" e "estoqueQ.txt" aqui...
	//implementação "estoqueU.txt"
	ifstream arquivo; // arquivo de leitura
	arquivo.open("data/estoqueU.txt"); // abre arquivo... antes sem o /data

	//Definição da variavéis necessárias seguindo a ordem de hierarquia das classes...(1° classe Produto---> 2°ProdutoUnidade)

	string nome, regrasC;
 	long int cod; //codigo do produto
 	int dia, mes ,ano; //validade( ex: 00/00/0000)
 	int estoque_embalagens;
 	float valor_da_unidade;


    if(arquivo.is_open()){
		while(!arquivo.eof()){ // enquanto não for fim de arquivo...

			getline(arquivo,nome);

			if (arquivo.eof())
				break;

			getline(arquivo,regrasC);
			arquivo>>cod;
			arquivo>>dia;
			arquivo>>mes;
			arquivo>>ano;
			arquivo>>estoque_embalagens;
			arquivo>>valor_da_unidade;
			ProdutoUnidade Pu(nome, cod, dia, mes, ano, regrasC, estoque_embalagens, valor_da_unidade); //cria um objeto ProdutoUnidade com os dados lidos no arquivo
			listaPro_unidade.push_back(Pu);  //insere o objeto ProdutoUnidade na lista do estoque
			arquivo.ignore();
		}
		arquivo.close(); //fecha o arquivo
	 }
				else{
					cout<<"Não foi possível abrir o arquivo"<<endl;
	 }
	 ifstream arquivo1; // arquivo de leitura
	arquivo1.open("data/estoqueQ.txt"); // abre arquivo... antes sem o /data

	//Definição da variavéis necessárias seguindo a ordem de hierarquia das classes...(1° classe Produto---> 2°ProdutoUnidade)

 	float kilo_valor, estoque_massa;


    if(arquivo1.is_open()){
		while(!arquivo1.eof()){ // enquanto não for fim de arquivo...

			getline(arquivo1,nome);

			if (arquivo1.eof())
				break;

			getline(arquivo1,regrasC);
			arquivo1>>cod;
			arquivo1>>dia;
			arquivo1>>mes;
			arquivo1>>ano;
			arquivo1>>estoque_massa;
			arquivo1>>kilo_valor;
			ProdutoQuilo Pq(nome, cod, dia, mes, ano, regrasC, estoque_massa, kilo_valor); //cria um objeto ProdutoUnidade com os dados lidos no arquivo
			listaPro_quilo.push_back(Pq);  //insere o objeto ProdutoUnidade na lista do estoque
			arquivo1.ignore();
		}
		arquivo1.close(); //fecha o arquivo
	 }
				else{
					cout<<"Não foi possível abrir o arquivo"<<endl;
	 }

}

void Estoque::ordena_produtos() {
    sort(listaPro_unidade.begin(), listaPro_unidade.end(), [](const ProdutoUnidade& a, const ProdutoUnidade& b) {
        // Insira aqui a lógica de comparação entre a e b para a ordenação
        // Por exemplo, se quiser ordenar por nome do produto:
        return a.getNomeProduto() < b.getNomeProduto();
    });

    sort(listaPro_quilo.begin(), listaPro_quilo.end(), [](const ProdutoQuilo& a, const ProdutoQuilo& b) {
        // Mesma lógica de comparação para a listaPro_quilo, se necessário
        return a.getNomeProduto() < b.getNomeProduto();
    });

    // Impressão do método
    for (int i = 0; i < listaPro_unidade.size(); i++) {
        cout << listaPro_unidade[i].getNomeProduto() << endl;
    }

    for (int i = 0; i < listaPro_quilo.size(); i++) {
        cout << listaPro_quilo[i].getNomeProduto() << endl;
        cout << "Ordena Produtos Funcionando" << endl;
    }
}

/*void Estoque::inserirPro_quilo(ProdutoQuilo& Q){
    listaPro_quilo.push_back(Q);
}

void Estoque::inserirPro_Unidade(ProdutoUnidade& obj){
    listaPro_unidade.push_back(obj);
}
*/

bool Estoque::pesquisaPro_quilo() {
    string nome; // Declare a variável nome
    cout << "Digite o nome do produto que deseja pesquisar" << endl;
    getline(cin, nome);

    bool encontrado = false;

    for (int i = 0; i < listaPro_quilo.size(); i++) {
        if (nome == listaPro_quilo[i].getNomeProduto()) {
            cout << "O produto cujo nome é: " << nome << " consta no estoque" << endl;
            encontrado = true;
            return true;
            break;
        }
    }//Atentar-se a caracteres maiusculos e minusculos;

    if (!encontrado) {
        cout << "O produto não consta no estoque." << endl;
        return false;
    }

    //cout << "Pesquisa produto funcionando" << endl;
}


bool Estoque::pesquisaPro_unidade() {
    string nome; // Declare a variável nome
    cout << "Digite o nome do produto que deseja pesquisar" << endl;
    getline(cin, nome);

    bool encontrado = false;

    for (int i = 0; i < listaPro_unidade.size(); i++) {
        if (nome == listaPro_unidade[i].getNomeProduto()) {
            cout << "O produto cujo nome é: " << nome << " consta no estoque" << endl;
            encontrado = true;
            return true;
            break;
        }
    }//Atentar-se a caracteres maiusculos e minusculos;

    if (encontrado == false) {
        cout << "O produto não consta no estoque." << endl;
        return false;
    }

    //cout << "Pesquisa produto funcionando" << endl;
}



void Estoque::retirarPro_quilo() {
    string nome;
    bool encontrado = false;

    cout << "Digite o nome do produto que deseja remover" << endl;
    cin >> nome;

    for (int i = 0; i < listaPro_quilo.size(); i++) {
        if (nome == listaPro_quilo[i].getNomeProduto()) {
            listaPro_quilo.erase(listaPro_quilo.begin() + i);
            cout << "O produto " << nome << " foi removido." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "O produto não consta no estoque." << endl;
    }
}

void Estoque::retirarPro_unidade() {
    string nome;
    bool encontrado = false;

    cout << "Digite o nome do produto que deseja remover" << endl;
    getline(cin, nome);

    for (int i = 0; i < listaPro_unidade.size(); i++) {
        if (nome == listaPro_unidade[i].getNomeProduto()) {
            listaPro_unidade.erase(listaPro_unidade.begin() + i);
            encontrado = true;
            cout << "O produto " << nome << " foi removido." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "O produto não consta no estoque." << endl;
    }
}

void Estoque::inserirprodutounidade(){
	ProdutoUnidade Pu;
	char op;
	cout<<"Deseja inserir produtos (s/n)?"<<endl;
	cin>>op;
	while(op == 's'){
		Pu.novoprodutounidade(); //*** lê do teclado os dados do produto
		listaPro_unidade.push_back(Pu); //*** insere os dados na lista de produtos
		cout << endl<< "Inserir outro produto por unidade (s/n) "<<endl;
		cin>>op;
	};
}

void Estoque::inserirprodutoquilo(){
	ProdutoQuilo Pq;
	char op;
	cout<<"Deseja inserir produtos (s/n)?"<<endl;
	cin>>op;
	while(op == 's'){
		Pq.novoprodutoquilo();
		listaPro_quilo.push_back(Pq);
		cout << endl<< "Inserir outro produto por quilo (s/n) "<<endl;
		cin>>op;
	};
}

Estoque::~Estoque(){
	ofstream arquivo; //arquivo de escrita
	arquivo.open("estoqueU.txt"); // abre arquivo

	if (arquivo.is_open()){
		for (unsigned i=0;i<listaPro_unidade.size();i++){
			arquivo<<listaPro_unidade[i].getNomeProduto()<<endl;
			arquivo<<listaPro_unidade[i].getRegrasConservacao()<<endl;
			arquivo<<listaPro_unidade[i].getCodigoProduto()<<endl;
			arquivo<<listaPro_unidade[i].getValidadeDia()<<endl;
			arquivo<<listaPro_unidade[i].getValidadeMes()<<endl;
			arquivo<<listaPro_unidade[i].getValidadeAno()<<endl;
			arquivo<<listaPro_unidade[i].get_embalagens_estoque()<<endl;
			arquivo<<listaPro_unidade[i].get_valor_uni()<<endl;

		}
		arquivo.close(); //fecha arquivo
	}else{
		cout<<"Não foi possível gravar no arquivo"<<endl;
	}

	ofstream arquivo1; //arquivo de escrita
	arquivo1.open("estoqueQ.txt"); // abre arquivo

	if (arquivo1.is_open()){
		for (unsigned i=0;i<listaPro_quilo.size();i++){
			arquivo1<<listaPro_quilo[i].getNomeProduto()<<endl;
			arquivo1<<listaPro_quilo[i].getRegrasConservacao()<<endl;
			arquivo1<<listaPro_quilo[i].getCodigoProduto()<<endl;
			arquivo1<<listaPro_quilo[i].getValidadeDia()<<endl;
			arquivo1<<listaPro_quilo[i].getValidadeMes()<<endl;
			arquivo1<<listaPro_quilo[i].getValidadeAno()<<endl;
			arquivo1<<listaPro_quilo[i].get_massa_estoque()<<endl;
			arquivo1<<listaPro_quilo[i].get_valor_k()<<endl;

		}
		arquivo1.close(); //fecha arquivo
	}else{
		cout<<"Não foi possível gravar no arquivo"<<endl;
	}
}

void Estoque::imprimeListaU() const{
	cout<<"Dados dos produtos(unidade)"<<endl<<endl;
	for (unsigned i=0 ; i < listaPro_unidade.size() ; i++){
		listaPro_unidade[i].impU();
		cout<<endl;
	}
}

void Estoque::imprimeListaQ() const{
	cout<<"Dados dos produtos(quilo)"<<endl<<endl;
	for (unsigned i=0; i < listaPro_quilo.size();i++){
		listaPro_quilo[i].impQ();
		cout<<endl;
	}
}

void Estoque::atualizaEstoqueQ(float quantidadeVendida, ProdutoQuilo& Q) {
    if (quantidadeVendida > Q.get_massa_estoque()) {
        cout << "Quantidade de gramas indisponível em estoque!" << endl;
    } else {
        float Massa = Q.get_massa_estoque();
        for(int i = 0; i < listaPro_quilo.size(); i++){//mudei aqui
            if(listaPro_quilo[i].getCodigoProduto() == Q.getCodigoProduto()){
               Massa -= quantidadeVendida;
               listaPro_quilo[i].set_massa_estoque(Massa);
            }
        }
        cout << quantidadeVendida << " grama(s) do produto " << Q.getNomeProduto() << " vendida(s)."
                      << " Estoque atual: " << Q.get_massa_estoque() << endl;
    }
};

void Estoque::atualizaEstoqueU(int quantidadeVendida, ProdutoUnidade& U) {
    if (quantidadeVendida > U.get_embalagens_estoque()) {
        cout << "Quantidade de embalagens indisponível em estoque!" << endl;
    } else {
        int Embalagens = U.get_embalagens_estoque();
        for(int i = 0; i < listaPro_unidade.size(); i++){//mudei aqui
            if(listaPro_unidade[i].getCodigoProduto() == U.getCodigoProduto()){
               Embalagens -= quantidadeVendida;
               listaPro_unidade[i].set_embalagens_estoque(Embalagens);
            }
        }
        cout << quantidadeVendida << " unidade(s) do produto " << U.getNomeProduto() << " vendida(s)." << " Estoque atual: " << U.get_embalagens_estoque() << endl;
    }
};

void Estoque::realizarvenda(long int codProdQ, long int codProdU, float massa, int embalagens, ProdutoQuilo& Q, ProdutoUnidade& U) {
    bool foundQuilo = false;
    bool foundUnidade = false;

    // Procurar o produto correspondente ao código para venda em quilo
    for (int i = 0; i < listaPro_quilo.size(); i++) {
        if (listaPro_quilo[i].getCodigoProduto() == codProdQ) {
            foundQuilo = true;
            Q = listaPro_quilo[i];
            break;
        }
    }

    // Procurar o produto correspondente ao código para venda por unidade
    for (int i = 0; i < listaPro_unidade.size(); i++) {
        if (listaPro_unidade[i].getCodigoProduto() == codProdU) {
            foundUnidade = true;
            U = listaPro_unidade[i];
            break;
        }
    }

    if (!foundQuilo && !foundUnidade) {
        cout << "Produto não encontrado no estoque!" << endl;
        return;
    }

    if (massa > 0 && foundQuilo) {
        atualizaEstoqueQ(massa, Q); // Atualizar o estoque do produto em quilo
    }

    if (embalagens > 0 && foundUnidade) {
        atualizaEstoqueU(embalagens, U); // Atualizar o estoque do produto por unidade
    }

    // Se ambas as variáveis forem verdadeiras, significa que foi encontrada uma correspondência para quilo e unidade
    if (foundQuilo && foundUnidade) {
        cout << "Venda realizada para produto em quilo e por unidade simultaneamente." << endl;
        return;
    }

    if (foundQuilo) {
        cout << "Venda realizada para produto em quilo." << endl;
    }

    if (foundUnidade) {
        cout << "Venda realizada para produto por unidade." << endl;
    }
}


