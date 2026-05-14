#include "math.hpp"

#include <limits.h>

#include <gtest/gtest.h>

TEST(multiplyTest, PositiveNumbers)
{
    auto res = lit::multiply(1, 2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 2);
}

TEST(multiplyTest, NegativeNumbers)
{
    auto res = lit::multiply(-1, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 2);
}

TEST(multiplyTest, DifferentSign)
{
    auto res = lit::multiply(1, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, -2);
}

TEST(multiplyTest, ByZero)
{
    auto res = lit::multiply(1, 0);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 0);
}

TEST(multiplyTest, EdgeMax)
{
    auto res = lit::multiply(INT_MAX, 1);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MAX);
}

TEST(multiplyTest, EdgeMin)
{
    auto res = lit::multiply(INT_MIN, 1);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MIN);
}

TEST(multiplyTest, OverflowMax)
{
    auto res = lit::multiply(INT_MAX, 2);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(multiplyTest, OverflowMin)
{
    auto res = lit::multiply(INT_MIN, 2);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(multiplyTest, OverflowMaxMin)
{
    auto res = lit::multiply(INT_MAX, INT_MIN);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(multiplyTest, OverflowMinMax)
{
    auto res = lit::multiply(INT_MIN, INT_MAX);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}
