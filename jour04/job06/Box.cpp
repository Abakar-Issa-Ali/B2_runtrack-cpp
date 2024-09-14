#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

// Classe abstraite Shape
class Shape {
public:
    virtual void draw() const = 0;  // Méthode virtuelle pure pour rendre Shape abstraite
    virtual ~Shape() {}             // Destructeur virtuel
};

// Classe Circle dérivée de Shape
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

// Classe Rectangle dérivée de Shape
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle." << std::endl;
    }
};

// Classe ShapeFactory avec méthode template pour créer des shapes
class ShapeFactory {
private:
    // Registre pour stocker les fonctions de création d'objets Shape
    static std::unordered_map<std::string, std::function<std::unique_ptr<Shape>()>> registry;

public:
    // Méthode template pour enregistrer des classes dérivées de Shape
    template <typename T>
    static void registerShape(const std::string& shapeType) {
        registry[shapeType] = []() -> std::unique_ptr<Shape> {
            return std::make_unique<T>();
        };
    }

    // Méthode statique pour créer des shapes
    static std::unique_ptr<Shape> createShape(const std::string& shapeType) {
        auto it = registry.find(shapeType);
        if (it != registry.end()) {
            return it->second();  // Appelle la fonction de création correspondante
        }
        std::cerr << "Unknown shape type: " << shapeType << std::endl;
        return nullptr;
    }
};

// Initialisation du registre de ShapeFactory
std::unordered_map<std::string, std::function<std::unique_ptr<Shape>()>> ShapeFactory::registry;

int main() {
    // Enregistrer des shapes dans la ShapeFactory
    ShapeFactory::registerShape<Circle>("Circle");
    ShapeFactory::registerShape<Rectangle>("Rectangle");

    // Créer des shapes via la ShapeFactory
    std::unique_ptr<Shape> circle = ShapeFactory::createShape("Circle");
    if (circle) {
        circle->draw();
    }

    std::unique_ptr<Shape> rectangle = ShapeFactory::createShape("Rectangle");
    if (rectangle) {
        rectangle->draw();
    }

    // Test avec un type inconnu
    std::unique_ptr<Shape> unknown = ShapeFactory::createShape("Triangle");
    if (unknown) {
        unknown->draw();
    }

    return 0;
}
