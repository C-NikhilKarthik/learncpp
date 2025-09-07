#include <vector.hpp>
#include <iostream>
#include <cassert>

int main()
{
    Vector<int> v;
    v.push_back(42);
    v.push_back(99);

    assert(v.size() == 2);
    assert(v[0] == 42);
    assert(v[1] == 99);

    std::cout << "✅ Vector tests passed!\n";
    return 0;
}
