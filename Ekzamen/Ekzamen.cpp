#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

// Функция для проверки, является ли символ гласной буквой (русской или английской)
bool isVowel(char ch) {
    ch = tolower(ch);
    const string vowels = "aeiouyаеёиоуыэюя";
    return vowels.find(ch) != string::npos;
}

vector<string> split(string& line) {
    vector<string> words; // вектор для хранения слов
    // Разбиваем строку на слова (обычный подход)
    // удаляет все разделители
    const string separators{ " ,;:.\"!?'*\n" }; // разделители слов
    size_t start{ line.find_first_not_of(separators) }; // начальный индекс первого слова
    while (start != string::npos) // проходим, пока в строке не окажется других символов, кроме separators
    {
        size_t end = line.find_first_of(separators, start + 1); // находим, где кончается слово
        if (end == string::npos) // если НЕ найден ни один из символов-разделителей
            end = line.length();        // устанавливаем переменную end на конец текста
        words.push_back(line.substr(start, end - start)); // добавляем в вектор слово
        start = line.find_first_not_of(separators, end + 1); // находим начальный индекс следующего слова и переустанавливаем start
    }
    return words;
}

int main() {
    setlocale(LC_ALL, "RU");
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл in.txt" << endl;
        return 1;
    }

    vector<string> lines; // вектор для хранения строк
    vector<string> words; // вектор для хранения слов
    string line; // текущая строка
    int lineNumber = 0;

    while (getline(inputFile, line)) {
        lines.push_back(line);
        words = split(line);
        lineNumber++;

        // Подсчет гласных и согласных
        int vowels = 0;
        int consonants = 0;
        for (char c : line) {
            if (isalpha(c)) { // проверяем только буквы
                if (isVowel(c)) {
                    vowels++;
                }
                else {
                    consonants++;
                }
            }
        }

        outputFile << lineNumber << " - слов: " << words.size()
            << ", гласных: " << vowels
            << ", согласных: " << consonants << endl;

        for (string w : words) {
            cout << w << " ";
        }
        cout << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Обработка завершена. Результаты записаны в out.txt." << endl;
    return 0;
}