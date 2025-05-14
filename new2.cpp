#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to draw a line using DDA algorithm
vector<pair<int, int>> ddaLine(int x1, int y1, int x2, int y2) {
    vector<pair<int, int>> points;
    
    // Calculate differences between endpoints
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    // Determine number of steps needed
    int steps = max(abs(dx), abs(dy));
    
    // Calculate increment values
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;
    
    // Start from the first point
    float x = x1;
    float y = y1;
    
    // Store all points along the line
    for (int i = 0; i <= steps; i++) {
        points.push_back({round(x), round(y)});
        x += xIncrement;
        y += yIncrement;
    }
    
    return points;
}

int main() {
    int x1, y1, x2, y2;
    
    // Get user input for coordinates
    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;
    
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;
    
    // Generate line points
    vector<pair<int, int>> linePoints = ddaLine(x1, y1, x2, y2);
    
    // Display the points
    cout << "\nPoints on the line:" << endl;
    for (auto point : linePoints) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }
    
    return 0;
}