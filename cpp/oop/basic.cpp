//205
/* Need for OOP :
    - no need to pass struct pointer everytime
    - no public access to member of structs/classes (only methods can access em)
    - default constructors/destructors
*/

#include <iostream>

class student {
    
    /* class members that can only be directly access by class methods */
    private:
        int age;
        char name;
        char grade;
    
    /* any instance of student can access this methods */
    public:

        /* defuault contructors, copy constructs, and destructos are made if not explicitly made */
        student(void);                                  // default parameterless constructor
        student(int age, char name, char grade);        // default constructor, gets called everytime new instance made
        void init(int age, char name, char grade);      // explicit "constructor", obj needs to call this explicitly

        int get_age(void);
        char get_name(void);
        char get_grade(void);

        void set_name(char name);
        void set_age(int age);
        void set_grade(char grade);

        // use overload later: https://stackoverflow.com/questions/23239646/print-function-for-class-c
        void print_student(void);   // opeator overload << for using cout << student()

        // destructors, takes no parameters
        ~student(void);    // automatically called when var out of scope

        // copy constructor : called everytime class is passed by value to make a copy and work on that copy
        student(const student &s); // const since not updating s but making a copy of s
        void temp_update_student(student s); // test copy constructor
};

student::student(void) {
    age = 18;
    name = 'F';
    grade = 'A';
}

student::student(int age, char name, char grade) {
    student::age = age;     // same parameter names would cause confusion and incorrect output
    student::name = name;
    student::grade = grade;
}

// copy constructor
student::student(const student &s) {
    student::age = s.age;
    name = s.name+1;
    grade = s.grade;
    std::cout << "Copied student " << s.name << ".\n";
}

// s gets copied, just for this method, nothing changes for s after method returns
void student::temp_update_student(student s){
    std::cout << "After copy. In method temp_update_student.\n";
    s.print_student();
    return;
}

/* definition of method of student class */
int student::get_age(void) {
    return student::age;    // just for clarification
}

void student::set_age(int age){
    age = age;
}

void student::print_student(void) {
    std::cout << "Age: " << get_age() << ". Name: " << name << ". Grade: " << student::grade << ".\n";
}

student::~student(void){
    std::cout << "Student named " << name << " destroyed.\n";
}

int main(void){

    student s1;
    int s1_age = s1.get_age();
    student s2(19, 'U', 'L');

    s1.print_student();
    s2.print_student();

    s1.temp_update_student(s2);

    return 0;
}