// #include <iostream>
// #include "delivery_exe_and_history.h" 

// using namespace std;

// #define MAX 20

// /* ===================== CIRCULAR QUEUE (DELIVERY ORDER) ===================== */
// struct Queue
// {
//     Package arr[MAX];
//     int front;
//     int rear;
// };

// // Initialize queue
// void initQueue(Queue &q)
// {
//     q.front = q.rear = -1;
// }

// // Check if queue empty
// bool isQueueEmpty(const Queue &q)
// {
//     return q.front == -1;
// }

// // Check if queue full
// bool isQueueFull(const Queue &q)
// {
//     return (q.rear + 1) % MAX == q.front;
// }

// // Enqueue package
// void enqueuePackage(Queue &q, const Package &p)
// {
//     if (isQueueFull(q))
//     {
//         cout << "Delivery Queue Full\n";
//         return;
//     }

//     if (q.front == -1)
//         q.front = q.rear = 0;
//     else
//         q.rear = (q.rear + 1) % MAX;

//     q.arr[q.rear] = p;
// }

// // Dequeue package
// Package dequeuePackage(Queue &q)
// {
//     Package p{-1, "", 0, 0.0}; // default package if empty

//     if (isQueueEmpty(q))
//     {
//         cout << "Delivery Queue Empty\n";
//         return p;
//     }

//     p = q.arr[q.front];

//     if (q.front == q.rear)
//         q.front = q.rear = -1;
//     else
//         q.front = (q.front + 1) % MAX;

//     return p;
// }

// /* ===================== STACK (DELIVERY HISTORY) ===================== */
// struct Stack
// {
//     Package arr[MAX];
//     int top;
// };

// // Initialize stack
// void initStack(Stack &s)
// {
//     s.top = -1;
// }

// bool isStackEmpty(const Stack &s)
// {
//     return s.top == -1;
// }

// // Push delivered package
// void pushHistory(Stack &s, const Package &p)
// {
//     if (s.top == MAX - 1)
//     {
//         cout << "History Stack Full\n";
//         return;
//     }
//     s.arr[++s.top] = p;
// }

// // Pop last delivered package
// Package popHistory(Stack &s)
// {
//     Package p{-1, "", 0, 0.0};

//     if (s.top == -1)
//         return p;
        
//     return s.arr[s.top--];
// }

// /* ===================== DELIVERY OPERATIONS ===================== */
// void executeDelivery(Queue &deliveryQueue, Stack &historyStack)
// {
//     if (isQueueEmpty(deliveryQueue))
//     {
//         cout << "No deliveries to execute\n";
//         return;
//     }

//     Package p = dequeuePackage(deliveryQueue);
//     pushHistory(historyStack, p);

//     cout << "Delivered Package ID: " << p.id << endl;
// }

// void undoDelivery(Stack &historyStack, Queue &deliveryQueue)
// {
//     if (isStackEmpty(historyStack))
//     {
//         cout << "Nothing to undo\n";
//         return;
//     }

//     Package p = popHistory(historyStack);
//     enqueuePackage(deliveryQueue, p);

//     cout << "Undo delivery of Package ID: " << p.id << endl;
// }


// // int main()
// // {
// //     Queue deliveryQueue;
// //     Stack historyStack;

// //     initQueue(deliveryQueue);
// //     initStack(historyStack);

// //     // Sample packages using full constructor
// //     enqueuePackage(deliveryQueue, Package(101, "Package A", 1, 2.5));
// //     enqueuePackage(deliveryQueue, Package(102, "Package B", 2, 1.2));
// //     enqueuePackage(deliveryQueue, Package(103, "Package C", 1, 3.0));

// //     executeDelivery(deliveryQueue, historyStack); // 101
// //     executeDelivery(deliveryQueue, historyStack); // 102
// //     undoDelivery(historyStack);                   // Undo 102
// //     executeDelivery(deliveryQueue, historyStack); // 103

// //     return 0;
// // }


#include <iostream>
#include "delivery_exe_and_history.h"

using namespace std;

// Initialize queue
void initQueue(HistoryQueue &q)
{
    q.front = q.rear = -1;
}

bool isQueueEmpty(const HistoryQueue &q)
{
    return q.front == -1;
}

bool isQueueFull(const HistoryQueue &q)
{
    return (q.rear + 1) % MAX == q.front;
}

void enqueuePackage(HistoryQueue &q, const Package &p)
{
    if (isQueueFull(q))
    {
        cout << "Delivery Queue Full\n";
        return;
    }

    if (q.front == -1)
        q.front = q.rear = 0;
    else
        q.rear = (q.rear + 1) % MAX;

    q.arr[q.rear] = p;
}

Package dequeuePackage(HistoryQueue &q)
{
    Package p{-1, "", 0, 0.0};

    if (isQueueEmpty(q))
    {
        cout << "Delivery Queue Empty\n";
        return p;
    }

    p = q.arr[q.front];

    if (q.front == q.rear)
        q.front = q.rear = -1;
    else
        q.front = (q.front + 1) % MAX;

    return p;
}

// Stack
void initStack(HistoryStack &s)
{
    s.top = -1;
}

bool isStackEmpty(const HistoryStack &s)
{
    return s.top == -1;
}

void pushHistory(HistoryStack &s, const Package &p)
{
    if (s.top == MAX - 1)
    {
        cout << "History Stack Full\n";
        return;
    }
    s.arr[++s.top] = p;
}

Package popHistory(HistoryStack &s)
{
    Package p{-1, "", 0, 0.0};
    if (s.top == -1)
        return p;

    return s.arr[s.top--];
}

// Delivery operations
void executeDelivery(HistoryQueue &deliveryQueue, HistoryStack &historyStack)
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

void undoDelivery(HistoryStack &historyStack, HistoryQueue &deliveryQueue)
{
    if (isStackEmpty(historyStack))
    {
        cout << "Nothing to undo\n";
        return;
    }

    Package p = popHistory(historyStack);
    enqueuePackage(deliveryQueue, p);

    cout << "Undo delivery of Package ID: " << p.id << endl;
}
