#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string binary;
    cout << "Введите число из нулей и единиц: ";
    cin >> binary;

    for (char c : binary) {
        if (c != '0' && c != '1') {
            cout << "Это не двоичное число!" << endl;
            return 1;
        }
    }

    int decimal = 0;
    int step = 1;

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += step;
        }
        step *= 2;
    }

    cout << "В обычных числах это: " << decimal << endl;

    double root = sqrt(decimal);
    cout << "Квадратный корень: " << root << endl;

    int root_int = (int)root;
    string binary_root;

    if (root_int == 0) {
        binary_root = "0";
    } else {
        while (root_int > 0) {
            if (root_int % 2 == 0) {
                binary_root = "0" + binary_root;
            } else {
                binary_root = "1" + binary_root;
            }
            root_int = root_int / 2;
        }
    }

    cout << "Целая часть корня в двоичном виде: " << binary_root << endl;

    return 0;
}