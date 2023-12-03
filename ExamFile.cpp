#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    setlocale(LC_ALL, "UKRAINIAN");

    int n;
    cout << "Введіть кількість тарілок: ";
    cin >> n;

    int* a = new int[n];
    cout << "Введіть кількість горішків в кожній тарілці:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Тарілка " << i + 1 << ": ";
        cin >> a[i];
    }

    int maxElement = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > maxElement) {
            maxElement = a[i];
        }
    }

    int minMinutes = INT_MAX;

    for (int x = 1; x <= maxElement; ++x) {
        int minutes = 0;
        for (int i = 0; i < n; ++i) {
            int needed = a[i] / x;
            if (needed * x < a[i]) {
                needed++;
            }
            minutes += needed;
        }
        minMinutes = min(minMinutes, minutes);
    }

    cout << "Мінімальна кількість хвилин: " << minMinutes << endl;

    delete[] a;

    return 0;
}
