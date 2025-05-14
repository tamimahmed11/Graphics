#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> drawLineDDA(int x1, int y1, int x2, int y2) {
    vector<pair<int, int>> points;
    
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; i++) {
        points.push_back(make_pair(round(x), round(y)));
        x += xIncrement;
        y += yIncrement;
    }
    
    return points;
}

int main() {
    int x1, y1, x2, y2;
    
    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;
    
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;
    
    vector<pair<int, int>> linePoints = drawLineDDA(x1, y1, x2, y2);
    
    cout << "Points on the line:" << endl;
    for (auto point : linePoints) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }
    
    return 0;
}