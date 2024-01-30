#include <iostream>
#include "nhlomann/json.hpp"
#include "difficulty.cpp"
#include <fstream>
#include <random>
using namespace std;
using json = nlohmann::json;

int main() {

    ifstream file("words.json");
    
    if (!file.is_open()) {
        cerr << "Error opening the file.\n";
        return 1;
    }

    // Parse the JSON data
    json hangmanData;
    file >> hangmanData;

    // Close the file
    file.close();

    // Display categories
    cout << "Categories:\n \n";

    // Loop through the categories

    for (auto& category : hangmanData.items()) {
        cout << category.key() << endl;
    }

    // Ask the user to select a category
    string category;

    cout << "Select a category:";

    while (true) {
        cin >> category;

        if (hangmanData.find(category) != hangmanData.end()) {
            break;
        }

        cout << "Category not found.\n";
        cout << "Try again.\n";
        cout << "Select a category: \n";
        for (auto& category : hangmanData.items()) {
            cout << category.key() << endl;
        }
        
    }

    // ask the user to select a difficulty
    int difficultyLevel = difficulty();

    // choose a random word from the category using hardware
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, hangmanData[category].size() - 1);
    string word = hangmanData[category][distr(gen)];

    // Display the word as underscores
    string hiddenWord(word.size(), '_');

    cout << hiddenWord << endl;

    // uncomment to see the word
    // cout << word << endl;

    // assign lives based on difficulty
    int lives = 0;

    switch (difficultyLevel) {
        case 1:
            lives = 10;
            break;
        case 2:
            lives = 7;
            break;
        case 3:
            lives = 5;
            break;
    }
    // loop until the user wins or loses
    while (lives >= 0) {
    if (lives == 0) {
        cout << "You lose!\n";
        cout << "The word was: " << word << endl;

        cout << "Play again? (y/n): ";

        char playAgain;

        cin >> playAgain;

        if (playAgain == 'y') {
            main();
        } else if (playAgain == 'n'){
            cout << "Thanks for playing!\n";
        } else {
            cout << "Invalid input.\n";
        }
        break;
    }
    bool found = false;

    cout << "Lives: " << lives << endl;

    if (lives == 1) {
        cout << "Last chance!\n";
    }

    char letter;

    cout << "Guess a letter: ";
    cin >> letter;

    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] == letter) {
            hiddenWord[i] = letter;
            found = true;
        }
    }

    if (!found) {
        cout << "Letter not found.\n";
        lives--;
    }

    cout << hiddenWord << endl;

    if (hiddenWord == word) {
        cout << "You win!\n";
        break;
    }
}
}