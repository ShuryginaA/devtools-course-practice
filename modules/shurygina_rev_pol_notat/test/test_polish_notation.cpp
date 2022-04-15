// Copyright 2022 Shurygina A

#include <gtest/gtest.h>
#include <string>
#include "include/polish_notation.h"
#include "include/queue.h"
#include "include/stack.h"

TEST(PolishNotation, Check_Queue1) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    ASSERT_NO_THROW(lex->isEmpty());
    ASSERT_TRUE(lex->isEmpty());
}

TEST(PolishNotation, Check_Queue2) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    ASSERT_NO_THROW(lex->isFull());
    ASSERT_FALSE(lex->isFull());
}

TEST(PolishNotation, Check_If_Numb_True_Throw) {
    PolishNotation l;
    char a = 's';
    ASSERT_ANY_THROW(l.ifNumb(a));
}

TEST(PolishNotation, Check_If_Numb_True_No_Throw) {
    PolishNotation l;
    char a = '5';
    ASSERT_NO_THROW(l.ifNumb(a));
    ASSERT_TRUE(l.ifNumb(a));
}
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

TEST(PolishNotation, Check_Prioriry6) {
    PolishNotation l;
    Lexem lex(" ", op, -1);
    EXPECT_EQ(l.prior(lex), -1);
}

TEST(PolishNotation, Check_Prioriry7) {
    PolishNotation l;
    Lexem lex("5", op, -1);
    EXPECT_EQ(l.prior(lex), 2);
}

TEST(PolishNotation, Check_Prioriry4) {
    PolishNotation l;
    Lexem lex("/", op, -1);
    ASSERT_NO_THROW(l.prior(lex));
}

TEST(PolishNotation, Check_Prioriry5) {
    PolishNotation l;
    Lexem lex("-", op, -1);
    ASSERT_NO_THROW(l.prior(lex));
}

TEST(PolishNotation, test_separat1) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "2+3/(4-1)*2";
    ASSERT_NO_THROW(l1.separat(str2));
}

TEST(PolishNotation, test_separat2) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+7";
    ASSERT_NO_THROW(l1.separat(str2));
}

TEST(PolishNotation, polishNotation0) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "2+3/(4-1)*2";
    lex = l1.separat(str2);
    ASSERT_NO_THROW(l1.revPolNot(lex));
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
TEST(PolishNotation, polishNotation5) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "7+1-3";
    lex = l1.separat(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "71+3-");
}
TEST(PolishNotation, polishNotation6) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+4*2-5*7";
    lex = l1.separat(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "542*+57*-");
}

TEST(PolishNotation, polishNotation7) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+4*2-5*7-(3+6*5)/4";
    lex = l1.separat(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "542*+57*-365*+4/-");
}

