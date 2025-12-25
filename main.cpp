#include "PackageManagement.h"
#include <iostream>
using namespace std;

int main(){
    PackageBST packageManager;

    packageManager.insertPackage(1, "Laptop", 1, 2.5);
    packageManager.displayPackages();
}