/*#include <iostream>
#include "PackageManagement.h"
using namespace std;


Package::Package(int _id, string _name, int _priority, double _weight)
{
    id = _id;
    name = _name;
    priority = _priority;
    weight = _weight;
    left = right = nullptr;
}

PackageBST::PackageBST()
{
    root = nullptr;
}


Package* PackageBST::insert(Package *node, Package *pkg)
{
    if (!node)
        return pkg;

    if (pkg->id < node->id)
        node->left = insert(node->left, pkg);
    else if (pkg->id > node->id)
        node->right = insert(node->right, pkg);

    return node;
}


Package* PackageBST::search(Package *node, int id)
{
    if (!node || node->id == id)
        return node;

    if (id < node->id)
        return search(node->left, id);

    return search(node->right, id);
}



Package* PackageBST::minValueNode(Package *node)
{
    Package *current = node;
    while (current && current->left)
        current = current->left;
    return current;
}



Package* PackageBST::remove(Package *node, int id)
{
    if (!node)
        return node;

    if (id < node->id)
        node->left = remove(node->left, id);
    else if (id > node->id)
        node->right = remove(node->right, id);
    else
    {
        if (!node->left)
        {
            Package *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Package *temp = node->left;
            delete node;
            return temp;
        }

        Package *temp = minValueNode(node->right);
        node->id = temp->id;
        node->name = temp->name;
        node->priority = temp->priority;
        node->weight = temp->weight;
        node->right = remove(node->right, temp->id);
    }

    return node;
}



void PackageBST::inorder(Package *node)
{
    if (!node)
        return;

    inorder(node->left);
    cout << "ID: " << node->id
         << ", Name: " << node->name
         << ", Priority: " << node->priority
         << ", Weight: " << node->weight << endl;
    inorder(node->right);
}



void PackageBST::insertPackage(int id, string name, int priority, double weight)
{
    root = insert(root, new Package(id, name, priority, weight));
}

void PackageBST::searchPackage(int id)
{
    Package *pkg = search(root, id);
    if (pkg)
        cout << "Found Package: " << pkg->name << " (ID " << pkg->id << ")\n";
    else
        cout << "Package not found.\n";
}


void PackageBST::deletePackage(int id)
{
    root = remove(root, id);
}


void PackageBST::displayPackages()
{
    cout << "\nAll Packages (Inorder Traversal):\n";
    inorder(root);
}



// class PackageBST
// {
// private:
//     Package *root;

//     Package *insert(Package *node, Package *pkg)
//     {
//         if (!node)
//             return pkg;
//         if (pkg->id < node->id)
//             node->left = insert(node->left, pkg);
//         else if (pkg->id > node->id)
//             node->right = insert(node->right, pkg);
//         return node;
//     }

//     // Recursive search
//     Package *search(Package *node, int id)
//     {
//         if (!node || node->id == id)
//             return node;
//         if (id < node->id)
//             return search(node->left, id);
//         return search(node->right, id);
//     }

//     Package *minValueNode(Package *node)
//     {
//         Package *current = node;
//         while (current && current->left)
//             current = current->left;
//         return current;
//     }

//     Package *remove(Package *node, int id)
//     {
//         if (!node)
//             return node;
//         if (id < node->id)
//             node->left = remove(node->left, id);
//         else if (id > node->id)
//             node->right = remove(node->right, id);
//         else
//         {
//             if (!node->left)
//             {
//                 Package *temp = node->right;
//                 delete node;
//                 return temp;
//             }
//             else if (!node->right)
//             {
//                 Package *temp = node->left;
//                 delete node;
//                 return temp;
//             }
//             Package *temp = minValueNode(node->right);
//             node->id = temp->id;
//             node->name = temp->name;
//             node->priority = temp->priority;
//             node->weight = temp->weight;
//             node->right = remove(node->right, temp->id);
//         }
//         return node;
//     }

//     void inorder(Package *node)
//     {
//         if (!node)
//             return;
//         inorder(node->left);
//         cout << "ID: " << node->id
//              << ", Name: " << node->name
//              << ", Priority: " << node->priority
//              << ", Weight: " << node->weight << endl;
//         inorder(node->right);
//     }

// public:
//     PackageBST() { root = nullptr; }

//     void insertPackage(int id, string name, int priority, double weight)
//     {
//         root = insert(root, new Package(id, name, priority, weight));
//     }

//     void searchPackage(int id)
//     {
//         Package *pkg = search(root, id);
//         if (pkg)
//             cout << "Found Package: " << pkg->name << " (ID " << pkg->id << ")\n";
//         else
//             cout << "Package not found.\n";
//     }

//     void deletePackage(int id) { root = remove(root, id); }

//     void displayPackages()
//     {
//         cout << "\nAll Packages (Inorder Traversal):\n";
//         inorder(root);
//     }
// };




// // int main()
// // {
// //     PackageBST bst;
// //     int choice;

// //     do
// //     {
// //         cout << "\n--- Package Management ---\n";
// //         cout << "1. Add Package\n2. Search Package\n3. Delete Package\n4. Display Packages\n0. Exit\n";
// //         cout << "Enter choice: ";
// //         cin >> choice;

// //         switch (choice)
// //         {
// //         case 1:
// //         {
// //             int id, priority;
// //             double weight;
// //             string name;
// //             cout << "Enter Package ID, Name, Priority, Weight: ";
// //             cin >> id >> ws;
// //             getline(cin, name);
// //             cin >> priority >> weight;
// //             bst.insertPackage(id, name, priority, weight);
// //             break;
// //         }
// //         case 2:
// //         {
// //             int id;
// //             cout << "Enter Package ID to search: ";
// //             cin >> id;
// //             bst.searchPackage(id);
// //             break;
// //         }
// //         case 3:
// //         {
// //             int id;
// //             cout << "Enter Package ID to delete: ";
// //             cin >> id;
// //             bst.deletePackage(id);
// //             break;
// //         }
// //         case 4:
// //             bst.displayPackages();
// //             break;
// //         case 0:
// //             cout << "Exiting...\n";
// //             break;
// //         default:
// //             cout << "Invalid choice!\n";
// //         }
// //     } while (choice != 0);

// //     return 0;
// // }
*/
#include <iostream>
#include <vector>
#include "PackageManagement.h"

using namespace std;

Package::Package()
{
    id = -1;
    name = "";
    priority = 0;
    weight = 0.0;
    destination = "";
    left = right = nullptr;
}

Package::Package(int _id, string _name, int _priority, double _weight, string _dest)
{
    id = _id;
    name = _name;
    priority = _priority;
    weight = _weight;
    destination = _dest;
    left = right = nullptr;
}

PackageBST::PackageBST()
{
    root = nullptr;
}

PackageBST::~PackageBST()
{
    clear(root);
}

void PackageBST::clear(Package *node)
{
    if (node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

Package *PackageBST::insert(Package *node, Package *pkg)
{
    if (!node)
        return pkg;

    if (pkg->id < node->id)
        node->left = insert(node->left, pkg);
    else if (pkg->id > node->id)
        node->right = insert(node->right, pkg);

    return node;
}

void PackageBST::insertPackage(int id, string name, int priority, double weight, string dest)
{
    Package *newPackage = new Package(id, name, priority, weight, dest);
    root = insert(root, newPackage);
    cout << "Package " << id << " '" << name << "' added to system.\n";
}

Package *PackageBST::search(Package *node, int id) const
{
    if (!node || node->id == id)
        return node;

    if (id < node->id)
        return search(node->left, id);

    return search(node->right, id);
}

bool PackageBST::searchPackage(int id) const
{
    Package *pkg = search(root, id);
    if (pkg)
    {
        cout << "\n=== Package Found ===\n";
        cout << "ID: " << pkg->id << "\n";
        cout << "Name: " << pkg->name << "\n";
        cout << "Priority: " << pkg->priority << "\n";
        cout << "Weight: " << pkg->weight << " kg\n";
        cout << "Destination: " << (pkg->destination.empty() ? "Not set" : pkg->destination) << "\n";
        return true;
    }
    else
    {
        cout << "Package ID " << id << " not found.\n";
        return false;
    }
}

Package *PackageBST::getPackage(int id) const
{
    return search(root, id);
}

Package *PackageBST::minValueNode(Package *node)
{
    Package *current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

Package *PackageBST::remove(Package *node, int id)
{
    if (!node)
        return node;

    if (id < node->id)
        node->left = remove(node->left, id);
    else if (id > node->id)
        node->right = remove(node->right, id);
    else
    {
        if (!node->left)
        {
            Package *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Package *temp = node->left;
            delete node;
            return temp;
        }

        Package *temp = minValueNode(node->right);
        node->id = temp->id;
        node->name = temp->name;
        node->priority = temp->priority;
        node->weight = temp->weight;
        node->destination = temp->destination;
        node->right = remove(node->right, temp->id);
    }
    return node;
}

void PackageBST::deletePackage(int id)
{
    if (searchPackage(id))
    {
        root = remove(root, id);
        cout << "Package " << id << " deleted from system.\n";
    }
}

void PackageBST::inorder(Package *node) const
{
    if (!node)
        return;

    inorder(node->left);
    cout << "ID: " << node->id
         << ", Name: " << node->name
         << ", Priority: " << node->priority
         << ", Weight: " << node->weight << " kg";
    if (!node->destination.empty())
        cout << ", Destination: " << node->destination;
    cout << "\n";
    inorder(node->right);
}

void PackageBST::displayPackages() const
{
    if (!root)
    {
        cout << "No packages in system.\n";
        return;
    }

    cout << "\n=== All Packages (Sorted by ID) ===\n";
    inorder(root);
}

void PackageBST::extractToVector(Package *node, vector<Package> &packages) const
{
    if (!node)
        return;

    extractToVector(node->left, packages);
    packages.push_back(*node);
    extractToVector(node->right, packages);
}

vector<Package> PackageBST::getAllPackages() const
{
    vector<Package> packages;
    extractToVector(root, packages);
    return packages;
}