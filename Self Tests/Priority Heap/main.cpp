// class implementation of priority queue

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
    // push
    // pop
    // top
    // empty
    // size
    // print

    public:
        PriorityQueue();
        void push(int value);
        void pop();
        int top();
        bool empty();
        int size();
        void print();

    private:

        vector<int> heap;
        int heapSize;


        void heapify(int index);
        void swap(int index1, int index2);
        int parent(int index);
        int leftChild(int index);
        int rightChild(int index);
};

PriorityQueue::PriorityQueue() {
    heapSize = 0;
}

void PriorityQueue::push(int value) {
    heap.push_back(value);
    heapSize++;
    heapify(heapSize - 1);
}

void PriorityQueue::pop() {
    if (heapSize == 0) {
        cout << "Heap is empty" << endl;
        return;
    }

    heap[0] = heap[heapSize - 1];
    heap.pop_back();
    heapSize--;
    heapify(0);
}

int PriorityQueue::top() {
    if (heapSize == 0) {
        cout << "Heap is empty" << endl;
        return -1;
    }

    return heap[0];
}

bool PriorityQueue::empty() {
    return heapSize == 0;
}

int PriorityQueue::size() {
    return heapSize;
}

void PriorityQueue::print() {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void PriorityQueue::heapify(int index) {
    if (index == 0) {
        return;
    }

    int parentIndex = parent(index);

    if (heap[parentIndex] < heap[index]) {
        swap(parentIndex, index);
        heapify(parentIndex);
    }
}

void PriorityQueue::swap(int index1, int index2) {
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

int PriorityQueue::parent(int index) {
    return (index - 1) / 2;
}

int PriorityQueue::leftChild(int index) {
    return 2 * index + 1;
}

int PriorityQueue::rightChild(int index) {
    return 2 * index + 2;
}

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);
    pq.push(60);
    pq.push(70);
    pq.push(80);
    pq.push(90);
    pq.push(100);

    pq.print();

    cout << "Top: " << pq.top() << '\n';
    cout << "Pop" << '\n'; pq.pop();
    cout << "Size: " << pq.size() << '\n'; 
    pq.pop();
    pq.print();
    cout << "Pop All\n";

    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();

    pq.print();

    return 0;
}