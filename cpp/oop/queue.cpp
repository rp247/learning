#include <iostream>


#define QUEUE_DEF_SIZE 15
#define QUEUE_EMP_ERR  -1

class Queue {

    private:
        int size;
    
    public:

        Queue();                        // queue with default size
        Queue(int size);                // size should be >= 2.

        bool enqueue(int val);          // false if queue full
        int dequeue(void);              // returns -1 if queue empty
        int queue_size(void);

        ~Queue();                       // uses default destructor

};


int main(void) {
    return 0;
}