#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int Convertor(double number) {
    return static_cast<int>(number);
}

char* VoidConvertor(void* vdptr) {
    cout << typeid(vdptr).name();
    return static_cast<char*>(vdptr);
}

class Shape {
private:
    string name;
public:
    virtual double Perimeter() = 0;
    virtual ~Shape() {};
};

class Circle : public Shape {
private:
    int r = 2;
    int P;
public:
    double Perimeter() override {
        cout << "Virtual function for circle, perimeter: ";
        P = pow(r, 2) * M_PI;
        return P;
    }
    ~Circle() {};
};

class Vehicle {
public:
    virtual void MakeSound() {
        cout << "Virtual sound" << endl;
    };
};

class Car : public Vehicle {
public:
    void MakeSound() override {
        cout << "Car made a sound" << endl;
    }
};

class Bicycle : public Vehicle {
    void MakeSound() override {
        cout << "Bicycle made a sound" << endl;
    }
};

void GetId(vector<Vehicle*> array) {
    for (Vehicle* n : array) {
        cout << typeid(*n).name() << endl;
    }
}

Car& Cast(Vehicle& vehicle){
    try {
        return dynamic_cast<Car&>(vehicle);
    }
    catch (std::bad_cast bc) {
        cout << bc.what() << endl;
        throw bc;
    }
}

int main() {
    //1;
    cout << Convertor(M_PI) << endl;

    //2
    Shape* shapeptr;
    Circle circle;
    Circle* circleptr = &circle;

    shapeptr = static_cast<Shape*>(&circle);
    cout << shapeptr->Perimeter() << endl;

    circleptr = static_cast<Circle*>(shapeptr);
    cout << circleptr->Perimeter() << endl;

    //3
    void* vdptr = new char();
    cout << VoidConvertor(vdptr) << endl;
    cout << typeid(vdptr).name() << endl;
    delete vdptr;

    //4
    vector<Vehicle*> vehiclearray;
    Car car;
    Bicycle bicycle;
    vehiclearray.push_back(static_cast<Vehicle*>(&car));
    vehiclearray.push_back(static_cast<Vehicle*>(&bicycle));

    GetId(vehiclearray);

    //5
    try {
        Vehicle vehicle;
        Vehicle& vehicle1 = vehicle;
        cout << typeid(vehicle1).name() << endl;
        cout << typeid(Cast(vehicle1)).name() << endl;
    }
    catch (...) {
        cout << "Some unknown exception caught!\n" << endl;
    }
}