#include <vector.hpp>
#include <iostream>

int main()
{
    Vector<int> a;

    a.push_back(1);

    std::cout << "Printing the vector" << std::endl;

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " " << std::endl;
    }

    return 0;
}