#include "math.hpp"

#include <limits.h>

#include <gtest/gtest.h>

TEST(factorialTest, PositiveNumber)
{
    const int arr[] = {1,         1,          2,          6,      24,
                       120,       720,        5'040,      40'320, 362'880,
                       3'628'800, 39'916'800, 479'001'600};
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        auto res = lit::factorial(static_cast<int>(i));
        ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
        EXPECT_EQ(res.value_, arr[i]);
    }
}

TEST(factorialTest, NegativeNumber)
{
    auto res = lit::factorial(-10);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kInvalidNumber);
}

TEST(factorialTest, Zero)
{
    auto res = lit::factorial(0);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 1);
}

TEST(factorialTest, EdgeMax)
{
    auto res = lit::factorial(lit::kMaxIntFactorial);
    ASSERT_EQ(res.error_, lit::ErrorStatus::kOk);
    EXPECT_EQ(res.value_, 479'001'600);
}

TEST(factorialTest, Overflow)
{
    auto res = lit::factorial(lit::kMaxIntFactorial + 1);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}

TEST(factorialTest, OverflowMax)
{
    auto res = lit::factorial(INT_MAX);
    EXPECT_EQ(res.error_, lit::ErrorStatus::kOverflow);
}
