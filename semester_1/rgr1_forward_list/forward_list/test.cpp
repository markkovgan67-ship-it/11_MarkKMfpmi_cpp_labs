
#include "forward_list_impl.h"
#include <iostream>
#include <cassert>
#include <sstream>

void Test1_DefaultConstructor() {
    std::cout << "Test 1: Default constructor... ";
    ForwardList list;
    assert(list.Size() == 0);
    std::cout << "PASSED\n";
}

void Test2_PushFront() {
    std::cout << "Test 2: PushFront... ";
    ForwardList list;
    list.PushFront(10);
    assert(list.Size() == 1);
    assert(list.Front() == 10);

    list.PushFront(20);
    assert(list.Size() == 2);
    assert(list.Front() == 20);
    std::cout << "PASSED\n";
}

void Test3_PopFront() {
    std::cout << "Test 3: PopFront... ";
    ForwardList list;
    list.PushFront(10);
    list.PushFront(20);

    list.PopFront();
    assert(list.Size() == 1);
    assert(list.Front() == 10);

    list.PopFront();
    assert(list.Size() == 0);
    std::cout << "PASSED\n";
}

void Test4_Remove() {
    std::cout << "Test 4: Remove... ";
    ForwardList list;
    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);
    list.PushFront(2);
    list.PushFront(4);

    list.Remove(2);
    // Проверяем, что осталось: 4, 3, 1
    assert(list.Size() == 3);

    // Проверяем первый элемент
    assert(list.Front() == 4);

    std::cout << "PASSED\n";
}

void Test5_CopyConstructor() {
    std::cout << "Test 5: Copy constructor... ";
    ForwardList list1;
    list1.PushFront(3);
    list1.PushFront(2);
    list1.PushFront(1);

    ForwardList list2 = list1;
    assert(list2.Size() == 3);
    assert(list2.Front() == 1);

    list1.PushFront(0);
    assert(list1.Size() == 4);
    assert(list2.Size() == 3);

    std::cout << "PASSED\n";
}

void Test6_Iterator() {
    std::cout << "Test 6: Iterator... ";
    ForwardList list;
    list.PushFront(3);
    list.PushFront(2);
    list.PushFront(1);

    
    int sum = 0;
    for (int value : list) {
        sum += value;
    }
    assert(sum == 6); // 1 + 2 + 3

    std::cout << "PASSED\n";
}

void Test7_InitializerList() {
    std::cout << "Test 7: Initializer list... ";
    ForwardList list = { 1, 2, 3, 4, 5 };
    assert(list.Size() == 5);
    assert(list.Front() == 1);

    std::cout << "PASSED\n";
}

void Test8_FindByValue() {
    std::cout << "Test 8: FindByValue... ";
    ForwardList list = { 1, 2, 3, 4, 5 };
    assert(list.FindByValue(3) == true);
    assert(list.FindByValue(6) == false);

    std::cout << "PASSED\n";
}

void Test9_Clear() {
    std::cout << "Test 9: Clear... ";
    ForwardList list = { 1, 2, 3 };
    list.Clear();
    assert(list.Size() == 0);

    std::cout << "PASSED\n";
}

void Test10_Print() {
    std::cout << "Test 10: Print... ";
    ForwardList list = { 1, 2, 3 };
    std::stringstream ss;
    list.Print(ss);

    std::string result = ss.str();
    assert(result == "1 2 3" || result == "1 2 3 ");

    std::cout << "PASSED\n";
}

int main() {
    std::cout << "=== Starting ForwardList Tests ===\n";

    try {
        Test1_DefaultConstructor();
        Test2_PushFront();
        Test3_PopFront();
        Test4_Remove();
        Test5_CopyConstructor();
        Test6_Iterator();
        Test7_InitializerList();
        Test8_FindByValue();
        Test9_Clear();
        Test10_Print();

        std::cout << "\n=== ALL TESTS PASSED ===\n";
        return 0;
    }
    catch (const std::exception& e) {
        std::cout << "\n=== TEST FAILED: " << e.what() << " ===\n";
        return 1;
    }
    catch (...) {
        std::cout << "\n=== UNKNOWN TEST FAILURE ===\n";
        return 1;
    }
}
