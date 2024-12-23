#pragma once
#include <iostream>
#include <string>
#include <exception>

class MyIntArray 
{
public:
    MyIntArray() = default;
    MyIntArray(int); // �������� �������
    ~MyIntArray(); 
    void erase(); // �������� �������
    int& operator[](int); // ������ � ��������
    int getLength() const; // ��������� ����� �������
    void reallocate(int); // ����������� ������� � ��������� ������ ��� ����� ������
    void resize(int); // ��������� ������� �������
    MyIntArray(const MyIntArray&); // �����������
    MyIntArray& operator=(const MyIntArray&); // ���������� =
    void insertBefore(int, int); // ������� �������� �����
    void remove(int); // �������� ��������
    void insertAtBeginning(int); // ������� �������� � ������
    void insertAtEnd(int); // ������� �������� � �����
    void findValue(int); // ����� ��������
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