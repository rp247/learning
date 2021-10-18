// reference : https://www.cplusplus.com/reference/map/map/

#include <iostream>
#include <map>

/*
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           > class map;

           {key: val}
*/

using namespace std;

int main(){

   map<int, int> m;
   m[0] = '1';

    return 0;
}