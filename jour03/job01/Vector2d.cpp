#include <iostream>
#include <cmath> // For sqrt() and pow()

class Vector2d {
private:
    double x;
    double y;

public:

    Vector2d(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }


    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    Vector2d operator+(const Vector2d& other) const {       // Operator Overloading for Addition
        return Vector2d(x + other.x, y + other.y);
    }
    
    Vector2d operator-(const Vector2d& other) const {       // Operator Overloading for Subtraction
        return Vector2d(x - other.x, y - other.y);
    }

    double distance(const Vector2d& other) const {          // Method to calculate distance between two vectors
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector2d v1(3.0, 4.0);
    Vector2d v2(1.0, 2.0);

    Vector2d v3 = v1 + v2;
    Vector2d v4 = v1 - v2;

    std::cout << "Vector v1: ";
    v1.display();
    std::cout << "Vector v2: ";
    v2.display();
    std::cout << "Vector v3 (v1 + v2): ";
    v3.display();
    std::cout << "Vector v4 (v1 - v2): ";
    v4.display();

    std::cout << "Distance between v1 and v2: " << v1.distance(v2) << std::endl;

    return 0;
}
