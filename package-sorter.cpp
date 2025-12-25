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


#include <iostream>
#include "PackageManagement.h"
using namespace std;
struct Node
{
    Package data;
    Node *left;
    Node *right;

    Node(Package p)
    {
        data = p;
        left = right = nullptr;
    }
};

// ---------- INSERT INTO BST ----------
Node* insertBST(Node* root, Package p)
{
    if (root == nullptr)
        return new Node(p);

    // Higher priority goes to LEFT
    if (p.priority > root->data.priority)
        root->left = insertBST(root->left, p);

    // Lower priority goes to RIGHT
    else if (p.priority < root->data.priority)
        root->right = insertBST(root->right, p);

    else
    {
        // Same priority → lower weight goes LEFT
        if (p.weight < root->data.weight)
            root->left = insertBST(root->left, p);
        else
            root->right = insertBST(root->right, p);
    }

    return root;
}

// ---------- INORDER TRAVERSAL ----------
void displayBST(Node* root)
{
    if (root == nullptr)
        return;

    displayBST(root->left);

    cout << root->data.id << "\t"
         << root->data.name << "\t"
         << root->data.priority << "\t\t"
         << root->data.weight << endl;

    displayBST(root->right);
}


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
