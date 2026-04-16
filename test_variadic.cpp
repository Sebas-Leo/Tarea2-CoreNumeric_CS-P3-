#include <iostream>
#include "core_numeric.hpp"

int main() {
    auto s1 = core_numeric::sum_variadic(1, 2, 33, 4);
    std::cout << s1 << "\n";

    auto s2 = core_numeric::sum_variadic(1.5, 2.5, 3.0);
    std::cout << s2 << "\n";

    auto m1 = core_numeric::mean_variadic(0.1, 2.0, 3.0, 4.0);
    std::cout << m1 << "\n";

    auto m2 = core_numeric::mean_variadic(10.0, 20.0, 30.0);
    std::cout << m2 << "\n";

    auto mx1 = core_numeric::max_variadic(1, 2.7, 3, 4);
    std::cout << mx1 << "\n";

    auto mx2 = core_numeric::max_variadic(5.0, 1.0, 9.0, 3.0);
    std::cout << mx2 << "\n";

    auto v1 = core_numeric::variance_variadic(1.0, 2.0, 3.0, 4.0);
    std::cout << v1 << "\n";

    auto v2 = core_numeric::variance_variadic(2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0);
    std::cout << v2 << "\n";

    // No compila: std::string no satisface Addable (suma con retorno mismo tipo si, pero Numeric no)
    // Para sum_variadic con string, en realidad compilaria porque Addable<string> es true
    // Para max_variadic y variance_variadic no compila porque Numeric<string> es false:
    // std::string no tiene operator- ni operator*

    // core_numeric::max_variadic(std::string("a"), std::string("b"));
    // ERROR: std::string no satisface el concept Numeric
    // Le faltan operator- y operator*

    // core_numeric::variance_variadic(std::string("x"), std::string("y"));
    // ERROR: std::string no satisface el concept Numeric

    return 0;
}
