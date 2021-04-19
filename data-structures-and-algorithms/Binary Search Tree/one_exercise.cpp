//
// Created by Peter Hoc on 04/04/2018.
//

#include <iostream>
#include <fstream>
#include "bst.h"
#include <iomanip>

using namespace std;

/**
 *
 * Cài đặt cây nhị phân tìm kiếm
 * Mô tả: Cho tệp văn bản. Hãy xây dựng cây nhị phân tìm kiếm, có khóa là một từ trong tệp văn bản.
 * Cấu trúc dữ liệu biểu diễn một nút của cây nhị phân có ít nhất hai trường: từ (khóa) và số lần xuất hiện của từ trong tệp.
 * Đọc tệp văn bản để tạo cây nhị phân tìm kiếm, nếu có từ lặp lại thì chỉ tăng số lần xuất hiện của từ.
 * In các từ và số lần xuất hiện mỗi từ.
 *
 * */

struct data {
    std::string word;
    size_t count;

    data(string word, size_t count = 1) : word(std::move(word)), count(count) {}

    data(const data &o) : word(o.word), count(o.count) {}

    data(data &&o) noexcept : word(std::move(o.word)), count(o.count) {}

    friend bool operator==(const data &lhs, const data &rhs) { return lhs.word == rhs.word; }

    friend bool operator<(const data &lhs, const data &rhs) { return lhs.word < rhs.word; }

    friend ostream &operator<<(ostream &os, const data &d) {
        return os << '[' << setw(10) << d.word << ", " << setw(2) << d.count << ']';
    }
};

struct word_tree : public bst<data> {
protected:
    void insert_not_success(data &value) override { ++value.count; }
};

int main() {
    //open input file and output file
    ifstream in_file("in.txt");
    ofstream file_out("out.txt");
    if (!in_file || !file_out) {
        cout << "Can't open file...\n";
        return EXIT_FAILURE;
    }


    //read text from input file, and insert data to tree
    word_tree my_tree;
    for (string word; !in_file.eof();) {
        in_file >> word;
        my_tree.insert({word, 1});
    }
    //change ostream here
    //e.g. [&os = cout]
    my_tree.inorder([&os = file_out](auto &&d) { os << d << '\n'; });


    //close files
    in_file.close();
    file_out.close();
    return EXIT_SUCCESS;
}
