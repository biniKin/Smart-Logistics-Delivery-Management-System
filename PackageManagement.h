// Include guards (MANDATORY)
/*
#ifndef PACKAGE_MANAGEMENT_H
#define PACKAGE_MANAGEMENT_H

#include<iostream>
#include<string>

using namespace std;

struct Package
{
    /* data
    int id;
    string name;
    int priority;
    double weight;
    Package *left;
    Package *right;

    Package()
    {
        id = -1;
        name = "";
        priority = 0;
        weight = 0.0;
        left = right = nullptr;
    }

    Package(int _id, string _name, int _priority, double _weight);
};

class PackageBST
{

private:


    Package *insert(Package *node, Package *pkg);

    // Recursive search
    Package *search(Package *node, int id);

    Package *minValueNode(Package *node);

    Package *remove(Package *node, int id);

    void inorder(Package *node);


public:
    Package *root;
    PackageBST();

    void insertPackage(int id, string name, int priority, double weight);

    void searchPackage(int id);

    void deletePackage(int id);

    void displayPackages();


};

#endif
*/
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

class PackageBST
{
private:
    Package *root;

    Package *insert(Package *node, Package *pkg);
    Package *search(Package *node, int id) const;
    Package *minValueNode(Package *node);
    Package *remove(Package *node, int id);
    void inorder(Package *node) const;
    void clear(Package *node);
    void extractToVector(Package *node, std::vector<Package> &packages) const;

public:
    PackageBST();
    ~PackageBST();

    void insertPackage(int id, std::string name, int priority, double weight, std::string dest = "");
    bool searchPackage(int id) const;
    void deletePackage(int id);
    void displayPackages() const;
    Package *getPackage(int id) const;
    std::vector<Package> getAllPackages() const;
    Package *getRoot() const { return root; }

    // Disable copy constructor and assignment
    PackageBST(const PackageBST &) = delete;
    PackageBST &operator=(const PackageBST &) = delete;
};

#endif