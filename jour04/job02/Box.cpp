#include <iostream>

template <typename T>
class Box {
private:
    T item;

public:

    Box() : item() {}

    Box(T item) : item(item) {}

    void setItem(T newItem) {       // Méthode pour définir l'élément dans la box
        item = newItem;
    }

    T getItem() const {                // Méthode pour obtenir l'élément de la box
        return item;
    }
};

int main() {

    Box<int> intBox(42);            // Création d'une Box contenant un int
    std::cout << "Int Box contient : " << intBox.getItem() << std::endl;

    Box<double> doubleBox(3.14);          // Création d'une Box contenant un double
    std::cout << "Double Box contient : " << doubleBox.getItem() << std::endl;

    Box<std::string> stringBox("Hello World!");        // Création d'une Box contenant un string
    std::cout << "String Box contient : " << stringBox.getItem() << std::endl;

    stringBox.setItem("Bonjour à tous!");
    std::cout << "String Box modifié contient : " << stringBox.getItem() << std::endl;

    return 0;
}
