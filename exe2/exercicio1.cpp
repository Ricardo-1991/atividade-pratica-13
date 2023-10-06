#include <iostream>
#include <string>

using namespace std;

struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

void Reajusta_dez_porcento(Empregado empregados[], int quantidade) {
    for (int i = 0; i < quantidade; ++i) {
        empregados[i].salario *= 1.10;
    }
}

int main() {
    const int MAX_EMPREGADOS = 50;
    Empregado empregados[MAX_EMPREGADOS] = {
        {"João", "Silva", 1980, "123456789", 2010, 5000.0},
        {"Maria", "Santos", 1992, "987654321", 2015, 6000.0},
    };

    int quantidadeEmpregados = 2;

    cout << "Salários antes do reajuste:" << endl;
    for (int i = 0; i < quantidadeEmpregados; ++i) {
        cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$ " << empregados[i].salario << endl;
    }

    Reajusta_dez_porcento(empregados, quantidadeEmpregados);

    cout << "\nSalários após o reajuste:" << endl;
    for (int i = 0; i < quantidadeEmpregados; ++i) {
        cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$ " << empregados[i].salario << endl;
    }

    return 0;
}
