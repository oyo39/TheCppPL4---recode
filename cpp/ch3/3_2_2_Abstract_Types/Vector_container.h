#include "Container.h"
#include "../3_2_1_3_Initializing_Containers/Vector.h"

class Vector_container : public Container {
    Vector v;
public:
    // Vector_container(int s): v(s) {}
    Vector_container(std::initializer_list<double> il): v(il) {}
    ~Vector_container() {}

    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};