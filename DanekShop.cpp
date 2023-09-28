#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>>
#include <cmath>
#include <conio.h>
#include <windows.h>
using namespace std;

void BasicDataOutput(int Case, int Videocard, int OZU, int Processor, int Screen, int Mice, int Keyboards, string massage, string unit)
{
    cout << "\n" <<  massage << "\n" << "\n";
    cout << "\t" << "Компьютерные корпуса: " << Case << unit << "\n";
    cout << "\t" << "Видеокарты: " << Videocard << unit << "\n";
    cout << "\t" << "Оперативная память: " << OZU << unit << "\n";
    cout << "\t" << "Процессоры: " << Processor << unit << "\n";
    cout << "\t" << "Мониторы: " << Screen << unit << "\n";
    cout << "\t" << "Компьютерные мышки: " << Mice << unit << "\n";
    cout << "\t" << "Клавиатуры: " << Keyboards << unit << "\n";
}

int SelectMethod(string firstMassage, string secondMassage, string ask)
{
    int counter = 1, chosen_option = counter;
    vector<string> options;

    options.push_back(firstMassage);
    options.push_back(secondMassage);

    while (chosen_option != 2)
    {
        system("cls"); 
        cout << "\t" << ask << "\n";
        for (size_t i = 0; i < options.size(); ++i)
        {
            if ((i + 1) == counter) cout << "> " << options[i] << endl;
            else cout << options[i] << endl;
        }

        char pressed = _getch();

        if (pressed == 'w' && counter != 1)
            counter--;
        if (pressed == 's' && counter != options.size())
            counter++;

        if (pressed == '\r' || pressed == '\n') {
            chosen_option = counter;
            system("cls");

            switch (chosen_option)
            {
            case 1: return 1; break;
            case 2: return 2; break;
            }

            _getch();
        }
    }
    _getch();
}

void AddData(int& addItem, double checkItem, string massage)
{
    bool isNumber;
    do {
        system("cls");
        cout << "\n" << "\t" << massage;
        cin >> addItem;
        isNumber = true;
        if (cin.fail()) { // проверяем, была ли ошибка при вводе
            isNumber = false;
            cin.clear(); // сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // очищаем буфер ввода
        }
    } while (!isNumber || (addItem > checkItem || addItem < 0));
}

double CalculateDataForAnalysis(int Do, double nds, int Case, int Videocard, int OZU, int Processor, int Screen, int Mice, int Keyboards, double storeMargin) {

    double _computerСasePrice = 0;
    double _videocardPrice = 0;
    double _OZUPrice = 0;
    double _processorPrice = 0;
    double _screenPrice = 0;
    double _micePrice = 0;
    double _keyboardsPrice = 0;

    getPrice(_computerСasePrice, _videocardPrice, _OZUPrice, _processorPrice, _screenPrice, _micePrice, _keyboardsPrice);

    double _revenue = 0;
    double _finalPrice = 0;
    int CaseCount,VideocardCount,OZUCount,ProcessorCount,ScreenCount,MiceCount,KeyboardsCount;
    switch (Do)
    {
    case 1: 
         _revenue = (Case * _computerСasePrice * storeMargin) +
            (Videocard * _videocardPrice * storeMargin) +
            (OZU * _OZUPrice * storeMargin) +
            (Processor * _processorPrice * storeMargin) +
            (Screen * _screenPrice * storeMargin) +
            (Mice * _micePrice * storeMargin) +
            (Keyboards * _keyboardsPrice * storeMargin);

        BasicDataOutput(Case,
            Videocard,
            OZU,
            Processor,
            Screen,
            Mice,
            Keyboards,
            "Необходимое колличество комплектующих для закупки в этом месяце: ",
            "шт.");

         _finalPrice = (Case * _computerСasePrice * nds) +
            (Videocard * _videocardPrice * nds) +
            (OZU * _OZUPrice * nds) +
            (Processor * _processorPrice * nds) +
            (Screen * _screenPrice * nds) +
            (Mice * _micePrice * nds) +
            (Keyboards * _keyboardsPrice * nds);

        assert(_finalPrice > 0);

        cout << "\n" << "\t" << "Общая цена закупки на этот месяц: " << _finalPrice << " руб.";

        return _finalPrice;
         break;

    case 2: 
        AddData(CaseCount, Case, "Колличество проданых корпусов в этом месяце: ");
        AddData(VideocardCount, Videocard, "Колличество проданых видеокарт в этом месяце: ");
        AddData(OZUCount, OZU, "Колличество проданых плашек оперативной памяти в этом месяце: ");
        AddData(ProcessorCount, Processor, "Колличество проданых процессоров в этом месяце: ");
        AddData(ScreenCount, Screen, "Колличество проданых мониторов в этом месяце: ");
        AddData(MiceCount, Mice, "Колличество проданых мышек в этом месяце: ");
        AddData(KeyboardsCount, Keyboards, "Колличество проданых клавиатур в этом месяце: ");

        system("cls");

        _finalPrice = (CaseCount * _computerСasePrice * nds) +
            (VideocardCount * _videocardPrice * nds) +
            (OZUCount * _OZUPrice * nds) +
            (ProcessorCount * _processorPrice * nds) +
            (ScreenCount * _screenPrice * nds) +
            (MiceCount * _micePrice * nds) +
            (KeyboardsCount * _keyboardsPrice * nds);

        assert(_finalPrice > 0);

        BasicDataOutput(CaseCount,
            VideocardCount,
            OZUCount,
            ProcessorCount,
            ScreenCount,
            MiceCount,
            KeyboardsCount,
            "Необходимое колличество комплектующих для закупки: ",
            "шт.");

            cout << "\n";

            CaseCount = Case - CaseCount;
            VideocardCount = Videocard - VideocardCount;
            OZUCount = OZU - OZUCount;
            ProcessorCount = Processor - ProcessorCount;
            ScreenCount = Screen - ScreenCount;
            MiceCount = Mice - MiceCount;
            KeyboardsCount = Keyboards - KeyboardsCount;

            BasicDataOutput(CaseCount,
                VideocardCount,
                OZUCount,
                ProcessorCount,
                ScreenCount,
                MiceCount,
                KeyboardsCount,
                "Колличество комплектующих оставшееся на складе: ",
                "шт.");

            cout << "\n" << "\t" << "Общая цена закупки на этот месяц: " << _finalPrice << " руб.";

        return _finalPrice;
        break;
    }
}
void getPrice(double& CasePrice, double& VideocardPrice, double& OZUPrice, double& ProcessorPrice, double& ScreenPrice, double& MicePrice, double& KeyboardsPrice)
{
    do
    {
        system("cls");
        cout << "\n" << "\t" << "Введите цену за 1 корпус: ";
        cin >> CasePrice;
    } while (CasePrice > 1000000 || CasePrice < 0);
    do
    {
        system("cls");
        cout << "\n" << "\t" << "Введите цену за 1 видеокарту: ";
        cin >> VideocardPrice;
    } while (VideocardPrice > 1000000 || VideocardPrice < 0);
    do
    {
        system("cls");
        cout << "\n" << "\t" << "Введите цену за 1 плашку оперативной памяти: ";
        cin >> OZUPrice;
    } while (OZUPrice > 1000000 || OZUPrice < 0);
    do
    {
        system("cls");
        cout << "\n" << "\t" << "Введите цену за 1 процессор: ";
        cin >> ProcessorPrice;
    } while (ProcessorPrice > 1000000 || ProcessorPrice < 0);
    do
    {
        system("cls");
        cout << "\n" << "\t" << "Введите цену за 1 монитор: ";
        cin >> ScreenPrice;
    } while (ScreenPrice > 1000000 || ScreenPrice < 0);
    do
    {
        system("cls");
        cout << "\n" << "\t" << "Введите цену за 1 компьютерную мышку: ";
        cin >> MicePrice;
    } while (MicePrice > 1000000 || MicePrice < 0);
    do
    {
        system("cls");
        cout << "\n" << "\t" << "Введите цену за 1 клавиатуру: ";
        cin >> KeyboardsPrice;
    } while (KeyboardsPrice > 1000000 || KeyboardsPrice < 0);
    system("cls");
}

 void getData( int& Case,  int& Videocard,  int& OZU, int& Processor, int& Screen, int& Mice, int& Keyboards, double& storeMargin)
{
    cout << "\n" << "\n"  << "\t" << "ВВОД ДАННЫХ О ЗАКУПКАХ " << "\n";

    AddData(Case, 10000, "Колличество закупленых корпусов в прошлом месяце: ");
    AddData(Videocard, 10000, "Колличество закупленых видеокарт в прошлом месяце: ");
    AddData(OZU, 10000, "Колличество закупленых плашек оперативной памяти в прошлом месяце: ");
    AddData(Processor, 10000, "Колличество закупленых процессоров в прошлом месяце: ");
    AddData(Screen, 10000, "Колличество закупленых мониторов в прошлом месяце: ");
    AddData(Mice, 10000, "Колличество закупленых мышек в прошлом месяце: ");
    AddData(Keyboards, 10000, "Колличество закупленых клавиатур в прошлом месяце: ");
}


 double CalculateProfit(int Do, double nds, int Case, int Videocard, int OZU, int Processor, int Screen, int Mice, int Keyboards, double storeMargin) {

     double _computerСasePrice = 0;
     double _videocardPrice = 0;
     double _OZUPrice = 0;
     double _processorPrice = 0;
     double _screenPrice = 0;
     double _micePrice = 0;
     double _keyboardsPrice = 0;

     getPrice(_computerСasePrice, _videocardPrice, _OZUPrice, _processorPrice, _screenPrice, _micePrice, _keyboardsPrice);

     double _revenue = 0;
     double _finalPrice = 0;
     int CaseCount, VideocardCount, OZUCount, ProcessorCount, ScreenCount, MiceCount, KeyboardsCount;
     double _profit = 0;
     double _tax = 0;
     switch (Do)
     {
     case 1:
         _finalPrice = (Case * _computerСasePrice * nds) +
             (Videocard * _videocardPrice * nds) +
             (OZU * _OZUPrice * nds) +
             (Processor * _processorPrice * nds) +
             (Screen * _screenPrice * nds) +
             (Mice * _micePrice * nds) +
             (Keyboards * _keyboardsPrice * nds);

         assert(_finalPrice > 0);

         cout << "\n" << "\t" << "Общая цена закупки за прошлый месяц: " << _finalPrice << " руб.";

         _tax = _finalPrice - ((Case * _computerСasePrice) +
             (Videocard * _videocardPrice) +
             (OZU * _OZUPrice) +
             (Processor * _processorPrice) +
             (Screen * _screenPrice) +
             (Mice * _micePrice) +
             (Keyboards * _keyboardsPrice));

         cout << "\n" << "\t" << "Общий налоговый вычет: " << _tax << " руб.";

         _revenue = (Case * _computerСasePrice * storeMargin) +
             (Videocard * _videocardPrice * storeMargin) +
             (OZU * _OZUPrice * storeMargin) +
             (Processor * _processorPrice * storeMargin) +
             (Screen * _screenPrice * storeMargin) +
             (Mice * _micePrice * storeMargin) +
             (Keyboards * _keyboardsPrice * storeMargin);

          cout << "\n" << "\t" << "Общая выручка магазина за прошлый месяц: " << _revenue << " руб.";
        
          _profit = _revenue - _finalPrice;

          if (_profit > 0)
          {
              cout << "\n" << "\t" << "Чистая прибыль магазина за прошлый месяц: " << _profit << " руб.";
          }
          else if(_profit == 0)
          {
              cout << "\n" << "\t" << "В данном месяце магазин отработал в 0" << " руб. прибыли и убытка";
          }
          else if (_profit < 0)
          {
              cout << "\n" << "\t" << "Убыток магазина за прошлый месяц: " <<  abs(_profit) << " руб.";
          }
          break;

     case 2:
         AddData(CaseCount,Case, "Колличество проданых корпусов: ");
         AddData(VideocardCount, Videocard, "Колличество проданых видеокарт: ");
         AddData(OZUCount, OZU, "Колличество проданых плашек оперативной памяти: ");
         AddData(ProcessorCount, Processor, "Колличество проданых процессоров: ");
         AddData(ScreenCount, Screen, "Колличество проданых мониторов: ");
         AddData(MiceCount, Mice, "Колличество проданых мышек: ");
         AddData(KeyboardsCount, Keyboards, "Колличество проданых клавиатур: ");

         system("cls");

         _finalPrice = (CaseCount * _computerСasePrice * nds) +
             (VideocardCount * _videocardPrice * nds) +
             (OZUCount * _OZUPrice * nds) +
             (ProcessorCount * _processorPrice * nds) +
             (ScreenCount * _screenPrice * nds) +
             (MiceCount * _micePrice * nds) +
             (KeyboardsCount * _keyboardsPrice * nds);

         assert(_finalPrice > 0);

         cout << "\n" << "\t" << "Общая цена закупки за прошлый месяц: " << _finalPrice << " руб.";

         _tax = _finalPrice - ((CaseCount * _computerСasePrice) +
             (VideocardCount * _videocardPrice) +
             (OZUCount * _OZUPrice) +
             (ProcessorCount * _processorPrice) +
             (ScreenCount * _screenPrice) +
             (MiceCount * _micePrice) +
             (KeyboardsCount * _keyboardsPrice));

         cout << "\n" << "\t" << "Общий налоговый вычет: " << _tax << " руб.";

         _revenue = (CaseCount * _computerСasePrice * storeMargin) +
             (VideocardCount * _videocardPrice * storeMargin) +
             (OZUCount * _OZUPrice * storeMargin) +
             (ProcessorCount * _processorPrice * storeMargin) +
             (ScreenCount * _screenPrice * storeMargin) +
             (MiceCount * _micePrice * storeMargin) +
             (KeyboardsCount * _keyboardsPrice * storeMargin);

        cout << "\n" << "\t" << "Общая выручка магазина за прошлый месяц: " << _revenue << " руб.";

        _profit = _revenue - _finalPrice;

        if (_profit > 0)
        {
            cout << "\n" << "\t" << "Чистая прибыль магазина за прошлый месяц: " << _profit << " руб.";
        }
        else if (_profit == 0)
        {
            cout << "\n" << "\t" << "В данном месяце магазин отработал в 0" << " руб. прибыли и убытка";
        }
        else if (_profit < 0)
        {
            cout << "\n" << "\t" << "Убыток магазина за прошлый месяц: " << abs(_profit) << " руб.";
        }
         break;
     }
     return _profit;
 }
 
int main()
{
    setlocale(0, "");

    int _requiredСomputerСaseCount = 30;
    int _requiredVideocardCount = 20;
    int _requiredOZUCount = 20;
    int _requiredProcessorCount = 20;
    int _requiredScreenCount = 20;
    int _requiredMiceCount = 20;
    int _requiredKeyboardsCount = 20;
    const double _NDS = 1.13;
    double _storeMargin = 2;
    int _do;
    double _finalPrice;


    getData(_requiredСomputerСaseCount,
        _requiredVideocardCount,
        _requiredOZUCount,
        _requiredProcessorCount,
        _requiredScreenCount,
        _requiredMiceCount,
        _requiredKeyboardsCount, 
        _storeMargin);

    _do = SelectMethod("Расчет общей стоимости закупки с учетом данных о продажах в прошлом месяце", "Расчет чистой прибыли за прошлый месяц", "Выберите цель расчетов");

    switch (_do)
    {
    case 1:

        BasicDataOutput(_requiredСomputerСaseCount,
            _requiredVideocardCount,
            _requiredOZUCount,
            _requiredProcessorCount,
            _requiredScreenCount,
            _requiredMiceCount,
            _requiredKeyboardsCount,
            "Закупленое в прошлом месяце колличество комплектующих: ",
            "шт.");

        Sleep(3000);

        _do = SelectMethod("Да", "Нет", "Всели комплектующие были проданы за этот месяц?");

         _finalPrice = CalculateDataForAnalysis(
            _do,
            _NDS,
            _requiredСomputerСaseCount,
            _requiredVideocardCount,
            _requiredOZUCount,
            _requiredProcessorCount,
            _requiredScreenCount,
            _requiredMiceCount,
            _requiredKeyboardsCount,
            _storeMargin);

        break;
    case 2:
        BasicDataOutput(_requiredСomputerСaseCount,
            _requiredVideocardCount,
            _requiredOZUCount,
            _requiredProcessorCount,
            _requiredScreenCount,
            _requiredMiceCount,
            _requiredKeyboardsCount,
            "Закупленое в прошлом месяце колличество комплектующих: ",
            "шт.");

        Sleep(3000);

        _do = SelectMethod("Да", "Нет", "Всели комплектующие были проданы за этот месяц?");

        _finalPrice = CalculateProfit(
            _do,
            _NDS,
            _requiredСomputerСaseCount,
            _requiredVideocardCount,
            _requiredOZUCount,
            _requiredProcessorCount,
            _requiredScreenCount,
            _requiredMiceCount,
            _requiredKeyboardsCount,
            _storeMargin);
        
        break;

    }
    return 0;
}
