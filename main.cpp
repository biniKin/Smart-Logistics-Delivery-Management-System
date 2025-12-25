/* // #include "PackageManagement.h"
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
*/
#include <iostream>
#include "VehicleManagement.h"
#include "PackageManagement.h"
#include "PackageSorter.h"
#include "delivery_exe_and_history.h"
#include "city_graph.h"

using namespace std;

void displayMainMenu()
{
    cout << "\n╔══════════════════════════════════════════╗\n";
    cout << "║     SMART LOGISTICS MANAGEMENT SYSTEM   ║\n";
    cout << "╚══════════════════════════════════════════╝\n";
    cout << "┌──────────────────────────────────────────┐\n";
    cout << "│  1. Vehicle Management                  │\n";
    cout << "│  2. Package Management (BST)            │\n";
    cout << "│  3. Package Sorting                     │\n";
    cout << "│  4. Delivery System                     │\n";
    cout << "│  5. City Route Management               │\n";
    cout << "│  6. Integrated Delivery Test            │\n";
    cout << "│  0. Exit                                │\n";
    cout << "└──────────────────────────────────────────┘\n";
    cout << "Enter your choice: ";
}

void vehicleManagementMenu()
{
    VehicleQueue vm;
    int choice;

    do
    {
        cout << "\n=== VEHICLE MANAGEMENT ===\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Assign Vehicle\n";
        cout << "3. Return Vehicle\n";
        cout << "4. Display Vehicles\n";
        cout << "5. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string driver;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Driver Name: ";
            cin.ignore();
            getline(cin, driver);
            vm.addVehicle(id, driver);
            break;
        }
        case 2:
            vm.assignVehicle();
            break;
        case 3:
        {
            int id;
            string driver;
            cout << "Enter Vehicle ID to return: ";
            cin >> id;
            cout << "Enter Driver Name: ";
            cin.ignore();
            getline(cin, driver);
            vm.returnVehicle(id, driver);
            break;
        }
        case 4:
            vm.displayVehicles();
            break;
        }
    } while (choice != 5);
}

void packageManagementMenu()
{
    PackageBST bst;
    int choice;

    do
    {
        cout << "\n=== PACKAGE MANAGEMENT (BST) ===\n";
        cout << "1. Add Package\n";
        cout << "2. Search Package\n";
        cout << "3. Delete Package\n";
        cout << "4. Display All Packages\n";
        cout << "5. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, priority;
            double weight;
            string name, dest;
            cout << "Enter Package ID: ";
            cin >> id;
            cout << "Enter Package Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Priority (1-3, 3=Highest): ";
            cin >> priority;
            cout << "Enter Weight (kg): ";
            cin >> weight;
            cout << "Enter Destination (optional): ";
            cin.ignore();
            getline(cin, dest);
            bst.insertPackage(id, name, priority, weight, dest);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter Package ID to search: ";
            cin >> id;
            bst.searchPackage(id);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter Package ID to delete: ";
            cin >> id;
            bst.deletePackage(id);
            break;
        }
        case 4:
            bst.displayPackages();
            break;
        }
    } while (choice != 5);
}

void packageSortingMenu()
{
    PackageBST bst;
    int choice;

    // Add some sample packages
    bst.insertPackage(101, "Laptop", 3, 2.5, "Addis Ababa");
    bst.insertPackage(102, "Phone", 2, 0.3, "Dire Dawa");
    bst.insertPackage(103, "Documents", 3, 0.1, "Hawassa");
    bst.insertPackage(104, "Furniture", 1, 25.0, "Bahir Dar");

    do
    {
        cout << "\n=== PACKAGE SORTING ===\n";
        cout << "1. Display Original Packages\n";
        cout << "2. Sort by Priority & Weight\n";
        cout << "3. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bst.displayPackages();
            break;
        case 2:
        {
            vector<Package> sorted = PackageSorter::extractAndSort(bst);
            PackageSorter::displaySortedPackages(sorted);
            break;
        }
        }
    } while (choice != 3);
}

void deliverySystemMenu()
{
    HistoryQueue deliveryQueue;
    HistoryStack historyStack;
    initQueue(deliveryQueue);
    initStack(historyStack);

    int choice;

    do
    {
        cout << "\n=== DELIVERY SYSTEM ===\n";
        cout << "1. Add Package to Delivery Queue\n";
        cout << "2. Execute Delivery\n";
        cout << "3. Undo Last Delivery\n";
        cout << "4. Show Delivery Queue\n";
        cout << "5. Show Delivery History\n";
        cout << "6. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            DeliveryPackage p;
            cout << "Enter Package ID: ";
            cin >> p.id;
            cout << "Enter Package Name: ";
            cin.ignore();
            getline(cin, p.name);
            cout << "Enter Priority: ";
            cin >> p.priority;
            cout << "Enter Weight: ";
            cin >> p.weight;
            cout << "Enter Destination: ";
            cin.ignore();
            getline(cin, p.destination);
            enqueuePackage(deliveryQueue, p);
            break;
        }
        case 2:
            executeDelivery(deliveryQueue, historyStack);
            break;
        case 3:
            undoDelivery(historyStack, deliveryQueue);
            break;
        case 4:
            displayQueue(deliveryQueue);
            break;
        case 5:
            displayHistory(historyStack);
            break;
        }
    } while (choice != 6);
}

void cityRouteMenu()
{
    CityGraph graph;
    graph.setupSampleData();
    int choice;

    do
    {
        CityGraph::displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string city = CityGraph::getStringInput("Enter city name: ");
            graph.addCity(city);
            break;
        }
        case 2:
        {
            string city1 = CityGraph::getStringInput("Enter first city: ");
            string city2 = CityGraph::getStringInput("Enter second city: ");
            int distance = CityGraph::getIntInput("Enter distance (km, 1-10000): ", 1, 10000);
            graph.addRoute(city1, city2, distance);
            break;
        }
        case 3:
        {
            string start = CityGraph::getStringInput("Enter start city: ");
            string target = CityGraph::getStringInput("Enter destination city: ");
            graph.findShortestRoute(start, target);
            break;
        }
        case 4:
        {
            string start = CityGraph::getStringInput("Enter start city: ");
            string target = CityGraph::getStringInput("Enter destination city: ");
            graph.findAllRoutes(start, target);
            break;
        }
        case 5:
            graph.showAllCities();
            break;
        case 6:
            graph.setupSampleData();
            break;
        case 0:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

        if (choice != 0)
        {
            cout << "\nPress Enter to continue...";
            cin.get();
        }

    } while (choice != 0);
}

void integratedTest()
{
    cout << "\n=== INTEGRATED SYSTEM TEST ===\n";

    // 1. Vehicle Management
    cout << "\n1. Testing Vehicle Management...\n";
    VehicleQueue vehicles;
    vehicles.addVehicle(1, "John Doe");
    vehicles.addVehicle(2, "Jane Smith");
    vehicles.displayVehicles();

    // 2. Package Management
    cout << "\n2. Testing Package Management (BST)...\n";
    PackageBST packages;
    packages.insertPackage(1001, "Medical Supplies", 3, 5.0, "Addis Ababa");
    packages.insertPackage(1002, "Electronics", 2, 3.5, "Dire Dawa");
    packages.insertPackage(1003, "Clothing", 1, 8.0, "Hawassa");
    packages.displayPackages();

    // 3. Package Sorting
    cout << "\n3. Testing Package Sorting...\n";
    vector<Package> sorted = PackageSorter::extractAndSort(packages);
    PackageSorter::displaySortedPackages(sorted);

    // 4. Delivery System
    cout << "\n4. Testing Delivery System...\n";
    HistoryQueue deliveryQueue;
    HistoryStack historyStack;
    initQueue(deliveryQueue);
    initStack(historyStack);

    DeliveryPackage p1(1001, "Medical Supplies", 3, 5.0, "Addis Ababa");
    DeliveryPackage p2(1002, "Electronics", 2, 3.5, "Dire Dawa");

    enqueuePackage(deliveryQueue, p1);
    enqueuePackage(deliveryQueue, p2);

    executeDelivery(deliveryQueue, historyStack);
    executeDelivery(deliveryQueue, historyStack);
    undoDelivery(historyStack, deliveryQueue);

    cout << "\n✅ Integrated Test Completed Successfully!\n";
}

int main()
{
    cout << "==============================================\n";
    cout << "   SMART LOGISTICS MANAGEMENT SYSTEM v2.0\n";
    cout << "       Integrated DSA Implementation\n";
    cout << "==============================================\n";

    int mainChoice;

    do
    {
        displayMainMenu();
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            vehicleManagementMenu();
            break;
        case 2:
            packageManagementMenu();
            break;
        case 3:
            packageSortingMenu();
            break;
        case 4:
            deliverySystemMenu();
            break;
        case 5:
            cityRouteMenu();
            break;
        case 6:
            integratedTest();
            break;
        case 0:
            cout << "\nThank you for using Smart Logistics System!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (mainChoice != 0);

    return 0;
}