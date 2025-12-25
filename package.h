#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;

struct Package
{
    int id;
    string name;
    int priority;
    double weight;
    Package *left;
    Package *right;

    // Default constructor (REQUIRED for arrays)
    Package()
    {
        id = -1;
        name = "";
        priority = 0;
        weight = 0.0;
        left = right = nullptr;
    }

    // Parameterized constructor
    Package(int _id, string _name, int _priority, double _weight)
    {
        id = _id;
        name = _name;
        priority = _priority;
        weight = _weight;
        left = right = nullptr;
    }
};

#endif // PACKAGE_H
