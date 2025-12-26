#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include "include/city_management.h"

using namespace std;

CityGraph::CityGraph()
{
    cityCount = 0;
}

int CityGraph::findCityIndex(const string &cityName) const
{
    for (int i = 0; i < cityCount; i++)
    {
        if (cities[i].name == cityName)
        {
            return i;
        }
    }
    return -1;
}

bool CityGraph::cityExists(const string &cityName) const
{
    return findCityIndex(cityName) != -1;
}

bool CityGraph::routeExists(const string &city1, const string &city2) const
{
    int idx1 = findCityIndex(city1);
    if (idx1 == -1)
        return false;

    for (int i = 0; i < cities[idx1].connectionCount; i++)
    {
        if (cities[idx1].connections[i].toCity == city2)
        {
            return true;
        }
    }
    return false;
}

int CityGraph::getDistanceBetween(const string &city1, const string &city2) const
{
    int idx1 = findCityIndex(city1);
    if (idx1 == -1)
        return -1;

    for (int i = 0; i < cities[idx1].connectionCount; i++)
    {
        if (cities[idx1].connections[i].toCity == city2)
        {
            return cities[idx1].connections[i].distance;
        }
    }
    return -1;
}

void CityGraph::resetVisited()
{
    for (int i = 0; i < cityCount; i++)
    {
        cities[i].visited = false;
    }
}

void CityGraph::addCity(const string &cityName)
{
    if (cityCount >= MAX_CITIES)
    {
        cout << "Maximum cities limit reached (" << MAX_CITIES << " cities).\n";
        return;
    }

    if (cityExists(cityName))
    {
        cout << "City '" << cityName << "' already exists!\n";
        return;
    }

    cities[cityCount].name = cityName;
    cities[cityCount].connectionCount = 0;
    cities[cityCount].visited = false;
    cityCount++;

    cout << "City '" << cityName << "' added successfully!\n";
}

void CityGraph::addRoute(const string &city1, const string &city2, int distance)
{
    if (!cityExists(city1))
    {
        cout << "City '" << city1 << "' does not exist. Please add it first.\n";
        return;
    }

    if (!cityExists(city2))
    {
        cout << "City '" << city2 << "' does not exist. Please add it first.\n";
        return;
    }

    if (city1 == city2)
    {
        cout << "Cannot add route from a city to itself!\n";
        return;
    }

    if (routeExists(city1, city2))
    {
        cout << "Route already exists between " << city1 << " and " << city2 << ".\n";
        return;
    }

    int idx1 = findCityIndex(city1);
    int idx2 = findCityIndex(city2);

    if (cities[idx1].connectionCount >= MAX_CONNECTIONS)
    {
        cout << "City '" << city1 << "' has reached maximum connections (" << MAX_CONNECTIONS << ").\n";
        return;
    }

    if (cities[idx2].connectionCount >= MAX_CONNECTIONS)
    {
        cout << "City '" << city2 << "' has reached maximum connections (" << MAX_CONNECTIONS << ").\n";
        return;
    }

    // Add connection from city1 to city2
    cities[idx1].connections[cities[idx1].connectionCount].toCity = city2;
    cities[idx1].connections[cities[idx1].connectionCount].distance = distance;
    cities[idx1].connectionCount++;

    // Add reverse connection from city2 to city1
    cities[idx2].connections[cities[idx2].connectionCount].toCity = city1;
    cities[idx2].connections[cities[idx2].connectionCount].distance = distance;
    cities[idx2].connectionCount++;

    cout << "Route added: " << city1 << " <-> " << city2 << " (" << distance << "km)\n";
}

void CityGraph::findShortestRoute(const string &start, const string &target)
{
    int startIdx = findCityIndex(start);
    int targetIdx = findCityIndex(target);

    if (startIdx == -1)
    {
        cout << "Start city '" << start << "' does not exist!\n";
        return;
    }

    if (targetIdx == -1)
    {
        cout << "Destination city '" << target << "' does not exist!\n";
        return;
    }

    if (start == target)
    {
        cout << "You're already at " << start << "!\n";
        return;
    }

    int distance[MAX_CITIES];
    string previous[MAX_CITIES];
    bool processed[MAX_CITIES] = {false};

    // Initialize
    for (int i = 0; i < cityCount; i++)
    {
        distance[i] = INF;
        previous[i] = "";
    }
    distance[startIdx] = 0;

    for (int count = 0; count < cityCount; count++)
    {
        int minDist = INF;
        int minIndex = -1;

        for (int i = 0; i < cityCount; i++)
        {
            if (!processed[i] && distance[i] < minDist)
            {
                minDist = distance[i];
                minIndex = i;
            }
        }

        if (minIndex == -1)
            break;

        processed[minIndex] = true;

        for (int i = 0; i < cities[minIndex].connectionCount; i++)
        {
            string neighbor = cities[minIndex].connections[i].toCity;
            int neighborIdx = findCityIndex(neighbor);
            int edgeWeight = cities[minIndex].connections[i].distance;

            if (!processed[neighborIdx])
            {
                int newDist = distance[minIndex] + edgeWeight;
                if (newDist < distance[neighborIdx])
                {
                    distance[neighborIdx] = newDist;
                    previous[neighborIdx] = cities[minIndex].name;
                }
            }
        }

        if (minIndex == targetIdx)
            break;
    }

    if (distance[targetIdx] == INF)
    {
        cout << "No route exists between " << start << " and " << target << "!\n";
        return;
    }

    string path[MAX_CITIES];
    int pathCount = 0;
    string current = target;

    while (current != "")
    {
        path[pathCount++] = current;
        current = previous[findCityIndex(current)];
    }

    for (int i = 0; i < pathCount / 2; i++)
    {
        swap(path[i], path[pathCount - 1 - i]);
    }

    cout << "\n=== SHORTEST ROUTE FOUND ===\n";
    cout << "Start: " << start << "\n";
    cout << "Destination: " << target << "\n";
    cout << "Total distance: " << distance[targetIdx] << "km\n";
    cout << "Number of stops: " << pathCount - 1 << "\n\n";

    cout << "Route: ";
    for (int i = 0; i < pathCount; i++)
    {
        cout << path[i];
        if (i < pathCount - 1)
        {
            cout << " -> ";
        }
    }
    cout << "\n\nIndividual distances:\n";
    int total = 0;
    for (int i = 0; i < pathCount - 1; i++)
    {
        int dist = getDistanceBetween(path[i], path[i + 1]);
        cout << "  " << path[i] << " → " << path[i + 1] << ": " << dist << "km\n";
        total += dist;
    }
    cout << "  ------------------------------\n";
    cout << "  Total: " << total << "km\n";
}

void CityGraph::dfsHelper(int currentIdx, int targetIdx, Path &currentPath, Path allPaths[], int &pathCount)
{
    cities[currentIdx].visited = true;
    currentPath.cities[currentPath.cityCount++] = cities[currentIdx].name;

    if (currentIdx == targetIdx)
    {
        currentPath.totalDistance = 0;
        for (int i = 0; i < currentPath.cityCount - 1; i++)
        {
            int dist = getDistanceBetween(currentPath.cities[i], currentPath.cities[i + 1]);
            currentPath.totalDistance += dist;
        }

        allPaths[pathCount] = currentPath;
        pathCount++;
    }
    else
    {
        for (int i = 0; i < cities[currentIdx].connectionCount; i++)
        {
            string neighbor = cities[currentIdx].connections[i].toCity;
            int neighborIdx = findCityIndex(neighbor);

            if (!cities[neighborIdx].visited)
            {
                dfsHelper(neighborIdx, targetIdx, currentPath, allPaths, pathCount);
            }
        }
    }

    currentPath.cityCount--;
    cities[currentIdx].visited = false;
}

void CityGraph::findAllRoutes(const string &start, const string &target)
{
    int startIdx = findCityIndex(start);
    int targetIdx = findCityIndex(target);

    if (startIdx == -1)
    {
        cout << "Start city '" << start << "' does not exist!\n";
        return;
    }

    if (targetIdx == -1)
    {
        cout << "Destination city '" << target << "' does not exist!\n";
        return;
    }

    resetVisited();

    Path currentPath;
    currentPath.cityCount = 0;
    currentPath.totalDistance = 0;

    Path allPaths[100];
    int pathCount = 0;

    dfsHelper(startIdx, targetIdx, currentPath, allPaths, pathCount);

    if (pathCount == 0)
    {
        cout << "No routes found between " << start << " and " << target << "!\n";
        return;
    }

    // Sort paths by distance (bubble sort)
    for (int i = 0; i < pathCount - 1; i++)
    {
        for (int j = i + 1; j < pathCount; j++)
        {
            if (allPaths[j].totalDistance < allPaths[i].totalDistance)
            {
                swap(allPaths[i], allPaths[j]);
            }
        }
    }

    cout << "\nFound " << pathCount << " route(s) between " << start << " and " << target << ":\n";
    cout << "================================================\n";

    for (int p = 0; p < pathCount; p++)
    {
        cout << "\nRoute #" << (p + 1) << ":\n";
        cout << "Distance: " << allPaths[p].totalDistance << "km\n";
        cout << "Stops: " << (allPaths[p].cityCount - 1) << "\n";

        if (p == 0 && pathCount > 1)
        {
            cout << "🏆 SHORTEST PATH\n";
        }

        cout << "Path: ";
        for (int i = 0; i < allPaths[p].cityCount; i++)
        {
            cout << allPaths[p].cities[i];
            if (i < allPaths[p].cityCount - 1)
            {
                cout << " → ";
            }
        }
        cout << "\n"
             << string(50, '-') << "\n";
    }
}

void CityGraph::showAllCities() const
{
    if (cityCount == 0)
    {
        cout << "No cities in the system. Add some cities first!\n";
        return;
    }

    cout << "\n=== ALL CITIES & ROUTES ===\n";
    cout << "System Status:\n";
    cout << "• Total Cities: " << cityCount << "/" << MAX_CITIES << "\n";

    int totalRoutes = 0;
    for (int i = 0; i < cityCount; i++)
    {
        totalRoutes += cities[i].connectionCount;
    }
    cout << "• Total Routes: " << (totalRoutes / 2) << "\n";
    cout << "================================\n\n";

    for (int i = 0; i < cityCount; i++)
    {
        cout << cities[i].name << "\n";
        cout << "  Connections: ";

        if (cities[i].connectionCount == 0)
        {
            cout << "None (Isolated city)";
        }
        else
        {
            for (int j = 0; j < cities[i].connectionCount; j++)
            {
                cout << cities[i].connections[j].toCity;
                cout << " (" << cities[i].connections[j].distance << "km)";
                if (j < cities[i].connectionCount - 1)
                {
                    cout << ", ";
                }
            }
            cout << " [" << cities[i].connectionCount << " connections]";
        }
        cout << "\n"
             << string(50, '-') << "\n";
    }
}

void CityGraph::setupSampleData()
{
    cityCount = 0;

    // Add cities
    string cityNames[] = {"Addis Ababa", "Dire Dawa", "Hawassa", "Bahir Dar", "Mekelle"};
    for (int i = 0; i < 5; i++)
    {
        cities[i].name = cityNames[i];
        cities[i].connectionCount = 0;
        cities[i].visited = false;
        cityCount++;
    }

    // Add routes with realistic distances
    struct
    {
        string city1, city2;
        int distance;
    } routes[] = {
        {"Addis Ababa", "Dire Dawa", 515},
        {"Addis Ababa", "Hawassa", 275},
        {"Addis Ababa", "Bahir Dar", 578},
        {"Dire Dawa", "Hawassa", 350},
        {"Bahir Dar", "Mekelle", 525}};

    for (auto &route : routes)
    {
        int idx1 = findCityIndex(route.city1);
        int idx2 = findCityIndex(route.city2);

        cities[idx1].connections[cities[idx1].connectionCount++] = {route.city2, route.distance};
        cities[idx2].connections[cities[idx2].connectionCount++] = {route.city1, route.distance};
    }

    cout << "\nSample data loaded successfully!\n";
    cout << "• 5 Ethiopian cities added\n";
    cout << "• 5 routes with realistic distances added\n";
}

string CityGraph::getStringInput(const string &prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);

    // Trim whitespace
    while (!input.empty() && isspace(input.back()))
        input.pop_back();
    while (!input.empty() && isspace(input.front()))
        input.erase(0, 1);

    if (input.empty())
    {
        cout << "Input cannot be empty! Please try again.\n";
        return getStringInput(prompt);
    }
    return input;
}

int CityGraph::getIntInput(const string &prompt, int min, int max)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
        }
        else if (value < min || value > max)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a value between " << min << " and " << max << ".\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void CityGraph::displayMenu()
{
    cout << "\n=== CITY ROUTE MANAGEMENT ===\n";
    cout << "1. Add New City\n";
    cout << "2. Add Route Between Cities\n";
    cout << "3. Find Shortest Route\n";
    cout << "4. Find All Routes\n";
    cout << "5. Show All Cities & Routes\n";
    cout << "6. Reset to Sample Data\n";
    cout << "0. Back to Main Menu\n";
    cout << "Choice: ";
}