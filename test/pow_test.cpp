#include "math.hpp"

#include <limits.h>

#include <gtest/gtest.h>

TEST(powTest, PositiveNumber)
{
    auto res = lit::pow(4, 2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 16);
}

TEST(powTest, NegativeNumber)
{
    auto res = lit::pow(-4, 2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 16);
}

TEST(powTest, NegativePow)
{
    auto res = lit::pow(-4, -2);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kInvalidNumber);
}

TEST(powTest, Zero)
{
    auto res = lit::pow(4, 0);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 1);
}

TEST(powTest, EdgeMax)
{
    auto res = lit::pow(INT_MAX, 1);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MAX);
}

TEST(powTest, EdgeMin)
{
    auto res = lit::pow(INT_MIN, 1);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MIN);
}

TEST(powTest, OverflowMax)
{
    auto res = lit::pow(INT_MAX, 2);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(powTest, OverflowMin)
{
    auto res = lit::pow(INT_MIN, 2);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(powTest, OverflowMaxMax)
{
    auto res = lit::pow(INT_MAX, INT_MAX);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}
