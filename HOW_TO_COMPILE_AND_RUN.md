# How to Compile and Run the Smart Logistics System

## ⚠️ IMPORTANT: You Need a C++ Compiler

Your system doesn't have a C++ compiler installed. The existing `main.exe` was compiled **before** the bug fixes were applied.

## 🔧 Step 1: Install a C++ Compiler

### Option A: MinGW-w64 (Recommended for Windows)

1. **Download MSYS2**: https://www.msys2.org/
2. **Install MSYS2** (follow the installer)
3. **Open MSYS2 terminal** and run:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
4. **Add to PATH**: Add `C:\msys64\mingw64\bin` to your system PATH
5. **Verify installation**:
   ```cmd
   g++ --version
   ```

### Option B: Visual Studio Build Tools

1. **Download**: https://visualstudio.microsoft.com/downloads/
2. **Install "Build Tools for Visual Studio"**
3. **Select "Desktop development with C++"**
4. **Open "Developer Command Prompt for VS"**

### Option C: Chocolatey (Package Manager)

```powershell
# Run PowerShell as Administrator
Set-ExecutionPolicy Bypass -Scope Process -Force
iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))

# Install MinGW
choco install mingw
```

## 🚀 Step 2: Compile the Fixed Code

Once you have a compiler installed:

### Using g++ (MinGW/GCC):
```cmd
g++ -o main.exe main.cpp src/city_graph.cpp src/delivery_execution_and_history.cpp src/package-management.cpp src/package-sorter.cpp src/vehicle-management.cpp -I.
```

### Using MSVC (Visual Studio):
```cmd
cl /EHsc /Fe:main.exe main.cpp src/*.cpp /I.
```

## ▶️ Step 3: Run the Program

```cmd
main.exe
```

Or simply double-click `main.exe` in File Explorer.

## 🧪 Step 4: Test All Features

### Test Sequence:

1. **Main Menu** → Choose option `6` (Integrated Delivery Test)
   - This will automatically test all modules

2. **Vehicle Management** (Option 1)
   - Add vehicle: ID=1, Driver="John Doe"
   - Add vehicle: ID=2, Driver="Jane Smith"
   - Display vehicles
   - Assign vehicle
   - Return vehicle

3. **Package Management** (Option 2)
   - Add package: ID=101, Name="Laptop", Priority=3, Weight=2.5, Dest="Addis Ababa"
   - Add package: ID=102, Name="Phone", Priority=2, Weight=0.3, Dest="Dire Dawa"
   - Search package: ID=101
   - Display all packages

4. **Package Sorting** (Option 3)
   - View sorted by priority & weight
   - Test BST-based sorting

5. **Delivery System** (Option 4)
   - Add packages to queue
   - Execute delivery
   - View history
   - Undo delivery

6. **City Route Management** (Option 5)
   - Sample data is pre-loaded
   - Find shortest route: Addis Ababa → Mekelle
   - Find all routes: Addis Ababa → Dire Dawa
   - Add new city
   - Add new route

## 🐛 What Was Fixed

The following bugs were fixed in the code:

1. ✅ **Duplicate header content** in `include/package-management.h`
2. ✅ **Wrong implementation** in `src/package-sorter.cpp`
3. ✅ **Wrong include path** in `main.cpp`
4. ✅ **Case sensitivity issues** in include statements

## 📊 Expected Output

When you run the integrated test (Option 6), you should see:

```
=== INTEGRATED SYSTEM TEST ===
Testing all modules together...

1. TESTING VEHICLE MANAGEMENT:
------------------------------
Vehicle 1 with driver John Doe added.
Vehicle 2 with driver Jane Smith added.
...

2. TESTING PACKAGE MANAGEMENT (BST):
-----------------------------------
Package 1001 'Medical Supplies' added to system.
...

3. TESTING PACKAGE SORTING:
---------------------------
=== Packages Sorted by Priority & Weight (Pure BST-based) ===
...

4. TESTING DELIVERY SYSTEM:
---------------------------
Package 1001 'Medical Supplies' added to delivery queue.
...

5. TESTING CITY ROUTE MANAGEMENT:
---------------------------------
Sample data loaded successfully!
...

Integrated Test Completed Successfully!
```

## ❌ Troubleshooting

### Error: "g++ is not recognized"
- Compiler not installed or not in PATH
- Follow Step 1 above

### Error: "Cannot open include file"
- Make sure you're running the compile command from the project root directory
- Check that all header files exist in `include/` folder

### Error: "Undefined reference to..."
- Make sure all `.cpp` files are included in the compile command
- Check that function declarations match implementations

### Program hangs or doesn't respond
- The program is waiting for user input
- Type a number and press Enter

## 🎯 Quick Test Commands

```cmd
# Compile
g++ -o main.exe main.cpp src/*.cpp -I.

# Run
main.exe

# Quick test (choose option 6 from menu)
# Then press 0 to exit
```

## 📝 Manual Testing Checklist

- [ ] Program compiles without errors
- [ ] Main menu displays correctly
- [ ] Vehicle management works (add, assign, return)
- [ ] Package management works (add, search, delete)
- [ ] Package sorting displays correctly
- [ ] Delivery queue works (enqueue, dequeue)
- [ ] Delivery history works (push, pop, undo)
- [ ] City routing works (shortest path, all paths)
- [ ] Integrated test runs successfully
- [ ] No memory leaks or crashes

## 🔍 Verification

After compilation, verify the fixes:

1. **Check package-management.h**: Should have NO duplicate content
2. **Check package-sorter.cpp**: Should have PackageSorter implementation (not Vehicle)
3. **Check main.cpp includes**: Should include `city_management.h` (not `city_graph.h`)

## 💡 Next Steps

After successful compilation and testing:

1. Review `PROJECT_ANALYSIS.md` for feature recommendations
2. Implement priority features (tracking, optimization, etc.)
3. Add error handling and input validation
4. Create unit tests
5. Add documentation

---

**Need Help?** 
- Check compiler installation: `g++ --version`
- Verify file structure: `dir include` and `dir src`
- Review error messages carefully
