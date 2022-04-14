// Copyright 2022 Shurygina A

#include <gtest/gtest.h>
#include <string>
#include "include/polish_notation.h"

TEST(PolishNotation, Check_If_Numb_True) {
    PolishNotation l;
    char a = '5';
    EXPECT_EQ(l.ifNumb(a), true);
}

TEST(PolishNotation, Check_If_Numb_False) {
    PolishNotation l;
    char a = '*';
    EXPECT_EQ(l.ifNumb(a), false);
}

TEST(PolishNotation, Check_Prioriry1) {
    PolishNotation l;
    Lexem lex("(", op, -1);
    EXPECT_EQ(l.prior(lex), 0);
}

TEST(PolishNotation, Check_Prioriry2) {
    PolishNotation l;
    Lexem lex("*", op, -1);
    EXPECT_EQ(l.prior(lex), 1);
}

TEST(PolishNotation, Check_Prioriry3) {
    PolishNotation l;
    Lexem lex("+", op, -1);
    EXPECT_EQ(l.prior(lex), 2);
}

TEST(PolishNotation, polishNotation1) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "2+3/(4-1)*2";
    lex = l1.separat(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "2341-/2*+");
}

TEST(PolishNotation, polishNotation2) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5-3/(4+1)*2";
    lex = l1.separat(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "5341+/2*-");
}

TEST(PolishNotation, polishNotation3) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+4*3";
    lex = l1.separat(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "543*+");
}

TEST(PolishNotation, polishNotation4) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "6-1+3";
    lex = l1.separat(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "61-3+");
}
