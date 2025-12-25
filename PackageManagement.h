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


    Package(int _id, string _name, int _priority, double _weight);
};

class PackageBST
{

private:
    Package *root;

    Package *insert(Package *node, Package *pkg);

    // Recursive search
    Package *search(Package *node, int id);

    Package *minValueNode(Package *node);

    Package *remove(Package *node, int id);

    void inorder(Package *node);


public:
    PackageBST();

    void insertPackage(int id, string name, int priority, double weight);

    void searchPackage(int id);

    void deletePackage(int id);

    void displayPackages();
    

};

#endif
