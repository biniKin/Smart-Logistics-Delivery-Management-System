
#include <iostream>
#include "include/delivery_exe_and_history.h"

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