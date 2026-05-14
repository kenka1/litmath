#include "math.hpp"

#include <limits.h>

#include <gtest/gtest.h>

TEST(divideTest, PositiveNumbers)
{
    auto res = lit::divide(4, 2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 2);
}

TEST(divideTest, NegativeNumbers)
{
    auto res = lit::divide(-4, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 2);
}

TEST(divideTest, DifferentSign)
{
    auto res = lit::divide(4, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, -2);
}

TEST(divideTest, ByZero)
{
    auto res = lit::divide(1, 0);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kDivisionByZero);
}

TEST(divideTest, FloorRemainder)
{
    auto res = lit::divide(3, 2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 1);
}

TEST(divideTest, EdgeMax)
{
    auto res = lit::divide(INT_MAX, 1);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MAX);
}

TEST(divideTest, EdgeMin)
{
    auto res = lit::divide(INT_MIN, 1);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MIN);
}

TEST(divideTest, OverflowMax)
{
    auto res = lit::divide(INT_MIN, -1);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}
