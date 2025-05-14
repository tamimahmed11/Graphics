#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<pair<int, int>> ddaLine(int x1, int y1, int x2, int y2) {
    vector<pair<int, int>> points;
    
    // Calculate differences
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    // Determine number of steps
    int steps = max(abs(dx), abs(dy));
    
    // Calculate increments
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    
    // Start from first point
    float x = x1;
    float y = y1;
    
    // Store all points
    for (int i = 0; i <= steps; i++) {
        points.push_back({round(x), round(y)});
        x += xInc;
        y += yInc;
    }
    
    return points;
}

int main() {
    // Example usage
    auto line = ddaLine(2, 3, 10, 8);
    
    // Print the points
    cout << "Points on the line:" << endl;
    for (auto p : line) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    
    return 0;
}