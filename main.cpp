#include "classes.h"
#include <iostream>
#include <windows.h> // Закомментировать для Linux
using namespace  std;

int main(int argc, char* argv[])
{
    //setlocale(LC_ALL, ""); // Закомментировать для Windows
    SetConsoleOutputCP( 65001 ); // Закомментировать для Linux

    try
    {
        // Инициализация объекта array типа MyIntArray
        MyIntArray array(10);
        int arr[10] = { 5,7,12,56,34,9,11,23,17,8 };
        for (int i = 0; i < 10; ++i)
            array[i] = arr[i];

        cout << "Массив array:\n"; 
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        MyIntArray b{ array }; 
        cout << "Массив b инициализируем массивом array: \n";
        for (int i = 0; i < b.getLength(); ++i)
            cout << b[i] << ' ';
        cout << '\n';

        array.resize(12); // Изменение длины
        cout << "Увеличение длины массива array на 2: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        array.resize(8); // Изменение длины
        cout << "Уменьшение длины массива array на 4: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        try
        {
            array.insertBefore(222, 5); // Вставка элемента
        }
        catch (MyException& ex)
        {
            cout << ex.getErrorMessage() << endl;
        }
        try
        {
            array.remove(3); // Удаление элемента
        }
        catch (MyException& ex)
        {
            cout << ex.what() << endl;
        }
        array.insertAtEnd(333); // Вставка в конец
        array.insertAtBeginning(444); // Вставка в начало

        cout << "Массив array после удаления одного и добавления трех элементов: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        try
        {
        cout << "Элемент с индексом 5: " << array[5] << endl; // Доступ к элементу по индексу
        }
        catch (Bad_Range& ex)
        {
            cout << ex.what() << endl;
        }

        b = array; // Копирование
        cout << "Массив b поcле копирования (b = array): \n";
        for (int i = 0; i < b.getLength(); ++i)
            cout << b[i] << ' ';
        cout << '\n';

        b = b;
        array = array;

        array.findValue(9); // Поиск элемента
        array.findValue(107);
    }
    catch (MyException& ex)
    {
        cout << ex.getErrorMessage() << ex.what() << endl;
    }
    system("pause");

    return 0;
}
