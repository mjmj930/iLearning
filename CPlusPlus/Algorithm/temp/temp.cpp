#include <iostream>
using namespace std;

int main() {
    int num;
    do {
        cout << "input less than 10 intger: ";
        cin >> num;
        cout << num <<endl;
    } while (num <= 10);
    cout << "input intger greater than 10, progarm is over" << endl;
    return 0;
}