#include <iostream>
#include <string>
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

    Vector2d operator+(const Vector2d& other) const {
        return Vector2d(x + other.x, y + other.y);
    }

    Vector2d operator-(const Vector2d& other) const {
        return Vector2d(x - other.x, y - other.y);
    }

    double distance(const Vector2d& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

// Classe abstraite GameObject
class GameObject : public Vector2d {
public:
    GameObject() : Vector2d() {}
    GameObject(double x, double y) : Vector2d(x, y) {}

    virtual void draw() = 0;
    virtual void update() = 0;
};

class Decor : public GameObject {
public:
    Decor(double x, double y) : GameObject(x, y) {}

    void draw() override {
        std::cout << "Drawing Decor at (" << x << ", " << y << ")\n";
    }

    void update() override {
        std::cout << "Decor at (" << x << ", " << y << ") does not move.\n";
    }
};

class Character : public GameObject {
private:
    std::string name;
    int healthPoints;

public:
    Character(const std::string& name, int healthPoints, double x, double y) 
        : GameObject(x, y), name(name), healthPoints(healthPoints) {}

    void draw() override {
        std::cout << "Drawing Character " << name << " at (" << x << ", " << y << ")\n";
    }

    void update() override {

        std::cout << "Updating Character " << name << "'s position at (" << x << ", " << y << ")\n";
    }

    bool isAlive() const {
        return healthPoints > 0;
    }

    int getHealthPoints() const { return healthPoints; }
    void setHealthPoints(int hp) { healthPoints = hp; }
};

int main() {
    Decor tree(10.0, 15.0);
    tree.draw();
    tree.update();

    Character hero("Hero", 100, 5.0, 5.0);
    hero.draw();
    hero.update();

    std::cout << "Is " << hero.getHealthPoints() << " alive? " << (hero.isAlive() ? "Yes" : "No") << "\n";
    hero.setHealthPoints(0);
    std::cout << "Is " << hero.getHealthPoints() << " alive? " << (hero.isAlive() ? "Yes" : "No") << "\n";

    return 0;
}
