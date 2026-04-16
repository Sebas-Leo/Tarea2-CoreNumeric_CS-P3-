#pragma once

#include <concepts>
#include <iterator>
#include <cstddef>
#include <type_traits>
#include <limits>

namespace core_numeric {

template<typename C>
concept Iterable = requires(C c) {
    std::begin(c);
    std::end(c);
};

template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template<typename T>
concept Divisible = requires(T a, std::size_t n) {
    { a / n } -> std::same_as<T>;
};

template<typename T>
concept Numeric = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
    { a - b } -> std::same_as<T>;
    { a * b } -> std::same_as<T>;
    { a < b } -> std::convertible_to<bool>;
};

template<Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& container) {
    using T = typename C::value_type;
    T result{};
    for (const auto& value : container)
        result = result + value;
    return result;
}

template<Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type>
auto mean(const C& container) {
    auto total = sum(container);
    std::size_t n = static_cast<std::size_t>(
        std::distance(std::begin(container), std::end(container)));
    return total / n;
}

template<Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type>
auto variance(const C& container) {
    using T = typename C::value_type;
    auto m = mean(container);
    std::size_t n = static_cast<std::size_t>(
        std::distance(std::begin(container), std::end(container)));
    T sq_sum{};
    for (const auto& v : container) {
        T diff = v - m;
        sq_sum = sq_sum + diff * diff;
    }
    return sq_sum / n;
}

template<Iterable C>
requires Numeric<typename C::value_type>
auto max(const C& container) {
    using T = typename C::value_type;
    if constexpr (std::is_arithmetic_v<T>) {
        T result = T{};
        for (const auto& v : container) {
            if (result < v)
                result = v;
        }
        return result;
    } else {
        auto it = std::begin(container);
        T result = *it;
        ++it;
        for (; it != std::end(container); ++it) {
            if (result < *it)
                result = *it;
        }
        return result;
    }
}

template<Iterable C, typename F>
requires Addable<typename C::value_type>
auto transform_reduce(const C& container, F func) {
    using T = typename C::value_type;
    T result{};
    for (const auto& v : container)
        result = result + func(v);
    return result;
}

template<typename T, typename... Args>
requires (Addable<T> && (Addable<Args> && ...))
auto sum_variadic(T first, Args... rest) {
    return (first + ... + rest);
}

template<typename T, typename... Args>
requires (Addable<T> && (Addable<Args> && ...))
auto mean_variadic(T first, Args... rest) {
    std::size_t n = sizeof...(Args) + 1;
    auto total = sum_variadic(first, rest...);
    return total / n;
}

template<typename T, typename... Args>
requires (Numeric<T> && (Numeric<Args> && ...))
auto max_variadic(T first, Args... rest) {
    using Common = std::common_type_t<T, Args...>;
    Common result = static_cast<Common>(first);
    ((result = (result < static_cast<Common>(rest))
               ? static_cast<Common>(rest)
               : result), ...);
    return result;
}

template<typename T, typename... Args>
requires (Numeric<T> && (Numeric<Args> && ...))
auto variance_variadic(T first, Args... rest) {
    using Common = std::common_type_t<T, Args...>;
    std::size_t n = sizeof...(Args) + 1;
    auto m = mean_variadic(first, rest...);
    Common mc = static_cast<Common>(m);

    Common sq_sum{};

    auto f = [&sq_sum, &mc](auto v) {
    Common d = static_cast<Common>(v) - mc;
    sq_sum = sq_sum + d * d;
        };
    f(first);
    if constexpr (sizeof...(Args) > 0) {
        (f(rest), ...);}

    return sq_sum / n;
}

}
