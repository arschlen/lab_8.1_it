#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку кількості входжень символів "+", "-", "="
void Count(char* str, int& plusCount, int& minusCount, int& equalCount) {
    plusCount = minusCount = equalCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+') plusCount++;
        else if (str[i] == '-') minusCount++;
        else if (str[i] == '=') equalCount++;
    }
}

// Функція для заміни пар символів "++", "--", "==" на "****"
void Change(char* str) {
    size_t len = strlen(str);
    char result[201] = ""; // Ініціалізація порожнім рядком
    int pos = 0;

    for (size_t i = 0; i < len; i++) {
        if ((str[i] == '+' && str[i + 1] == '+') ||
            (str[i] == '-' && str[i + 1] == '-') ||
            (str[i] == '=' && str[i + 1] == '=')) {
            result[pos++] = '*';
            result[pos++] = '*';
            result[pos++] = '*';
            result[pos++] = '*';
            i++; // Пропускаємо наступний символ у парі
        }
        else {
            result[pos++] = str[i];
        }
    }
    result[pos] = '\0';
    strcpy_s(str, 201, result);
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int plusCount, minusCount, equalCount;
    Count(str, plusCount, minusCount, equalCount);

    cout << "Count of '+' symbols: " << plusCount << endl;
    cout << "Count of '-' symbols: " << minusCount << endl;
    cout << "Count of '=' symbols: " << equalCount << endl;

    Change(str);
    cout << "Modified string (result): " << str << endl;

    return 0;
}