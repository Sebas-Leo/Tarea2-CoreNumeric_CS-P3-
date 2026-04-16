#pragma once

#include <cstddef>
#include <cmath>

struct Vector2D {
    double x, y;

    Vector2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(const Vector2D& other) const {
        return Vector2D(x * other.x, y * other.y);
    }

    Vector2D operator/(std::size_t n) const {
        return Vector2D(x / static_cast<double>(n), y / static_cast<double>(n));
    }

    bool operator<(const Vector2D& other) const {
        return (x * x + y * y) < (other.x * other.x + other.y * other.y);
    }
};

struct Esfera {
    double radio;

    Esfera(double r = 0.0) : radio(r) {}

    Esfera operator+(const Esfera& other) const {
        return Esfera(radio + other.radio);
    }

    Esfera operator-(const Esfera& other) const {
        return Esfera(radio - other.radio);
    }

    Esfera operator*(const Esfera& other) const {
        return Esfera(radio * other.radio);
    }

    Esfera operator/(std::size_t n) const {
        return Esfera(radio / static_cast<double>(n));
    }

    bool operator<(const Esfera& other) const {
        return radio < other.radio;
    }
};

struct SoloSumable {
    double valor;

    SoloSumable(double v = 0.0) : valor(v) {}

    SoloSumable operator+(const SoloSumable& other) const {
        return SoloSumable(valor + other.valor);
    }
};
