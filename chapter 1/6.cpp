/*
Word Frequency in Text
Trung bình
Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

Example
Input
abc  def abc 
abc abcd def 

Output 
abc 3
abcd 1
def 2
*/
/*
Đọc toàn bộ văn bản đến hết đầu vào. Mỗi từ là một dãy liên tiếp các chữ cái
ASCII hoặc chữ số, dài tối đa 20 ký tự. Các ký tự khác là dấu phân cách.
Phân biệt chữ hoa và chữ thường. In mỗi từ khác nhau và số lần xuất hiện
trên một dòng, cách nhau một dấu cách, theo thứ tự từ điển.
*/

#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<std::string, long long> frequencies;
    std::string word;
    char ch;
    while (std::cin.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            word += ch;
        } else if (!word.empty()) {
            ++frequencies[word];
            word.clear();
        }
    }
    if (!word.empty()) {
        ++frequencies[word];
    }

    for (const auto& entry : frequencies) {
        std::cout << entry.first << ' ' << entry.second << '\n';
    }
}
