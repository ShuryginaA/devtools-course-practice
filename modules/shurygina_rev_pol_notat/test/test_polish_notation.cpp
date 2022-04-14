// Copyright 2022 Shurygina A

#include <gtest/gtest.h>
#include <string>
#include "include/polish_notation.h"
#include "include/queue.h"


TEST(TQueue, can_create_queue_with_positive_length) {
    ASSERT_NO_THROW(TQueue<int> s(5));
}


TEST(TQueue, throws_when_create_queue_with_negative_length) {
    ASSERT_ANY_THROW(TQueue<int> s(-5));
}

TEST(TQueue, can_create_copied_queue) {
    TStruct<int>* s = new TQueue<int>;

    ASSERT_NO_THROW(TStruct<int>*s1(s));
}

TEST(TQueue, can_push_and_pop) {
    TStruct<int>* s = new TQueue<int>;
    s->push(3);
    int t = s->pop();
    EXPECT_EQ(3, t);
}


TEST(TQueue, can_assign_queue_to_itself) {
    TStruct<int>* s = new TQueue<int>;
    TStruct<int>* s1(s);
    s = s;
    EXPECT_EQ(s, s1);
}


TEST(TQueue, check_void) {
    TStruct<int>* s = new TQueue<int>;
    EXPECT_EQ(true, s->isEmpty());
}
TEST(TQueue, check_fullness) {
    TStruct<int>* s = new TQueue<int>(2);
    s->push(3);
    EXPECT_EQ(true, s->isFull());
}

TEST(Lexem, can_create) {
    ASSERT_NO_THROW(Lexem l("2", value, 2));
}

TEST(Lexem, can_get_type) {
    Lexem l("2", value, 2);
    EXPECT_EQ(l.getType(), value);
}

TEST(Lexem, can_get_val) {
    Lexem l("2", value, 2);
    EXPECT_EQ(l.getVal(), 2);
}

TEST(Lexem, can_get_s) {
    Lexem l("2", value, 2);
    EXPECT_EQ(l.getS(), "2");
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
