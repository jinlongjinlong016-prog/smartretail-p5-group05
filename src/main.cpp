// SmartRetail P5 - Goi y san pham thay the (Product substitution)
// Build: g++ -std=c++17 -Wall -Wextra src/main.cpp -o bin/p5
// Moi task nam trong mot vung rieng co comment ghi ma task.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================================
// T02 - Struct + doc rating            (Assignee: To Chau)
// ============================================================

struct Product {
    string id;
    string name;
    string category;
    string brand;
    long long price;    // VND, so nguyen
    int ratingTenths;   // rating x 10, vi du 4.7 -> 47
};

struct StockItem {
    string storeId;
    string productId;
    int stock;
};

// Doi chuoi rating thanh so nguyen "phan muoi": "4.7" -> 47, "5" -> 50.
// Chi nhan dang "d" hoac "d.d", gia tri toi da 5.0.
// Chuoi khong hop le -> tra ve -1.
int toTenths(string text) {
    int n = text.length();
    int result = -1;

    if (n == 1 && text[0] >= '0' && text[0] <= '9') {
        result = (text[0] - '0') * 10;
    } else if (n == 3 && text[0] >= '0' && text[0] <= '9' && text[1] == '.'
               && text[2] >= '0' && text[2] <= '9') {
        result = (text[0] - '0') * 10 + (text[2] - '0');
    }

    if (result > 50) {
        result = -1;        // rating lon hon 5.0 la sai
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: p5 <data_folder> <product_id> [store_id] [K] [max_price]"
             << " [--brand <brand>] [--export <file.csv>]" << endl;
        return 1;
    }
    cout << "Data folder: " << argv[1] << endl;   // T03, T04 se doc du lieu o day.
    return 0;
}
