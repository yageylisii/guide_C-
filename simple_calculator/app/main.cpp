#include <iostream>
#include <utils.hpp>
#include <string>

int main (int args_cnt, char ** data) {
    if (args_cnt != 3) {
        std::cerr << "This file" << data[0] << "must have 2 parametrs\nfor example: ./build/main 4 4\n";
        return 1;
    }
    long long first_op = std::stoll(data[1]);
    long long second_op = std::stoll(data[2]);
    std::cout << solution(first_op, second_op) << "\n";

    return 0;
} 