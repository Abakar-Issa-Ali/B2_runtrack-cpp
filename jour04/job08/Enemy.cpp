#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

class Enemy {
public:
    virtual void attack() const = 0;  // Méthode virtuelle pure pour rendre Enemy abstraite
    virtual ~Enemy() {}
};

// Classe Goblin dérivée de Enemy
class Goblin : public Enemy {
public:
    void attack() const override {
        std::cout << "Goblin attacks with a dagger!" << std::endl;
    }
};

// Classe Ogre dérivée de Enemy
class Ogre : public Enemy {
public:
    void attack() const override {
        std::cout << "Ogre attacks with a club!" << std::endl;
    }
};

// Classe Dragon dérivée de Enemy
class Dragon : public Enemy {
public:
    void attack() const override {
        std::cout << "Dragon attacks with fire breath!" << std::endl;
    }
};

class EnemyFactory {
private:
    std::unordered_map<std::string, std::function<std::unique_ptr<Enemy>()>> registry;       // Map associant des types d'ennemis à leurs fonctions de création

public:

    EnemyFactory() {                // Constructeur qui initialise la map avec les types d'ennemis disponibles
        registry["Goblin"] = []() -> std::unique_ptr<Enemy> { return std::make_unique<Goblin>(); };
        registry["Ogre"] = []() -> std::unique_ptr<Enemy> { return std::make_unique<Ogre>(); };
        registry["Dragon"] = []() -> std::unique_ptr<Enemy> { return std::make_unique<Dragon>(); };
    }

    std::unique_ptr<Enemy> createEnemy(const std::string& enemyType) {
        auto it = registry.find(enemyType);
        if (it != registry.end()) {
            return it->second();
        }
        std::cerr << "Unknown enemy type: " << enemyType << std::endl;
        return nullptr;
    }
};

int main() {
    EnemyFactory factory;

    std::unique_ptr<Enemy> goblin = factory.createEnemy("Goblin");
    if (goblin) {
        goblin->attack();
    }

    std::unique_ptr<Enemy> ogre = factory.createEnemy("Ogre");
    if (ogre) {
        ogre->attack();
    }

    std::unique_ptr<Enemy> dragon = factory.createEnemy("Dragon");
    if (dragon) {
        dragon->attack();
    }

    // Test avec un type inconnu
    std::unique_ptr<Enemy> unknown = factory.createEnemy("Troll");
    if (unknown) {
        unknown->attack();
    }

    return 0;
}
