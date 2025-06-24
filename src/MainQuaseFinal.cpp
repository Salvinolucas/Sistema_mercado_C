#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Produto.cpp"
#include "ProdutoQuilo.cpp"
#include "ProdutoUnidade.cpp"
#include "Pedido.cpp"
#include "Estoque.cpp"
#include "Empresa.cpp"

int main() {
    int escolha;
    int acesso;
    int op;
    Estoque estoque;
    ProdutoQuilo prodQ("Arroz", 12345, 1, 12, 2023, "manter congelado", 20000, 3.99);
    ProdutoUnidade prodU("tempero", 54321, 24, 12, 2024, "deixe com o papai", 3000, 5.99);
    Empresa empresa;

    do {
        cout << "insira a opção: " << endl;
        cout << "1. Funcionario: " << endl;
        cout << "2. Administrador: " << endl;
        cout << "0. sair do sistema: " << endl;
        cin >> acesso;

        switch (acesso) {
            case 1:
                do {
                    cout << "===================================================================" << endl;
               cout << "insira os produtos que o cliente deseja: " << endl;
               cout <<  "1. Consultar estoque: " << endl;
               cout <<  "2. Efetuar compra: " << endl;
               cout <<  "0. voltar para o menu: " << endl;
               cin >> escolha;
               //system("cls");

            switch(escolha){
                    case 1:
                        estoque.imprimeListaQ();
                        estoque.imprimeListaU();
                        break;
                    case 2:
                        Pedido pedido;
                        long int CodU, CodQ;                     //long int codProdQ, long int codProdU, float massa, int embalagens, ProdutoQuilo& Q, ProdutoUnidade& U
                        float mass;
                        int emb;
                        cout << "===================================================================" << endl;
                        cout << "Digite o codigo do produto por unidade: " << endl;
                        cin >> CodU;
                        cout << "Informe quantas embalagens do produto o cliente deseja(se nao desejar digite 0): " << endl;
                        cin >> emb;
                        cout << "Digite o codigo do produto por quilo: " << endl;
                        cin >> CodQ;
                        cout << "Informe quantas gramas do produto por quilo o cliente deseja(se nao desejar digite 0): " << endl;
                        cin >> mass;
                        cout << "===================================================================" << endl;
                        //system("cls");

                        if(prodQ.get_massa_estoque() >= mass ){
                                if(prodU.get_embalagens_estoque() >= emb){
                                    estoque.realizarvenda(CodQ, CodU, mass, emb, prodQ, prodU); // Alterar o realizar venda para imprimir os dados no metodo
                                    /*prodQ.impQ();
                                    prodU.impU();*/

                                    double money;
                                    pedido.despacha_valor_compraQ(prodQ, mass);
                                    pedido.despacha_valor_compraU(prodU, emb);

                                    money = pedido.despacha_valor_compraQ(prodQ, mass) + pedido.despacha_valor_compraU(prodU, emb);
                                    empresa.set_receita(money);
                                    cout << "===================================================================" << endl;
                                    cout << "O valor da compra foi de :  R$ " << money << " obrigado pela preferencia, volte sempre!" << endl;
                                    cout << "===================================================================" << endl;

                                    }
                                 else if (prodU.get_embalagens_estoque() < emb){
                                    cout << "===================================================================" << endl;
                                    cout << "quantidade indisponivel de" << prodU.getNomeProduto() << "no estoque" << endl;
                                    cout << "===================================================================" << endl;

                                    }
                                }
                        else if (prodU.get_embalagens_estoque() >= emb){
                                estoque.realizarvenda(CodQ, CodU, mass, emb, prodQ, prodU);

                                estoque.imprimeListaU();

                                empresa.set_receita(pedido.despacha_valor_compraU(prodU, emb));
                                cout << "===================================================================" << endl;
                                cout << "O valor da compra foi de:  R$" << pedido.despacha_valor_compraU(prodU, emb) << endl;
                                cout << "===================================================================" << endl;

                                }

                        else if (prodQ.get_massa_estoque() >= mass){
                                estoque.realizarvenda(CodQ, CodU, mass, emb, prodQ, prodU);

                                prodQ.impQ();
                                empresa.set_receita(pedido.despacha_valor_compraU(prodU, emb));
                                cout << "===================================================================" << endl << endl;
                                cout << "O valor da compra foi de: " << pedido.despacha_valor_compraU(prodU, emb) << endl << endl;;
                                cout << "===================================================================" << endl;

                        }
                        break;
                    }
                } while (escolha != 0);
                break;
            case 2:
                do {
                    cout << "Insira a opcao que deseja senhor." << endl;
                    cout << "1. Alterar o nome da empresa." << endl;
                    cout << "2. Alterar o endereco da empresa." << endl;
                    cout << "3. Adicionar produto do tipo quilo ao estoque." << endl;
                    cout << "4. Adicionar produto do tipo unidade ao estoque." << endl;
                    cout << "5. Retirar produto do tipo quilo do estoque." << endl;
                    cout << "6. Retirar produto do tipo unidade do estoque" << endl;
                    cout << "7. Consultar receita." << endl;
                    cout << "8. Consultar estoque." << endl;
                    cout << "0. Sair para o menu." << endl;
                    cin >> op;

                    switch (op) {
                        case 1: {
                            string newname;
                            cout << "Para qual nome deseja alterar ?: " << endl;
                            cin.ignore();
                            getline(cin, newname);
                            empresa.set_nome_empresa(newname);
                            break;
                        }
                        case 2: {
                            string newadress;
                            cout << "Informe o novo endereco da empresa: " << empresa.get_nome_empresa() << endl;
                            cin.ignore();  // Limpar a entrada
                            getline(cin, newadress);
                            empresa.set_endereco(newadress);
                            break;
                        }
                        case 3:{
                            estoque.inserirprodutoquilo();
                            break;
                        }
                        case 4:{
                            estoque.inserirprodutounidade();
                            break;
                        }
                        case 5:{
                            estoque.retirarPro_quilo();
                            break;
                        }
                        case 6:{
                            estoque.retirarPro_unidade();
                            break;
                        }
                        case 7:{
                            cout << "Receita: " << empresa.get_receita() << endl;
                            break;
                        }
                        case 8:{
                            estoque.imprimeListaQ();
                            estoque.imprimeListaU();
                            break;
                    }
                }
                }while (op != 0);

        }
    } while (acesso != 0);

    return 0;
}
