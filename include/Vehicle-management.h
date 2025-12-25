
#ifndef VEHICLE_MANAGEMENT_H
#define VEHICLE_MANAGEMENT_H

#include <iostream>
#include <string>

const int MAX_VEHICLES = 5;

struct Vehicle
{
    int id;
    std::string driver;
    bool available;

    Vehicle() : id(0), driver(""), available(true) {}
    Vehicle(int _id, std::string _driver, bool _available = true);
};

class VehicleQueue
{
private:
    Vehicle queue[MAX_VEHICLES];
    int front;
    int rear;

public:
    VehicleQueue();
    bool isEmpty();
    bool isFull();
    void addVehicle(int id, std::string driver);
    void assignVehicle();
    void returnVehicle(int id, std::string driver);
    void displayVehicles();
    int getAvailableCount();
};

#endif