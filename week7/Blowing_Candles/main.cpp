#include <iostream>
#include <cstdio>
#include <cmath>
#include <complex>
#include <map>
#include <algorithm>
#include <vector>
//#include <fstream>

using namespace std;

typedef pair<int, int> pii;

// Helper function to determine if three points make a right turn
bool turnRight(pii a, pii b, pii c) {
    return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first) < 0;
}

vector<pii> convexHull(vector<pii>& in) {
    if (in.size() <= 1) return in;
    sort(in.begin(), in.end());// Sort the points lexicographically (by x, and by y if x is the same)
    vector<pii> lower, upper;
    // Build the lower hull
    for (const pii& p : in) {
        while (lower.size() >= 2 && !turnRight(lower[lower.size() - 2], lower[lower.size() - 1], p)) {
            lower.pop_back();
        }
        lower.push_back(p);
    }
    // Build the upper hull
    for (int i = in.size() - 1; i >= 0; i--) {
        const pii& p = in[i];
        while (upper.size() >= 2 && !turnRight(upper[upper.size() - 2], upper[upper.size() - 1], p)) {
            upper.pop_back();
        }
        upper.push_back(p);
    }
    // Remove the last point of each half because it is repeated at the beginning of the other half
    lower.pop_back();
    upper.pop_back();
    
    lower.insert(lower.end(), upper.begin(), upper.end()); // Concatenate lower and upper hulls
    return lower;
}


int main() {
    int N, R;
    vector<pii> candles;
    cin >> N >> R;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        candles.push_back({x, y});
    }

    vector<pii> hull = convexHull(candles);
/*
    // Output points to a file
    ofstream outfile("hull_points.txt");
    for (pii p : hull) {
        outfile << p.first << " " << p.second << endl;
    }
    outfile.close();
*/

    // Find the points that form the bigger diameter of the obtained polygon
    pii p1, p2;
    int max_dist = 0;
    for (int i = 0; i < hull.size(); i++) {
        for (int j = i + 1; j < hull.size(); j++) {
            int dist = (hull[i].first - hull[j].first)*(hull[i].first - hull[j].first) + (hull[i].second - hull[j].second)*(hull[i].second - hull[j].second);
            if (dist > max_dist) {
                max_dist = dist;
                p1 = hull[i];
                p2 = hull[j];
            }
        }
    }

    // Compute a and b for the line equation y = ax + b
    double a = (p1.second - p2.second) / (double)(p1.first - p2.first);
    double b = p1.second - a * p1.first;

    // find the farthest point from the line at the left and right of the line
    double max_dist_left = 0.0, max_dist_right = 0.0;
    pii p_l, p_r;
    for (pii p : hull) {
        double dist = abs(a * p.first - p.second + b) / sqrt(a * a + 1); // distance from a point to a line
        if (a * p.first + b < p.second) {
            if (dist > max_dist_left) {
                max_dist_left = dist;
                p_l = p;
            }
        } else {
            if (dist > max_dist_right) {
                max_dist_right = dist;
                p_r = p;
            }
        }
    }

    // The widtg of the flow is the sum of the distances from the line to the farthest points at the left and right
    double width = max_dist_left + max_dist_right;
    printf("%.16f\n", width);

    return 0;
}
