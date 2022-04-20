// Copyright 2022 Shurygina A

#include <string>
#include <stack>

#include "include/polish_notation.h"
#include "include/lexem.h"
#include "include/stack.h"
#include "include/queue.h"


// check wheather a charackter is number or not

bool PolishNotation::ifNumber(char c) {
    if ((c >= '0') && (c <= '9'))
        return true;
    if ((c != '+') && (c != '-') && (c != '(')
        && (c != ')') && (c != ' ') && (c != '*') && (c != '/'))
        throw std::string("Can't divide by zero");
    return false;
}

// find out the priority of operations

int PolishNotation::priority(Lexem tmp) {
    if (tmp.getS() == " ")
        return -1;
    if (tmp.getS() == "(" || tmp.getS() == ")")
        return 0;
    if (tmp.getS() == "*" || tmp.getS() == "/")
        return 1;
    else
        return 2;
}

// convert mat expresion into lexems array

TQueue<Lexem*>* PolishNotation::separatExpressionOnLexems(std::string _s) {
    std::string str;
    char c;
    TQueue<Lexem*>* q = new TQueue<Lexem*>;
    State st = q0;
    for (size_t i = 0; i < _s.length(); i++) {
        c = _s[i];
        if (st == q0) {
            str = c;
            if (ifNumber(c))
                st = q1;

            if (!ifNumber(c))
                q->push(new Lexem(str, op, -1));
        } else {
            if (st == q1) {
                if (ifNumber(c))
                    str += c;
                if (!ifNumber(c)) {
                    int val_ = atoi(str.c_str());
                    q->push(new Lexem(str, value, val_));
                    st = q0;
                    str = c;
                    q->push(new Lexem(str, op, -1));
                }
            }
        }
    }
    if (ifNumber(c)) {
        str = c;
        int val_ = atoi(str.c_str());
        q->push(new Lexem(str, value, val_));
    }

    return q;
}
