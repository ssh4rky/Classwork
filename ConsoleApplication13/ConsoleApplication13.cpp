#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Vector {
private:
    T* _arr;
    int _size;
public:
    Vector() : Vector(nullptr, 0) {}
    Vector(const T* arr, int size) {
        if (arr == nullptr || size == 0) {
            _arr = nullptr;
            _size = 0;
            return;
        }

        _arr = new T[size];
        _size = size;
        for (int i = 0; i < size; i++) {
            _arr[i] = arr[i];
        }
    }
    Vector(const Vector& other) : Vector(other._arr, other._size) {}

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        if (this->_arr) {
            delete[] this->_arr;
        }

        if (other._arr == nullptr || other._size == 0) {
            this->_arr = nullptr;
            this->_size = 0;
            return *this;
        }

        this->_arr = new T[other._size];
        this->_size = other._size;
        for (int i = 0; i < this->_size; i++) {
            this->_arr[i] = other._arr[i];
        }
        return *this;
    }
    Vector& operator=(Vector&& other) noexcept {
        if (this->_arr) {
            delete[] this->_arr;
        }
        
        this->_arr = other._arr;
        this > _size = other._size;
        
        other._arr = nullptr;
        return *this;
    }
    

    Vector(Vector&& other) noexcept {
        this->_arr = other._arr;
        this->_size = other._size;
        
        other._arr = nullptr;
    }

    void PushBack(T value) {
        if (_arr) {
            T* temp_arr = new T[++_size];
            for (int i = 0; i < _size - 1; i++) {
                temp_arr[i] = _arr[i];
            }
            temp_arr[_size - 1] = value;
            delete[] _arr;
            _arr = temp_arr;
        }
        else {
            _arr = new T[1];
            _arr[0] = value;
            _size = 1;
        }
    }
    void Print() const {
        if (_size == 0) {
            cout << "Vector is empty";
        }
        else {
            for (int i = 0; i < _size; i++) {
                cout << _arr[i] << " ";
            }
        }
    }
    void RemoveByIndex(int index) {
        if (!_arr) {
            cerr << "Array is empty." << endl;
            return;
        }

        if (index > _size || index < 0) {
            cerr << "Index out of bounds" << endl;
            return;
        }

        T* tempPtr = new T[--_size];
        for (int i = 0; i < index; i++) {
            tempPtr[i] = _arr[i];
        }
        for (int i = index + 1; i < _size + 1; i++) {
            tempPtr[i - 1] = _arr[i];
        }
        delete[] _arr;
        _arr = tempPtr;
    }

    /*T& operator[](int index) {
        if (index < 0 || index > size) {
            throw out_of_range("Index is out of bounds");
        }

        return _arr[index];
    }
    T operator[](int index) const {
        if (index < 0 || index > size) {
            throw out_of_range("Index is out of bounds");
        }

        return _arr[index];
    }*/

    int GetSize() {
        return _size;
    }

    ~Vector() {
        if (_arr) {
            delete[] _arr;
        }
    }
};

Vector<int> CreateVector() {
    return Vector<int>();
}

/// <summary>
/// Клас-функтор для возведення в степінь
/// </summary>
class Power {
private:
    int exponent; // Степінь
public:

    Power(int exp) : exponent(exp) {}
    /// <summary>
    /// Перевантажений оператор виклику функції.
    /// </summary>
    /// <param name="base">Base of the power</param>
    /// <returns>Base in exponent</returns>
    double operator()(double base) {
        return pow(base, exponent);
    }
};

int main()
{
    int arr[] = { 1, 4, 8 };

    Vector<bool> VectorBool;

    Vector<int> vector(arr, 3);
    vector.Print();
    vector.PushBack(8);
    cout << endl;

    vector.RemoveByIndex(1);
    vector.Print();
    cout << endl;

    Vector<int> vector1;
    vector1.Print();
    cout << endl;

    Vector<int> vector2 = CreateVector();
    vector2.Print();
    cout << endl;

    vector1 = vector;
    vector.Print();
    cout << endl;

    Vector<int> vector3(vector1);
    vector3.Print();
    cout << endl;

    Power cube(3);
    cout << cube(3) << endl;
}
