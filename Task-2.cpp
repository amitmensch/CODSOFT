#include <iostream>
#include <limits> 
int main() {
    double num1, num2;
    char operation;
    bool continueCalculation = true;
    char choice;

    std::cout << "Welcome to the Simple Calculator!\n";

    while (continueCalculation) {
        std::cout << "\nEnter the first number: ";
        if (!(std::cin >> num1)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> operation;

        std::cout << "Enter the second number: ";
        if (!(std::cin >> num2)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (operation) {
            case '+':
                std::cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
                break;
            case '-':
                std::cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
                break;
            case '*':
                std::cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
                break;
            case '/':
                if (num2 == 0) {
                    std::cout << "Error! Division by zero is not allowed.\n";
                } else {
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
                }
                break;
            default:
                std::cout << "Invalid operator. Please use one of the following: +, -, *, /.\n";
                break;
        }

        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            continueCalculation = false;
        }
    }

    std::cout << "Thank you for using the calculator!\n";

    return 0;
}
