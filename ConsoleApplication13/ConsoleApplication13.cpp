#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Aggregation
class Case {
private:
	string material;
	bool onphone;
public:
	Case() : material("Plastic"), onphone(false) {};
	Case(string m) : material(m), onphone(true) {};
	bool GetCase() {
		return onphone;
	}
};

class Phone {
private:
	Case* phonecase;
	string brand;
	string model;
public:
	Phone() : brand("Samsung"), model("S25") {
		phonecase = new Case("Metal");
	}
	void PrintInfo() {
		cout << "Brand: " << brand << endl;
		cout << "Model: " << model << endl;
		cout << "Case is on? " << (phonecase->GetCase() ? "Yes" : "No") << endl;
	}
};

//Composition
class VideoCard {
private:
    string brand;
    string model;
    double performance_quality;
    bool inpc;
public:
    VideoCard() : brand("Nvidia"), model("RTX5090"), performance_quality(100.0), inpc(true) {}
    VideoCard(string b, string m, double pq) : brand(b), model(m), performance_quality(pq), inpc(true) {}

    bool GetPCStatus() const {
        return inpc;
    }

    double GetPerformance() const {
        return performance_quality;
    }

    void GetInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Performance quality: " << performance_quality << endl;
        cout << "In PC? " << (inpc ? "Yes" : "No") << endl;
    }
};

class Processor {
private:
    string brand;
    string model;
    double performance_quality;
    bool inpc;
public:
    Processor() : brand("Intel"), model("Core i9"), performance_quality(90.0), inpc(true) {}
    Processor(string b, string m, double pq) : brand(b), model(m), performance_quality(pq), inpc(true) {}

    bool GetPCStatus() const {
        return inpc;
    }

    double GetPerformance() const {
        return performance_quality;
    }

    void GetInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Performance quality: " << performance_quality << endl;
        cout << "In PC? " << (inpc ? "Yes" : "No") << endl;
    }
};

class PC {
private:
    VideoCard videocard;
    Processor processor;
    double sum_performance;
public:
    PC() : videocard(), processor() {
        sum_performance = (videocard.GetPerformance() + processor.GetPerformance()) / 2;
    }

    PC(VideoCard vc, Processor pr) : videocard(vc), processor(pr) {
        sum_performance = (videocard.GetPerformance() + processor.GetPerformance()) / 2;
    }

    bool GetOverallPCStatus() const {
        return videocard.GetPCStatus() && processor.GetPCStatus();
    }

    void GetPCInfo() const {
        if (GetOverallPCStatus()) {
            videocard.GetInfo();
            processor.GetInfo();
            cout << "Performance Statistics: " << sum_performance << endl;
        }
        else {
            cout << "Something went missing" << endl;
        }
    }
};

//Inheritance
class Dog {
protected:
	string name;
	string breed;
	int age;
public:
	Dog() : name("Barsyk"), breed("StreetCat"), age(10) {};
	Dog(string name, string breed, int age) : name(name), breed(breed), age(age) {}
	virtual void MakeSound() {
		cout << "Meow" << endl;
	}
	void PrintInfo() {
		cout << "Name: " << name << endl;
		cout << "Breed: " << breed << endl;
		cout << "Age: " << age << endl;
	}
};

class Wolf : public Dog {
public:
	Wolf() {
		name = "Druzhok";
		breed = "Wolf";
		age = 30;
	}
	void MakeSound() override {
		cout << "MEOW" << endl;
	}
};

int main()
{
	// Aggregation
	Phone myPhone;
	myPhone.PrintInfo();
	cout << endl;

	// Composition
	PC myPC;
	myPC.GetPCInfo();
	cout << endl;

	// Inheritance
	Dog myDog("Rex", "German Shepherd", 5);
	myDog.PrintInfo();
	myDog.MakeSound();
	cout << endl;

	Wolf myWolf;
	myWolf.PrintInfo();
	myWolf.MakeSound();
	cout << endl;
}
