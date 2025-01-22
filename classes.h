#pragma once
#include <iostream>
#include <string>
#include <exception>

class MyIntArray 
{
public:
    MyIntArray() = default;
    MyIntArray(int); // Создание массива
    ~MyIntArray(); 
    void erase(); // Удаление массива
    int& operator[](int); // Доступ к элементу
    int getLength() const; // Получение длины массива
    void reallocate(int); // Уничтожение массива и выделение памяти под новый размер
    void resize(int); // Изменение размера массива
    MyIntArray(const MyIntArray&); // Копирование
    MyIntArray& operator=(const MyIntArray&); // Перегрузка =
    void insertBefore(int, int); // Вставка элемента перед
    void remove(int); // Удаление элемента
    void insertAtBeginning(int); // Вставка элемента в начало
    void insertAtEnd(int); // Вставка элемента в конец
    void findValue(int); // Поиск элемента
private:
    int _length;
    int* _data;
};

class MyException : public std::exception
{
public:
    MyException(std::string);
    std::string getErrorMessage() const;
    virtual const char* what() const noexcept override;
private:
    std::string _message;
};

class Bad_Range : public std::exception
{
public:
    virtual const char* what() const noexcept override;
};

class Bad_Length : public std::exception
{
public:
    virtual const char* what() const noexcept override;
};
