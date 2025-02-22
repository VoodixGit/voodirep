// Задача Геометрические фигуры
#include <iostream>
#include <clocale>
#define _USE_MATH_DEFINES	// включаем математические константы
#include <math.h>	// библиотека математических функций (для функции pow)

using namespace std;

double rectangle(double a, double b) {	// функция для вычисления площади прямоугольника
	double S;
	S = a * b;
	return S;
}

double triangle(double a, double b, double c) {	// функция для вычисления площади треугольника
	double S, p;
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

double circle(double R) {	// функция для вычисления площади круга
	double S;
	S = M_PI * pow(R, 2);	// здесь используется константа Пи
	return S;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int figure;
	cout << "Для какой фигуры нужно узнать площадь? Введите 1 для прямоугольника, 2 - треугольника, 3 - круга: " << endl;
	cin >> figure;

	switch (figure) {	// оператор множественного выбора
	case 1:	// если пользователь ввел "1", программа вычисляет площадь прямоугольника
	{
		double a, b, S;
		cout << "Введите сторону а прямоугольника: " << endl;
		cin >> a;
		while (a < 0) {
			cout << "Данная величина не может быть отрицательной: " << endl;
			cout << "Введите сторону а прямоугольника: " << endl;
			cin >> a;
		}
		cout << "Введите сторону b прямоугольника: " << endl;
		cin >> b;
		while (b < 0) {
			cout << "Данная величина не может быть отрицательной: " << endl;
			cout << "Введите сторону b прямоугольника: " << endl;
			cin >> b;
		}
		S = rectangle(a, b);	// вызов подпрограммы
		cout << "Площадь прямоугольника = " << S;
		break;
	}
	case 2:	// если пользователь ввел "2", программа вычисляет площадь треугольника
	{
		double a, b, c, S;
		cout << "Введите сторону а треугольника: " << endl;
		cin >> a;
		while (a < 0) {
			cout << "Данная величина не может быть отрицательной: " << endl;
			cout << "Введите сторону а треугольника: " << endl;
			cin >> a;
		}
		cout << "Введите сторону b треугольника: " << endl;
		cin >> b;
		while (b < 0) {
			cout << "Данная величина не может быть отрицательной: " << endl;
			cout << "Введите сторону b треугольника: " << endl;
			cin >> b;
		}
		cout << "Введите сторону c треугольника: " << endl;
		cin >> c;
		while (c < 0) {
			cout << "Данная величина не может быть отрицательной: " << endl;
			cout << "Введите сторону c треугольника: " << endl;
			cin >> c;
		}
		if ((a + b > c) && (a + c > b) && (b + c > a)) {	// критерий существования треугольника
			S = triangle(a, b, c);	// вызов подпрограммы
			cout << "Площадь треугольника = " << S;
		}
		else
			cout << "Треугольник с такими сторонами невозможен!";
		break;
	}
	case 3:	// если пользователь ввел "3", программа вычисляет площадь круга
	{
		double R, S;
		cout << "Введите радиус круга: " << endl;
		cin >> R;
		while (R < 0) {
			cout << "Данная величина не может быть отрицательной: " << endl;
			cout << "Введите радиус круга: " << endl;
			cin >> R;
		}
		S = circle(R);	// вызов подпрограммы
		cout << "Площадь круга = " << S;
		break;
	}
	default:
		cout << "Неверный ввод!";
	}

	return 0;
}
