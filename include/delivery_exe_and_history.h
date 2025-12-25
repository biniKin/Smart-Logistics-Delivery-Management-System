/*#ifndef DELIVERY_EXE_AND_HISTORY_H
#define DELIVERY_EXE_AND_HISTORY_H

#include "PackageManagement.h"

#define MAX 20

struct HistoryQueue
{
    Package arr[MAX];
    int front;
    int rear;
};

struct HistoryStack
{
    Package arr[MAX];
    int top;
};

// Queue functions
void initQueue(HistoryQueue &q);
bool isQueueEmpty(const HistoryQueue &q);
bool isQueueFull(const HistoryQueue &q);
void enqueuePackage(HistoryQueue &q, const Package &p);
Package dequeuePackage(HistoryQueue &q);

// Stack functions
void initStack(HistoryStack &s);
bool isStackEmpty(const HistoryStack &s);
void pushHistory(HistoryStack &s, const Package &p);
Package popHistory(HistoryStack &s);

// Delivery operations
void executeDelivery(HistoryQueue &deliveryQueue, HistoryStack &historyStack);
void undoDelivery(HistoryStack &historyStack, HistoryQueue &deliveryQueue);

#endif
*/
#ifndef DELIVERY_EXE_AND_HISTORY_H
#define DELIVERY_EXE_AND_HISTORY_H

#include <string>

struct DeliveryPackage
{
    int id;
    std::string name;
    int priority;
    double weight;
    std::string destination;
    std::string status;

    DeliveryPackage();
    DeliveryPackage(int _id, std::string _name, int _priority, double _weight, std::string _dest = "");
};

struct HistoryQueue
{
    DeliveryPackage arr[20];
    int front;
    int rear;
};

struct HistoryStack
{
    DeliveryPackage arr[20];
    int top;
};

// Queue functions
void initQueue(HistoryQueue &q);
bool isQueueEmpty(const HistoryQueue &q);
bool isQueueFull(const HistoryQueue &q);
void enqueuePackage(HistoryQueue &q, const DeliveryPackage &p);
DeliveryPackage dequeuePackage(HistoryQueue &q);
void displayQueue(const HistoryQueue &q);

// Stack functions
void initStack(HistoryStack &s);
bool isStackEmpty(const HistoryStack &s);
void pushHistory(HistoryStack &s, const DeliveryPackage &p);
DeliveryPackage popHistory(HistoryStack &s);
void displayHistory(const HistoryStack &s);

// Delivery operations
void executeDelivery(HistoryQueue &deliveryQueue, HistoryStack &historyStack);
void undoDelivery(HistoryStack &historyStack, HistoryQueue &deliveryQueue);

#endif