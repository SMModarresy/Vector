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

TEST(VectorTest, SelfAssignAssertions) {
    Vector<int> v(2, 2);

    v.push_back(3);

    v = v;

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
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

TEST(VectorTest, AssignCellAssertions) {
    Vector<int> v(2, 2);

    v[1] = 3;

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v[1], 3);
}

TEST(VectorTest, OutOfRangeAssertions) {
    Vector<int> v1, v2, v3(2, 2), v4, v5(2);

    v1.push_back(1);
    v1.push_back(1);

    v2.push_back(1);
    v2.push_back(1);
    v2.pop_back();

    v3.pop_back();

    EXPECT_NO_THROW(v1[1]);
    EXPECT_NO_THROW(v2[0]);
    EXPECT_THROW(v2[1], out_of_range);
    EXPECT_NO_THROW(v3[0]);
    EXPECT_THROW(v3[1], out_of_range);
    EXPECT_THROW(v4[0], out_of_range);
    EXPECT_NO_THROW(v5[1]);
    EXPECT_THROW(v5[2], out_of_range);
}