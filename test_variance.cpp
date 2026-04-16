#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.hpp"
#include "custom_types.hpp"

int main() {
    std::vector<double> data {1.0, 2.0, 3.0};
    std::cout << core_numeric::variance(data) << "\n";

    std::vector<float> dataf {2.0f, 4.0f, 6.0f, 8.0f};
    std::cout << core_numeric::variance(dataf) << "\n";

    std::vector<Vector2D> vv { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
    Vector2D var = core_numeric::variance(vv);
    std::cout << var.x << " " << var.y << "\n";

    std::vector<Esfera> ve { Esfera(1.0), Esfera(2.0), Esfera(3.0) };
    Esfera varE = core_numeric::variance(ve);
    std::cout << varE.radio << "\n";

    // No compila: std::string no satisface Addable ni Divisible de la forma requerida
    // std::vector<std::string> data2 {"a", "b", "c"};
    // core_numeric::variance(data2);
    // ERROR: std::string no satisface el concept Divisible requerido por variance

    // No compila: SoloSumable no satisface Divisible (no tiene operator/)
    // std::vector<SoloSumable> vs { SoloSumable(1.0) };
    // core_numeric::variance(vs);
    // ERROR: SoloSumable no satisface el concept Divisible

    return 0;
}
