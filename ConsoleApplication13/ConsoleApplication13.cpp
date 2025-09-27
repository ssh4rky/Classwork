#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
	string author;
	string title;
public:
	Book(string author, string title) : author(author), title(title) {}
	void Print() const {
		cout << "Author: " << author << endl;
		cout << "Title: " << title << endl;
	}
};

class BookShelf {
private:
	vector<Book> books;
public:
	void AddBook(Book& book) {
		books.push_back(book);
	}
	void PrintBooks() {
		for (auto book : books) {
			book.Print();
		}
	}
};

class Engine {
private:
	bool incar;
	int hp;
public:
	Engine() : incar(true), hp(100) {};
	Engine(bool incar, int hp) : incar(incar), hp(hp) {};

	bool GetEngine() {
		return incar;
	}
};

class Car {
private:
	Engine* engine;
public:
	Car() {
		engine = new Engine(true, 100);
	}
	void Start() {
		if (!engine) {
			cout << "Cannot start without engine" << endl;
		}
		else {
			cout << "Engine Started..." << endl;
		}
	}
};

class Cat {
protected:
	string name;
	string breed;
	int age;
public:
	Cat() : name("Barsyk"), breed("StreetCat"), age(10) {};
	Cat(string name, string breed, int age) : name(name), breed(breed), age(age) {}
	virtual void MakeSound() {
		cout << "Meow" << endl;
	}
	void PrintInfo() {
		cout << "Name: " << name << endl;
		cout << "Breed: " << breed << endl;
		cout << "Age: " << age << endl;
	}
};

class Tiger : public Cat {
public:
	Tiger() {
		name = "Druzhok";
		breed = "Tiger";
		age = 30;
	}
	void MakeSound() override {
		cout << "MEOW" << endl;
	}
};

int main()
{
	Cat cat;
	Tiger tiger;

	cat.PrintInfo();
	cat.MakeSound();
	tiger.PrintInfo();
	tiger.MakeSound();
}
