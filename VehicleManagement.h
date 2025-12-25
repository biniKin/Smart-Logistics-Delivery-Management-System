#ifndef VEHICLE_MANAGEMENT_H
#define VEHICLE_MANAGEMENT_H

#include <iostream>
#include <string>
using namespace std;

#define MAX 5

struct Vehicle {
    int id;
    string driver;
    bool available;
    Vehicle():id(0), driver(""), available(true){};
    Vehicle(int _id, string _driver, bool _available);
};

class VehicleQueue {
private:
    Vehicle queue[MAX];
    int front;
    int rear;

public:
    VehicleQueue();
    bool isEmpty();
    bool isFull();
    void addVehicle(int id, std::string driver);
    void assignVehicle();
    void displayVehicles();
};

#endif
