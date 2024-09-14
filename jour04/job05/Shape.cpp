#include <iostream>
#include <memory>
#include <string>

class Shape {
public:
    virtual void draw() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle." << std::endl;
    }
};

// Classe ShapeFactory avec méthode statique createShape
class ShapeFactory {
public:
    // Méthode statique pour créer des instances de Shape
    static std::unique_ptr<Shape> createShape(const std::string& shapeType) {
        if (shapeType == "Circle") {
            return std::make_unique<Circle>();
        } else if (shapeType == "Rectangle") {
            return std::make_unique<Rectangle>();
        } else {
            std::cerr << "Unknown shape type: " << shapeType << std::endl;
            return nullptr;
        }
    }
};

int main() {
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
