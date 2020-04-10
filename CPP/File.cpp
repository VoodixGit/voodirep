// Задача Файл
/* Программа считает любые целые числа (в том числе и отрицательные), записанные через пробел.
В случае некорректной записи числа программа просуммирует все числа, не включая некорректное.
Например, запись "98 -5 а4" даст результат 93*/

#include <iostream>
#include <clocale>
#include <cstdlib>  // для функции atoi
#include <sstream>  // для функций isdigit и isspace
#include <fstream>  // для работы с файлами
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int j = 0, sum = 0;
    string chislo, s, s1;
    bool probel = true;

    ofstream fout("file_2.txt");    // создаём файл
    cout << "Введите числа: " << endl;
    getline(cin, s);    // вводим числа через пробел
    fout << s;  // переносим числа в файл из строки
    fout.close();   // закрываем файл

    ifstream fin("file_2.txt");
    getline(fin, s1);   // выводим из файла в строку числа
    fin.close();

    for (int i = 0; i < s1.length(); i++) { // перебираем символы строки как элементы массива
        j++;    // используем переменную для определения порядкового номера символа для перебираемого числа
        if (!probel) {  // проверяем, была ли ошибка в записи числа или было ли записано не число (например, d5)
            if (!isspace(s1[i]))    // если да, доходим до конца данного "числа"
                continue;
            else
                probel = true;
        }
        if (isdigit(s1[i]) || ((j == 1) && (s[i] == '-'))) {    // находим цифру или знак минус в перебираемом числе
            chislo += s1[i];
        }
        else {  // если не нашли...
            if (isspace(s[i])) {    // ... проверяем, является ли данный символ разделителем между числами
                sum += atoi(chislo.c_str());    // если да, используем функцию для преобразования строки в число
                chislo = "";    // обнуляем перебираемое число
                j = 0;  // обнуляем порядковый номер
            }
            else {  // если не является разделителем, значит произошла ошибка в записи
                probel = false;
                chislo = "";
                j = 0;
            }
        }
        if ((i == s1.length() - 1) && (chislo != "")) { // условие для последнего символа
            sum += atoi(chislo.c_str());
        }
    }

    cout << sum; // вывод суммы

    system("pause");
    return 0;
}
