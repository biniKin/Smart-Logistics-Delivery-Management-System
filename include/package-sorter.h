#ifndef PACKAGE_SORTER_H
#define PACKAGE_SORTER_H

#include "package-management.h"

class PackageSorter
{
public:
    // Display sorted packages using PackageBST's BST-based sorting
    static void displaySortedPackages(PackageBST &bst);

    // Alternative: Manual linked list merge sort (without vectors)
    static PackageNode *mergeSortByPriorityWeight(PackageNode *head);
    static PackageNode *merge(PackageNode *left, PackageNode *right);
    static void displayPackageList(PackageNode *head);
};

#endif