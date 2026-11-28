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

// ============================================================
// T03 - Doc products.csv                (Assignee: Jin Long)
// ============================================================

// Tach mot dong theo ky tu sep. Bo ky tu '\r' (tep tao tren Windows).
vector<string> splitLine(string line, char sep) {
    vector<string> fields;
    string cur = "";
    for (int i = 0; i < (int)line.length(); i++) {
        char ch = line[i];
        if (ch == sep) {
            fields.push_back(cur);
            cur = "";
        } else if (ch != '\r') {
            cur = cur + ch;
        }
    }
    fields.push_back(cur);
    return fields;
}

// true neu text co 1..15 ky tu va chi gom chu so 0-9 (gia am, rong, co chu -> false).
// Gioi han 15 chu so de stoll khong bi tran so.
bool isDigits(string text) {
    if (text == "" || text.length() > 15) {
        return false;
    }
    for (int i = 0; i < (int)text.length(); i++) {
        if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }
    return true;
}

// Tim tuan tu vi luc dang doc tep, mang chua duoc sap xep. Khong co -> -1.
int indexOfId(const vector<Product>& products, string id) {
    for (int i = 0; i < (int)products.size(); i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Doc dataDir/products.csv vao products. Dong loi: in canh bao ra cerr kem so dong, bo qua.
// Tra ve false neu khong mo duoc tep; tep rong van tra ve true.
bool loadProducts(string dataDir, vector<Product>& products) {
    ifstream file(dataDir + "/products.csv");
    if (!file.is_open()) {
        cerr << "Error: cannot open " << dataDir << "/products.csv" << endl;
        return false;
    }

    string line;
    getline(file, line);            // bo dong tieu de
    int lineNo = 1;

    while (getline(file, line)) {
        lineNo = lineNo + 1;
        vector<string> fields = splitLine(line, ',');

        if (fields.size() != 6) {
            cerr << "Warning: products.csv line " << lineNo << ": wrong column count" << endl;
            continue;
        }
        if (!isDigits(fields[4])) {
            cerr << "Warning: products.csv line " << lineNo << ": invalid price" << endl;
            continue;
        }
        int r = toTenths(fields[5]);
        if (r < 0 || r > 50) {
            cerr << "Warning: products.csv line " << lineNo << ": invalid rating" << endl;
            continue;
        }
        if (indexOfId(products, fields[0]) != -1) {
            cerr << "Warning: products.csv line " << lineNo << ": duplicate id "
                 << fields[0] << ", keep first" << endl;
            continue;
        }

        Product p;
        p.id = fields[0];
        p.name = fields[1];
        p.category = fields[2];
        p.brand = fields[3];
        p.price = stoll(fields[4]);
        p.ratingTenths = r;
        products.push_back(p);
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: p5 <data_folder> <product_id> [store_id] [K] [max_price]"
             << " [--brand <brand>] [--export <file.csv>]" << endl;
        return 1;
    }

    vector<Product> products;
    if (!loadProducts(argv[1], products)) {
        return 1;
    }
    cout << "Loaded " << products.size() << " products" << endl;   // tam thoi, de kiem tra T03
    return 0;
}
