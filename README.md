# Smart Logistics Management System

A comprehensive C++ logistics management system implementing multiple data structures for efficient package delivery, vehicle management, and route optimization.


## Features

### 1. **Vehicle Management** (Queue)
- Add vehicles to fleet
- Assign vehicles to deliveries (FIFO)
- Return vehicles after delivery
- Track vehicle availability

### 2. **Package Management** (Binary Search Tree)
- Fast package lookup by ID (O(log n))
- Add, search, and delete packages
- Efficient sorted traversal
- Linked list for sequential access

### 3. **Package Sorting** (BST + Merge Sort)
- Sort by priority (High → Low)
- Sort by weight (Light → Heavy)
- Two algorithms: BST-based and Merge Sort
- No built-in sort functions used

### 4. **Delivery System** (Queue + Stack)
- **Queue**: FIFO delivery queue
- **Stack**: Delivery history with undo functionality
- Execute deliveries in order
- Undo last delivery

### 5. **City Route Management** (Graph)
- **Dijkstra's Algorithm**: Find shortest route
- **DFS**: Find all possible routes
- Pre-loaded Ethiopian cities
- Add custom cities and routes

## Project Structure

```
Smart-Logistics-Management-System/
├── main.cpp                          # Main program entry
├── include/
│   ├── city_management.h             # Graph & routing
│   ├── delivery_exe_and_history.h    # Queue & Stack
│   ├── package-management.h          # BST & Linked List
│   ├── package-sorter.h              # Sorting algorithms
│   └── Vehicle-management.h          # Vehicle queue
├── src/
│   ├── city_graph.cpp
│   ├── delivery_execution_and_history.cpp
│   ├── package-management.cpp
│   ├── package-sorter.cpp
│   └── vehicle-management.cpp

```

## Quick Start

### Step 1: Verify Fixes
```cmd
verify_fixes.bat
```

### Step 2: Install C++ Compiler

**Option A: MinGW (Recommended)**
1. Download MSYS2: https://www.msys2.org/
2. Install and run: `pacman -S mingw-w64-x86_64-gcc`
3. Add to PATH: `C:\msys64\mingw64\bin`

**Option B: Visual Studio**
- Install "Build Tools for Visual Studio"
- Select "Desktop development with C++"

### Step 3: Compile
```cmd
g++ -o main.exe main.cpp src/*.cpp -I.
```

### Step 4: Run
```cmd
main.exe
```


## Data Structures Used

| Module | Data Structure | Purpose |
|--------|---------------|---------|
| Package Management | Binary Search Tree | Fast O(log n) lookup |
| Package Storage | Linked List | Sequential traversal |
| Package Sorting | BST + Merge Sort | Priority/weight sorting |
| Delivery Queue | Circular Queue | FIFO delivery order |
| Delivery History | Stack | LIFO undo functionality |
| Vehicle Fleet | Queue | FIFO vehicle assignment |
| City Network | Graph (Adjacency List) | Route management |
| Shortest Path | Dijkstra's Algorithm | Optimal routing |
| All Paths | DFS | Route exploration |

## Usage Example

```
=== SMART LOGISTICS MANAGEMENT SYSTEM ===

1. Vehicle Management
2. Package Management (BST)
3. Package Sorting
4. Delivery System
5. City Route Management
6. Integrated Delivery Test
0. Exit

Enter your choice: 5

=== CITY ROUTE MANAGEMENT ===
Sample data loaded successfully!
• 5 Ethiopian cities added
• 5 routes with realistic distances added

1. Add City
2. Add Route Between Cities
3. Find Shortest Route (Dijkstra)
4. Find All Routes (DFS)
5. Show All Cities & Routes
6. Reset to Sample Data
0. Back to Main Menu

Choice: 3

Enter start city: Addis Ababa
Enter destination city: Mekelle

=== SHORTEST ROUTE FOUND ===
Start: Addis Ababa
Destination: Mekelle
Total distance: 1103km
Number of stops: 2

Route: Addis Ababa → Bahir Dar → Mekelle
```


## Team members

- AMEN TESHOME REGASA             ETS0165/16
- AMIR ABDULJELIL MIFTAH          ETS0167/16
- BETSEGAW TESFAYE W/GEBRIEL      ETS0285/16
- BINIYAM KINFE G/KIDAN           ETS0304/16
- DEGAGA DESTA BAKALA             ETS0352/16
- BINYAM YALEW GEDAM              ETS0297/15


