class MyCircularQueue {
public:
    std::vector<int> circular_queue;
    int front;
    int rear;
    int max_size;
    int size;
    MyCircularQueue(int k) : front(0), rear(0), max_size(k), size(0) {
        /*
            vector of size k
            keep track of two pointers front and rear
            enque increments back until the queue is full
            enqueue element at rear pointer + 1
            dequeue increments the start pointer by 1
            empty if rear = front
            full if rear + 1 = front
        */
        circular_queue.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        circular_queue[rear] = value;
        rear = (rear + 1) % max_size;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % max_size;
        size--;
        return true;
    }
    
    int Front() {
        if (size == 0) return -1;
        return circular_queue[front];
    }
    
    int Rear() {
        if (size == 0) return -1;
        return circular_queue[(((rear - 1) % max_size) + max_size) % max_size];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size >= max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */