// Задача Ссуда
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	// позволяет выводить кириллицу
	double S, p, m, r, m1 = 0;
	int n;
	cout << "Введите размер ссуды S: " << endl;
	cin >> S;
	cout << "На какой срок n взята ссуда?(в годах) " << endl;
	cin >> n;
	cout << "Каков ежемесяный платёж m? " << endl;
	cin >> m;
	// цикл перебирает значение процента
	for (p = 0.1; fabs(m-m1) > 0.1; p += 0.01) {
		r = p / 100;
		m1 = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
		// находим промежуточное значение месячной выплаты по формуле
		if (fabs(m - m1) <= 0.1) {
			// если промежуточная выплата больше введённой, значит процент найден
			cout << "Процент ссуды p: " << p;
			break;
		}
	}
	return 0;
}