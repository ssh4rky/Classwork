#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {

};

int main()
{
    int a[4] = { 10, 15, 4, 5 };

    // ptr[0] + ( index * size1 )
    // 0x00f + ( 2 * 4 )

    cout << "Enter elements count: ";
    int size;
    cin >> size;
    char* str = new char[size];
    for (int i = 0; i < size - 1; i++) {
        str[i] = 'N';
    }
    str[size - 1] = '\0';
    cout << str << endl;
    char* temp = new char[size + 1];
    for (int i = 0; i < size - 1; i++) {
        str[i] = 'N';
    }
    temp[size - 1] = 'n';
    temp[size] = '\0';
    delete[] str;
    str = temp;
    temp = nullptr;

    delete[] str;
}
