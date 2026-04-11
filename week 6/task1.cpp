#include <iostream>
#include <stack>
using namespace std;

// Reverse String
void reverseString() {
    string str = "Hello";
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
        s.push(str[i]);

    cout << "Reversed: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

// Balanced Parentheses
void checkBalanced() {
    string exp = "((a+b)*c)";
    stack<char> s;
    bool balanced = true;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(')
            s.push('(');
        else if (exp[i] == ')') {
            if (s.empty()) {
                balanced = false;
                break;
            }
            s.pop();
        }
    }

    if (!s.empty()) balanced = false;

    if (balanced)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}

// Infix to Postfix
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix() {
    string infix = "(a+b)*c";
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch))
            postfix += ch;

        else if (ch == '(')
            s.push(ch);

        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }

        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix: " << postfix << endl;
}

int main() {
    reverseString();
    checkBalanced();
    infixToPostfix();
}
