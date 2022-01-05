#include <iostream>

#define QUEUE_DEF_SIZE 15
#define QUEUE_EMP_ERR  -1

class Queue {

    private:
        int capacity = QUEUE_DEF_SIZE;
        int *q_arr = NULL;                     // make vector later??
        int curr_qsize = 0;
        int head = 0;
        int tail = 0;
    
    public:
        Queue();                        // queue with default size
        Queue(int size);                // size should be >= 2.

        Queue(const Queue &q);          // custom copy constructor. copies all q elements and its size.

        bool enqueue(int val);          // false if queue full
        int dequeue(void);              // returns -1 if queue empty
        bool is_full(void);             // true if curr_qsize == capacity
        int queue_size(void);
        void print_queue(void);

        // ~Queue();                       // uses default destructor

};


/* no param default constructor */
Queue::Queue() {

    Queue::q_arr = (int *) calloc(QUEUE_DEF_SIZE, sizeof(int));         // not zeroed out

    return;

}


/* constructor with **size** argument */
Queue::Queue(int size) {

    if (size < 2) {
        std::cerr << "Invalid queue size. Must be >= 2.\n";
        return;                                               // throw an exception later https://stackoverflow.com/questions/45643859/how-to-return-error-code-from-constructor
    }

    Queue::capacity = size;
    Queue::q_arr = (int *) calloc(size, sizeof(int));         // not zeroed out

    return;

}


/* returns size of the queue */
inline int Queue::queue_size(void) {
    return Queue::curr_qsize;
}


/* returns true if queue is full, else false */
inline bool Queue::is_full() {
    return Queue::capacity == Queue::curr_qsize;
}

/* to wrap head and tail around */
static inline uint32_t next_pos(uint32_t elem, uint32_t capacity) {
    return (elem + 1) % capacity;
}

/* adds elements at the end of queue */
bool Queue::enqueue(int val) {

    if (Queue::is_full()) return false;

    Queue::q_arr[Queue::tail] = val;                // add elem at the end
    Queue::tail = next_pos(tail, capacity);         // wrap around tail
    Queue::curr_qsize++;                            // increment q size

    return true;

}


/* returns first in elem (dequeued one) */ 
int Queue::dequeue(void) {
    if (Queue::curr_qsize == 0) return -99;         // -99 reserved for now. change dequeue to ret bool, +int *arg

    int temp = Queue::q_arr[head];                  // get elem from head
    head = next_pos(head, capacity);                // update (wrap if poss) head
    curr_qsize--;

    return temp;
}


/* prints elements of queue */
void Queue::print_queue(void) {
    if (q_arr && curr_qsize != 0) {
        std::cout << "Q: ";

        int i = head;

        /* print queue head to tail */
        do {
            std::cout << " " << Queue::q_arr[i];
            i = next_pos(i, capacity);                      // wrap i around as well
        } while (i != tail);

        std::cout << std::endl;
    }

    return;
}

int main(void) {

    /* constructor tests */
    Queue q1;
    Queue q2(2);
    Queue q3(-2);

    /* printing tests */
    q1.print_queue();
    q2.print_queue();
    // q3.print_queue();

    /* enqueue tests */
    q1.enqueue(-1); 
    int i = 0;
    while (q1.enqueue(i)) {
        i++;
    }
    std::cout << "Queue full. i = " << i << ".\n";
    q1.print_queue();

    /* dequeue tests */
    std::cout << "Dequeued: " << q1.dequeue() << ".\n";
    q1.enqueue(-71); 
    q1.print_queue();

    return 0;
}