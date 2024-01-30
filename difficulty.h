#include <iostream>

using namespace std;
int difficulty() {
    int difficulty;

    cout << "Select a difficulty (1-3): ";

    while (true) {
        cin >> difficulty;

        if (difficulty >= 1 && difficulty <= 3) {
            break;
        }

        cout << "Invalid difficulty.\n";
        cout << "Try again.\n";
        cout << "Select a difficulty (1-3): ";
    }
  return difficulty;
}