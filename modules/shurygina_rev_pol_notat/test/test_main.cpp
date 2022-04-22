// Copyright 2022 Shurygina A

#include <gtest/gtest.h>
#include "include/stack.h"


TEST(TQueue, can_pop) {
    TQueue<int> q(10);
    q.push(6);
    EXPECT_EQ(q.pop(), 6);
}

TEST(TQueue, can_create_queue_with_positive_length) {
    ASSERT_NO_THROW(TQueue<int> s(5));
}


TEST(TQueue, throws_when_create_queue_with_negative_length) {
    ASSERT_ANY_THROW(TQueue<int> s(-5));
}

TEST(TQueue, can_create_copied_queue) {
    TQueue<int>* s = new TQueue<int>;

    ASSERT_NO_THROW(TQueue<int>*s1(s));
}

TEST(TQueue, can_push_and_pop) {
    TQueue<int>* s = new TQueue<int>;
    s->push(3);
    int t = s->pop();
    EXPECT_EQ(3, t);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
