#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
private:
    int* arr;
    int size;

public:
    SafeArray(int s) {
        if (s <= 0) {
            throw invalid_argument("Size must be positive");
        }

        size = s;
        arr = new int[size]();
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range");
        }

        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }

    SafeArray(const SafeArray&) = delete;
    SafeArray& operator=(const SafeArray&) = delete;
};

int main() {
    try {
        SafeArray a(5);

        for (int i = 0; i < 5; i++) {
            a[i] = (i + 1) * 10;
        }

        cout << "Array elements: ";

        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }

        cout << "\nAccessing invalid index:\n";
        cout << a[10] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}