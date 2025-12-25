// Include guards (MANDATORY)

#ifndef PACKAGE_MANAGEMENT_H
#define PACKAGE_MANAGEMENT_H

#include<iostream>
#include<string>

using namespace std;

struct Package
{
    /* data */
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
