#include <iostream>
#include <limits>
#include <random>

// 1. Ask user for password length
// 2. Generate password
      // - Lower case
      // - Upper case
      // - Numbers
      // - Special characters
// 3. Store password in txt

int randomGen(int minDistrib, int maxDistrib) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minDistrib, maxDistrib); // Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

void clearScreen() {
    system("cls");
}

int main() {

    bool lengthBeingChosen{true};

    int passLength{0};

    // 1. Get user input for length.
    while (lengthBeingChosen) {
        std::cout << "Enter the length of the password you'd like: " << std::endl;
        std::cin >> passLength;
        std::cout << "The password length you've chosen is: " << passLength << std::endl;

        // 1.a - Length value is too big
        if (passLength >= 20) {
            std::cout << "Your password is too lengthy. Choose a shorter one." << std::endl;
        }
        // 1.b - Length value is too short or null
        else if (passLength <= 0) {
            std::cout << "Your password is too short. Choose a lengthier one." << std::endl;
        }
        // 1.c - Length value is correct
        else if (passLength > 0 && passLength <= 20) {
            std::cout << "Password length is OK. Proceeding to generate you a new password." << std::endl;
            lengthBeingChosen = false;
        }
        // 1.d - Length value isn't numeric
        else {
            // FIXME: I forgot how to solve this issue. Input has to be limited to numeric values when taking length.
            clearScreen();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Basically fool-proofs the input when in the menu
            std::cout << "You didn't enter a numeric value. Try again." << std::endl;
        }
    }

    // 2. Generate password.
    for (int i = 0; i < passLength; ++i) {
        char currentCharacter = randomGen(33, 126);
        std::cout << currentCharacter;
    }

    return 0;
}
