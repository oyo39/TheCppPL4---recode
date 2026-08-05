#include "Vector.h"
#include <iostream>
#include <string>
#include <list>
#include <stdexcept>
using namespace std;

template<typename T>
T readElement(std::istream& in) {
    T x;
    if (!(in >> x)) throw std::runtime_error("Failed to read element");
    return x;
}

// Không cần template specialization cho std::string vì nó đã được hỗ trợ bởi read_one<T> tổng quát.
// operator>> cho std::string đọc một token (bỏ qua whitespace đầu vào), nên hoàn toàn đúng với cách nhập vs từ input.txt.
// Và với định dạng đầu vào tệp input.txt thì cũng không cần định nghĩa read_one<char> (mà chỉ hữu ích nếu cần đọc luôn các ký tự khoảng trắng như: dấu cách, tab, xuống dòng; trong khi >> c sẽ bỏ qua các khoảng trắng -> cần cách đọc khác như in.get(c)).

template<>
std::list<int> readElement<std::list<int>>(std::istream& in) {
    int k;
    if (!(in >> k)) throw std::runtime_error("Failed to read list size");
    std::list<int> lst;
    for (int i = 0; i < k; i++) {
        int x;
        if (!(in >> x)) throw std::runtime_error("Failed to read list element");
        lst.push_back(x);
    }
    return lst;
}

template<typename T>
void readVector(std::istream& in, Vector<T>& vec) {
    int n;
    if (!(in >> n)) throw std::runtime_error("Failed to read vector size");

    if (n != vec.size())
        throw std::runtime_error("Vector size mismatch");

    for (int i = 0; i < n; i++) {
        vec[i] = readElement<T>(in);
    }
}

//---
template<typename T>
void writeElement(const T& elem, std::ostream& out) {
    out << elem << ' ';
}

template<>
void writeElement<std::list<int>>(const std::list<int>& lst, std::ostream& out) {
    out << "List: ";
    for (const auto& val : lst) {
        out << val << ' ';
    }
    out << std::endl;
}

template<typename T>
void writeVector(const Vector<T>& vec, std::ostream& out = std::cout) {
    for (int i = 0; i < vec.size(); ++i) {
        writeElement(vec[i], out);
    }
    out << std::endl;
}

void f2(const Vector<string> &vs)
{
    for (auto& s : vs) {
        cout << s << '\n';
    }
}
//---

int main() {
    Vector<char> vc(200);
    Vector<std::string> vs(17);
    Vector<std::list<int>> vli(45);

    std::string tag;
    // Đọc từ stdin (đã được redirect từ input.txt)
    std::cin >> tag; if (tag != "vc") throw std::runtime_error("Expected vc");
    readVector(std::cin, vc);

    std::cin >> tag; if (tag != "vs") throw std::runtime_error("Expected vs");
    readVector(std::cin, vs);

    std::cin >> tag; if (tag != "vli") throw std::runtime_error("Expected vli");
    readVector(std::cin, vli);

    //---
    writeVector(vc);
    writeVector(vs);
    writeVector(vli);

    cout << "Demonstrating range-for loop with Vector<string>:" << endl;
    f2(vs);
    //---

    return 0;
}