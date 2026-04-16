#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.hpp"
#include "custom_types.hpp"

int main() {
    std::vector<int> vi {1, 2, 3, 4, 5};
    std::cout << core_numeric::sum(vi) << "\n";

    std::vector<double> vd {1.5, 2.5, 3.0};
    std::cout << core_numeric::sum(vd) << "\n";

    std::vector<std::string> vs {"hola", " ", "mundo"};
    std::cout << core_numeric::sum(vs) << "\n";

    std::vector<Vector2D> vv { {1.0, 2.0}, {3.0, 4.0} };
    Vector2D r = core_numeric::sum(vv);
    std::cout << r.x << " " << r.y << "\n";

    // No compila: SoloSumable no tiene operator+
    // SoloSumable no define operator+ con retorno mismo tipo... espera, si lo tiene.
    // Para ver fallo real, usar tipo sin operator+:

    // struct SinOperadores { double x; };
    // std::vector<SinOperadores> vsin { {1.0}, {2.0} };
    // core_numeric::sum(vsin);
    // ERROR: SinOperadores no satisface el concept Addable
    // porque no tiene operator+ definido

    return 0;
}
