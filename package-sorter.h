#ifndef PACKAGE_SORTER_H
#define PACKAGE_SORTER_H

#include "PackageManagement.h"
#include <vector>
#include <algorithm>

class PackageSorter
{
public:
    static std::vector<Package> sortByPriorityWeight(const std::vector<Package> &packages);
    static void displaySortedPackages(const std::vector<Package> &packages);
    static std::vector<Package> extractAndSort(PackageBST &bst);
};

#endif