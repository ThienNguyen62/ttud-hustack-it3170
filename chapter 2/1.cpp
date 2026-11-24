/*
 Simulation prefix sum 1-array
Trung bình
PREFIX_SUM
Given a sequence of integers a[1], a[2], ..., a[n].
Each of the Q queries q(i, j) returns the sum of a[i], a[i + 1], ..., a[j].

Input
Line 1: contains a positive integer n (2 <= n <= 100000)
Line 2: contains a[1], a[2], ..., a[n] (1 <= a[i] <= 1000).
Line 3: contains a positive integer Q (1 <= Q <= 100000)
Line 3 + k (k = 1, 2, ..., Q): contains two positive integers i and j
(1 <= i < j <= n) for the k-th query.
 
Output
Write in each line, the result of the corresponding query read from the input

Example
Input
5
5 8 7 1 9 
4
1 2
1 5
1 3
4 5

Output 
13
30
20
10 
*/

/*
Đọc dãy n số và Q truy vấn. Với mỗi cặp chỉ số i, j (đánh số từ 1),
in tổng các phần tử từ i đến j trên một dòng.
*/

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        int value;
        std::cin >> value;
        prefix[i] = prefix[i - 1] + value;
    }

    int queries;
    std::cin >> queries;
    for (int query = 0; query < queries; ++query) {
        int left, right;
        std::cin >> left >> right;
        std::cout << prefix[right] - prefix[left - 1] << '\n';
    }
}
/*
đề yêu cầu tính tổng các phần tử của mảng từ i đến j
đây là 2 biên , coi như là từ left đến right
cách đơn giản nhất là tính tổng từ i đến j là cứ chạy từ i đến j rồi cộng lại
sum += a[k]; rồi in ra -> brute force
nhược điểm nếu có 100000 truy vấn số lần cộng sẽ là 10^10
chương trình phải cộng lại quá nhiều

ví dụ 
1 3
1 4
1 5
1 3 → 5 + 8 + 7         = 20
1 4 → 5 + 8 + 7 + 1     = 21
1 5 → 5 + 8 + 7 + 1 + 9 = 30
vấn đề là truy vấn thứ hai cộng lại phần đã ở truy vấn thứ 1, thứ ba dùng lại phần đã cộng ở truy vấn thứ 2
tư duy là ta sẽ lưu các tổng lại để sử dụng về sau

PREfix sum thực chất là mảng lưu tổng cộng dồn từ đầu đến từng vị trí

giả sử  tính tổng tử vị trí thứ 3 đến thứ 5 
a = [5, 8, 7, 1, 9]
nhìn 2 tổng đã lưu
prefix[5] = 5 + 8 + 7 + 1 + 9 = 30
prefix[2] = 5 + 8             = 13
sum = prefix [5] - prefix[2]
=tổng [j] - tổng [i-1]

sum = prefix[right] - prefix[left-1]
left -1 là muốn bỏ những phần tử đứng trước left không bao gồm left

trong code có đoạn prefix(n+1) do dòng 2 input bắt nhập các giá trị từ i =1, vậy với n là số phần tử thì mảng phải có n+1 khoảng trống (bao gồm vị trí 0)
*/
