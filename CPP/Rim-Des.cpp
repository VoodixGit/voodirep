// Программа работает корректно до числа 3999 включительно

#include <iostream>
#include <clocale>
#include <string>

using namespace std;

int fed(char prev, char pres, char fut) {	// подпрограмма подсчёта разряда единиц
	int x;
	if (pres == 'V' && fut == 'I')	// для случая IV
		x = 4;
	else if (pres == 'V')
		x = 5;
	else if (pres == 'I')
		x = 1;
	else
		x = 0;
	return x;
}

int fdes(char prev, char pres, char fut) {	// подпрограмма подсчёта разряда десятков
	int x;
	if (pres == 'L' && fut == 'X')	// для случая XL
		x = 40;
	else if (pres == 'L')
		x = 50;
	else if (pres == 'X')
		x = 10;
	else
		x = 0;
	return x;
}

int fsot(char prev, char pres, char fut) {	// подпрограмма подсчёта разряда сотен
	int x;
	if (pres == 'D' && fut == 'C')	// для случая CD
		x = 400;
	else if (pres == 'D')
		x = 500;
	else if (pres == 'C')
		x = 100;
	else
		x = 0;
	return x;
}

int ftys(char fut) {	// подпрограмма подсчёта разряда тысяч
	int x;
	if (fut != 'M')
		x = 0;
	else
		x = 1000;
	return x;
}

int main() {
	setlocale(LC_ALL, "RUS");
	// для чего используются переменные будет пркомментировано ниже
	int chislo = 0, a, chI = 0, chX = 0, chC = 0, chM = 0;
	string Rchislo;
	char pres, prev, fut;
	bool ed = false, des = false, sot = false, tys = false, flag = false, kostyl = false;
	bool chV = true, chL = true, chD = true;

	cout << "Введите римское число: " << endl;
	cin >> Rchislo;

	for (int i = Rchislo.length() - 1; i >= 0; i--) {

		if (Rchislo.length() == 1) {	// проверка на единственный символ в числе
			fut = ' ';		// переменная, хранящая в себе значение следующего символа
			prev = ' ';		// переменная, хранящая в себе значение предыдущего символа
		}
		else if (i == Rchislo.length() - 1) {	// проверка на первый перебираемый символ
			prev = ' ';
			fut = Rchislo[i - 1];
		}
		else if (i == 0) {	// проверка на последний перебираемый символ
			prev = Rchislo[i + 1];
			fut = ' ';
		}
		else {
			prev = Rchislo[i + 1];
			fut = Rchislo[i - 1];
		}
		pres = Rchislo[i];	// переменная, хранящая в себе значение текущего символа

		/* В следующем блоке записывается количество повторений символа.
		I, X, C, M не могут повторяться больше 3-х раз подряд */

		if (pres == 'I') {
			chI += 1;	// ch_ =  переменная, которая хранит в себе значение повторений символа
		}

		if (pres == 'X') {
			if (fut == 'I')		// переменная не записывает этот символ, т.к. описывается случай ___IX
				chX = 0;		// например, XXXIX - корректная запись, однако Х повторяется 4 раза
			else {
				chX += 1;
			}
		}
								// далее аналогично
		if (pres == 'C') {
			if (fut == 'X')
				chC = 0;
			else {
				chC += 1;
			}
		}

		if (pres == 'M') {
			if (fut == 'C')
				chM = 0;
			else {
				chM += 1;
			}
		}

		if (pres == 'I' && !ed) {	// работа с символом 'I'. В условии "Если работа с единицами не закончена..."
			if (chI > 3) {		// проверка на кол-во повторений
				flag = true;	// переменная типа bool, которая указывает на ошибку
				break;	// выход из цикла
			}
			else if (fut != 'V' && fut != 'I') {	// если следуюий символ не 'V' или 'I' ...
				ed = true;		// ... значит работа с разрядом единиц закончена
				chislo += fed(prev, pres, fut);		// вызываем подпрограмму и записываем в сумму значение символа
			}
			else {
				chislo += fed(prev, pres, fut);
			}
		}

		else if (pres == 'V' && !ed && chV) {	// работа с символом 'V'. Переменная chV описывается ниже
			if (fut == 'I' && prev == 'I'){		// исключаем случай __IVI__
				flag = true;
				break;
			}
			a = fed(prev, pres, fut);		// вызываем подпрограмму и записываем в сумму значение символа
			chislo += a;
			if (a == 4)		// если встречается случай IV, символ I не пройдёт по условиям ...
				kostyl = true;	// ... поэтому, чтобы он не вызвал ошибку, записываем переменную типа bool
			ed = true;	// работа с разрядом единиц закончена
		}

		else if (pres == 'X' && !des) {		// работает так же, как с символом I
			if (fut == 'I' && !ed) {	// для случая IX
				chislo += 9;
				kostyl = true;
			}
			else if (chX > 3) {
				flag = true;
				break;
			}
			else if (fut != 'L' && fut != 'X') {
				des = true;		// работа с разрядом десятков закончена
				chislo += fdes(prev, pres, fut);
			}
			else
				chislo += fdes(prev, pres, fut);
			ed = true;
		}

		else if (pres == 'L' && !des && chL) {	// работает так же, как с символом V
			if (fut == 'X' && prev == 'X') {
				flag = true;
				break;
			}
			a = fdes(prev, pres, fut);
			chislo += a;
			if (a == 40)	// случай XL
				kostyl = true;
			des = true;
			ed = true;
		}

		else if (pres == 'C' && !sot) {	// работает так же, как с символом I
			if (fut == 'X' && !des) {	// случай XC
				chislo += 90;
				kostyl = true;
			}
			else if (chC > 3) {
				flag = true;
				break;
			}
			else if (fut != 'D' && fut != 'C') {
				sot = true;		// работа с разрядом сотен закончена
				chislo += fsot(prev, pres, fut);
			}
			else
				chislo += fsot(prev, pres, fut);
			des = true;
			ed = true;
		}

		else if (pres == 'D' && !sot && chD) {	// работает так же, как с символом V
			if (fut == 'C' && prev == 'C') {
				flag = true;
				break;
			}
			a = fsot(prev, pres, fut);
			chislo += a;
			if (a == 400)	// случай CD
				kostyl = true;
			sot = true;
			des = true;
			ed = true;
		}

		else if (pres == 'M') {		// работает так же, как с символом I
			if (fut == 'C' && !sot) {	// случай CM
				chislo += 900;
				kostyl = true;
			}
			else if (chM > 3) {
				flag = true;
				break;
			}
			else
				chislo += ftys(fut);
			sot = true;
			des = true;
			ed = true;
		}

		else {		// если символ не прошел условия
			if (kostyl) {	// если это, допустим, символ I из числа IV
				kostyl = false; // возвращаем первоначальное значение
				continue;	// переходим к следующей итерации цикла
			}
			else {	// иначе число записано с ошибкой
				flag = true;
				break;
			}
		}

		/* Далее записывается наличие в числе символов
		V, L, D, которые не могут повторяться*/
		if (pres == 'V') {
			chV = false;  // в цикле при работе с символом V проверяется, был ли записан этот символ прежде
		}

		if (pres == 'L') {
			chL = false;
		}

		if (pres == 'D') {
			chD = false;
		}
	}

	if (!flag)	// если переменная имеет значение false
 		cout << chislo;	// вывод числа арабскими цифра
	else    // иначе, пользователь неверно ввел число
		cout << "Ошибка в записи!";
	return 0;
}
