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
    std::uniform_int_distribution<> distrib(minDistrib, maxDistrib);// Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

int main() {
    bool onTitleScreen{true};

    bool lengthBeingChosen{true};

    int passLength{0};

    //User can only continue if they enter 'x' or 'X' as input. Transits to the main menu after.
    while (onTitleScreen == true) {
        std::string toContinue;

        std::cout << "You are only allowed to generate a password with the length of 0-20." << std::endl;
        std::cout << "If you'd like to know how you can increase the range of values for the password generator. I urge you to find the hidden easter egg." << std::endl;
        std::cout << "With love (and greed ;] ). Your favourite programmer." << std::endl;
        std::cout << "Oh and your clue is 01000101." << std::endl;
        std::cout << "< Enter 'x' to continue >" << std::endl;
        std::cin >> toContinue;

        if (toContinue == "x" || toContinue == "X") {
            onTitleScreen = false;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Basically fool-proofs the input when in the menu
        }
    }

    // 1. Get user input for length.
    while (lengthBeingChosen) {
        std::cout << "Enter the length of the password you'd like: " << std::endl;
        std::cin >> passLength;
        std::cout << std::endl;

        // 1.a - Length value is too big
        if (passLength >= 21) {
            std::cout << "Your password is too lengthy. Choose a shorter one." << std::endl;
            // Because I can.
            if (passLength == 69) {
                std::cout << std::endl;
                std::cout << "CONGRATULATIONS!!!" << std::endl;
                std::cout << "You have found the not-so-hidden easter egg!" << std::endl;
                std::cout << "There are two ways you can increase the password length." << std::endl;
                std::cout << "You can go to the < Store Page > and buy the DLC for 54.99$ (This price was hand-picked by me btw.)" << std::endl;
                std::cout << "Or you could also support me via PayPal and I will personally alter the range of values." << std::endl;
                std::cout << "Probaly." << std::endl;
                std::cout << "I mean.." << std::endl;
                std::cout << "I dont know..." << std::endl;
                std::cout << "Okay...." << std::endl;
                std::cout << "Bye." << std::endl;
                std::cout << std::endl;
            }
        }
        // 1.b - Length value is too short or null
        else if (passLength <= 0) {
            std::cout << "Your password is too short. Choose a lengthier one." << std::endl;
        }
        // 1.c - Length value is correct
        else if (passLength > 0 && passLength <= 20) {
            std::cout << "Password length is OK." << std::endl;
            std::cout << "Proceeding to generate you a new password:" << std::endl;
            lengthBeingChosen = false;
        }
        // 1.d - Length value isn't numeric
        else {
            // FIXME: I forgot how to solve this issue. Input has to be limited to numeric values when taking length.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Basically fool-proofs the input when in the menu
            std::cout << "You didn't enter a numeric value. Try again." << std::endl;
        }
    }

    // 2. Generate password.
    for (int i = 0; i < passLength; ++i) {
        // '!' is the same as 33, but it eliminates the "casting" issue we would face if the distribution numbers were of type int
        char currentChar = char(randomGen('!', '~'));
        std::cout << currentChar;
    }
    std::cout << std::endl;

    return 0;
}
