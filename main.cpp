#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;
int main() {
    SetConsoleOutputCP(65001);

    string nomes[20];
    int qtdAlunos, qtdDisciplinas;
    float notas[20][5];
    float media[20];

    cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;

    do {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++) {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    // commit 1

    do {
        cout << "\nQuantidade de disciplinas (1 a 5): " << endl;
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for(int i = 0; i < qtdAlunos; i++) {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for(int j = 0; j < qtdDisciplinas; j++) {
            do {
                cout << "Disciplina " << j + 1 << " (1 a 5): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }

    cout << "\nAlunos cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++) {
        cout << "   " << i + 1 << ". " << nomes[i] << endl;
    }

    // COMMIT 2

    cout << "\n=== RELATÓRIO ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;
    for (int i = 0; i < qtdAlunos; i++) {
        cout << nomes[i] << " - Média: " << media[i] << " - ";
        if (media[i] >= 7) {
            cout << "Aprovado!" << endl;
            aprovados++;
        } else if (media[i] >= 5) {
            cout << "Recuperação!" << endl;
            recuperacao++;
        } else {
            cout << "Reprovado!" << endl;
            reprovados++;
        }
    }

    cout << "\nResumo: " << aprovados << " aprovados, " << reprovados << " reprovados, " << recuperacao << " recuperação." << endl;

    // COMMIT 3

    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open()) {
        arquivo << "=== RELATÓRIO ===" << endl;
        for(int i = 0; i < qtdAlunos; i++) {
            arquivo << nomes[i] << " - Média: " << media[i] << " - ";
            if (media[i] >= 7) {
                arquivo << "Aprovado! :)" << endl;
            } else if(media[i] >= 5) {
                arquivo << "Recuperação!" << endl;
            } else {
                arquivo << "Reprovado! :(" << endl;
            }
        }
        arquivo << "\nResumo: " << aprovados << " Aprovados, " << recuperacao << " Em recuperação, " << reprovados << " Reprovados." << endl;

        arquivo.close();
        cout << "\nRelatório criado com sucesso! Salvo como relatorio.txt" << endl;
    } else {
        cout << "Erro ao criar o arquivo.";
    }

    // COMMIT 4

    return 0;
}