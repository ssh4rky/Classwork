#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

int main() {
	unique_ptr<int> up1(new int(10));
	cout << "Adress: " << up1.get() << endl;
	cout << "Value: " << *up1 << endl;
}