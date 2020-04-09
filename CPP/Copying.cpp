//Задача Копирование файла
#include <iostream>
#include <fstream>
// заголовочный файл для работы с файлами
#include <clocale>
#include <string>
// работа со строками

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	string s;

	ofstream fout("file_1.txt"); // создаём файл
	fout << "Привет, я файл!"; // записываем текст в файл
	fout.close();
	// закрываем файл
	ifstream fin;
	// создаем объект типа ifstream для чтения файлов
	fin.open("file_1.txt");
	getline(fin, s); // записываем в строку s текст из файла
	fin.close();

	cout << s << endl; // выводим строку
	system("pause");
	return 0;
}
