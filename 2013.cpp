class DetectSquares {
private:
    int pointCount[1001][1001] = {};
    vector<pair<int, int>> points;

public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        if (pointCount[x][y] == 0) {
            points.push_back({x, y});
        }
        pointCount[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int res = 0;

        for (const auto& p : points) {
            int px = p.first;
            int py = p.second;

            if (abs(px - x) == abs(py - y) && px != x) {
                res += pointCount[px][py] * pointCount[px][y] * pointCount[x][py];
            }
        }

        return res;
    }
};

