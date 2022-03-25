#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <stdio.h>
#include <conio.h>

using namespace std;
using namespace chrono;

HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);

#define SIZE 5

void PrintMenu();
void PrintInfo();
void DrawValuesVector(int v[], int size);
void GenerateSortedVector(int v[], int size);
void GenerateInverseVector(int v[], int size);
int MaxMin2(int vetor[], int size, int &max, int &min);
void PrintResult(int v[], int size, int &max, int &min, string type, duration<double> time, int comparisions, int highestIndex, int lowestIndex);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int Vector[SIZE];
    int highestIndex, lowestIndex, comparisions, option;
    string type;

    int *max = &highestIndex;
    int *min = &lowestIndex;

    do
    {
        PrintMenu();
        cout << "\nEscolha uma opção: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            GenerateSortedVector(Vector, SIZE);
            type = "sorted";
            break;
        case 2:
            system("cls");
            GenerateInverseVector(Vector, SIZE);
            type = "inverse";
            break;
        case 3:
            system("cls");
            DrawValuesVector(Vector, SIZE);
            type = "draw";
            break;
        case 4:
            PrintInfo();
            break;
        case 5:
            break;
        default:
            cout << "Opção inválida!";
            getch();
            break;
        }
    } while (option > 5);

    // Definição do clock t1 para marcar o início da contagem
    steady_clock::time_point t1 = steady_clock::now();
    comparisions = MaxMin2(Vector, SIZE, *max, *min);
    // Definição do clock t2 para marcar o término da contagem
    steady_clock::time_point t2 = steady_clock::now();
    // Criação via template class da variável tempo que receberá a duration_cast da chrono de t2 - t1
    duration<double> time = duration_cast<duration<double>>(t2 - t1);

    cout << "\n\n*** RESULTADOS ***" << endl;
    cout << "\nTempo de execução: " << time.count() << " segundos." << endl;
    cout << "Total de comparações: " << comparisions << endl;
    cout << "O maior valor do vetor encontra-se no índice: " << highestIndex << endl;
    cout << "O menor valor do vetor encontra-se no índice: " << lowestIndex << endl;

    return 0;
}

void GenerateSortedVector(int v[], int size)
{
    SetConsoleTextAttribute(colors, 6);
    cout << "Vector: ";
    SetConsoleTextAttribute(colors, 7);
    for (int i = 0; i < size; i++)
    {
        v[i] = i + 1;
        cout << "[" << v[i] << "] ";
    }
    cout << endl;
}

void GenerateInverseVector(int v[], int size)
{
    SetConsoleTextAttribute(colors, 6);
    cout << "Vector: ";
    SetConsoleTextAttribute(colors, 7);
    for (int i = 0; i < size; i++)
    {
        v[i] = size - i;
        cout << "[" << v[i] << "] ";
    }
    cout << endl;
}

void DrawValuesVector(int v[], int size)
{
    srand(time(NULL));
    SetConsoleTextAttribute(colors, 6);
    cout << "Vector: ";
    SetConsoleTextAttribute(colors, 7);
    for (int i = 0; i < size; i++)
    {
        int n = rand() % 100;
        v[i] = n;
        cout << "[" << n << "] ";
    }
    cout << endl;
}

int MaxMin2(int v[], int size, int &max, int &min)
{
    int maxIndex = 0;
    int minIndex = 0;
    int comparisions = 0;
    int exchanges = 0;

    for (int i = 1; i < size; i++)
    {
        comparisions++;
        if (v[i] > v[maxIndex])
        {
            exchanges++;
            cout << "\nTroca de índice " << exchanges << " para encontrar o Max: ";
            cout << "[" << v[maxIndex] << "] "
                 << " => "
                 << "[" << v[i] << "] ";
            maxIndex = i;
        }
        if (v[i] < v[minIndex])
        {
            comparisions++;
            exchanges++;
            cout << "\nTroca de índice " << exchanges << " para encontrar o Min: ";
            cout << "[" << v[minIndex] << "] "
                 << " => "
                 << "[" << v[i] << "] ";
            minIndex = i;
        }
    }
    max = maxIndex;
    min = minIndex;

    return comparisions;
}

void PrintMenu()
{
    system("cls");
    SetConsoleTextAttribute(colors, 15);
    cout << "*** ANÁLISE DO ALGORITMO MaxMin2 ***\n\n";
    SetConsoleTextAttribute(colors, 7);
    cout << "    +-+-+-+-+-MAXMIN2-+-+-+-+-+\n";
    cout << "    |                         |\n";
    cout << "    |      MENU PRINCIPAL     |\n";
    cout << "    |                         |\n";
    cout << "    | (1) Vetor Ordenado      |\n";
    cout << "    | (2) Vetor Inverso       |\n";
    cout << "    | (3) Vetor Aleatório     |\n";
    cout << "    | (4) Sobre               |\n";
    cout << "    | (5) Sair                |\n";
    cout << "    |                         |\n";
    cout << "    +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
}

void PrintInfo()
{
    system("cls");
    SetConsoleTextAttribute(colors, 15);
    cout << "*** ANÁLISE DO ALGORITMO MaxMin2 ***\n\n";
    SetConsoleTextAttribute(colors, 7);
    cout << "Seja f(n) o número de comparaçoes entre os elementos de Vector, se Vector contiver n elementos.\n";
    cout << "Logo, a função de complexidade considerando o número de comparaçoes realizadas seguirá a seguinte ordem:\n\n";
    SetConsoleTextAttribute(colors, 2);
    cout << "Melhor caso:\n";
    SetConsoleTextAttribute(colors, 7);
    cout << "# quando os elementos estão em ordem crescente\n";
    cout << "# executa sempre o if\n";
    SetConsoleTextAttribute(colors, 15);
    cout << "# f(n) = n - 1\n\n";
    SetConsoleTextAttribute(colors, 7);
    SetConsoleTextAttribute(colors, 4);
    cout << "Pior caso:\n";
    SetConsoleTextAttribute(colors, 7);
    cout << "# quando o maior elemento é o primeiro no vetor\n";
    cout << "# executa sempre o if e o else if\n";
    SetConsoleTextAttribute(colors, 15);
    cout << "# f(n) = 2(n - 1)\n\n";
    SetConsoleTextAttribute(colors, 7);
    SetConsoleTextAttribute(colors, 6);
    cout << "Caso médio:\n";
    SetConsoleTextAttribute(colors, 7);
    cout << "# no caso médio, V[i] é maior do que Max a metade das vezes\n";
    cout << "# executa sempre o if e o else if\n";
    SetConsoleTextAttribute(colors, 15);
    cout << "# f(n) = (3n - 3)/2\n\n";
    SetConsoleTextAttribute(colors, 7);
    cout << getch();
    main();
}