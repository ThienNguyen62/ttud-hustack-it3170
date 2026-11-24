/*
Simulation prefix Sum on 2D array
Trung bình
PREFIX_SUM
Given a table of n rows (1, 2, ..., n) and m columns (1, 2, ..., m). Each cell (i,j) has a non-negative integer a(i,j).
Perform a sequence of queries (r1, c1, r2, c2) which returns the sum of elements of the sub-table from row r1 to row r2 
and from column c1 to column c2 (1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m).

Input
Line 1: contains n and m (1 <= n, m <= 1000)
Line i+1(i = 1, 2, ..., n): contains the elements on row i of the table    
Line n+2: contains a positive integer Q (1 <= Q <= 100000) which is the number of queries 
Line q+n+2 (q = 1, 2, ..., Q): contains r1, c1, r2, c2 (1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m)

Output
Write in each line the result of the corresponding query read from the input

Example
Input
3 4
1 1 0 1 
1 1 1 0 
0 1 0 0 
3
2 3 3 4
1 3 3 4
2 2 3 4

Output 
1
2
3
*/

/*
Đọc bảng n hàng, m cột và Q truy vấn. Mỗi truy vấn cho hai góc
(r1, c1) và (r2, c2), đánh số từ 1. In tổng các ô trong hình chữ nhật
tính cả hai hàng và hai cột biên.
*/

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rows, cols;
    std::cin >> rows >> cols;
    std::vector<std::vector<long long>> prefix(rows + 1,std::vector<long long>(cols + 1));
    for (int r = 1; r <= rows; ++r) {
        for (int c = 1; c <= cols; ++c) {
            long long value;
            std::cin >> value;
            prefix[r][c] = value + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
        }
    }

    int queries;
    std::cin >> queries;
    for (int query = 0; query < queries; ++query) {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;
        const long long sum = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
        std::cout << sum << '\n';
    }
}
/*

trường hợp không biết prefix sum 2d sẽ giải như nào
c1 brute force duyệt tất cả các ô trong hình chữ nhật
khi tính tổng một hình chữ nhật, cách đơn giản nhất là duyệt từng hàng
rồi từng cột trong vùng cần tính
code
long long sum = 0;

for (int r = r1; r <= r2; r++) {
    for (int c = c1; c <= c2; c++) {
        sum += a[r][c];
    }
}
vòng ngoài duyệt hàng, vòng trong duyệt cột của từng hàng

nhược điểm bảng sẽ có max size = 1000x1000 =10^6 ô
10^5 .10^6 = 10^11 lượt xử lí

câu hỏi đặt ra là bảng có thay đổi gì sau mỗi lượt xử lí không
nếu không thay đổi tại sao mỗi lần truy cập lại cộng các ô từ đầu, có thể tính sẵn thông tin nào không

ta muốn tính prefix[r][c]
tức là tổng của hình chữ nhật từ (1,1) đến (r,c)
hãy quan sát ta thấy 
prefix[r-1][c] là tổng của tất cả các hàng phía trên hàng r
prefix[r][c-1]: tổng tất cả các cột bên trái cột c
cộng hai vùng này ta gần như có toàn bộ hình chữ nhật cần tìm
tuy vậy một số ô bị tính hai lần do đó ta phải trừ phần bị tính hai lần đi một lần
cuối cùng, thêm ô hiện tại a[r][c]

prefix[r][c] =a[r][c] + prefix[r-1][c] + prefix[r][c-1] - prefix[r-1][c-1]
lấy toàn bộ phần trên X + toàn bộ phần bên trái X - phần trùng của 2 phần + X
với X = prefix [r][c]

*/