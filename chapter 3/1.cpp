/*Cut Material
Khó
backtracking + bitmask + pruning
Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
Example
Input
7 5
4
1 5
6 2
2 2
4 3
Output
1*/

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

struct Piece {
    int height;
    int width;

    int area() const { return height * width; }
};

bool canPack(int height, int width, const std::vector<Piece>& pieces,
             std::array<int, 10>& occupied, std::size_t index) {
    if (index == pieces.size()) {
        return true;
    }

    auto [pieceHeight, pieceWidth] = pieces[index];
    const int orientationCount = pieceHeight == pieceWidth ? 1 : 2;
    for (int orientation = 0; orientation < orientationCount; ++orientation) {
        for (int row = 0; row + pieceHeight <= height; ++row) {
            for (int col = 0; col + pieceWidth <= width; ++col) {
                const int mask = ((1 << pieceWidth) - 1) << col;
                int end = row;
                while (end < row + pieceHeight && (occupied[end] & mask) == 0) {
                    ++end;
                }
                if (end != row + pieceHeight) {
                    continue;
                }

                for (int r = row; r < end; ++r) {
                    occupied[r] |= mask;
                }
                if (canPack(height, width, pieces, occupied, index + 1)) {
                    return true;
                }
                for (int r = row; r < end; ++r) {
                    occupied[r] &= ~mask;
                }
            }
        }
        std::swap(pieceHeight, pieceWidth);
    }
    return false;
}

int main() {
    int height, width, count;
    if (!(std::cin >> height >> width >> count)) {
        return 0;
    }

    std::vector<Piece> pieces(count);
    int totalArea = 0;
    for (auto& piece : pieces) {
        std::cin >> piece.height >> piece.width;
        const bool fits = piece.height <= height && piece.width <= width;
        const bool fitsRotated = piece.width <= height && piece.height <= width;
        if (!fits && !fitsRotated) {
            std::cout << 0 << '\n';
            return 0;
        }
        totalArea += piece.area();
    }
    if (totalArea > height * width) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::sort(pieces.begin(), pieces.end(), [](const Piece& a, const Piece& b) {
        return a.area() > b.area();
    });

    std::array<int, 10> occupied{};
    std::cout << canPack(height, width, pieces, occupied, 0) << '\n';
}
/*
Bố trí n hình chữ nhật
Bài toán tìm kiếm tổ hợp
|
Thử từng vị trí và hướng xoay
Brute Force
|
Loại ngay cách đặt không hợp lệ
Backtracking
|
Đặt hình lớn trước, kiểm tra diện tích
Pruning và heuristic
|
Dùng bit để kiểm tra cả hàng
Backtracking + Bitmask

*/