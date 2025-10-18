#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

class Matrix {
private:
	int width, length;
	vector<vector<int>> matrix;
public:
	Matrix(int a, int b) : length(a), width(b) {
		srand(time(NULL));
		matrix = vector<vector<int>>(length, vector<int>(width));
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				matrix[i][j] = rand() % 10;
			}
		}
	}

	friend ostream& operator<<(ostream& os, const Matrix& m) {
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m.width; j++) {
				os << m.matrix[i][j] << " ";
			}
			os << "\n";
		}
		return os;
	}

	friend istream& operator>>(istream& is, Matrix& m) {
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m.width; j++) {
				is >> m.matrix[i][j];
			}
		}
		return is;
	}

	friend ofstream& operator<<(ofstream& os, const Matrix& m) {
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m.width; j++) {
				os << m.matrix[i][j] << " ";
			}
			os << "\n";
		}
		return os;
	}

	friend ifstream& operator>>(ifstream& is, Matrix& m) {
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m.width; j++) {
				is >> m.matrix[i][j];
			}
		}
		return is;
	}
};


int main() {
	int a, b;
	cout << "Enter length: ";
	cin >> a;
	cout << "Enter width: ";
	cin >> b;

	Matrix m(a, b);
	ofstream fout("test.txt", ios_base::app);
	if (!fout) {
		cerr << "Error: could not open file for writing.\n";
		return 1;
	}
	fout << m;
	fout.close();

	cout << "\nGenerated matrix:\n";
	cout << m;
}