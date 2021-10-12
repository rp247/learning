/*
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

using namespace std;

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
    */
    vector<int> range = vector<int>(fill.begin(), fill.end());

    /* 
    copy :  container with copy of each elements of x in the same order
            vector (const vector& x, const allocator_type& alloc);
    */
    vector<int> copy = vector<int>(fill);

    // continue: move and initializer list

    return 0;
}

