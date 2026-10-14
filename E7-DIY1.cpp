#include <iostream>
using namespace std;

class Money {
private:
    int rupees;
    int paise;

    void normalize() {
        rupees += paise / 100;
        paise %= 100;

        if (paise < 0) {
            rupees--;
            paise += 100;
        }
    }

public:
    Money(int r = 0, int p = 0) {
        rupees = r;
        paise = p;
        normalize();
    }

    Money operator+(const Money& m) const {
        return Money(rupees + m.rupees, paise + m.paise);
    }

    Money operator-(const Money& m) const {
        return Money(rupees - m.rupees, paise - m.paise);
    }

    void display() const {
        cout << rupees << " rupees and " << paise << " paise" << endl;
    }
};

int main() {
    Money m1(10, 80);
    Money m2(5, 50);

    Money sum = m1 + m2;
    Money difference = m1 - m2;

    cout << "First amount: ";
    m1.display();

    cout << "Second amount: ";
    m2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    return 0;
}