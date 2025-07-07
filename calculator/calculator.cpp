#include "calculator.hpp"

double Calculator::solve(std::string& inp) {
    int n = inp.size();
    for (int i = 0; i < n; i++) {
        char& dig = inp[i];
        if (dig == ' ') continue;
        if (dig == ')') {
            if (operations.size() < 2) {
                std::cout << "paren invalid\n";
                throw std::exception();
            }
            operations.pop();
            double curr = values.top();
            values.pop();
            values.top() = values.top() + (operations.top() == '+' ? 1 : -1) * curr;
        }
        else if (dig == '(') {
            operations.push('+');
            values.push(0LL);
        }
        else if (dig == '-' || dig == '+') {
            if (operations.empty()) throw std::exception();
            operations.top() = dig;
        }
        else { // just a number
            int start = i;
            bool dec = false;
            while (isdigit(inp[i]) || inp[i] == '.') {
                if (inp[i] == '.') {
                    if (dec) {
                        std::cout << "double decimal\n";
                        throw std::exception();
                    }
                    else dec = true;
                }
                i++;
            }
            std::string number = inp.substr(start, i - start);
            values.top() = values.top() + (operations.top() == '+' ? 1LL : -1LL) * std::stod(number);
            i--;
        }
    }

    if (operations.size() > 1) {
        throw std::exception();
    }

    return values.top();
}

void Calculator::reset() {
    while (!operations.empty()) operations.pop();
    while (!values.empty()) values.pop();
    operations.push('+');
    values.push(0);
}
