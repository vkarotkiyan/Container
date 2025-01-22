#include "classes.h"
#include <iostream>
#include <exception>
#include <algorithm>
using namespace  std;

MyIntArray::MyIntArray(int length) : _length(length)
{
    if (_length < 0)
    {
        throw MyException("Длина массива не может быть меньше 0! (1)\n");
    }
    _data = new int[length];
    //cout << "Массив создан!" << endl;
}

MyIntArray::~MyIntArray()
{
    delete[] _data;
    //cout << "Массив уничтожен!" << endl;
}

void MyIntArray::erase()
{
    delete[] _data;
    _data = nullptr; // указывает в никуда
    _length = 0;
}

int& MyIntArray::operator[](int index)
{
    if (index < 0 || index >= _length)
    {
        throw Bad_Range(); // Для соответствия заданию
    }
    return _data[index];
}

int MyIntArray::getLength() const
{
    return _length;
}

void MyIntArray::reallocate(int newLength)
{
    erase();
    if (newLength <= 0)
        return;
    _data = new int[newLength];
    _length = newLength;
}

void MyIntArray::resize(int newLength)
{
    if (newLength < 0)
    {
        throw MyException("Длина массива не может быть меньше 0! (2)\n");
    }
    if (newLength == _length)
        return;
    if (newLength <= 0)
    {
        erase();
        return;
    }
    int* data = new int[newLength];
    if (_length > 0)
    {
        int elementsToCopy{ (newLength > _length) ? _length : newLength };
        std::copy_n(_data, elementsToCopy, data); 
    }
    for (int i = _length; i < newLength; i++)
        data[i] = 0;
    delete[] _data;
    _data = data;
    _length = newLength;
}

MyIntArray::MyIntArray(const MyIntArray& a) : MyIntArray(a.getLength()) 
{
    std::copy_n(a._data, _length, _data);
}

MyIntArray& MyIntArray::operator=(const MyIntArray& a)
{
    if (&a == this) // Самопроверка
        return *this;
    reallocate(a.getLength());
    std::copy_n(a._data, _length, _data);
    return *this;
}

void MyIntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > _length)
    {
        throw MyException("Неверный индекс. (2)\n");
    }
    int* data = new int[_length + 1]; 
    std::copy_n(_data, index, data); 
    data[index] = value; 
    std::copy_n(_data + index, _length - index, data + index + 1);
    delete[] _data;
    _data = data;
    ++_length;
}

void MyIntArray::remove(int index)
{
    if (index < 0 || index >= _length)
    {
        throw MyException("Неверный индекс. (3)\n");
    }
    if (_length == 1) 
    {
        erase();
        return;
    }
    int* data = new int[_length - 1]; 
    std::copy_n(_data, index, data); 
    std::copy_n(_data + index + 1, _length - index - 1, data + index); 
    delete[] _data;
    _data = data;
    --_length;
}

void MyIntArray::insertAtBeginning(int value) 
{ 
    insertBefore(value, 0); 
}

void MyIntArray::insertAtEnd(int value) 
{ 
    insertBefore(value, _length); 
}

void MyIntArray::findValue(int value)
{
    for (int i = 0; i < _length; i++)
    {
        if (_data[i] == value)
        {
            cout << "Индекс элемента " << value << ": " << i << endl;
            return;
        }
    }
    cout << "Элемент " << value << " не найден." << endl;
}

MyException::MyException(string message) : _message(message)
{
}

string MyException::getErrorMessage() const
{
    return _message;
}

const char* MyException::what() const noexcept
{
    return "Мое сообщение об ошибке!\n";
}

const char* Bad_Range::what() const noexcept
{
    return "Выход за пределы диапазона!\n";
}

const char* Bad_Length::what() const noexcept
{
    return "Неверная длина массива.\n";
}
