#include <iostream>
using namespace std;

struct Package
{
    int id;
    string name;
    int priority;
    double weight;
    Package *left;
    Package *right;

    Package(int _id, string _name, int _priority, double _weight)
    {
        id = _id;
        name = _name;
        priority = _priority;
        weight = _weight;
        left = right = nullptr;
    }
};

class PackageBST
{
private:
    Package *root;

    Package *insert(Package *node, Package *pkg)
    {
        if (!node)
            return pkg;
        if (pkg->id < node->id)
            node->left = insert(node->left, pkg);
        else if (pkg->id > node->id)
            node->right = insert(node->right, pkg);
        return node;
    }

    // Recursive search
    Package *search(Package *node, int id)
    {
        if (!node || node->id == id)
            return node;
        if (id < node->id)
            return search(node->left, id);
        return search(node->right, id);
    }

    Package *minValueNode(Package *node)
    {
        Package *current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    Package *remove(Package *node, int id)
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

    void inorder(Package *node)
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

public:
    PackageBST() { root = nullptr; }

    void insertPackage(int id, string name, int priority, double weight)
    {
        root = insert(root, new Package(id, name, priority, weight));
    }

    void searchPackage(int id)
    {
        Package *pkg = search(root, id);
        if (pkg)
            cout << "Found Package: " << pkg->name << " (ID " << pkg->id << ")\n";
        else
            cout << "Package not found.\n";
    }

    void deletePackage(int id) { root = remove(root, id); }

    void displayPackages()
    {
        cout << "\nAll Packages (Inorder Traversal):\n";
        inorder(root);
    }
};

int main()
{
    PackageBST bst;
    int choice;

    do
    {
        cout << "\n--- Package Management ---\n";
        cout << "1. Add Package\n2. Search Package\n3. Delete Package\n4. Display Packages\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, priority;
            double weight;
            string name;
            cout << "Enter Package ID, Name, Priority, Weight: ";
            cin >> id >> ws;
            getline(cin, name);
            cin >> priority >> weight;
            bst.insertPackage(id, name, priority, weight);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter Package ID to search: ";
            cin >> id;
            bst.searchPackage(id);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter Package ID to delete: ";
            cin >> id;
            bst.deletePackage(id);
            break;
        }
        case 4:
            bst.displayPackages();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
