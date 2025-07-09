#include "bitwise-engine/src/OperationNode.hpp"
#include <iostream>
#include <cassert>

void test_shift_operation_with_shiftAmount() {
    std::cout << "Testing OperationNode with SHIFT operation..." << std::endl;
    
    // Create a SHIFT operation node with shiftAmount=3
    OperationNode shiftNode(8, OperationType::SHIFT, 0, 3);
    
    uint64_t input = 0b00000101; // 5 in binary
    uint8_t offset = 0;
    uint64_t output = 0;
    
    shiftNode.apply_operation_node(input, offset, output);
    
    // Expected: 5 << 3 = 40 (0b00101000)
    assert(output == 0b00101000);
    std::cout << "SHIFT with shiftAmount test: PASSED" << std::endl;
}

void test_operation_node_with_mask() {
    std::cout << "Testing OperationNode with OR operation..." << std::endl;
    
    // Create an OR operation node with mask
    OperationNode orNode(8, OperationType::OR, 0b11110000, 0);
    
    uint64_t input = 0b10101010;
    uint8_t offset = 0;
    uint64_t output = 0;
    
    orNode.apply_operation_node(input, offset, output);
    
    // Expected: 0b10101010 | 0b11110000 = 0b11111010
    assert(output == 0b11111010);
    std::cout << "OR with mask test: PASSED" << std::endl;
}

int main() {
    std::cout << "Testing OperationNode shift operations..." << std::endl;
    
    test_shift_operation_with_shiftAmount();
    test_operation_node_with_mask();
    
    std::cout << "All OperationNode tests passed!" << std::endl;
    return 0;
}