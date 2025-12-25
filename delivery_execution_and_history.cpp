#include <iostream>
using namespace std;

#define MAX 20

/* ===================== PACKAGE STRUCTURE ===================== */
struct Package
{
    int id;
};

/* ===================== CIRCULAR QUEUE (DELIVERY ORDER) ===================== */
struct Queue
{
    Package arr[MAX];
    int front;
    int rear;
};

// Initialize queue-Time Complexity : O(1)
void initQueue(Queue &q)
{
    q.front = q.rear = -1;
}

// Check if queue empty-Time Complexity: O(1)

bool isQueueEmpty(Queue q)
{
    return q.front == -1;
}

// Check if queue full-Time Complexity: O(1)

bool isQueueFull(Queue q)
{
    return (q.rear + 1) % MAX == q.front;
}

// Enqueue package (Circular Queue)-Time Complexity: O(1)

void enqueuePackage(Queue &q, Package p)
{
    if (isQueueFull(q))
    {
        cout << "Delivery Queue Full\n";
        return;
    }

    if (q.front == -1) // First insertion
        q.front = q.rear = 0;
    else
        q.rear = (q.rear + 1) % MAX;

    q.arr[q.rear] = p;
}

// Dequeue package (Circular Queue)-Time Complexity: O(1)

Package dequeuePackage(Queue &q)
{
    Package p;

    if (isQueueEmpty(q))
    {
        cout << "Delivery Queue Empty\n";
        p.id = -1;
        return p;
    }

    p = q.arr[q.front];

    if (q.front == q.rear)
        q.front = q.rear = -1; // Queue becomes empty
    else
        q.front = (q.front + 1) % MAX;

    return p;
}

//===================== STACK (DELIVERY HISTORY) =====================
struct Stack
{
    Package arr[MAX];
    int top;
};

// Initialize stack-Time Complexity: O(1)

void initStack(Stack &s)
{
    s.top = -1;
}

bool isStackEmpty(Stack s)
{
    return s.top == -1;
}

// Push delivered package to history-Time Complexity: O(1)

void pushHistory(Stack &s, Package p)
{
    s.arr[++s.top] = p;
}

// Pop last delivered package (Undo)-Time Complexity: O(1)

Package popHistory(Stack &s)
{
    return s.arr[s.top--];
}

// ===================== DELIVERY OPERATIONS =====================

// Execute delivery-Uses Queue + Stack-Time Complexity: O(1)

void executeDelivery(Queue &deliveryQueue, Stack &historyStack)
{
    if (isQueueEmpty(deliveryQueue))
    {
        cout << "No deliveries to execute\n";
        return;
    }

    Package p = dequeuePackage(deliveryQueue);
    pushHistory(historyStack, p);

    cout << "Delivered Package ID: " << p.id << endl;
}

// Undo last delivery-Uses Stack-Time Complexity: O(1)

void undoDelivery(Stack &historyStack)
{
    if (isStackEmpty(historyStack))
    {
        cout << "Nothing to undo\n";
        return;
    }

    Package p = popHistory(historyStack);
    cout << "Undo delivery of Package ID: " << p.id << endl;
}

// int main()
// {
//     Queue deliveryQueue;
//     Stack historyStack;

//     initQueue(deliveryQueue);
//     initStack(historyStack);

//     // these are samples for this bench code, but after the full implementation is just the users input
//     enqueuePackage(deliveryQueue, {101});
//     enqueuePackage(deliveryQueue, {102});
//     enqueuePackage(deliveryQueue, {103});

//     executeDelivery(deliveryQueue, historyStack); // 101
//     executeDelivery(deliveryQueue, historyStack); // 102
//     undoDelivery(historyStack);                   // Undo 102
//     executeDelivery(deliveryQueue, historyStack); // 103

//     return 0;
// }
