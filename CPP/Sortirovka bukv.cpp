// Задача Сортировка букв
#include <iostream>
#include <clocale>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	char temp;
	string s;

	cout << "Введите строку: " << endl;
	cin >> s;

	for (int i = 0; i < s.length(); i++) { // сортируем буквы методом пузырька
		for (int j = 1; j < s.length() - i; j++) {
			// для этого необходимо выполнить явное преобразование. У символа будет значение его порядкового номера в таблице ASCII
			if ((int)s[j] < (int)s[j - 1]) { 
				temp = s[j];
				s[j] = s[j - 1];
				s[j - 1] = temp;
			}	
		}
	}

	cout << s << endl;
	system("pause");
	return 0;
}