#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <limits>  

int main() {
    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and 100.\n";
    std::cout << "Can you guess it?\n";

    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        attempts++;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue; 
        }

        if (userGuess > randomNumber) {
            std::cout << "Too high! Try a smaller number.\n";
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try a larger number.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number!\n";
            std::cout << "It took you " << attempts << " attempts to win.\n";
        }
    }

    return 0;
}
