#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <set>
#include "Span.hpp"

int main() {
    try {
        // 단일 숫자 추가 테스트
        Span sp(7);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(-2147483648);
        sp.addNumber(2147483647);
        
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        
        // 여러 숫자 추가 테스트
        
        
        // 예외 처리 테스트
        Span sp3(3);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);
        // sp3.addNumber(4); // 예외 발생: Span is full
        
        Span sp4(2);
        sp4.addNumber(1);
        // sp4.shortestSpan(); // 예외 발생: Not enough numbers to find a span
        // sp4.longestSpan(); // 예외 발생: Not enough numbers to find a span

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    Span test(50);
    test.rangeAdd();
    std::cout << "Longest Span: " << test.longestSpan() << std::endl;
    std::cout << "Shortest Span: " << test.shortestSpan() << std::endl;
    
    return 0;
}