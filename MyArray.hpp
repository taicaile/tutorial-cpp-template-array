#pragma once

#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyArray
{

public:
    MyArray(int capacity)
    {
        cout << "MyArray 构造函数调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        cout << "MyArray 拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        // 深拷贝
        this->pAddress = new T[arr.m_Capacity];
        // 将 array 中的数据都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝问题
    MyArray &operator=(const MyArray &arr)
    {
        cout << "MyArray operator= 调用" << endl;
        // 先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    // 尾插法
    void Push_Back(T val)
    {
        if(this->m_Capacity==this->m_Size)
        {
            return;
        }

        this->pAddress[this->m_Size] = val;
        this->m_Size ++;
    }

    // 尾删法
    void Pop_Back()
    {
        if(this->m_Size==0)
        {
            return;
        }
        this->m_Size--;
    }

    // 通过下标方式访问数组中的元素
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

    // 析构函数
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            cout << "MyArray 析构函数调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    int m_Size;
    int m_Capacity;
    // 指针指向堆区开辟的真实数组
    T *pAddress;
};
