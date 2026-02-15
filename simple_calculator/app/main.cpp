#include <iostream>
#include <utils.hpp>
#include <string>


int main (int args_cnt, char ** data) {
    if (args_cnt != 4) {
        std::cerr << "This file" << data[0] << "must have 2 parametrs\nfor example: ./build/main 4 4\n";
        return 1;
    }
    long long first_op = std::stoll(data[1]);
    char * ope = data[2];
    long long second_op = std::stoll(data[3]);
    std::cout << querty_output(first_op, second_op, ope) << "\n";

    return 0;
}