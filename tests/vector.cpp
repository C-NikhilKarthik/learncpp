#include <vector.hpp>
#include <iostream>
#include <cassert>

#define TEST_ASSERT(expr, msg)                       \
    if (!(expr))                                     \
    {                                                \
        std::cerr << "Test failed: " << msg << "\n"; \
        std::abort();                                \
    }

int main()
{
    {
        std::cout << "Running tests on empty vector...\n";
        Vector<int> vec;
        TEST_ASSERT(vec.size() == 0, "size() of empty vector");
        TEST_ASSERT(vec.empty(), "empty() should be true on empty vector");
    }

    {
        std::cout << "Running push_back + size tests...\n";
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        TEST_ASSERT(vec.size() == 3, "size after 3 push_backs");
        TEST_ASSERT(!vec.empty(), "vector is not empty after push_back");
    }

    {
        std::cout << "Running operator[] tests...\n";
        Vector<int> vec;
        vec.push_back(5);
        vec.push_back(15);
        vec.push_back(25);
        TEST_ASSERT(vec[0] == 5, "operator[] index 0");
        TEST_ASSERT(vec[1] == 15, "operator[] index 1");
        TEST_ASSERT(vec[2] == 25, "operator[] index 2");
    }

    {
        std::cout << "Running front() and back() tests...\n";
        Vector<int> vec;
        vec.push_back(42);
        vec.push_back(99);
        TEST_ASSERT(vec.front() == 42, "front() returns first element");
        TEST_ASSERT(vec.back() == 99, "back() returns last element");
    }

    {
        std::cout << "Running pop_back() tests...\n";
        Vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.pop_back();
        TEST_ASSERT(vec.size() == 2, "size after one pop_back");
        TEST_ASSERT(vec.back() == 2, "back() after pop_back");
    }

    {
        std::cout << "Running iterator tests...\n";
        Vector<int> vec;
        vec.push_back(11);
        vec.push_back(22);
        vec.push_back(33);

        int expected[] = {11, 22, 33};
        int i = 0;
        for (auto it = vec.begin(); it != vec.end(); ++it, ++i)
        {
            TEST_ASSERT(*it == expected[i], "iterator traversal matches values");
        }
    }

    {
        std::cout << "Running reallocation tests...\n";
        Vector<int> vec;
        for (int i = 0; i < 100; i++)
        {
            vec.push_back(i);
        }
        TEST_ASSERT(vec.size() == 100, "size after pushing 100 elements");
        TEST_ASSERT(vec.front() == 0, "front after many push_backs");
        TEST_ASSERT(vec.back() == 99, "back after many push_backs");
    }

    std::cout << "✅ All Vector tests passed!\n";
}
