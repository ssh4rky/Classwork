#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

int main() {
	/*unique_ptr<int> up1(new int(10)), up2(new int(15)), up3(new int(20));
	cout << "Adress 1: " << up1.get() << endl;
	cout << "Adress 2: " << up2.get() << endl;
	cout << "Adress 3: " << up3.get() << endl;
	cout << "Value 1: " << *up1 << endl;
	cout << "Value 2: " << *up2 << endl;
	cout << "Value 3: " << *up3 << endl;
	up3.release();
	up3 = make_unique<int>(111);
	up1.swap(up2);
	cout << "Adress 1: " << up1.get() << endl;
	cout << "Adress 2: " << up2.get() << endl;
	cout << "Adress 2: " << up3.get() << endl;
	cout << "Value 1: " << *up1 << endl;
	cout << "Value 2: " << *up2 << endl;
	cout << "Value 2: " << *up3 << endl;
	cout << "(up1 <=> up2) == 0 : " << ((up1 <=> up2) == 0) << '\n';*/

	/*shared_ptr<double> p1(new double(45.1));*/
	/*shared_ptr<int> p2 = p1;
	shared_ptr<int> p3 = p2;
	cout << "Adress 1: " << p1.get() << endl;
	cout << "Adress 2: " << p2.get() << endl;
	cout << "Adress 3: " << p3.get() << endl;
	cout << "Value 1: " << *p1 << endl;
	cout << "Value 2: " << *p2 << endl;
	cout << "Value 3: " << *p3 << endl;*/

	/*weak_ptr<double> wp1 = p1;
	if (shared_ptr<double> locked = wp1.lock()) {
		cout << *locked << endl;
		cout << locked.use_count() << endl;
	}
	else {
		cout << "The object have already been deleted" << endl;
	}*/

	
}