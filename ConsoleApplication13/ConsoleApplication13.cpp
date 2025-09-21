#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
    T* data;
    int capacity;
    int size;
    int front;
    int last;

    void reasize(int newCapacity) {
        T* temp = new T[newCapacity];
        for (int i = 0; i < capacity; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
public:
    Queue(int initCapacity = 10) :
        capacity(initCapacity), size(0), front(0), last(-1) {
    }
    ~Queue() {
        delete[] data;
    }

};

int main()
{

}
