/*- Задача №3 на поиск подстроки -*/

#include <iostream>
#include <vector>
using namespace std;

int controlSum(string &line, int end) // расчёт контрольных сумм;
{
  int sum = 0;                  // изначально 0;
  for (int i = 0; i < end; ++i) // обходим до i;
  {
    sum += (int)line[i]; // добавляем в накопитель код символа;
  }
  return sum; // возвращаем накопитель;
};

int main()
{
  string primatumLine = "";              // первичная строка, в которой искать
  cout << "Vvodim stroku, gde iskat`: "; // сообщение о ней
  cin >> primatumLine;                   // заполняем первичную строку

  string littleLine = ""; // строка, которую искать

  while (true) // циклическое звено подпрограммы
  {
    cout << "Vvodim stroku, kotoruy iskat`: "; // сообщение о вводе строки
    cin >> littleLine;                         // ввод строки

    if (primatumLine.size() < littleLine.size()) // если первичная строка короче вторичной, то...;
    {
      cout << "Vtorichnaya stroka slishkom dlinnaya!" << endl; // сообщаем об этом;
      break;                                                   // прерываем цикл;
    };

    int controlSumLittleLine = controlSum(littleLine, littleLine.size()); // контрольн. сумма мал. строки;
    int controlSumFragment = controlSum(primatumLine, littleLine.size()); // контрольн. сумма фрагм. больш. строки по разм. мал.;

    int startIndex = 0;                   // начальн. индекс в больш. строке;
    int endIndex = littleLine.size() - 1; // конечн. индекс в больш. строке;

    bool find = false; // находка;

    while (true) // внутр. цикл;
    {
      if (controlSumLittleLine == controlSumFragment) // если контрольные суммы равны, то...;
      {
        find = true; //...находка есть;
        break;       // прерываем внутренний цикл;
      }
      endIndex++;                          // иначе увеличиваем хвостовой индекс;
      if (endIndex >= primatumLine.size()) // если хвост. индекс больше или равен длине больш. строки, то...;
      {
        break; //...прерываем внутренний цикл (а находки нет!);
      }
      controlSumFragment += (int)primatumLine[endIndex];   // к хэшу фрагмента добавляем код символа по хвост. индексу;
      controlSumFragment -= (int)primatumLine[startIndex]; // из хэша фрагмента вычитаем код символа по старт. индексу;
      startIndex++;                                        // увелич. старт. индекс;
    };

    if (find) // если есть находка;
    {
      cout << "Podstroka \"" << littleLine << "\" najdena po indeksu " << startIndex << endl;
    }
    else // если нет находки;
    {
      cout << "Podstroka \"" << littleLine << "\" ne najdena." << endl;
    };

    if (littleLine == "exit") // если вторичная строка == exit, то...;
    {
      break; // прерываем цикл;
    };
  };

  return 0;
}