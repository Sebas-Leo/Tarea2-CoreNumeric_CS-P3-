#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.hpp"
#include "custom_types.hpp"

int main() {
    std::vector<double> data {1.0, 2.7, 0.3};
    std::cout << core_numeric::max(data) << "\n";

    std::vector<int> vi {5, 3, 8, 1};
    std::cout << core_numeric::max(vi) << "\n";

    std::vector<float> vf {1.1f, 3.3f, 2.2f};
    std::cout << core_numeric::max(vf) << "\n";

    std::vector<Vector2D> vv { {1.0, 0.0}, {3.0, 4.0}, {2.0, 2.0} };
    Vector2D m = core_numeric::max(vv);
    std::cout << m.x << " " << m.y << "\n";

    std::vector<Esfera> ve { Esfera(5.0), Esfera(1.0), Esfera(3.0) };
    Esfera me = core_numeric::max(ve);
    std::cout << me.radio << "\n";

    // No compila: std::string no satisface el concept Numeric
    // El concept Numeric requiere operator- y operator*
    // std::string no tiene operator- ni operator*
    // std::vector<std::string> vs {"a", "b", "c"};
    // core_numeric::max(vs);
    // ERROR: std::string no satisface el concept Numeric

    // No compila: SoloSumable no satisface Numeric
    // SoloSumable solo tiene operator+, le faltan operator-, operator*, operator<
    // std::vector<SoloSumable> vss { SoloSumable(1.0), SoloSumable(2.0) };
    // core_numeric::max(vss);
    // ERROR: SoloSumable no satisface el concept Numeric

    return 0;
}
