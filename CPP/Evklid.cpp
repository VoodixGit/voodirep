// Алгоритм Евклида
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b;

	cout << "Введите число а: " << endl;
	cin >> a;
	cout << "Введите число b: " << endl;
	cin >> b;

	// реализуем алгоритм Евклида
	while (a != b) { // если числа равны друг другу, они являются НОД
			if (a > b)
				a = a - b; // из большего числа вычитаем меньшее
			else
				b = b - a; // из большего числа вычитаем меньшее
	}
	cout << "НОД: " << a; // выводим НОД
	return 0;
}
