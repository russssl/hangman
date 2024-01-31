#include <iostream>

using namespace std;
int difficulty() {
    int difficulty;
    // Ask the user to select a difficulty 
    // 100 is a joke obviously huh
    cout << "Select a difficulty (1-5 or 100 (impossible)): ";

    // validate the difficulty input
    while (true) {
        cin >> difficulty;

        if (difficulty >= 1 && difficulty <= 5 || difficulty == 100) {
            break;
        }

        cout << "Invalid difficulty.\n";
        cout << "Try again.\n";
        cout << "Select a difficulty (1-5): ";
    }
  return difficulty;
}