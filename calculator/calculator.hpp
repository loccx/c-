#define bug(x) std::cout << #x << ": " << x << '\n';

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
#include <exception>

/*
can calculate with paren
+ - / * ()
error handling for divide by 0
*/
class Calculator {
public:
    Calculator() {
        operations.push('+');
        values.push(0LL);
    }

    double solve(std::string& inp);
    void reset();

private:
    std::stack<char> operations;
    std::stack<double> values;
};
