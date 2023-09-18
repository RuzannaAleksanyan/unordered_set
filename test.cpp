#include "unordered_set.h"
#include <iostream>

void test_unordered_set() {
    unordered_set set;

    // Test insert and contains
    set.insert(42);
    set.insert(7);
    set.insert(15);
    set.insert(30);

    std::cout << "Insert and Contains Test:" << std::endl;
    std::cout << "Contains 7: " << (set.contains(7) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 42: " << (set.contains(42) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 15: " << (set.contains(15) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 30: " << (set.contains(30) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 99: " << (set.contains(99) ? "Yes" : "No") << std::endl;

    // Test size and empty
    std::cout << "Size: " << set.size() << std::endl;
    std::cout << "Empty: " << (set.empty() ? "Yes" : "No") << std::endl;

    // Test remove
    set.remove(7);
    set.remove(42);

    std::cout << "After Remove Test:" << std::endl;
    std::cout << "Contains 7: " << (set.contains(7) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 42: " << (set.contains(42) ? "Yes" : "No") << std::endl;
    std::cout << "Size: " << set.size() << std::endl;

    // Test clear
    set.clear();

    std::cout << "After Clear Test:" << std::endl;
    std::cout << "Size: " << set.size() << std::endl;
    std::cout << "Empty: " << (set.empty() ? "Yes" : "No") << std::endl;

    // Test reserve and load_factor
    set.reserve(100);
    std::cout << "After Reserve Test:" << std::endl;
    std::cout << "Bucket Count: " << set.bucket_count() << std::endl;
    std::cout << "Load Factor: " << set.load_factor() << std::endl;

    // Test bucket_size
    std::cout << "Bucket Size at 0: " << set.bucket_size(0) << std::endl;
    std::cout << "Bucket Size at 1: " << set.bucket_size(1) << std::endl;

    // Test rehash
    set.insert(5);
    set.insert(50);

    std::cout << "After Rehash Test:" << std::endl;
    std::cout << "Bucket Count: " << set.bucket_count() << std::endl;
    std::cout << "Bucket Size at 0: " << set.bucket_size(0) << std::endl;
    std::cout << "Bucket Size at 1: " << set.bucket_size(1) << std::endl;

    // Test print
    std::cout << "Print Test:" << std::endl;
    set.print();
}

int main() {
    test_unordered_set();
    return 0;
}
