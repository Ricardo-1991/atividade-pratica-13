#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_PRODUTOS = 300;

struct Produto {
    string codigo;
    string nome;
    double preco;
};

struct Supermercado {
    Produto produtos[MAX_PRODUTOS];
    int quantidadeProdutos = 0;
};

bool codigoExiste(const Supermercado& mercado, const string& codigo) {
    for (int i = 0; i < mercado.quantidadeProdutos; ++i) {
        if (mercado.produtos[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}

bool nomeExiste(const Supermercado& mercado, const string& nome) {
    for (int i = 0; i < mercado.quantidadeProdutos; ++i) {
        if (mercado.produtos[i].nome == nome) {
            return true;
        }
    }
    return false;
}

void inserirProduto(Supermercado& mercado) {
    if (mercado.quantidadeProdutos == MAX_PRODUTOS) {
        cout << "Limite máximo de produtos atingido." << endl;
        return;
    }

    Produto novoProduto;
    cout << "Código do produto (13 caracteres numéricos): ";
    cin >> novoProduto.codigo;

    if (codigoExiste(mercado, novoProduto.codigo)) {
        cout << "Produto com esse código já existe." << endl;
        return;
    }

    cout << "Nome do produto (até 20 caracteres): ";
    cin.ignore(); // Ignorar o newline pendente do cin
    getline(cin, novoProduto.nome);

    if (nomeExiste(mercado, novoProduto.nome)) {
        cout << "Produto com esse nome já existe." << endl;
        return;
    }

    cout << "Preço do produto (duas casas decimais): ";
    cin >> novoProduto.preco;

    mercado.produtos[mercado.quantidadeProdutos] = novoProduto;
    mercado.quantidadeProdutos++;

    cout << "Produto inserido com sucesso." << endl;
}

void excluirProduto(Supermercado& mercado) {
    string codigoExclusao;
    cout << "Digite o código do produto a ser excluído: ";
    cin >> codigoExclusao;

    for (int i = 0; i < mercado.quantidadeProdutos; ++i) {
        if (mercado.produtos[i].codigo == codigoExclusao) {
            // Substituir o produto a ser excluído pelo último da lista
            mercado.produtos[i] = mercado.produtos[mercado.quantidadeProdutos - 1];
            mercado.quantidadeProdutos--;
            cout << "Produto excluído com sucesso." << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

void listarProdutos(const Supermercado& mercado) {
    if (mercado.quantidadeProdutos == 0) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }

    cout << "Lista de produtos:" << endl;
    for (int i = 0; i < mercado.quantidadeProdutos; ++i) {
        cout << "Código: " << mercado.produtos[i].codigo << " | Nome: " << mercado.produtos[i].nome << " | Preço: R$ " << fixed << setprecision(2) << mercado.produtos[i].preco << endl;
    }
}

void consultarPreco(const Supermercado& mercado) {
    string codigoConsulta;
    cout << "Digite o código do produto para consultar o preço: ";
    cin >> codigoConsulta;

    for (int i = 0; i < mercado.quantidadeProdutos; ++i) {
        if (mercado.produtos[i].codigo == codigoConsulta) {
            cout << "Preço do produto " << mercado.produtos[i].nome << ": R$ " << fixed << setprecision(2) << mercado.produtos[i].preco << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

int main() {
    Supermercado mercado;

    int opcao;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Inserir novo produto" << endl;
        cout << "2. Excluir produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar preço de um produto" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirProduto(mercado);
                break;
            case 2:
                excluirProduto(mercado);
                break;
            case 3:
                listarProdutos(mercado);
                break;
            case 4:
                consultarPreco(mercado);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
