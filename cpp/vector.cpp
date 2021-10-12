/*
 - Ref: https://www.cplusplus.com/reference/vector/vector/

 - Vectors are just like arrarys, except they can grow dynamically.
 - The elements could still be accessed by offset of the 0th element. 
 - Thus, they alloacte more space in advance to not reallocate too many times.
 - It does reallocate when mem runs out. Slow as hell. 
 - Hence, the capacity of vector (how much it can hold) >= size of vector (how much it currently holds)
 - Initial allocation and reallocation (mem usage v. realloc time) is library dependent

 Container Properties:
 - Elements are in a strict linear sequence. 
 - Allows direct access in sequence, fast add/remove from the end. 

 To do:
 - Implement from scratch.
*/

#include <vector>
#include <iostream>

using namespace std;

void vc_print(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << ' ' << *it;
    }
    cout << endl;
}

int main(){

    /* Constructors: https://www.cplusplus.com/reference/vector/vector/vector/ */

    /* 
    empty :  returns an empty vector. 
             explicit vector (const allocator_type& alloc);
    */
    vector<int> empty = vector<int>();

    /* 
    fill :  construct vec with n elements, each with copy of val if provided 
            vector (size_type n, {const value_type& val}, const allocator_type& alloc = allocator_type());
    */
    vector<int> fill = vector<int>(10, -1);

    /* 
    range :  Constructs a container with as many elements as the range [first,last), with each element emplace-constructed from its corresponding element in that range, in the same order.
             template <class InputIterator>; vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
             useful when one does not want to copy whole vector but wants a range of elements
    */
    vector<int> range = vector<int>(fill.begin(), fill.end()-3);

    /* 
    copy :  container with copy of each elements of x in the same order
            vector (const vector& x, const allocator_type& alloc);
    */
    vector<int> copy = vector<int>(fill);

    // from array (iterator)
    int temp[] = {0, 1, 2, 3, 4};
    vector<int> from_arr = vector<int>(temp, temp+(sizeof(temp)/sizeof(int)));

    // continue: move and initializer list

    /* CONSTRUCTOR & PRINT TEST */
    cout << "Empty Vector : "; vc_print(empty);
    cout << "Fill Vector : (10 -1s)"; vc_print(fill);
    cout << "Range Vector : (fill begin to end-3, same elements)"; vc_print(range);
    cout << "Copy Vector : (copy fill)"; vc_print(copy);
    cout << "From_arr Vector : "; vc_print(from_arr);


    /* OPERATORS */

    // = . copies elements into a vector (or a container) from a vector (container, or an initializer list)
    vector<int> fill2 = fill;

    // [] . returns reference to vector element
    cout << "3rd elem of fill2 = " << (fill2[2] = 9);

    /*
     ITERATORS
     .{r|cr}begin() : returns it to the {reverse|const.rev}beginning element
     .{r|cr}end() : returns it to the {reverse|const.rev}end element
    */

   /* CONT: capacity  https://www.cplusplus.com/reference/vector/vector/ */

    return 0;
}

