/*
Inversion
Khó
Given a sequence of integers a[1], a[2], ..., a[n]. A pair (i, j) is call an inversion if i < j and a[i] > a[j]. Compute the number Q of inversions

Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a[1], a[2], ..., a[n] (0 <= a[i] <= 10^6)

Output
Write the value Q modulo 10^9 + 7

Example
Input
6
3 2 4 5 6 1
Output
6
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int maxValue = 1000000;
    const int mod = 1000000007;
    vector<int> fenwick(maxValue + 2);
    long long inversions = 0;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        const int index = value + 1;

        // Count earlier values <= value. Equal values are not inversions.
        int notGreater = 0;
        for (int p = index; p > 0; p -= p & -p) {
            notGreater += fenwick[p];
        }
        inversions += i - notGreater;

        for (int p = index; p <= maxValue + 1; p += p & -p) {
            ++fenwick[p];
        }
    }

    cout << inversions % mod << '\n';
}
