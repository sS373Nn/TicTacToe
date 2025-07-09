#include "bitwise-engine/src/OperationNode.hpp"
#include <iostream>
#include <cassert>

void test_xor_operation() {
    uint64_t input = 0b10101010;
    uint8_t mask = 0b11110000;
    
    operation_map.at(OperationType::XOR)(input, mask);
    
    assert(input == 0b01011010);
    std::cout << "XOR operation test: PASSED" << std::endl;
}

void test_not_operation() {
    uint64_t input = 0b10101010;
    uint8_t mask = 0b11111111; // ignored for NOT
    
    operation_map.at(OperationType::NOT)(input, mask);
    
    assert((input & 0xFF) == 0b01010101);
    std::cout << "NOT operation test: PASSED" << std::endl;
}

void test_shift_operation() {
    uint64_t input = 0b10101010;
    uint8_t shiftAmount = 2;
    
    operation_map.at(OperationType::SHIFT)(input, shiftAmount);
    
    assert(input == 0b1010101000);
    std::cout << "SHIFT operation test: PASSED" << std::endl;
}

int main() {
    std::cout << "Testing new bitwise operations..." << std::endl;
    
    test_xor_operation();
    test_not_operation();
    test_shift_operation();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}