#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Задаем размеры матриц
    const int m = 2;  // строки первой матрицы
    const int n = 2;  // столбцы первой матрицы / столбцы второй матрицы
    const int k = 2;  // стоки второй матрицы

    // задаём элементы 1 матрицы
    int matrix1[m][n] = {
        {1, 2},
        {4, 5}
    };

    // задаём элементы 2 матрицы
    int matrix2[k][n] = {
        {7, 8},
        {9, 10}
    };

    int result[m][k] = { 0 };

    // вычисление умножения матриц
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int l = 0; l < n; ++l) {
                result[i][j] += matrix1[i][l] * matrix2[l][j];
            }
        }
    }

    // вывод 1 матрицы
    cout << "Первая матрица (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix1[i][j] << " ";
        }
        cout << "\n";
    }

    // вывод 2 матрицы
    cout << "\nВторая матрица (" << n << "x" << k << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << matrix2[i][j] << " ";
        }
        cout << "\n";
    }

    // вывод результата умножение 1 и 2 матрицы
    cout << "\nРезультат умножения (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}