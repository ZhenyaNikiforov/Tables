/*- Задание №2 (полноценный хэш) -*/

#include <iostream>
#include <vector>
using namespace std;

int raise(int number, int degree) // возведение в степень;
{
  if (degree == 0) // если степень 0, то...;
  {
    return 1; // результат 1;
  };
  if (degree == 1) // если степень 1, то...;
  {
    return number; //... результат это само число;
  };
  int mult = number;                     // начальное значение накопителя равно основанию;
  for (int i = 0; i < (degree - 1); ++i) // на 1 меньше степени;
  {
    mult *= number; // накопитель умножаем на основание и обратно в накопитель;
  };
  return mult; // возвращаем в накопитель;
};

int realStringHash(string &line, int numberP, int numberN) // расчёт контрольной суммы;
{
  int acc = 0;                          // переменная-накопитель;
  for (int i = 0; i < line.size(); ++i) // обходим всю строку как массив;
  {
    acc += (int)line[i] * raise(numberP, i); // код символа умножаем на константу в степени индекса и добавляем в накопитель;
  };
  return acc % numberN; // остаток от деления накопителя на константу;
};

int main()
{
  int numberP = 0;
  cout << "Vvodim P: ";
  cin >> numberP; // то, что возводить в степень;

  int numberN = 0;
  cout << "Vvodim N: ";
  cin >> numberN; // то, на что делить;

  string line = ""; // начальное значение - пустая строка;

  while (true) // циклическое звено подпрограммы
  {
    cout << "Vvodim stroku: "; // начальное сообщение;
    cin >> line;               // вводим значение в строку
    cout << "Kontrolnaya summa stroki \"" << line << "\" ravna: " << realStringHash(line, numberP, numberN) << endl;
    if (line == "exit") // если строка exit, то...;
    {
      break; //...прерываем цикл;
    };
  };
  return 0;
}