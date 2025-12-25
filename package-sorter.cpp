// #include <iostream>
// #include <vector>
// using namespace std;

// // Same Package structure (without BST pointers)
// struct Package
// {
//     int id;
//     string name;
//     int priority;
//     double weight;
// };

// // ---------- MERGE FUNCTION ----------
// void merge(vector<Package> &arr, int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     vector<Package> L(n1), R(n2);

//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     int i = 0, j = 0, k = left;

//     while (i < n1 && j < n2)
//     {
//         // Priority comparison (High to Low)
//         if (L[i].priority > R[j].priority)
//         {
//             arr[k++] = L[i++];
//         }
//         else if (L[i].priority < R[j].priority)
//         {
//             arr[k++] = R[j++];
//         }
//         else
//         {
//             // If priority is equal → sort by weight (Low to High)
//             if (L[i].weight < R[j].weight)
//                 arr[k++] = L[i++];
//             else
//                 arr[k++] = R[j++];
//         }
//     }

//     while (i < n1)
//         arr[k++] = L[i++];

//     while (j < n2)
//         arr[k++] = R[j++];
// }

// // ---------- MERGE SORT ----------
// void mergeSort(vector<Package> &arr, int left, int right)
// {
//     if (left < right)
//     {
//         int mid = (left + right) / 2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// // ---------- DISPLAY ----------
// void display(const vector<Package> &packages)
// {
//     cout << "\nID\tName\tPriority\tWeight\n";
//     for (auto &p : packages)
//     {
//         cout << p.id << "\t" << p.name << "\t"
//              << p.priority << "\t\t" << p.weight << endl;
//     }
// }

/*#include <vector>
#include <iostream>
#include "PackageManagement.h"
using namespace std;

// Function to extract packages from BST
void extractPackages(Package* node, vector<Package>& packages) {
    if (!node) return;
    extractPackages(node->left, packages);
    packages.push_back(*node);
    extractPackages(node->right, packages);
}

// Merge function for priority -> weight
void merge(vector<Package>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Package> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].priority > R[j].priority)
            arr[k++] = L[i++];
        else if (L[i].priority < R[j].priority)
            arr[k++] = R[j++];
        else
            arr[k++] = (L[i].weight < R[j].weight) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<Package>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// Display sorted packages
void displayPackagesSorted(PackageBST& bst) {
    vector<Package> packages;
    extractPackages(bst.root, packages);  // root should be public or use a getter
    mergeSort(packages, 0, packages.size()-1);

    cout << "\nID\tName\tPriority\tWeight\n";
    for (auto &p : packages)
        cout << p.id << "\t" << p.name << "\t" << p.priority << "\t\t" << p.weight << endl;
}

*/
// // ---------- MAIN (MENU) ----------
// int main()
// {
//     vector<Package> packages;
//     int choice;

//     do
//     {
//         cout << "\n--- Package Sorting Menu (Member 4) ---\n";
//         cout << "1. Add Package\n";
//         cout << "2. Sort Packages (Priority -> Weight)\n";
//         cout << "3. Display Packages\n";
//         cout << "4. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         if (choice == 1)
//         {
//             Package p;
//             cout << "Enter Package ID: ";
//             cin >> p.id;
//             cout << "Enter Package Name: ";
//             cin >> p.name;
//             cout << "Enter Priority (1-Low, 2-Medium, 3-High): ";
//             cin >> p.priority;
//             cout << "Enter Weight: ";
//             cin >> p.weight;

//             packages.push_back(p);
//         }
//         else if (choice == 2)
//         {
//             if (!packages.empty())
//             {
//                 mergeSort(packages, 0, packages.size() - 1);
//                 cout << "\nPackages sorted successfully.\n";
//             }
//             else
//             {
//                 cout << "\nNo packages to sort.\n";
//             }
//         }
//         else if (choice == 3)
//         {
//             display(packages);
//         }

//     } while (choice != 4);

//     return 0;
// }
#include <iostream>
#include <vector>
#include "PackageSorter.h"
#include "PackageManagement.h"

using namespace std;

vector<Package> PackageSorter::sortByPriorityWeight(const vector<Package> &packages)
{
    vector<Package> sorted = packages;

    // Sort by priority (high to low), then by weight (low to high)
    sort(sorted.begin(), sorted.end(), [](const Package &a, const Package &b)
         {
             if (a.priority != b.priority)
                 return a.priority > b.priority; // Higher priority first
             return a.weight < b.weight;         // Lighter weight first if same priority
         });

    return sorted;
}

void PackageSorter::displaySortedPackages(const vector<Package> &packages)
{
    if (packages.empty())
    {
        cout << "No packages to display.\n";
        return;
    }

    cout << "\n=== Packages Sorted by Priority & Weight ===\n";
    cout << "ID\tName\t\tPriority\tWeight\tDestination\n";
    cout << "--------------------------------------------------------------\n";

    for (const auto &pkg : packages)
    {
        cout << pkg.id << "\t"
             << pkg.name;

        if (pkg.name.length() < 8)
            cout << "\t";
        cout << "\t" << pkg.priority << "\t\t"
             << pkg.weight << " kg\t"
             << (pkg.destination.empty() ? "-" : pkg.destination) << "\n";
    }
}

vector<Package> PackageSorter::extractAndSort(PackageBST &bst)
{
    vector<Package> packages = bst.getAllPackages();
    return sortByPriorityWeight(packages);
}