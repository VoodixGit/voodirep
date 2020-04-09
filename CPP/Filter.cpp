// Задача Фильтр
#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <cctype>	// для работы функции isdigit

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	string s, s1, chislo = "";

	ofstream fout("file_1.txt");		 // создаём файл
	fout << "Если умножить 21 на 2, получится 42";		// записываем в файл текст
	fout.close();		// закрываем файл

	ifstream fin;
	fin.open("file_1.txt");
	getline(fin, s1);		// считываем текст в строку
	fin.close();

	for (int i = 0; i < s1.length(); i++) {
		if (isdigit(s1[i])) { // проверяет символ строки, является ли тот цифрой
			chislo += s1[i]; // если да, то записывает его в строку
		}
	else {
		// если нет...
		if (chislo != "") {
			// ... и строка не пустая, то есть имеет записанное в себя число ...
				cout << chislo << " "; // ... выводит число и обнуляется
				chislo = "";
			}
		}
	if ((i == s1.length() - 1) && (chislo != "")) {
		// то же самое для случая последнего элемента
		cout << chislo << endl;
		chislo = "";
		}
	}

	system("pause");
	return 0;
}