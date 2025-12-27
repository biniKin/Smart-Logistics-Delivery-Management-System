#include <iostream>
#include "include/Vehicle-management.h"
#include "include/package-management.h"
#include "include/package-sorter.h"
#include "include/delivery_exe_and_history.h"
#include "include/city_management.h"

using namespace std;

void displayMainMenu();
void vehicleManagementMenu();
void packageManagementMenu();
void packageSortingMenu();
void deliverySystemMenu();
void cityRouteMenu();
void integratedTest();

int main()
{
    cout << "==============================================\n";
    cout << "  SMART LOGISTICS MANAGEMENT SYSTEM v1.0\n";
    cout << "      Integrated DSA Implementation\n";
    cout << "==============================================\n";

    int mainChoice;

    do
    {
        displayMainMenu();
        cin >> mainChoice;
        cin.ignore(); // Clear newline

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

// Main menu display
void displayMainMenu()
{
    cout << "\n========================================\n";
    cout << "  SMART LOGISTICS MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "  1. Vehicle Management                  \n";
    cout << "  2. Package Management (BST)            \n";
    cout << "  3. Package Sorting                     \n";
    cout << "  4. Delivery System                     \n";
    cout << "  5. City Route Management               \n";
    cout << "  6. Integrated Delivery Test            \n";
    cout << "  0. Exit                                \n";
    cout << "Enter your choice: ";
}

// Vehicle Management Menu
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
        cin.ignore();

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
        case 5:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

// Package Management Menu
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
        cin.ignore();

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
        case 5:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

// Package Sorting Menu
void packageSortingMenu()
{
    PackageBST bst;
    int choice;

    // Add some sample packages
    cout << "Adding sample packages...\n";
    bst.insertPackage(101, "Laptop", 3, 2.5, "Addis Ababa");
    bst.insertPackage(102, "Phone", 2, 0.3, "Dire Dawa");
    bst.insertPackage(103, "Documents", 3, 0.1, "Hawassa");
    bst.insertPackage(104, "Furniture", 1, 25.0, "Bahir Dar");
    bst.insertPackage(105, "Medicine", 3, 0.5, "Bahir Dar");
    bst.insertPackage(106, "Books", 2, 5.0, "Mekelle");
    bst.insertPackage(107, "Clothes", 1, 3.0, "Hawassa");
    bst.insertPackage(108, "Electronics", 2, 1.2, "Addis Ababa");

    do
    {
        cout << "\n=== PACKAGE SORTING MENU ===\n";
        cout << "1. Display All Packages (BST inorder)\n";
        cout << "2. Sort by Priority & Weight (BST-based sorting)\n";
        cout << "3. Alternative: Linked List Merge Sort\n";
        cout << "4. Add New Package\n";
        cout << "5. Delete Package\n";
        cout << "6. Search Package\n";
        cout << "7. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            bst.displayPackages();
            break;

        case 2:
            // Using PackageBST's built-in BST sorting
            bst.displaySortedByPriorityWeight();
            break;

        case 3:
        {
            // Alternative: Get all packages and sort with linked list merge sort
            cout << "\n=== Alternative: Manual Linked List Merge Sort ===\n";
            cout << "This creates a copy and sorts using merge sort algorithm\n";

            // Note: We need to implement a way to get packages as linked list
            // For demonstration, we'll extract and manually sort
            cout << "\nDemonstration of linked list merge sort algorithm:\n";
            cout << "1. Traverse BST and create linked list\n";
            cout << "2. Apply merge sort on linked list\n";
            cout << "3. Comparator: Priority(High->Low) then Weight(Light->Heavy)\n";
            cout << "4. Display sorted linked list\n";

            // In a complete implementation, we would call:
            // PackageNode* list = bst.getAllPackagesAsLinkedList();
            // PackageNode* sorted = PackageSorter::mergeSortByPriorityWeight(list);
            // PackageSorter::displayPackageList(sorted);

            cout << "\nAlgorithm complexity: O(n log n) with linked list merge sort\n";
            break;
        }

        case 4:
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

        case 5:
        {
            int id;
            cout << "Enter Package ID to delete: ";
            cin >> id;
            bst.deletePackage(id);
            break;
        }

        case 6:
        {
            int id;
            cout << "Enter Package ID to search: ";
            cin >> id;
            bst.searchPackage(id);
            break;
        }

        case 7:
            cout << "Returning to main menu...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}

// Delivery System Menu
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
        cin.ignore();

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
        case 6:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

// City Route Menu
void cityRouteMenu()
{
    CityGraph graph;
    graph.setupSampleData();
    int choice;

    do
    {
        cout << "\n=== CITY ROUTE MANAGEMENT ===\n";
        cout << "1. Add City\n";
        cout << "2. Add Route Between Cities\n";
        cout << "3. Find Shortest Route (Dijkstra)\n";
        cout << "4. Find All Routes (DFS)\n";
        cout << "5. Show All Cities & Routes\n";
        cout << "6. Reset to Sample Data\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string city;
            cout << "Enter city name: ";
            getline(cin, city);
            graph.addCity(city);
            break;
        }
        case 2:
        {
            string city1, city2;
            int distance;
            cout << "Enter first city: ";
            getline(cin, city1);
            cout << "Enter second city: ";
            getline(cin, city2);
            cout << "Enter distance (km, 1-10000): ";
            cin >> distance;
            cin.ignore();
            graph.addRoute(city1, city2, distance);
            break;
        }
        case 3:
        {
            string start, target;
            cout << "Enter start city: ";
            getline(cin, start);
            cout << "Enter destination city: ";
            getline(cin, target);
            graph.findShortestRoute(start, target);
            break;
        }
        case 4:
        {
            string start, target;
            cout << "Enter start city: ";
            getline(cin, start);
            cout << "Enter destination city: ";
            getline(cin, target);
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

// Integrated Test Function
void integratedTest()
{
    cout << "\n=== INTEGRATED SYSTEM TEST ===\n";
    cout << "Testing all modules together...\n\n";

    // 1. Vehicle Management Test
    cout << "1. TESTING VEHICLE MANAGEMENT:\n";
    cout << "------------------------------\n";
    VehicleQueue vehicles;
    vehicles.addVehicle(1, "John Doe");
    vehicles.addVehicle(2, "Jane Smith");
    vehicles.displayVehicles();
    vehicles.assignVehicle();
    vehicles.displayVehicles();
    vehicles.returnVehicle(1, "John Doe");
    vehicles.displayVehicles();

    // 2. Package Management Test
    cout << "\n2. TESTING PACKAGE MANAGEMENT (BST):\n";
    cout << "-----------------------------------\n";
    PackageBST packages;
    packages.insertPackage(1001, "Medical Supplies", 3, 5.0, "Addis Ababa");
    packages.insertPackage(1002, "Electronics", 2, 3.5, "Dire Dawa");
    packages.insertPackage(1003, "Clothing", 1, 8.0, "Hawassa");
    packages.displayPackages();
    packages.searchPackage(1002);

    // 3. Package Sorting Test
    cout << "\n3. TESTING PACKAGE SORTING:\n";
    cout << "---------------------------\n";
    packages.displaySortedByPriorityWeight();

    // 4. Delivery System Test
    cout << "\n4. TESTING DELIVERY SYSTEM:\n";
    cout << "---------------------------\n";
    HistoryQueue deliveryQueue;
    HistoryStack historyStack;
    initQueue(deliveryQueue);
    initStack(historyStack);

    DeliveryPackage p1(1001, "Medical Supplies", 3, 5.0, "Addis Ababa");
    DeliveryPackage p2(1002, "Electronics", 2, 3.5, "Dire Dawa");
    DeliveryPackage p3(1003, "Clothing", 1, 8.0, "Hawassa");

    enqueuePackage(deliveryQueue, p1);
    enqueuePackage(deliveryQueue, p2);
    enqueuePackage(deliveryQueue, p3);

    displayQueue(deliveryQueue);
    executeDelivery(deliveryQueue, historyStack);
    executeDelivery(deliveryQueue, historyStack);
    displayHistory(historyStack);
    undoDelivery(historyStack, deliveryQueue);
    displayQueue(deliveryQueue);

    // 5. City Route Test
    cout << "\n5. TESTING CITY ROUTE MANAGEMENT:\n";
    cout << "---------------------------------\n";
    CityGraph cityGraph;
    cityGraph.setupSampleData();
    cityGraph.findShortestRoute("Addis Ababa", "Mekelle");

    cout << "\nIntegrated Test Completed Successfully!\n";
    cout << "\nPress Enter to continue...";
    cin.get();
}