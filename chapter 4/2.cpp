/*
Job Selection & Planning
Trung bình
GREEDY
Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.

Input
Line 1: contains a positive integer n (1 <= n <= 10^5)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10^5)

Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300
*/

#include <bits/stdc++.h>
using namespace std;

int findSlot(vector<int>& parent, int slot) {
    while (parent[slot] != slot) {
        parent[slot] = parent[parent[slot]];
        slot = parent[slot];
    }
    return slot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> jobs(n);
    for (auto& [profit, deadline] : jobs) {
        cin >> deadline >> profit;
    }
    sort(jobs.rbegin(), jobs.rend());

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    long long totalProfit = 0;
    for (const auto& [profit, deadline] : jobs) {
        // Use the latest available slot to leave earlier slots free.
        const int slot = findSlot(parent, min(n, deadline));
        if (slot > 0) {
            totalProfit += profit;
            parent[slot] = findSlot(parent, slot - 1);
        }
    }

    cout << totalProfit << '\n';
}
