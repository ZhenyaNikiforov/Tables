/*-Задание №1 (простая хэш-функция)-*/

#include <iostream>
#include <vector>
using namespace std;

int simpleStringHash(std::string &line) // подпрограмма подсчёта хэша;
{
  int hash = 0;                         // изначальное значение хэша;
  for (int i = 0; i < line.size(); ++i) // обходим строку по циклу;
  {
    hash += (int)line[i]; // накапливаем в хэше;
  }
  return hash; // возвращаем хэш;
}

int main()
{
  string line = ""; // изначальное значение строки;
  while (true)
  {
    cout << "Vvodim stroku: ";                                                                       // объявляем;
    cin >> line;                                                                                     // вводим строку;
    cout << "Kontrolnaya summa stroki \"" << line << "\" ravna: " << simpleStringHash(line) << endl; // хэш;
    if (line == "exit")                                                                              // если экзит...;
    {
      break; //...рвём цикл;
    }
  };
  return 0;
}