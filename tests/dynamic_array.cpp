#include <dynamic_array.hpp>
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
        std::cout << "Running tests on empty array...\n";
        DynamicArray<int> arr;
        TEST_ASSERT(arr.size() == 0, "size() of empty array");
        TEST_ASSERT(arr.empty(), "empty() should be true on empty array");
    }

    {
        std::cout << "Running push_back + size tests...\n";
        DynamicArray<int> arr;
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        TEST_ASSERT(arr.size() == 3, "size after 3 push_backs");
        TEST_ASSERT(!arr.empty(), "array is not empty after push_back");
    }

    {
        std::cout << "Running operator[] tests...\n";
        DynamicArray<int> arr;
        arr.push_back(5);
        arr.push_back(15);
        arr.push_back(25);
        TEST_ASSERT(arr[0] == 5, "operator[] index 0");
        TEST_ASSERT(arr[1] == 15, "operator[] index 1");
        TEST_ASSERT(arr[2] == 25, "operator[] index 2");
    }

    {
        std::cout << "Running front() and back() tests...\n";
        DynamicArray<int> arr;
        arr.push_back(42);
        arr.push_back(99);
        TEST_ASSERT(arr.front() == 42, "front() returns first element");
        TEST_ASSERT(arr.back() == 99, "back() returns last element");
    }

    {
        std::cout << "Running pop_back() tests...\n";
        DynamicArray<int> arr;
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);
        arr.pop_back();
        TEST_ASSERT(arr.size() == 2, "size after one pop_back");
        TEST_ASSERT(arr.back() == 2, "back() after pop_back");
    }

    {
        std::cout << "Running iterator tests...\n";
        DynamicArray<int> arr;
        arr.push_back(11);
        arr.push_back(22);
        arr.push_back(33);

        int expected[] = {11, 22, 33};
        int i = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it, ++i)
        {
            TEST_ASSERT(*it == expected[i], "iterator traversal matches values");
        }
    }

    std::cout << "✅ All tests passed!\n";
}
