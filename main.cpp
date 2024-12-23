#include "classes.h"
#include <iostream>
using namespace  std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    try
    {
        // ������������� ������� array ���� MyIntArray
        MyIntArray array(10);
        int arr[10] = { 5,7,12,56,34,9,11,23,17,8 };
        for (int i = 0; i < 10; ++i)
            array[i] = arr[i];

        cout << "������ array:\n"; 
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        MyIntArray b{ array }; 
        cout << "������ b �������������� �������� array: \n";
        for (int i = 0; i < b.getLength(); ++i)
            cout << b[i] << ' ';
        cout << '\n';

        array.resize(12); // ��������� �����
        cout << "���������� ����� ������� array �� 2: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        array.resize(8); // ��������� �����
        cout << "���������� ����� ������� array �� 4: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        try
        {
            array.insertBefore(222, 5); // ������� ��������
        }
        catch (MyException& ex)
        {
            cout << ex.getErrorMessage() << endl;
        }
        try
        {
            array.remove(3); // �������� ��������
        }
        catch (MyException& ex)
        {
            cout << ex.what() << endl;
        }
        array.insertAtEnd(333); // ������� � �����
        array.insertAtBeginning(444); // ������� � ������

        cout << "������ array ����� �������� ������ � ���������� ���� ���������: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        try
        {
        cout << "������� � �������� 5: " << array[5] << endl; // ������ � �������� �� �������
        }
        catch (Bad_Range& ex)
        {
            cout << ex.what() << endl;
        }

        b = array; // �����������
        cout << "������ b ��c�� ����������� (b = array): \n";
        for (int i = 0; i < b.getLength(); ++i)
            cout << b[i] << ' ';
        cout << '\n';

        b = b;
        array = array;

        array.findValue(9); // ����� ��������
        array.findValue(107);
    }
    catch (MyException& ex)
    {
        cout << ex.getErrorMessage() << ex.what() << endl;
    }

    return 0;
}
