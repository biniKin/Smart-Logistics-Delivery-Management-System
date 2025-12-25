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

/*
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
*/
#include <iostream>
#include "delivery_exe_and_history.h"

using namespace std;

DeliveryPackage::DeliveryPackage()
{
    id = -1;
    name = "";
    priority = 0;
    weight = 0.0;
    destination = "";
    status = "Pending";
}

DeliveryPackage::DeliveryPackage(int _id, string _name, int _priority, double _weight, string _dest)
{
    id = _id;
    name = _name;
    priority = _priority;
    weight = _weight;
    destination = _dest;
    status = "Pending";
}

// Queue implementation
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
    return (q.rear + 1) % 20 == q.front;
}

void enqueuePackage(HistoryQueue &q, const DeliveryPackage &p)
{
    if (isQueueFull(q))
    {
        cout << "Delivery Queue is full! Cannot add more packages.\n";
        return;
    }

    if (q.front == -1)
    {
        q.front = q.rear = 0;
    }
    else
    {
        q.rear = (q.rear + 1) % 20;
    }

    q.arr[q.rear] = p;
    cout << "Package " << p.id << " '" << p.name << "' added to delivery queue.\n";
}

DeliveryPackage dequeuePackage(HistoryQueue &q)
{
    DeliveryPackage emptyPackage;

    if (isQueueEmpty(q))
    {
        cout << "Delivery Queue is empty!\n";
        return emptyPackage;
    }

    DeliveryPackage p = q.arr[q.front];

    if (q.front == q.rear)
    {
        q.front = q.rear = -1;
    }
    else
    {
        q.front = (q.front + 1) % 20;
    }

    return p;
}

void displayQueue(const HistoryQueue &q)
{
    if (isQueueEmpty(q))
    {
        cout << "Delivery queue is empty.\n";
        return;
    }

    cout << "\n=== Delivery Queue ===\n";
    cout << "Packages waiting: ";

    if (q.front <= q.rear)
    {
        for (int i = q.front; i <= q.rear; i++)
        {
            cout << q.arr[i].id << " ";
        }
    }
    else
    {
        for (int i = q.front; i < 20; i++)
        {
            cout << q.arr[i].id << " ";
        }
        for (int i = 0; i <= q.rear; i++)
        {
            cout << q.arr[i].id << " ";
        }
    }
    cout << "\n";
}

// Stack implementation
void initStack(HistoryStack &s)
{
    s.top = -1;
}

bool isStackEmpty(const HistoryStack &s)
{
    return s.top == -1;
}

bool isStackFull(const HistoryStack &s)
{
    return s.top == 19;
}

void pushHistory(HistoryStack &s, const DeliveryPackage &p)
{
    if (isStackFull(s))
    {
        cout << "History stack is full! Cannot push more.\n";
        return;
    }
    s.arr[++s.top] = p;
}

DeliveryPackage popHistory(HistoryStack &s)
{
    DeliveryPackage emptyPackage;

    if (isStackEmpty(s))
    {
        cout << "History stack is empty!\n";
        return emptyPackage;
    }

    return s.arr[s.top--];
}

void displayHistory(const HistoryStack &s)
{
    if (isStackEmpty(s))
    {
        cout << "No delivery history.\n";
        return;
    }

    cout << "\n=== Delivery History (Recent First) ===\n";
    for (int i = s.top; i >= 0; i--)
    {
        cout << "Package " << s.arr[i].id << ": " << s.arr[i].name
             << " - Status: " << s.arr[i].status << "\n";
    }
}

// Delivery operations
void executeDelivery(HistoryQueue &deliveryQueue, HistoryStack &historyStack)
{
    if (isQueueEmpty(deliveryQueue))
    {
        cout << "No packages to deliver.\n";
        return;
    }

    DeliveryPackage p = dequeuePackage(deliveryQueue);
    p.status = "Delivered";
    pushHistory(historyStack, p);

    cout << "\n✅ DELIVERY EXECUTED ✅\n";
    cout << "Package ID: " << p.id << "\n";
    cout << "Name: " << p.name << "\n";
    cout << "Weight: " << p.weight << " kg\n";
    if (!p.destination.empty())
    {
        cout << "Destination: " << p.destination << "\n";
    }
    cout << "Status: " << p.status << "\n";
}

void undoDelivery(HistoryStack &historyStack, HistoryQueue &deliveryQueue)
{
    if (isStackEmpty(historyStack))
    {
        cout << "Nothing to undo - no recent deliveries.\n";
        return;
    }

    DeliveryPackage p = popHistory(historyStack);
    p.status = "Pending";
    enqueuePackage(deliveryQueue, p);

    cout << "\n↩️ DELIVERY UNDONE ↩️\n";
    cout << "Package " << p.id << " '" << p.name << "' returned to queue.\n";
}