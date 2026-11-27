/*
TSP
Khó
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.

Input
Line 1: a positive integer n (1 <= n <= 20)
Line i+1 (i = 1, . . ., n): contains the i-th row of the distance matrix x (elements are separated by a SPACE character)

Output
Write the total travel distance of the optimal itinerary found.

Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7
*/

#include <bits/stdc++.h>
using namespace std;

int indexWithoutBit(int mask, int bit) {
    return (mask & (bit - 1)) | ((mask & ~(2 * bit - 1)) >> 1);
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
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    const int cities = n - 1;
    const int fullMask = (1 << cities) - 1;
    const long long inf = numeric_limits<long long>::max();
    // Each row stores only masks containing its ending city.
    vector<vector<long long>> dp(cities, vector<long long>(1 << (cities - 1)));

    for (int mask = 1; mask <= fullMask; ++mask) {
        for (int ends = mask; ends != 0; ends &= ends - 1) {
            const int last = __builtin_ctz(static_cast<unsigned>(ends));
            const int lastBit = 1 << last;
            const int previous = mask ^ lastBit;
            long long& best = dp[last][indexWithoutBit(mask, lastBit)];
            if (previous == 0) {
                best = cost[0][last + 1];
                continue;
            }

            best = inf;
            for (int candidates = previous; candidates != 0; candidates &= candidates - 1) {
                const int from = __builtin_ctz(static_cast<unsigned>(candidates));
                const long long path = dp[from][indexWithoutBit(previous, 1 << from)];
                best = min(best, path + cost[from + 1][last + 1]);
            }
        }
    }

    long long answer = inf;
    for (int last = 0; last < cities; ++last) {
        const long long path = dp[last][indexWithoutBit(fullMask, 1 << last)];
        answer = min(answer, path + cost[last + 1][0]);
    }
    cout << answer << '\n';
}
