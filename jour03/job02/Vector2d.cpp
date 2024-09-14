#include <iostream>
#include <cmath>

class Vector2d {
protected:
    double x;
    double y;

public:

    Vector2d() : x(0), y(0) {}


    Vector2d(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    // Surcharge de l'opérateur +
    Vector2d operator+(const Vector2d& other) const {
        return Vector2d(x + other.x, y + other.y);
    }

    // Surcharge de l'opérateur -
    Vector2d operator-(const Vector2d& other) const {
        return Vector2d(x - other.x, y - other.y);
    }

    double distance(const Vector2d& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class GameObject : public Vector2d {
public:

    GameObject() : Vector2d() {}

    GameObject(double x, double y) : Vector2d(x, y) {}

    virtual void draw() = 0;
    virtual void update() = 0;
};

// Exemple d'une classe dérivée qui implémente GameObject
class Player : public GameObject {
public:
    Player(double x, double y) : GameObject(x, y) {}

    void draw() override {
        std::cout << "Drawing Player at (" << x << ", " << y << ")\n";
    }

    void update() override {
        x += 1;
        y += 1;
        std::cout << "Updating Player position to (" << x << ", " << y << ")\n";
    }
};

int main() {
    Player player(5.0, 10.0);
    player.draw();
    player.update();

    return 0;
}
