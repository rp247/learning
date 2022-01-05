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

void map_print(map<int, int> &m) {
    for (map<int, int>::iterator t = m.begin(); t != m.end(); t++) {
        cout << t->first << ':' << t->second << endl;
    }
    return;
}

int main(){

   map<int, int> m;
   m[0] = -1;

   map_print(m);

    return 0;
}