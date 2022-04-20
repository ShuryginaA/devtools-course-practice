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
    ASSERT_ANY_THROW(l.ifNumber(a));
}

TEST(PolishNotation, Check_If_Numb_True_No_Throw) {
    PolishNotation l;
    char a = '5';
    ASSERT_NO_THROW(l.ifNumber(a));
    ASSERT_TRUE(l.ifNumber(a));
}
TEST(PolishNotation, Check_If_Numb_True) {
    PolishNotation l;
    char a = '5';
    EXPECT_EQ(l.ifNumber(a), true);
}

TEST(PolishNotation, Check_If_Numb_False) {
    PolishNotation l;
    char a = '*';
    EXPECT_EQ(l.ifNumber(a), false);
}

TEST(PolishNotation, Check_If_Numb_False1) {
    PolishNotation l;
    char a = '/';
    EXPECT_EQ(l.ifNumber(a), false);
}


TEST(PolishNotation, Check_Prioriry1) {
    PolishNotation l;
    Lexem lex("(", op, -1);
    EXPECT_EQ(l.priority(lex), 0);
}
TEST(PolishNotation, Check_Prioriry0) {
    PolishNotation l;
    Lexem lex(")", op, -1);
    EXPECT_EQ(l.priority(lex), 0);
}

TEST(PolishNotation, Check_Prioriry2) {
    PolishNotation l;
    Lexem lex("*", op, -1);
    EXPECT_EQ(l.priority(lex), 1);
}

TEST(PolishNotation, Check_Prioriry22) {
    PolishNotation l;
    Lexem lex("/", op, -1);
    EXPECT_EQ(l.priority(lex), 1);
}

TEST(PolishNotation, Check_Prioriry3) {
    PolishNotation l;
    Lexem lex("+", op, -1);
    EXPECT_EQ(l.priority(lex), 2);
}

TEST(PolishNotation, Check_Prioriry6) {
    PolishNotation l;
    Lexem lex(" ", op, -1);
    EXPECT_EQ(l.priority(lex), -1);
}

TEST(PolishNotation, Check_Prioriry7) {
    PolishNotation l;
    Lexem lex("5", op, -1);
    EXPECT_EQ(l.priority(lex), 2);
}

TEST(PolishNotation, Check_Prioriry4) {
    PolishNotation l;
    Lexem lex("/", op, -1);
    ASSERT_NO_THROW(l.priority(lex));
}

TEST(PolishNotation, Check_Prioriry5) {
    PolishNotation l;
    Lexem lex("-", op, -1);
    ASSERT_NO_THROW(l.priority(lex));
}

TEST(PolishNotation, test_separat1) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "2+3/(4-1)*2";
    ASSERT_NO_THROW(l1.separatExpressionOnLexems(str2));
}

TEST(PolishNotation, test_separat2) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+7";
    ASSERT_NO_THROW(l1.separatExpressionOnLexems(str2));
}

