#include <iostream>
#include <clocale>
#include <string>

using namespace std;

int fed(char prev, char pres, char fut) {
	int x;
	if (pres == 'I' && prev == 'V')
		x = 4;
	else if (pres == 'V' && fut != 'I')
		x = 5;
	else if (pres == 'I')
		x = 1;
	else
		x = 0;
	return x;
}

int fdes(char prev, char pres, char fut) {
	int x;
	if (pres == 'X' && prev == 'L')
		x = 40;
	else if (pres == 'L' && fut != 'X' && fut != 'V' && fut != 'I')
		x = 50;
	else if (pres == 'X' && fut != 'V' && fut != 'I')
		x = 10;
	else
		x = 0;
	return x;
}

int fsot(char prev, char pres, char fut) {
	int x;
	if (pres == 'C' && prev == 'D')
		x = 400;
	else if (pres == 'D' && (fut == 'M' || fut == ' '))
		x = 500;
	else if (pres == 'C' && (fut == 'M' || fut == 'D' || fut == ' '))
		x = 100;
	else
		x = 0;
	return x;
}

int ftys(char fut) {
	int x;
	if (fut != 'M' && fut != ' ')
		x = 0;
	else
		x = 1000;
	return x;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int chislo = 0, check, a;
	string Rchislo;
	char pres, prev, fut;
	bool ed = false, des = false, sot = false, tys = false, flag = false, kostyl = false;

	cout << "Введите римское число: " << endl;
	cin >> Rchislo;

	for (int i = Rchislo.length() - 1; i >= 0; i--) {
		if (Rchislo.length() == 1) {
			fut = ' ';
			prev = ' ';
		}
		else if (i == Rchislo.length() - 1) {
			prev = ' ';
			fut = Rchislo[i - 1];
		}
		else if (i == 0) {
			prev = Rchislo[i + 1];
			fut = ' ';
		}

		else {
			prev = Rchislo[i + 1];
			fut = Rchislo[i - 1];
		}
		pres = Rchislo[i];

		if ((pres == 'I' || pres == 'V') && ed == false) {
			a = fed(prev, pres, fut);
			chislo = a;
			if (a == 4)
				kostyl = true;
		}

		else if (pres == 'X' && des == false) {
			if (fut == 'I') {
				chislo += 9;
				ed = true;
				kostyl = true;
			}
			else {
				chislo += fdes(prev, pres, fut);
				ed = true;
			}
		}

		else if (pres == 'L' && des == false) {
			a = fdes(prev, pres, fut);
			chislo = a;
			if (a == 40)
				kostyl = true;
			des = true;
			ed = true;
		}

		else if (pres == 'C' && sot == false) {
			if (fut == 'X') {
				chislo += 90;
				des = true;
				kostyl = true;
			}
			else {
				chislo += fsot(prev, pres, fut);
				des = true;
				ed = true;
			}
		}

		else if (pres == 'D' && sot == false) {
			a = fsot(prev, pres, fut);
			chislo = a;
			if (a == 400)
				kostyl = true;
			sot = true;
			des = true;
			ed = true;
		}

		else if (pres == 'M') {
			if (fut == 'C') {
				chislo += 900;
				sot = true;
				kostyl = true;
			}
			else {
				chislo += ftys(fut);
				sot = true;
				des = true;
				ed = true;
			}
		}
		else {
			if (kostyl == true)
				continue;
			else {
				flag = true;
				chislo = 0;
				break;
			}
		}
	}

	if (flag == false)
		cout << chislo;
	else
		cout << "Ошибка в записи!";
	return 0;
}
