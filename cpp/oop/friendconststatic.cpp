#include <iostream>

// cont.: static, const members and FUNCTIONS, wbu classes??

class Animal {
    private:
        int age;
        int height;
        int weight;
        const int legs, eyes, ears;         // won't change
        static int animal_count;            // only one per all objects, only one per class, not new everytime new instance

    public:
        Animal() : legs(4), eyes(2), ears(2) { animal_count++; }
        enum {just_a_constant = 100};
        int get_height(void) { return age; }
        int get_weight(void) { return height; }
        int total(void)     { return animal_count; }
        friend int comp_weight(Animal &a1, Animal &a2);
        // ~Animal() { animal_count--; }
        friend class Carn;      // Carn has access to all members and funcs of Animal
};

int Animal::animal_count = 0;   // initialization of static class members

class Carn {
    private:
        char name;
    
    public:
        char get_name(void) { Animal a1; return a1.weight; }
        friend int comp_weight_inception(Animal &a1, Animal &a2);   // friend method of friend class would not have access
                                                                    // here this cannot access animal members
};

/* suppose we don't have get weight function and we want 
   an outside (not of class) method that would compare their weights,
   then in order to access it's private members we need to make it friendly */
int comp_weight(Animal &a1, Animal &a2) {
    return a1.age == a2.age;
}

int main(void){
    Animal a1, a2;
    std::cout << "Animal Height: " << a1.get_height() << std::endl;
    std::cout << "Same weights? " << comp_weight(a1, a2) << std::endl;

    Carn c1;
    std::cout << "Carn name: " << c1.get_name() << Animal::just_a_constant << std::endl;

    std::cout << "Total animals: " << a1.total() << std::endl;
    return 0;
}