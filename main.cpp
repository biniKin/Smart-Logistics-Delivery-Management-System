// #include "PackageManagement.h"
// #include <iostream>
// using namespace std;

// int main(){
//     PackageBST packageManager;

//     packageManager.insertPackage(1, "Laptop", 1, 2.5);
//     packageManager.displayPackages();
// }

#include <iostream>
#include "PackageManagement.h"
#include "delivery_exe_and_history.h"

using namespace std;

int main()
{
    cout << "=== Smart Logistics System Test ===\n\n";

    // ---------------- PACKAGE MANAGEMENT (BST) ----------------
    PackageBST packageManager;

    cout << "Adding packages to BST...\n";
    packageManager.insertPackage(10, "Laptop", 1, 2.5);
    packageManager.insertPackage(5, "Phone", 2, 0.4);
    packageManager.insertPackage(20, "TV", 3, 8.0);

    packageManager.displayPackages();

    cout << "\nSearching for Package ID 5:\n";
    packageManager.searchPackage(5);

    cout << "\nDeleting Package ID 10\n";
    packageManager.deletePackage(10);
    packageManager.displayPackages();

    // ---------------- DELIVERY EXECUTION ----------------
    HistoryQueue deliveryQueue;
    HistoryStack historyStack;

    initQueue(deliveryQueue);
    initStack(historyStack);

    cout << "\nAdding packages to delivery queue...\n";

    // Simulated packages for delivery
    Package p1{1, "Laptop", 1, 2.5};
    Package p2{2, "Phone", 2, 0.4};
    Package p3{3, "TV", 3, 8.0};

    enqueuePackage(deliveryQueue, p1);
    enqueuePackage(deliveryQueue, p2);
    enqueuePackage(deliveryQueue, p3);

    cout << "\nExecuting deliveries...\n";
    executeDelivery(deliveryQueue, historyStack);
    executeDelivery(deliveryQueue, historyStack);

    cout << "\nUndo last delivery...\n";
    undoDelivery(historyStack, deliveryQueue);

    cout << "\nExecuting delivery again...\n";
    executeDelivery(deliveryQueue, historyStack);

    cout << "\n=== Test Completed Successfully ===\n";

    return 0;
}
