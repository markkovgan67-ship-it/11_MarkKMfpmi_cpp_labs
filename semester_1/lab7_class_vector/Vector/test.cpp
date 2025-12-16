#include "vector_impl.h"
#include <iostream>
#include <cassert>

int main() {
    std::cout << " Testing Vector class \n" << std::endl;

    std::cout << "1. Testing constructors:" << std::endl;
    Vector v1; 
    Vector v2(3); 
    Vector v3 = { 1, 2, 3, 4, 5 }; 

    assert(v1.Size() == 0);
    assert(v2.Size() == 3);
    assert(v3.Size() == 5);
    std::cout << "    Constructors work" << std::endl;

    
    std::cout << "\n2. Testing element access:" << std::endl;
    assert(v3[0] == 1);
    assert(v3[2] == 3);
    assert(v3[4] == 5);

    
    bool got_exception = false;
    try {
        v3.At(10);
    }
    catch (const std::out_of_range&) {
        got_exception = true;
    }
    assert(got_exception);
    std::cout << "    Element access works" << std::endl;

   
    std::cout << "\n3. Testing PushBack/PopBack:" << std::endl;
    Vector v;
    v.PushBack(10);
    v.PushBack(20);
    v.PushBack(30);

    assert(v.Size() == 3);
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);

    v.PopBack();
    assert(v.Size() == 2);
    assert(v[1] == 20);
    std::cout << "    PushBack/PopBack work" << std::endl;

   
    std::cout << "\n4. Testing Clear/Reserve:" << std::endl;
    v.Clear();
    assert(v.Size() == 0);

    Vector v4 = { 1, 2, 3 };
    v4.Reserve(10);
    assert(v4.Capacity() >= 10);
    assert(v4.Size() == 3);
    std::cout << "    Clear/Reserve work" << std::endl;

   
    std::cout << "\n5. Testing assignment operator:" << std::endl;
    Vector v5 = { 100, 200, 300 };
    Vector v6;
    v6 = v5;

    assert(v6.Size() == 3);
    assert(v6[0] == 100);
    assert(v6[2] == 300);
    std::cout << "   Assignment works" << std::endl;

   
    std::cout << "\n6. Testing output:" << std::endl;
    Vector v7 = { 7, 8, 9 };
    std::cout << "   Vector v7 = " << v7 << std::endl;

    
    std::cout << "\n7. Quick integration test:" << std::endl;
    Vector vec;

  
    for (int i = 0; i < 10; ++i) {
        vec.PushBack(i * 10);
    }

    
    assert(vec.Size() == 10);
    assert(vec[0] == 0);
    assert(vec[9] == 90);

    
    vec.PopBack();
    vec.PopBack();
    assert(vec.Size() == 8);

    
    vec[5] = 999;
    assert(vec[5] == 999);

    std::cout << "   Final vector: " << vec << std::endl;
    std::cout << "   Size: " << vec.Size() << ", Capacity: " << vec.Capacity() << std::endl;

    std::cout << "\n All tests passed!" << std::endl;
    return 0;
}