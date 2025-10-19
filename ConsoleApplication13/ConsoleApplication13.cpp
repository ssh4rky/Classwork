#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <memory>
#include <cstdlib>

using namespace std;

struct Time {
    int hours, minutes;
};

ostream& operator<<(ostream& os, const Time& time) {
    os << (time.hours < 10 ? "0" : "") << time.hours << ":"
        << (time.minutes < 10 ? "0" : "") << time.minutes;
    return os;
}

istream& operator>>(istream& is, Time& time) {
    char ch;
    is >> time.hours >> ch >> time.minutes;
    return is;
}

Time GenerateTime() {
    Time time;
    time.hours = rand() % 24;
    time.minutes = rand() % 60;
    return time;
}

class Train {
private:
    static int globalNumber;
    int number;
    string arrivalStation;
    Time time;
public:
    Train() : number(++globalNumber), arrivalStation("Station"), time(GenerateTime()) {}

    void SetTrainInfo() {
        cout << "Enter time (HH:MM): ";
        cin >> time;
        cout << "Enter arrival station: ";
        cin >> arrivalStation;
    }

    void GetTrainInfo() const {
        cout << "Train number: " << number
            << ", Time: " << time
            << ", Station: " << arrivalStation << endl;
    }

    const string& GetStation() const { return arrivalStation; }
    int GetNumber() const { return number; }
};

int Train::globalNumber = 0;

class Station {
private:
    string name;
    vector<Train> trains;
public:
    Station() : name("Universitatea") {}

    void AddTrain() {
        Train t;
        t.SetTrainInfo();
        trains.push_back(t);
    }

    void ShowAllTrains() const {
        if (trains.empty()) {
            cout << "No trains available.\n";
            return;
        }
        for (const auto& t : trains) {
            t.GetTrainInfo();
        }
    }

    void ShowTrainByNumber(int num) const {
        for (const auto& t : trains) {
            if (t.GetNumber() == num) {
                t.GetTrainInfo();
                return;
            }
        }
        cout << "Train with number " << num << " not found.\n";
    }

    void ShowTrainsByStation(const string& stationName) const {
        bool found = false;
        for (const auto& t : trains) {
            if (t.GetStation() == stationName) {
                t.GetTrainInfo();
                found = true;
            }
        }
        if (!found)
            cout << "No trains to " << stationName << " found.\n";
    }
};

int main() {
    srand(time(NULL));
    Station st;

    int choice;
    do {
        cout << "\n1) Add train\n2) Show all trains\n3) Show train by number\n4) Show trains by station\n0) Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1: st.AddTrain(); break;
        case 2: st.ShowAllTrains(); break;
        case 3: {
            int num;
            cout << "Enter train number: ";
            cin >> num;
            st.ShowTrainByNumber(num);
            break;
        }
        case 4: {
            string station;
            cout << "Enter station name: ";
            cin >> station;
            st.ShowTrainsByStation(station);
            break;
        }
        case 0: break;
        default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
