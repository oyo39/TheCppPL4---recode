#include "Container.h"
#include "Vector_container.h"
#include "List_container.h"
#include <iostream>

using namespace std;

void use(Container& c)
{
    const int sz = c.size();

    for (int i = 0; i != sz; ++i)
        cout << c[i] << endl;
}

void g()
{
    Vector_container vc {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    use(vc);
}

void h()
{
    List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    use(lc);
}

int main()
{
    cout << "Testing Vector container:" << endl;
    g();

    cout << "Testing List container:" << endl;
    h();
    
    return 0;
}