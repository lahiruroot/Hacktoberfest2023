#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int sum = (n * (n + 1)) / 2;

    cout << "Sum of numbers from 1 to " << n << " is: " << sum << endl;

    return 0;
}
