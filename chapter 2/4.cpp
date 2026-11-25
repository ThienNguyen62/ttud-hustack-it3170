/*
Longest Bounded SubSequence
Khó
TWO_POINTERS
Given a sequence of positive integers a[1], a[2], ..., a[n].
A subsequence here consists of consecutive elements a[i], a[i + 1], ..., a[j]
(1 <= i <= j <= n). Its weight is the sum of its elements.
Given a positive integer Q, find the longest such subsequence with weight
less than or equal to Q.

Input
Line 1: contains two positive integers n and Q (1 <= n <= 10^6, 1 <= Q <= 100000).
Line 2: contains a[1], a[2], ..., a[n] (1 <= a[i] <= 10000).

Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.
Example
Input
10 40
19 2 7 6 9 1 17 19 8 4 
Output
5

*/

/*
Đọc dãy n số nguyên dương và giới hạn Q. In độ dài lớn nhất của đoạn
liên tiếp có tổng không vượt quá Q. In -1 nếu không có đoạn nào thỏa mãn.
đề bài dùng subsequence, định nghĩa là các phần tử liên tiếp , vì vậy bản chất là bài đoạn con liên tiếp
không được chọn rời rạc
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, limit;
    std::cin >> n >> limit;
    std::vector<int> values(n);

    int left = 0;
    int sum = 0;
    int best = 0;
    for (int right = 0; right < n; ++right) {
        std::cin >> values[right];
        sum += values[right];
        while (sum > limit) {
            sum -= values[left++]; // xóa đầu , cửa sổ cũ chuyển sang vị trí tiếp theo
        }
        best = std::max(best, right - left + 1);
    }
    std::cout << (best == 0 ? -1 : best) << '\n';
}


/*
cách làm đơn giản nhất 
vd
a = [4, 2, 3, 5, 1]
Q = 8
tìm đoạn liên tiếp dài nhất có tổng <= 8
int best = 0;

for (int i = 0; i < n; i++) {
    int sum = 0;

    for (int j = i; j < n; j++) {
        sum += a[j];

        if (sum <= Q) {
            best = max(best, j - i + 1);
        }
    }
}
đoạn code thử tất cả các đoạn có thể bắt đầu ở vị trí i và kết thúc ở J, với i <=j
mỗi khi đoạn hợp lệ, cập nhật độ dài lớn nhất
nhược điểm
số lượt xét quá lớn, tại sao mỗi lần chuyển vị trí bắt đầu, ta lại phải cộng lại những phẩn tử đã xử lí
đây là công việc lặp cần loại bỏ

thay vì mỗi lần bắt đầu lại từ đầu, tưởng tượng ta có một cửa số bao quanh một đoạn của mảng với leeft là vị trí bắt đầu
còn right là vị trí kết thúc
nếu tổng vượt quá thì bỏ bớt phần tử ở đầu bên trái, thay vì xóa toàn bộ đoạn và bắt đầu tính lại


+ quy tắc: mở rộng cửa sổ sang phải, nếu tổng vượt Q, thu hẹp cửa sổ từ bên trái cho đến khi tổng hợp lệ ( chỉ áp dụng cho số dương)
length = right - left + 1
*/