#include "math.hpp"

#include <limits.h>

#include <gtest/gtest.h>

TEST(addTest, PositiveNumbers)
{
    auto res = lit::add(1, 2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 3);
}

TEST(addTest, NegativeNumbers)
{
    auto res = lit::add(-1, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, -3);
}

TEST(addTest, DifferentSign)
{
    auto res = lit::add(1, -2);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, -1);
}

TEST(addTest, EdgeMax)
{
    auto res = lit::add(INT_MAX, 0);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MAX);
}

TEST(addTest, EdgeMin)
{
    auto res = lit::add(INT_MIN, 0);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, INT_MIN);
}

TEST(addTest, OverflowMax)
{
    auto res = lit::add(INT_MAX, 1);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(addTest, OverflowMin)
{
    auto res = lit::add(INT_MIN, -1);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(addTest, OverflowMaxMax)
{
    auto res = lit::add(INT_MAX, INT_MAX);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(addTest, OverflowMinMin)
{
    auto res = lit::add(INT_MIN, INT_MIN);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}
