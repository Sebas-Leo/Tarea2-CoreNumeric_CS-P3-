#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.hpp"
#include "custom_types.hpp"

int main() {
    std::vector<double> vd {1.0, 2.0, 3.0};
    std::cout << core_numeric::mean(vd) << "\n";

    std::vector<float> vf {2.0f, 4.0f, 6.0f};
    std::cout << core_numeric::mean(vf) << "\n";

    std::vector<Vector2D> vv { {2.0, 4.0}, {4.0, 8.0} };
    Vector2D m = core_numeric::mean(vv);
    std::cout << m.x << " " << m.y << "\n";

    // No compila: int no satisface Divisible
    // El concept Divisible requiere que { a / size_t } -> same_as<T>
    // Para int: int / size_t devuelve size_t, no int
    // std::vector<int> vi {1, 2, 3};
    // core_numeric::mean(vi);
    // ERROR: int no satisface el concept Divisible

    // No compila: std::string no satisface Divisible
    // std::vector<std::string> vs {"a", "b"};
    // core_numeric::mean(vs);
    // ERROR: std::string no satisface el concept Divisible

    return 0;
}
