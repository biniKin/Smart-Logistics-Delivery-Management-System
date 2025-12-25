#include <iostream>
#include <string>
#include "VehicleManagement.h"

using namespace std;


Vehicle::Vehicle(int _id, string _driver, bool _available){
    id = _id;
    driver = _driver;
    available = _available;
};


VehicleQueue::VehicleQueue(){
    front = -1;
    rear = -1;
};

    
bool VehicleQueue::isEmpty() {
    return (front == -1 || front > rear);
}


   
bool VehicleQueue::isFull() {
    return (rear == MAX - 1);
}
    
void VehicleQueue::addVehicle(int id, string driver) {
    if (isFull()) {
        cout << "Vehicle queue is full!\n";
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = {id, driver, true};
    cout << "Vehicle " << id << " added.\n";
}

   
void VehicleQueue::assignVehicle() {
    if (isEmpty()) {
        cout << "No vehicles available!\n";
        return;
    }
    Vehicle v = queue[front];
    front++;
    v.available = false;
    cout << "\nVehicle Assigned:\n";
    cout << "ID: " << v.id << ", Driver: " << v.driver << endl;
    // Simulate delivery completion
    v.available = true;
    addVehicle(v.id, v.driver);
}

    
void VehicleQueue::displayVehicles() {
    if (isEmpty()) {
        cout << "No vehicles in system.\n";
        return;
    }
    cout << "\nAvailable Vehicles:\n";
    for (int i = front; i <= rear; i++) {
        cout << "ID: " << queue[i].id
             << ", Driver: " << queue[i].driver << endl;
    }
}



// #define MAX 5


// struct Vehicle {
//     int id;
//     string driver;
//     bool available;
// };


// class VehicleQueue {
// private:
//     Vehicle queue[MAX];
//     int front;
//     int rear;

// public:
    
//     VehicleQueue() {
//         front = -1;
//         rear = -1;
//     }

    
//     bool isEmpty() {
//         return (front == -1 || front > rear);
//     }

    
//     bool isFull() {
//         return (rear == MAX - 1);
//     }

    
//     void addVehicle(int id, string driver) {
//         if (isFull()) {
//             cout << "Vehicle queue is full!\n";
//             return;
//         }

//         if (front == -1)
//             front = 0;

//         rear++;
//         queue[rear] = {id, driver, true};
//         cout << "Vehicle " << id << " added.\n";
//     }

   
//     void assignVehicle() {
//         if (isEmpty()) {
//             cout << "No vehicles available!\n";
//             return;
//         }

//         Vehicle v = queue[front];
//         front++;

//         v.available = false;

//         cout << "\nVehicle Assigned:\n";
//         cout << "ID: " << v.id << ", Driver: " << v.driver << endl;

//         // Simulate delivery completion
//         v.available = true;
//         addVehicle(v.id, v.driver);
//     }

    
//     void displayVehicles() {
//         if (isEmpty()) {
//             cout << "No vehicles in system.\n";
//             return;
//         }

//         cout << "\nAvailable Vehicles:\n";
//         for (int i = front; i <= rear; i++) {
//             cout << "ID: " << queue[i].id
//                  << ", Driver: " << queue[i].driver << endl;
//         }
//     }
// };


// int main() {
//     VehicleQueue vm;

//     vm.addVehicle(101, "Amen");
//     vm.addVehicle(102, "Amir");
//     vm.addVehicle(103, "Degaga");

//     vm.displayVehicles();

//     vm.assignVehicle();
//     vm.assignVehicle();

//     vm.displayVehicles();

//     return 0;
// }
