#include <iostream>
using namespace std;
#include "MyArray.hpp"

void test01()
{
    MyArray<int> arr1(20);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 = arr1;
}

void printIntArray(MyArray <int>& arr)
{
    for(int i=0; i< arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test02()
{
    MyArray<int> arr1(5);
    for (int i=0; i<5 ;i++)
    {
        arr1.Push_Back(i);
    }
    printIntArray(arr1);
    arr1.Pop_Back();
    printIntArray(arr1);

}

int main(int argc, char const *argv[])
{
    test01();
    test02();

    return 0;
}
