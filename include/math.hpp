#pragma once

#include <limits.h>
#include <stdint.h>

namespace lit
{

inline constexpr int kMaxIntFactorial = 12;

enum class ErrorStatus : uint8_t
{
    kOk,
    kOverflow,
    kDivisionByZero,
    kInvalidNumber,
};

/*
 * If MathRes contains error(!= kOk), value unspecified
 * */
struct MathRes
{
    int value_;
    ErrorStatus error_;
};

inline MathRes add(int num1, int num2) noexcept
{
    const int64_t res = static_cast<int64_t>(num1) + num2;
    if (res > INT_MAX || res < INT_MIN)
        return {0, ErrorStatus::kOverflow};
    return {static_cast<int>(res), ErrorStatus::kOk};
}

inline MathRes subtract(int num1, int num2) noexcept
{
    const int64_t res = static_cast<int64_t>(num1) - num2;
    if (res > INT_MAX || res < INT_MIN)
        return {0, ErrorStatus::kOverflow};
    return {static_cast<int>(res), ErrorStatus::kOk};
}

inline MathRes multiply(int num1, int num2) noexcept
{
    const int64_t res = static_cast<int64_t>(num1) * num2;
    if (res > INT_MAX || res < INT_MIN)
        return {0, ErrorStatus::kOverflow};
    return {static_cast<int>(res), ErrorStatus::kOk};
}

inline MathRes divide(int num1, int num2) noexcept
{
    if (num2 == 0)
        return {0, ErrorStatus::kDivisionByZero};
    const int64_t res = static_cast<int64_t>(num1) / num2;
    if (res > INT_MAX)
        return {0, ErrorStatus::kOverflow};
    return {static_cast<int>(res), ErrorStatus::kOk};
}

inline MathRes pow(int base, int exponent) noexcept
{
    if (exponent == 0)
        return {1, ErrorStatus::kOk};
    if (exponent < 0)
        return {0, ErrorStatus::kInvalidNumber};
    int64_t res{1};
    for (int i = 0; i < exponent; ++i)
    {
        res *= base;
        if (res > INT_MAX || res < INT_MIN)
            return {0, ErrorStatus::kOverflow};
    }
    return {static_cast<int>(res), ErrorStatus::kOk};
}

static constexpr int factorialHelp(int num) noexcept
{
    if (num <= 1)
        return 1;
    return num * factorialHelp(num - 1);
}

inline MathRes factorial(int num) noexcept
{
    if (num < 0)
        return {0, ErrorStatus::kInvalidNumber};

    if (num > kMaxIntFactorial)
        return {0, ErrorStatus::kOverflow};

    return {factorialHelp(num), ErrorStatus::kOk};
}
} // namespace lit
