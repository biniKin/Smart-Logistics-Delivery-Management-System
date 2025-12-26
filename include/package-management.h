#ifndef PACKAGE_MANAGEMENT_H
#define PACKAGE_MANAGEMENT_H

#include <iostream>
#include <string>

struct Package
{
    int id;
    std::string name;
    int priority;
    double weight;
    std::string destination;
    Package *left;
    Package *right;

    Package();
    Package(int _id, std::string _name, int _priority, double _weight, std::string _dest = "");
};

// Linked list node for package traversal
struct PackageNode
{
    Package *package;
    PackageNode *next;

    PackageNode(Package *pkg) : package(pkg), next(nullptr) {}
};

// BST node for priority/weight sorting
struct PriorityWeightNode
{
    Package *package;
    PriorityWeightNode *left;
    PriorityWeightNode *right;

    PriorityWeightNode(Package *pkg) : package(pkg), left(nullptr), right(nullptr) {}
};

class PackageBST
{
private:
    Package *root;
    PackageNode *packageListHead; // Linked list of all packages

    Package *insert(Package *node, Package *pkg);
    Package *search(Package *node, int id) const;
    Package *minValueNode(Package *node);
    Package *remove(Package *node, int id);
    void inorder(Package *node) const;
    void clear(Package *node);

    // Linked list management
    void addToPackageList(Package *pkg);
    void removeFromPackageList(int id);
    void clearPackageList();

    // BST for priority/weight sorting
    PriorityWeightNode *insertPriorityWeight(PriorityWeightNode *node, Package *pkg) const;
    void inorderPriorityWeight(PriorityWeightNode *node, PackageNode *&head, PackageNode *&tail) const;
    void clearPriorityWeight(PriorityWeightNode *node) const;

public:
    PackageBST();
    ~PackageBST();

    void insertPackage(int id, std::string name, int priority, double weight, std::string dest = "");
    bool searchPackage(int id) const;
    void deletePackage(int id);
    void displayPackages() const;
    Package *getPackage(int id) const;

    // BST-based sorting without vectors
    PackageNode *getSortedByPriorityWeight() const;
    void displaySortedByPriorityWeight() const;

    PackageBST(const PackageBST &) = delete;
    PackageBST &operator=(const PackageBST &) = delete;
};

#endif