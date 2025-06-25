#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция бинарного поиска
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Элемент найден
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Ищем в правой половине
        }
        else {
            right = mid - 1; // Ищем в левой половине
        }
    }

    return -1; // Элемент не найден
}

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы массива (отсортированные по возрастанию):\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Проверка отсортированности массива
    if (!is_sorted(arr.begin(), arr.end())) {
        cout << "Ошибка: массив должен быть отсортирован по возрастанию!\n";
        return 1;
    }

    int target;
    cout << "Введите значение для поиска: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    }
    else {
        cout << "Элемент не найден в массиве." << endl;
    }

    return 0;
}