#include <iostream>
#include <string>
#include <cmath>
#include <vector>

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
protected:
    std::string name;
    int healthPoints;

public:
    Character(const std::string& name, int healthPoints, double x, double y)
        : GameObject(x, y), name(name), healthPoints(healthPoints) {}

    void draw() override {
        std::cout << "Drawing Character " << name << " at (" << x << ", " << y << ")\n";
    }

    virtual void update() override = 0;
    bool isAlive() const {
        return healthPoints > 0;
    }

    int getHealthPoints() const { return healthPoints; }
    void setHealthPoints(int hp) { healthPoints = hp; }
    const std::string& getName() const { return name; }
};

class Weapon {
public:
    virtual ~Weapon() = default;
    virtual void attack(Character& target) = 0;
    virtual int getRange() const = 0;
    virtual int getPower() const = 0;
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

class Enemy : public Character {
public:
    Enemy(const std::string& name, int healthPoints, double x, double y)
        : Character(name, healthPoints, x, y) {}

    void update() override {
        std::cout << name << " is thinking about moving or attacking.\n";
    }

    void update(Character& player) {
        double dist = this->distance(player);
        if (dist > 1.0) {
    
            x += (player.getX() - x) / dist; 
            y += (player.getY() - y) / dist;
            std::cout << name << " is moving towards " << player.getName() << " to position (" << x << ", " << y << ")\n";
        } else {
            player.setHealthPoints(player.getHealthPoints() - 1); // Dégâts de 1
            std::cout << name << " attacks " << player.getName() << "! Damage: 1\n";
        }
    }
};

class Player : public Character {
private:
    Weapon* currentWeapon;
    std::vector<Weapon*> weapons;
    int weaponIndex;

public:
    Player(const std::string& name, int healthPoints, double x, double y)
        : Character(name, healthPoints, x, y), weaponIndex(0) {
        weapons.push_back(new Bow());
        weapons.push_back(new Spear());
        weapons.push_back(new Sword());
        currentWeapon = weapons[weaponIndex];
    }

    ~Player() {
        for (Weapon* weapon : weapons) {
            delete weapon;
        }
    }

    void update() override {
        std::cout << name << " is updating...\n";
    }

    void update(Character& enemy) {
        if (currentWeapon->getRange() >= this->distance(enemy)) {
            currentWeapon->attack(enemy);
        } else {
            std::cout << name << " is out of range to attack with current weapon.\n";
        }
        switchWeapon();
    }

    void switchWeapon() {
        weaponIndex = (weaponIndex + 1) % weapons.size();
        currentWeapon = weapons[weaponIndex];
        std::cout << name << " switched weapon to " << (weaponIndex == 0 ? "Bow" : weaponIndex == 1 ? "Spear" : "Sword") << ".\n";
    }
};

int main() {
    Player player("Hero", 100, 0.0, 0.0);
    Enemy enemy("Goblin", 50, 5.0, 5.0);

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n--- Turn " << i + 1 << " ---\n";
        player.update(enemy);
        if (!enemy.isAlive()) {
            std::cout << enemy.getName() << " is defeated!\n";
            break;
        }
        enemy.update(player);
        if (!player.isAlive()) {
            std::cout << player.getName() << " is defeated!\n";
            break;
        }
    }

    return 0;
}
