/*
TSP - Large Scale
Khó
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person wants to find a closed tour that visits each city exactly once (excelt the starting city). Find the itinerary for that person so that the total travel distance is minimal.
A solution is represented by a sequence x[1], x[2], . . ., x[n] (a permutation of 1, 2, . . ., n) in which the closed tour is: x[1] ->  x[2] ->  x[3] ->  . . . ->  x[n] ->  x[1].

Input
Line 1: a positive integer n (1 <= n <= 1000)
Line i+1 (i = 1, . . ., n): contains the i-th row of the distance matrix x (elements are separated by a SPACE character)

Output
Line 1: write n
Line 2: write the sequence of points x[1], x[2], . . ., x[n] (a permutation of 1, 2, . . ., n) of the itinerary found.

Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
4
1 3 2 4
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nearestNeighbor(const vector<vector<long long>>& cost, int start) {
    const int n = static_cast<int>(cost.size());
    vector<int> tour{start};
    vector<bool> visited(n);
    visited[start] = true;

    while (static_cast<int>(tour.size()) < n) {
        const int current = tour.back();
        int next = -1;
        for (int city = 0; city < n; ++city) {
            if (!visited[city] && (next == -1 || cost[current][city] < cost[current][next])) {
                next = city;
            }
        }
        visited[next] = true;
        tour.push_back(next);
    }
    return tour;
}

long long tourCost(const vector<vector<long long>>& cost, const vector<int>& tour) {
    long long total = cost[tour.back()][tour.front()];
    for (size_t i = 1; i < tour.size(); ++i) {
        total += cost[tour[i - 1]][tour[i]];
    }
    return total;
}

void improveTour(const vector<vector<long long>>& cost, vector<int>& tour) {
    const int n = static_cast<int>(tour.size());
    const int maxPasses = 16;
    for (int pass = 0; pass < maxPasses; ++pass) {
        long long bestDelta = 0;
        int moved = -1, insertAfter = -1;
        for (int i = 1; i < n; ++i) {
            const int previous = tour[i - 1];
            const int city = tour[i];
            const int next = tour[(i + 1) % n];
            const long long removeDelta = cost[previous][next] - cost[previous][city] - cost[city][next];

            for (int j = 0; j < n; ++j) {
                if (j == i - 1 || j == i) {
                    continue;
                }
                const int left = tour[j];
                const int right = tour[(j + 1) % n];
                // Replace three directed arcs without reversing the tour.
                const long long delta = removeDelta + cost[left][city] + cost[city][right] - cost[left][right];
                if (delta < bestDelta) {
                    bestDelta = delta;
                    moved = i;
                    insertAfter = j;
                }
            }
        }
        if (moved == -1) {
            return;
        }
        const int city = tour[moved];
        tour.erase(tour.begin() + moved);
        if (insertAfter > moved) {
            --insertAfter;
        }
        tour.insert(tour.begin() + insertAfter + 1, city);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<long long>> cost(n, vector<long long>(n));
    for (auto& row : cost) {
        for (long long& value : row) {
            cin >> value;
        }
    }

    vector<int> bestTour;
    long long bestCost = numeric_limits<long long>::max();
    const int starts = min(n, 8);
    for (int i = 0; i < starts; ++i) {
        auto tour = nearestNeighbor(cost, i * n / starts);
        const long long total = tourCost(cost, tour);
        if (bestTour.empty() || total < bestCost) {
            bestCost = total;
            bestTour = move(tour);
        }
    }
    improveTour(cost, bestTour);

    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << bestTour[i] + 1 << (i + 1 == n ? '\n' : ' ');
    }
}
