// Задача Заём
#include <iostream>
#include <cmath> // библиотека математических функций
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU"); // включает отображение кириллицы в консоли
	double S, p, m, r;
	int n;

	cout << "Введите размер займа S: " << endl;
	cin >> S;
	cout << "На какой срок n берётся займ?(в годах) " << endl;
	cin >> n;
	cout << "Под какой процент p берётся займ? " << endl;

	cin >> p;
	// реализация формулы из задания
	r = p / 100;
	m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

	cout << "Месячная выплата составит m: " << m;
	return 0;
}