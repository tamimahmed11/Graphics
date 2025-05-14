#include <iostream>
#include <vector>
#include <utility> // for std::pair

using namespace std;

vector<pair<int, int>> bresenhamLine(int x1, int y1, int x2, int y2) {
    vector<pair<int, int>> points;
    
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    
    int err = dx - dy;
    
    while(true) {
        points.push_back(make_pair(x1, y1));
        
        if(x1 == x2 && y1 == y2) break;
        
        int e2 = 2 * err;
        
        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        
        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    
    return points;
}

int main() {
    int x1, y1, x2, y2;
    
    cout << "Enter first point (x1 y1): ";
    cin >> x1 >> y1;
    
    cout << "Enter second point (x2 y2): ";
    cin >> x2 >> y2;
    
    vector<pair<int, int>> line = bresenhamLine(x1, y1, x2, y2);
    
    cout << "\nPoints on the line:\n";
    for(auto p : line) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
    
    return 0;
}
