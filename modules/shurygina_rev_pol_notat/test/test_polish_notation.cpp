// Copyright 2022 Shurygina A

#include <gtest/gtest.h>
#include <string>
#include "include/polish_notation.h"
#include "include/queue.h"
#include "include/stack.h"
#include "include/structures.h"

TEST(PolishNotation, Check_Queue1) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    ASSERT_NO_THROW(lex->isEmpty());
    EXPECT_EQ(lex->isEmpty(), true);
}

TEST(PolishNotation, Check_Queue2) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    ASSERT_NO_THROW(lex->isFull());
    EXPECT_EQ(lex->isFull(), false);
}
TEST(Lexem, can_create) {
    ASSERT_NO_THROW(new Lexem("/", op, -1));
    ASSERT_NO_THROW(new Lexem("5", value, 5));
}

TEST(Lexem, can_get_value) {
    Lexem l("/", op, -1);
    ASSERT_NO_THROW(l.getVal());
}

TEST(TQueue, can_assign_queue_to_itself) {
    TStruct<int>* s = new TQueue<int>;
    TStruct<int>* s1(s);
    s = s;
    EXPECT_EQ(s, s1);
}
TEST(TStack, can_create_stack_with_positive_length) {
    ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, can_create_stack_assert) {
    ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_create_stack_assert_push) {
    TStack<int> s(2);
    s.push(1);
    s.push(2);
    ASSERT_ANY_THROW(s.push(2));
}


TEST(TStack, can_create_stack_assert_pop) {
    TStack<int> s(2);
    ASSERT_ANY_THROW(s.pop());
}

TEST(TMatrix, throws_when_create_stack_with_negative_length) {
    ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_create_copied_stack) {
    TStruct<int>* s = new TStack<int>;

    ASSERT_NO_THROW(TStruct<int>*s1(s));
}

TEST(TStack, can_push_and_pop) {
    TStruct<int>* s = new TStack<int>;
    s->push(3);
    int t = s->pop();
    EXPECT_EQ(3, t);
}


TEST(TStack, can_assign_stack_to_itself) {
    TStruct<int>* s = new TStack<int>;
    TStruct<int>* s1(s);
    s = s;
    EXPECT_EQ(s, s1);
}


TEST(TStack, check_void) {
    TStruct<int>* s = new TStack<int>;
    EXPECT_EQ(true, s->isEmpty());
}
TEST(TStack, check_fullness) {
    TStruct<int>* s = new TStack<int>(1);
    s->push(3);
    EXPECT_EQ(true, s->isFull());
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

TEST(Lexem, Check_Lex) {
    Lexem lex1("(", op, -1);
    Lexem lex2("(", op, -1);
    EXPECT_EQ(lex1, lex2);
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

TEST(PolishNotation, polishNotation1) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "2+3/(4-1)*2";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "2341-/2*+");
}

TEST(PolishNotation, polishNotation2) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5-3/(4+1)*2";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "5341+/2*-");
}

TEST(PolishNotation, polishNotation3) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+4*3";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "543*+");
}

TEST(PolishNotation, polishNotation4) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "6-1+3";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "61-3+");
}
TEST(PolishNotation, polishNotation5) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "7+1-3";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "71+3-");
}
TEST(PolishNotation, polishNotation6) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+4*2-5*7";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "542*+57*-");
}

TEST(PolishNotation, polishNotation7) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "5+4*2-5*7-(3+6*5)/4";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "542*+57*-365*+4/-");
}

TEST(PolishNotation, polishNotation8) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "54+4*2-5*71-(3+6*5)/4";
    lex = l1.separatExpressionOnLexems(str2);
    result = l1.revPolNot(lex);
    EXPECT_EQ(result, "5442*+571*-365*+4/-");
}

TEST(PolishNotation, polishNotation0) {
    PolishNotation l1;
    TQueue<Lexem*>* lex = new TQueue<Lexem*>;
    std::string result;
    std::string str2 = "2+3/(4-1)*2";
    lex = l1.separatExpressionOnLexems(str2);
    ASSERT_NO_THROW(l1.revPolNot(lex));
}
