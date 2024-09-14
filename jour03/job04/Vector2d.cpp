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

class GameObject : public Vector2d {
public:
    GameObject() : Vector2d() {}
    GameObject(double x, double y) : Vector2d(x, y) {}

    virtual void draw() = 0;
    virtual void update() = 0;
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
    const std::string& getName() const { return name; }
};

// Interface Weapon
class Weapon {
public:
    virtual ~Weapon() = default;
    virtual void attack(Character& target) = 0; // Méthode pour attaquer un personnage
    virtual int getRange() const = 0;           // Retourne la portée de l'arme
    virtual int getPower() const = 0;           // Retourne la puissance de l'arme
};

class Bow : public Weapon {
private:
    int range;
    int power;

public:
    Bow() : range(4), power(1) {}

    void attack(Character& target) override {
        target.setHealthPoints(target.getHealthPoints() - power);
        std::cout << "Attacking " << target.getName() << " with Bow. Damage: " << power << "\n";
    }

    int getRange() const override { return range; }
    int getPower() const override { return power; }
};

class Spear : public Weapon {
private:
    int range;
    int power;

public:
    Spear() : range(2), power(2) {}

    void attack(Character& target) override {
        target.setHealthPoints(target.getHealthPoints() - power);
        std::cout << "Attacking " << target.getName() << " with Spear. Damage: " << power << "\n";
    }

    int getRange() const override { return range; }
    int getPower() const override { return power; }
};

class Sword : public Weapon {
private:
    int range;
    int power;

public:
    Sword() : range(1), power(4) {}

    void attack(Character& target) override {
        target.setHealthPoints(target.getHealthPoints() - power);
        std::cout << "Attacking " << target.getName() << " with Sword. Damage: " << power << "\n";
    }

    int getRange() const override { return range; }
    int getPower() const override { return power; }
};

int main() {

    Character hero("Hero", 100, 5.0, 5.0);
    Character enemy("Enemy", 50, 7.0, 7.0);

    Bow bow;
    Spear spear;
    Sword sword;

    // Utilisation des armes pour attaquer l'ennemi
    bow.attack(enemy);
    std::cout << enemy.getName() << " Health: " << enemy.getHealthPoints() << "\n";

    spear.attack(enemy);
    std::cout << enemy.getName() << " Health: " << enemy.getHealthPoints() << "\n";

    sword.attack(enemy);
    std::cout << enemy.getName() << " Health: " << enemy.getHealthPoints() << "\n";

    return 0;
}
