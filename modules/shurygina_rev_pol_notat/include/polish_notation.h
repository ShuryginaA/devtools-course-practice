// Copyright 2022 Shurygina A

#ifndef  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_POLISH_NOTATION_H_
#define  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_POLISH_NOTATION_H_

#include <string>
#include "include/lexem.h"

class PolishNotation {
 public:
    bool ifNumb(char c);
    int prior(Lexem tmp);
    int res(Lexem orr , Lexem ol, std::string mark);
    TQueue<Lexem*>* separat(std::string _s);
    std::string revPolNot(TQueue<Lexem*>* q);
};
#endif  //  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_POLISH_NOTATION_H_

