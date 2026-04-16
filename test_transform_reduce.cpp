#include <iostream>
#include <vector>
#include "core_numeric.hpp"
#include "custom_types.hpp"

int main() {
    std::vector<double> v {1.0, 2.0, 3.0, 4.0};

    auto r = core_numeric::transform_reduce(v, [](double x) {
        return x * x;
    });
    std::cout << r << "\n";

    auto r2 = core_numeric::transform_reduce(v, [](double x) {
        return x + 10.0;
    });
    std::cout << r2 << "\n";

    std::vector<int> vi {1, 2, 3, 4};
    auto r3 = core_numeric::transform_reduce(vi, [](int x) {
        return x * x;
    });
    std::cout << r3 << "\n";

    std::vector<Vector2D> vv { {1.0, 2.0}, {3.0, 4.0} };
    auto r4 = core_numeric::transform_reduce(vv, [](Vector2D p) {
        return p * p;
    });
    std::cout << r4.x << " " << r4.y << "\n";

    // No compila: SoloSumable no satisface Addable de forma directa
    // (en realidad si lo satisface, pero si usamos struct sin operator+:)
    // struct SinSuma { double x; };
    // std::vector<SinSuma> vss { {1.0} };
    // core_numeric::transform_reduce(vss, [](SinSuma s){ return s; });
    // ERROR: SinSuma no satisface el concept Addable

    return 0;
}
