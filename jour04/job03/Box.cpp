#include <iostream>
#include <memory>

template <typename T>
class Box {
private:
    T item;

public:

    Box() : item() {}

    Box(T item) : item(item) {}

    void setItem(T newItem) {
        item = newItem;
    }

    T getItem() const {
        return item;
    }
};

template <typename T>                    // Spécialisation de la classe Box pour contenir un pointeur
class Box<T*> {
private:
    T* item;  // Pointeur sur l'élément contenu dans la box

public:

    Box() : item(nullptr) {}

    Box(T* item) : item(item) {}

    void setItem(T* newItem) {
        item = newItem;
    }


    T getItem() const {
        return *item;
    }

    // Méthode pour obtenir le pointeur brut
    T* getPointer() const {
        return item;
    }
};

int main() {
    // Utilisation de la classe Box normale avec un int
    Box<int> intBox(42);
    std::cout << "Int Box contient : " << intBox.getItem() << std::endl;

    int value = 100;
    Box<int*> intPtrBox(&value);
    std::cout << "Int Pointer Box contient : " << intPtrBox.getItem() << std::endl;

    // Modifier la valeur pointée
    *intPtrBox.getPointer() = 200;
    std::cout << "Int Pointer Box modifié contient : " << intPtrBox.getItem() << std::endl;

    // Utilisation avec un pointeur vers un double
    double dValue = 3.14;
    Box<double*> doublePtrBox(&dValue);
    std::cout << "Double Pointer Box contient : " << doublePtrBox.getItem() << std::endl;

    return 0;
}
