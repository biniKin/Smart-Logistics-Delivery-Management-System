#include <iostream>
#include "include/package-sorter.h"

using namespace std;

void PackageSorter::displaySortedPackages(PackageBST &bst)
{
    bst.displaySortedByPriorityWeight();
}

// Split linked list into two halves
PackageNode *split(PackageNode *head)
{
    PackageNode *slow = head;
    PackageNode *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    PackageNode *mid = slow->next;
    slow->next = nullptr;
    return mid;
}

PackageNode *PackageSorter::merge(PackageNode *left, PackageNode *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    PackageNode *result = nullptr;

    // Compare by priority (higher first), then by weight (lighter first)
    bool leftFirst = false;
    if (left->package->priority > right->package->priority)
    {
        leftFirst = true;
    }
    else if (left->package->priority == right->package->priority)
    {
        if (left->package->weight < right->package->weight)
        {
            leftFirst = true;
        }
    }

    if (leftFirst)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

PackageNode *PackageSorter::mergeSortByPriorityWeight(PackageNode *head)
{
    if (!head || !head->next)
        return head;

    PackageNode *mid = split(head);

    PackageNode *left = mergeSortByPriorityWeight(head);
    PackageNode *right = mergeSortByPriorityWeight(mid);

    return merge(left, right);
}

void PackageSorter::displayPackageList(PackageNode *head)
{
    if (!head)
    {
        cout << "No packages to display.\n";
        return;
    }

    cout << "\n=== Sorted Package List (Merge Sort) ===\n";
    cout << "ID\tName\t\tPriority\tWeight\tDestination\n";
    cout << "--------------------------------------------------------------\n";

    PackageNode *current = head;
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
    }
}
