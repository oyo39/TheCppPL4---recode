#include "Container.h"
#include <list>
#include <stdexcept>

using namespace std;

class List_container : public Container {
    list<double> ld;
public:
    List_container() {}
    List_container(initializer_list<double> il) : ld{il} {}
    ~List_container() {}

    double& operator[](int);
    int size() const { return ld.size(); }
};

double& List_container::operator[](int i)
{
    for (auto& x : ld) {
        if (i==0) return x;
        --i;
    }
    throw out_of_range("List container");
}