#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x, y, r;
    const double EPSILON = 1e-9; // Точность сравнения для вещественных чисел

    // Ввод данных
    cout << "Введите координату Х: ";
    cin >> x;
    cout << "Введите координату Y: ";
    cin >> y;
    cout << "Введите радиус окружности R: ";
    cin >> r;

    // Проверка корректности ввода радиуса
    if (r < 0) {
        cout << "Ошибка: радиус не может быть отрицательным!" << endl;
        return 1;
    }

    // Вычисление расстояния от центра до точки
    double distance_squared = x * x + y * y;
    double r_squared = r * r;

    // Проверка принадлежности с учетом точности
    bool belong = abs(distance_squared - r_squared) < EPSILON;

    cout << "\nРезультат:\n"; //выводим результат
    cout << "Указанная точка с координатами ("
        << fixed << setprecision(2) << "" x << ", " << y << ") ";

    if (belong) {
        cout << "принадлежит";
    }
    else {
        cout << "не принадлежит";
    }

    cout << " окружности радиуса " << fixed << setprecision(2) << r << "." << endl;

    return 0;
}