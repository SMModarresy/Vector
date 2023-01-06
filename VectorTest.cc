//
// Created by XamarinDev on 12/31/2022.
//

#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorTest, DefaultConstructionAssertions) {
    Vector<int> v;

    EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, SizeConstructionAssertion) {
    Vector<int> v(120);

    EXPECT_EQ(v.size(), 120);
}

TEST(VectorTest, SizeDefaultConstructionAssertion) {
    Vector<int> v(3, 12);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 12);
    EXPECT_EQ(v[1], 12);
    EXPECT_EQ(v[2], 12);
}

TEST(VectorTest, PushAssertion) {
    Vector<int> v;

    v.push_back(12);

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 12);
}

TEST(VectorTest, MultiPushAssertion) {
    Vector<int> v;

    v.push_back(12);
    v.push_back(5);
    v.push_back(140);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 12);
    EXPECT_EQ(v[1], 5);
    EXPECT_EQ(v[2], 140);
}

TEST(VectorTest, PopAssertions) {
    Vector<int> v(120);

    v.pop_back();

    EXPECT_EQ(v.size(), 119);
}

TEST(VectorTest, FullPopAssertions) {
    Vector<int> v(120);

    for (int i = 0; i < 120; i++) {
        v.pop_back();
    }

    EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, OverPopAssertions) {
    Vector<int> v(120);

    for (int i = 0; i < 120; i++) {
        v.pop_back();
    }

    EXPECT_NO_THROW(v.pop_back());
}

TEST(VectorTest, PushAfterOverPopAssertions) {
    Vector<int> v(120);

    for (int i = 0; i < 150; i++) {
        v.pop_back();
    }

    v.push_back(3);

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 3);
}

TEST(VectorTest, CopyAssertions) {
    Vector<int> v1(2, 2);

    v1.push_back(3);

    Vector<int> v2(v1);

    EXPECT_EQ(v2.size(), 3);
    EXPECT_EQ(v2[0], 2);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, CopyNoRefAssertions) {
    Vector<int> v1(2, 2);
    Vector<int> v2(v1);

    v2.push_back(3);

    EXPECT_EQ(v1.size(), 2);
    EXPECT_EQ(v2.size(), 3);
    EXPECT_EQ(v2[0], 2);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, MoveAssertions) {
    Vector<int> v1(3, 2);

    Vector<int> v2 = move(v1);

    EXPECT_EQ(v2.size(), 3);
    EXPECT_EQ(v2[0], 2);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 2);
    EXPECT_EQ(v1.size(), 0);
}

TEST(VectorTest, AssignAssertions) {
    Vector<int> v1(2, 2), v2;

    v1.push_back(3);

    v2 = v1;

    EXPECT_EQ(v2.size(), 3);
    EXPECT_EQ(v2[0], 2);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, AssignNoRefAssertions) {
    Vector<int> v1(2, 2), v2;

    v2 = v1;
    v2.push_back(3);

    EXPECT_EQ(v1.size(), 2);
    EXPECT_EQ(v2.size(), 3);
    EXPECT_EQ(v2[0], 2);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
}