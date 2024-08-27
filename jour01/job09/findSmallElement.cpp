# include <iostream>
using namespace std;

int findSmallElement(int* tableau, int size){
    int* smaller = tableau;
    
    for (int i = 1; i < size; i++){
        if (*(tableau + i) < *smaller){
            smaller = tableau + i;
        }
    }
    return *smaller;
}

int main(){
    int tableau [] = {10, 22, 3, 15, 8, 7};
    int size = sizeof(tableau) / sizeof(tableau[0]);

    int smaller =  findSmallElement(tableau, size);

    std::cout << "Le plus petit élément du tableau est: " << smaller << std::endl;

    return 0;
}