#include <iostream>

namespace Calculator {
    double number1, number2;
    char operation;
}

namespace Option {
    char option;
}

double lastResult = 0.0;
bool stop = false;

int sum(double number1, double number2) {
    return number1 + number2;
}

int minus(double number1, double number2) {
    return number1 - number2;
}

int divisor(double number1, double number2) {
    return number1 / number2;
}

int repeat(double number1, double number2) {
    return number1 * number2;
}

int exec_calculator() {
    using namespace Calculator;
    double value = 0.0;

    switch (operation) {
        case '+':
            value = sum(number1, number2);
            break;

        case '-':
            value = minus(number1, number2);
            break;

        case '/':
            value = divisor(number1, number2);
            break;
            
        case '*':
            value = repeat(number1, number2);
            break;
    }

    return value;
}

int load_calculator() {
    using namespace Calculator;

    std::cout << "Type number 1: " << '\n';
    std::cin >> number1;

    std::cout << "Type operator: " << '\n';
    std::cin >> operation;

    std::cout << "Type number 2: " << '\n';
    std::cin >> number2;

    return exec_calculator();
}

int load_option() {
    using namespace Option;
    std::cout << "What do you want to make? n = historic, c = calculator s = close" << '\n';
    std::cin >> option;
    double value = 0.0;

    switch (option) {
        case 'n':
            std::cout << "Historic: " << lastResult << '\n';
            break;
        
        case 'c':
            std::cout << "Calculator..." << '\n';
            value = load_calculator();
            break;

        case 's':
            std::cout << "Stopping..." << '\n';
            stop = true;
            break;
    }

    return value;
}

int main() {
    double value = load_option();
    lastResult = value;
    std::cout << "Result: " << value << '\n';

    if (!stop) {
        main();
    } else {
        return 0;
    }
}