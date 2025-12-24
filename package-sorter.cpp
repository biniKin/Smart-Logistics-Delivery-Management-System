#include <iostream>
#include <vector>
using namespace std;

// SAME Package structure (without tree pointers)
struct Package
{
    int id;
    string name;
    int priority;   // Higher number = higher priority
    double weight;
};

class PackageSorter
{
private:
    vector<Package> packages;

public:
    // Add package for sorting
    void addPackage(int id, string name, int priority, double weight)
    {
        Package p;
        p.id = id;
        p.name = name;
        p.priority = priority;
        p.weight = weight;
        packages.push_back(p);
    }

    // Bubble Sort by Priority, if equal then by Weight
    void sortByPriorityAndWeight()
    {
        int n = packages.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                // Case 1: lower priority comes after higher priority
                if (packages[j].priority < packages[j + 1].priority)
                {
                    swap(packages[j], packages[j + 1]);
                }
                // Case 2: same priority, sort by weight (lighter first)
                else if (packages[j].priority == packages[j + 1].priority &&
                         packages[j].weight > packages[j + 1].weight)
                {
                    swap(packages[j], packages[j + 1]);
                }
            }
        }
        cout << "\nPackages sorted by Priority and Weight successfully.\n";
    }

    // Display packages
    void displayPackages()
    {
        if (packages.empty())
        {
            cout << "No packages available.\n";
            return;
        }

        cout << "\nID\tName\tPriority\tWeight\n";
        for (auto &p : packages)
        {
            cout << p.id << "\t"
                 << p.name << "\t"
                 << p.priority << "\t\t"
                 << p.weight << endl;
        }
    }

    // Menu for your module
    void menu()
    {
        int choice;
        do
        {
            cout << "\n--- Package Sorting Menu ---\n";
            cout << "1. Add Package\n";
            cout << "2. Sort by Priority (if equal, by Weight)\n";
            cout << "3. Display Packages\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                int id, priority;
                double weight;
                string name;

                cout << "Enter Package ID: ";
                cin >> id;
                cout << "Enter Package Name: ";
                cin >> name;
                cout << "Enter Priority (3=High, 2=Medium, 1=Low): ";
                cin >> priority;
                cout << "Enter Weight: ";
                cin >> weight;

                addPackage(id, name, priority, weight);
            }
            else if (choice == 2)
            {
                sortByPriorityAndWeight();
            }
            else if (choice == 3)
            {
                displayPackages();
            }
            else if (choice == 4)
            {
                cout << "Exiting sorting module...\n";
            }
            else
            {
                cout << "Invalid choice!\n";
            }

        } while (choice != 4);
    }
};