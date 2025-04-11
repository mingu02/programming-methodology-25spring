#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    if((a > 0 && b > 0 && a + b < 0) || (a < 0 && b < 0 && a + b > 0))
    {
        throw std::overflow_error("Overflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if((a > 0 && b < 0 && a - b < 0) || (a < 0 && b > 0 && a - b > 0))
    {
        throw std::overflow_error("Overflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if((a > 0 && b > 0 && a * b < 0) || (a < 0 && b < 0 && a * b < 0) || (a < 0 && b > 0 && a * b > 0) || (a > 0 && b < 0 && a * b > 0))
    {
        throw std::overflow_error("Overflow");
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    if(b == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}