#include "math.hpp"

#include <limits.h>

#include <gtest/gtest.h>

TEST(subtractTest, PositiveNumbers)
{
    auto res = lit::subtract(1, 2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, -1);
}

TEST(subtractTest, NegativeNumbers)
{
    auto res = lit::subtract(-1, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 1);
}

TEST(subtractTest, DifferentSign)
{
    auto res = lit::subtract(1, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 3);
}

TEST(subtractTest, EdgeMax)
{
    auto res = lit::subtract(INT_MAX, 0);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MAX);
}

TEST(subtractTest, EdgeMin)
{
    auto res = lit::subtract(INT_MIN, 0);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MIN);
}

TEST(subtractTest, OverflowMax)
{
    auto res = lit::subtract(INT_MAX, -1);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(subtractTest, OverflowMin)
{
    auto res = lit::subtract(INT_MIN, 1);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(subtractTest, OverflowMaxMin)
{
    auto res = lit::subtract(INT_MAX, INT_MIN);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(subtractTest, OverflowMinMax)
{
    auto res = lit::subtract(INT_MIN, INT_MAX);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}
