#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n = "") : name(n) {}
    virtual void Show() const = 0;
    virtual void SaveToFile(ofstream& fout) const = 0;
    virtual void LoadFromFile(ifstream& fin) = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s = 0) : Shape("Square"), side(s) {}

    void Show() const override {
        cout << name << " — side: " << side
            << ", S: " << side * side << endl;
    }

    void SaveToFile(ofstream& fout) const override {
        fout << name << " " << side << endl;
    }

    void LoadFromFile(ifstream& fin) override {
        fin >> side;
    }
};

class Rectangle : public Shape {
private:
    double a, b;
public:
    Rectangle(double a = 0, double b = 0) : Shape("Rectangle"), a(a), b(b) {}

    void Show() const override {
        cout << name << " — Sides: " << a << " and " << b
            << ", S: " << a * b << endl;
    }

    void SaveToFile(ofstream& fout) const override {
        fout << name << " " << a << " " << b << endl;
    }

    void LoadFromFile(ifstream& fin) override {
        fin >> a >> b;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r = 0) : Shape("Circle"), radius(r) {}

    void Show() const override {
        cout << name << " — Radius: " << radius
            << ", S: " << 3.14159 * radius * radius << endl;
    }

    void SaveToFile(ofstream& fout) const override {
        fout << name << " " << radius << endl;
    }

    void LoadFromFile(ifstream& fin) override {
        fin >> radius;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Square(4));
    shapes.push_back(new Rectangle(3, 5));
    shapes.push_back(new Circle(2));

    ofstream fout("shapes.txt");
    if (!fout) {
        cerr << "Error: cannot open file;" << endl;
        return 1;
    }
    for (auto s : shapes)
        s->SaveToFile(fout);
    fout.close();

    ifstream fin("shapes.txt");
    if (!fin) {
        cerr << "Error: cannot open file;" << endl;
        return 1;
    }

    vector<Shape*> loaded;
    string type;
    while (fin >> type) {
        Shape* s = nullptr;
        if (type == "Square") s = new Square();
        else if (type == "Rectangle") s = new Rectangle();
        else if (type == "Circle") s = new Circle();

        if (s) {
            s->LoadFromFile(fin);
            loaded.push_back(s);
        }
    }
    fin.close();

    cout << "Downloaded figures:\n";
    for (auto s : loaded)
        s->Show();

    for (auto s : shapes) delete s;
    for (auto s : loaded) delete s;

    return 0;
}
