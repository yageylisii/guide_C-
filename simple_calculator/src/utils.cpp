//main alghorithms
#include "utils.hpp"

int solution (int first_operand, int second_operand) {
    return first_operand + second_operand;
}

int multiply (int first_operand, int second_operand) {
    return first_operand * second_operand;
}

int division (int first_operand, int second_operand) {
    return first_operand / second_operand;
}

int sub (int first_operand, int second_operand) {
    return first_operand - second_operand;
}

int querty_output (int first_op, int second_op, char * op) {
    if (*op == '-') {
        return sub(first_op, second_op);
    } else if (*op == '+') {
        return solution(first_op, second_op);
    } else if (*op == '*') {
        return multiply(first_op, second_op);
    } else if (*op == '/') {
        return division(first_op, second_op);
    }
    return 2;
}