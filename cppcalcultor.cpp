#include <iostream>
#include <limits> // For numeric_limits

using namespace std;

int main() {
    // Variables to store user inputs and results
    double num1, num2;
    char operation;
    double result;

    cout << "Welcome to the Basic Calculator!" << endl;
    cout << "Please enter two numbers and choose an operation (+, -, *, /)." << endl;

    // Input first number
    cout << "Enter the first number: ";
    while (!(cin >> num1)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid number: ";
    }

    // Input second number
    cout << "Enter the second number: ";
    while (!(cin >> num2)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid number: ";
    }

    // Input operation
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "The result of " << num1 << " + " << num2 << " is " << result << "." << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "The result of " << num1 << " - " << num2 << " is " << result << "." << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "The result of " << num1 << " * " << num2 << " is " << result << "." << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "The result of " << num1 << " / " << num2 << " is " << result << "." << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            break;
    }

    return 0;
}
