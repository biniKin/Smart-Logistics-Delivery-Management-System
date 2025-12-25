#include <iostream>
#include "include/package-management.h"

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
    packageListHead = nullptr;
}

PackageBST::~PackageBST()
{
    clear(root);
    clearPackageList();
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

// Linked list management
void PackageBST::addToPackageList(Package *pkg)
{
    PackageNode *newNode = new PackageNode(pkg);
    if (!packageListHead)
    {
        packageListHead = newNode;
    }
    else
    {
        PackageNode *current = packageListHead;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void PackageBST::removeFromPackageList(int id)
{
    if (!packageListHead)
        return;

    if (packageListHead->package->id == id)
    {
        PackageNode *temp = packageListHead;
        packageListHead = packageListHead->next;
        delete temp;
        return;
    }

    PackageNode *current = packageListHead;
    while (current->next && current->next->package->id != id)
    {
        current = current->next;
    }

    if (current->next)
    {
        PackageNode *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void PackageBST::clearPackageList()
{
    PackageNode *current = packageListHead;
    while (current)
    {
        PackageNode *temp = current;
        current = current->next;
        delete temp;
    }
    packageListHead = nullptr;
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
    addToPackageList(newPackage); // Add to linked list
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
        removeFromPackageList(id); // Remove from linked list
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

    cout << "\n=== All Packages (Sorted by ID - BST Inorder) ===\n";
    inorder(root);

    // Also display using linked list
    cout << "\n=== All Packages (Linked List Traversal) ===\n";
    PackageNode *current = packageListHead;
    int count = 0;
    while (current)
    {
        cout << ++count << ". ID: " << current->package->id
             << ", Name: " << current->package->name
             << ", Priority: " << current->package->priority
             << ", Weight: " << current->package->weight << " kg";
        if (!current->package->destination.empty())
            cout << ", Destination: " << current->package->destination;
        cout << "\n";
        current = current->next;
    }
}

// ==================== BST-BASED SORTING BY PRIORITY/WEIGHT ====================

// Comparator for BST insertion: higher priority first, then lighter weight
PriorityWeightNode *PackageBST::insertPriorityWeight(PriorityWeightNode *node, Package *pkg) const
{
    if (!node)
        return new PriorityWeightNode(pkg);

    // Compare by priority (higher priority first)
    if (pkg->priority > node->package->priority)
    {
        node->left = insertPriorityWeight(node->left, pkg);
    }
    else if (pkg->priority < node->package->priority)
    {
        node->right = insertPriorityWeight(node->right, pkg);
    }
    else
    {
        // Same priority: compare by weight (lighter weight first)
        if (pkg->weight < node->package->weight)
        {
            node->left = insertPriorityWeight(node->left, pkg);
        }
        else
        {
            node->right = insertPriorityWeight(node->right, pkg);
        }
    }

    return node;
}

// Inorder traversal of priority/weight BST - builds sorted linked list
void PackageBST::inorderPriorityWeight(PriorityWeightNode *node, PackageNode *&head, PackageNode *&tail) const
{
    if (!node)
        return;

    // Traverse left subtree (higher priority/lighter weight)
    inorderPriorityWeight(node->left, head, tail);

    // Add current node to linked list
    PackageNode *newNode = new PackageNode(node->package);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    // Traverse right subtree (lower priority/heavier weight)
    inorderPriorityWeight(node->right, head, tail);
}

void PackageBST::clearPriorityWeight(PriorityWeightNode *node) const
{
    if (node)
    {
        clearPriorityWeight(node->left);
        clearPriorityWeight(node->right);
        delete node;
    }
}

// Main method: Get packages sorted by priority (high to low) then weight (low to high)
PackageNode *PackageBST::getSortedByPriorityWeight() const
{
    if (!packageListHead)
        return nullptr;

    // Build BST based on priority/weight comparison
    PriorityWeightNode *priorityRoot = nullptr;

    // Traverse linked list and insert each package into priority BST
    PackageNode *current = packageListHead;
    while (current)
    {
        priorityRoot = insertPriorityWeight(priorityRoot, current->package);
        current = current->next;
    }

    // Build sorted linked list from BST inorder traversal
    PackageNode *sortedHead = nullptr;
    PackageNode *sortedTail = nullptr;
    inorderPriorityWeight(priorityRoot, sortedHead, sortedTail);

    // Clean up the temporary BST
    clearPriorityWeight(priorityRoot);

    return sortedHead;
}

void PackageBST::displaySortedByPriorityWeight() const
{
    PackageNode *sortedList = getSortedByPriorityWeight();

    if (!sortedList)
    {
        cout << "No packages to display.\n";
        return;
    }

    cout << "\n=== Packages Sorted by Priority & Weight (Pure BST-based) ===\n";
    cout << "No vectors or built-in sort used!\n";
    cout << "Using: 1. Linked List for storage\n";
    cout << "       2. BST for sorting by priority/weight\n";
    cout << "       3. Linked List for sorted output\n";
    cout << "--------------------------------------------------------------\n";
    cout << "ID\tName\t\tPriority\tWeight\tDestination\n";
    cout << "--------------------------------------------------------------\n";

    PackageNode *current = sortedList;
    int count = 0;
    while (current)
    {
        cout << current->package->id << "\t"
             << current->package->name;

        if (current->package->name.length() < 8)
            cout << "\t";
        cout << "\t" << current->package->priority << "\t\t"
             << current->package->weight << " kg\t"
             << (current->package->destination.empty() ? "-" : current->package->destination) << "\n";

        current = current->next;
        count++;
    }

    cout << "\nTotal packages sorted: " << count << "\n";

    // Clean up the sorted list (it was created for display only)
    current = sortedList;
    while (current)
    {
        PackageNode *temp = current;
        current = current->next;
        delete temp;
    }

    // Show sorting criteria
    cout << "\nSorting Criteria (BST comparator):\n";
    cout << "1. Priority: Higher (3) → Lower (1) [Left subtree]\n";
    cout << "2. Weight: Lighter → Heavier [Left subtree when priority equal]\n";
}