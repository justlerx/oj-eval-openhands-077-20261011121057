#include "CrossArray.hpp"
#include <iostream>
#include <cassert>

int main() {
    std::cout << "Testing CrossArray class..." << std::endl;

    // Test 1: Constructor
    sjtu::CrossArray arr1(5);
    std::cout << "Test 1 passed: Constructor" << std::endl;

    // Test 2: InsertArrays
    int data1[] = {1, 2, 3};
    assert(arr1.InsertArrays(data1, 3) == true);
    std::cout << "Test 2 passed: InsertArrays" << std::endl;

    // Test 3: At and AtArray
    assert(arr1.At(0, 0) == 1);
    assert(arr1.At(0, 1) == 2);
    assert(arr1.At(0, 2) == 3);
    const int* array0 = arr1.AtArray(0);
    assert(array0 != nullptr);
    assert(array0[0] == 1);
    std::cout << "Test 3 passed: At and AtArray" << std::endl;

    // Test 4: Insert more arrays
    int data2[] = {4, 5};
    assert(arr1.InsertArrays(data2, 2) == true);
    assert(arr1.At(1, 0) == 4);
    assert(arr1.At(1, 1) == 5);
    std::cout << "Test 4 passed: Multiple InsertArrays" << std::endl;

    // Test 5: AppendArrays
    int data3[] = {6, 7};
    arr1.AppendArrays(data3, 1, 2);
    assert(arr1.At(1, 2) == 6);
    assert(arr1.At(1, 3) == 7);
    assert(arr1.AtArray(1)[2] == 6);
    std::cout << "Test 5 passed: AppendArrays" << std::endl;

    // Test 6: Copy constructor
    sjtu::CrossArray arr2 = arr1;
    assert(arr2.At(0, 0) == 1);
    assert(arr2.At(1, 3) == 7);
    std::cout << "Test 6 passed: Copy constructor" << std::endl;

    // Test 7: IsSame
    assert(arr1.IsSame(arr1) == true);
    assert(arr1.IsSame(arr2) == false);
    std::cout << "Test 7 passed: IsSame" << std::endl;

    // Test 8: WhichGreater
    sjtu::CrossArray arr3(3);
    int data4[] = {10, 20, 30, 40};
    arr3.InsertArrays(data4, 4);
    sjtu::CrossArray& greater1 = arr1.WhichGreater(arr3);
    // arr1 has 3+4=7 elements, arr3 has 4 elements, so arr1 should be greater
    assert(&greater1 == &arr1);
    
    sjtu::CrossArray& greater2 = arr3.WhichGreater(arr1);
    assert(&greater2 == &arr1);  // arr1 is still greater
    
    sjtu::CrossArray arr4(2);
    int data5[] = {1, 2, 3, 4, 5};
    arr4.InsertArrays(data5, 5);
    sjtu::CrossArray& greater3 = arr3.WhichGreater(arr4);
    // arr3 has 4 elements, arr4 has 5 elements, so arr4 should be greater
    assert(&greater3 == &arr4);
    std::cout << "Test 8 passed: WhichGreater" << std::endl;

    // Test 9: DoubleCrossLength
    // We can't directly access capacity as it's private
    // Instead, we'll test the functionality
    arr1.DoubleCrossLength();
    // After doubling, we should be able to insert more arrays
    // The original capacity was 5, so after doubling it should be 10
    // We've already inserted 2 arrays, so we should be able to insert 8 more
    int data6[] = {8, 9, 10};
    assert(arr1.InsertArrays(data6, 3) == true);
    assert(arr1.At(2, 0) == 8);

    std::cout << "Test 9 passed: DoubleCrossLength" << std::endl;

    // Test 10: Edge cases
    // Try to insert beyond original capacity (should work after DoubleCrossLength)
    int data7[] = {11};
    assert(arr1.InsertArrays(data7, 1) == true);
    assert(arr1.InsertArrays(data7, 1) == true);
    std::cout << "Test 10 passed: Edge cases" << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}