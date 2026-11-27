/*
Warehouse
Khó
Dynamic Programming
A truck is planned to arrive at some stations among N stations 1, 2, . . ., N located on a line. Station i (i = 1,…,N) has coordinate i and has following information
a[i]: amount of goods
t[i]: pickup time duration for taking goods
The route of the truck is a sequence of stations x[1] < x[2] < . . . < x[k] (1 ≤ x[j] ≤ N, j = 1,…, k). Due to technical constraints, the distance between two consecutive stations that the truck arrives x[i] and x[i+1] is less than or equal to D and the total pickup time duration cannot exceed T. Find a route for the truck such that total amount of goods picked up is maximal.

Input
Line 1: N, T, D (1 <= N <= 1000, 1 <= T <= 100, 1 <= D <= 10)
Line 2: a[1],. . ., a[N] (1 <= a[i] <= 10)
Line 3: t[1], . . ., t[N] (1 <=  t[i] <= 10)

Output
Write the total amount of goods that the truck picks up in the route.

Example
Input
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2

Output
24
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, timeLimit, maxGap;
    cin >> n >> timeLimit >> maxGap;
    vector<int> goods(n), pickupTime(n);
    for (int& value : goods) {
        cin >> value;
    }
    for (int& value : pickupTime) {
        cin >> value;
    }

    // dp[i][t] stores the best route ending at i with exactly t pickup time.
    vector<vector<int>> dp(n, vector<int>(timeLimit + 1, -1));
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (pickupTime[i] > timeLimit) {
            continue;
        }
        dp[i][pickupTime[i]] = goods[i];
        answer = max(answer, goods[i]);
        for (int previous = max(0, i - maxGap); previous < i; ++previous) {
            for (int time = pickupTime[i]; time <= timeLimit; ++time) {
                const int before = dp[previous][time - pickupTime[i]];
                if (before >= 0) {
                    dp[i][time] = max(dp[i][time], before + goods[i]);
                    answer = max(answer, dp[i][time]);
                }
            }
        }
    }

    cout << answer << '\n';
}
