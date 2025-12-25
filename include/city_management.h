#ifndef CITY_GRAPH_H
#define CITY_GRAPH_H

#include <iostream>
#include <string>

const int MAX_CITIES = 50;
const int MAX_CONNECTIONS = 20;
const int INF = 999999;

struct CityConnection
{
    std::string toCity;
    int distance;
};

struct City
{
    std::string name;
    CityConnection connections[MAX_CONNECTIONS];
    int connectionCount;
    bool visited;
};

struct Path
{
    std::string cities[MAX_CITIES];
    int cityCount;
    int totalDistance;
};

class CityGraph
{
private:
    City cities[MAX_CITIES];
    int cityCount;

    int findCityIndex(const std::string &cityName) const;
    bool routeExists(const std::string &city1, const std::string &city2) const;
    int getDistanceBetween(const std::string &city1, const std::string &city2) const;
    void resetVisited();
    void dfsHelper(int currentIdx, int targetIdx, Path &currentPath, Path allPaths[], int &pathCount);

public:
    CityGraph();

    bool cityExists(const std::string &cityName) const;
    void addCity(const std::string &cityName);
    void addRoute(const std::string &city1, const std::string &city2, int distance);
    void findShortestRoute(const std::string &start, const std::string &target);
    void findAllRoutes(const std::string &start, const std::string &target);
    void showAllCities() const;
    void setupSampleData();
    int getCityCount() const { return cityCount; }

    // Menu functions
    static void displayMenu();
    static std::string getStringInput(const std::string &prompt);
    static int getIntInput(const std::string &prompt, int min, int max);
};

#endif