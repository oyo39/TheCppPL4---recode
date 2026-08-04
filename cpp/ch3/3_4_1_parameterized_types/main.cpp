#include "Vector.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

enum class VectorType { char_vector, string_vector, list_int_vector };

VectorType get_vector_type(istream& is) {
    char ch;
    if (!(is >> ch)) {
        throw runtime_error("No input for vector type");
    }

    switch (ch) {
        case 'c': return VectorType::char_vector;
        case 's': return VectorType::string_vector;
        case 'l': 
            if (!(is >> ch) || ch != 'i') {
                throw runtime_error("Expected 'li' for list<int> vector type");
            }
            return VectorType::list_int_vector;
        default: 
            char ch2;
            is >> ch2; // Read the next character to provide more context in the error message
            cout << "Unknown vector type: " << ch << ch2 << endl;
            throw runtime_error("Unknown vector type");
    }
}

void write(const Vector<char>& vc)
{
    for (int i = 0; i < vc.size(); ++i)
        cout << vc[i];
    cout << endl;
}

void write(const Vector<string>& vs)
{
    for (int i = 0; i < vs.size(); ++i)
        cout << vs[i] << '\n';
}

void write(const Vector<list<int>>& vli)
{
    for (int i = 0; i < vli.size(); ++i) {
        cout << "List " << i << ": ";
        for (const auto& val : vli[i]) {
            cout << val << ' ';
        }
        cout << endl;
    }
}

void f2(const Vector<string> &vs)
{
    for (auto& s : vs) {
        cout << s << '\n';
    }
}

int main() {
    Vector<char> vc(200);       // vector of 200 characters
    Vector<string> vs(17);      // vector of 17 strings
    Vector<list<int>> vli(45);  // vector of 45 lists of integers

    while(cin && !cin.eof()) {
        try {
            VectorType vt = get_vector_type(cin);
            int size;
            cin >> size;

            switch (vt) {
                case VectorType::char_vector: {
                    if (size > vc.size()) {
                        throw runtime_error("Size exceeds char vector capacity");
                    }

                    for (int i = 0; i < size; ++i) {
                        cin >> vc[i];
                    }
                    cout << "Read char vector of size " << size << endl;
                    continue; // Skip to the next iteration after reading char vector
                }
                case VectorType::string_vector: {
                    if (size > vs.size()) {
                        throw runtime_error("Size exceeds string vector capacity");
                    }

                    for (int i = 0; i < size; ++i) {
                        cin >> vs[i];
                    }
                    cout << "Read string vector of size " << size << endl;
                    continue; // Skip to the next iteration after reading string vector
                }
                case VectorType::list_int_vector: {
                    if (size > vli.size()) {
                        throw runtime_error("Size exceeds list<int> vector capacity");
                    }
                    
                    for (int i = 0; i < size; ++i) {
                        int list_size;
                        cin >> list_size;
                        list<int> li;
                        for (int j = 0; j < list_size; ++j) {
                            int value;
                            cin >> value;
                            li.push_back(value);
                        }
                        vli[i] = li;
                    }
                    cout << "Read list<int> vector of size " << size << endl;
                    continue; // Skip to the next iteration after reading list<int> vector
                }
                default:
                    throw runtime_error("Unhandled vector type");
            }
        } catch (const exception& e) {
            cerr << "Error reading char vector: " << e.what() << endl;
            return 1; // Exit the program on error
        }
    }

    write(vc);
    write(vs);
    write(vli);

    cout << "Demonstrating range-for loop with Vector<string>:" << endl;
    f2(vs);

    return 0;
}