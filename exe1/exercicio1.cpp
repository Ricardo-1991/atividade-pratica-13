#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Passagem {
    string numeroAssento;
    string dataHora;
    string cpf;
    string nome;
    int idade;
};

double calcularTotalViagem(const vector<Passagem>& viagem) {
    double total = 0.0;
    for (const auto& passagem : viagem) {
        total += 80.0;
    }
    return total;
}

double calcularTotalMes(const vector<Passagem>& vendas) {
    double total = 0.0;
    for (const auto& passagem : vendas) {
        total += 80.0;
    }
    return total;
}

string obterNomePassageiro(const vector<Passagem>& viagem, const string& numeroAssento) {
    for (const auto& passagem : viagem) {
        if (passagem.numeroAssento == numeroAssento) {
            return passagem.nome;
        }
    }
    return "Poltrona não ocupada nesta viagem.";
}

string calcularHorarioMaisRentavel(const map<string, vector<Passagem>>& vendasPorHorario) {
    string horarioMaisRentavel;
    double maiorArrecadacao = 0.0;

    for (const auto& par : vendasPorHorario) {
        double arrecadacao = calcularTotalViagem(par.second);
        if (arrecadacao > maiorArrecadacao) {
            maiorArrecadacao = arrecadacao;
            horarioMaisRentavel = par.first;
        }
    }

    return horarioMaisRentavel;
}

double calcularMediaIdade(const vector<Passagem>& vendas) {
    if (vendas.empty()) {
        return 0.0;
    }

    int somaIdades = 0;
    for (const auto& passagem : vendas) {
        somaIdades += passagem.idade;
    }

    return static_cast<double>(somaIdades) / vendas.size();
}

int main() {
    vector<Passagem> vendas;
    map<string, vector<Passagem>> vendasPorHorario;

    Passagem passagem1 = {"A1", "01/10/2023 08:00", "12345678900", "João", 25};
    vendas.push_back(passagem1);
    vendasPorHorario["08:00"].push_back(passagem1);

    Passagem passagem2 = {"B5", "01/10/2023 12:00", "98765432100", "Maria", 30};
    vendas.push_back(passagem2);
    vendasPorHorario["12:00"].push_back(passagem2);

    cout << "Total arrecadado para a viagem das 08:00: R$ " << fixed << setprecision(2) << calcularTotalViagem(vendasPorHorario["08:00"]) << endl;
    cout << "Total arrecadado em outubro de 2023: R$ " << fixed << setprecision(2) << calcularTotalMes(vendas) << endl;
    cout << "Nome do passageiro na poltrona B5: " << obterNomePassageiro(vendas, "B5") << endl;
    cout << "Horário de viagem mais rentável: " << calcularHorarioMaisRentavel(vendasPorHorario) << endl;
    cout << "Média de idade dos passageiros: " << fixed << setprecision(2) << calcularMediaIdade(vendas) << " anos" << endl;

    return 0;
}
