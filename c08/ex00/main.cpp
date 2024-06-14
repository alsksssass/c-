#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
int main() {
    try {
        //const vecotor 테스트
        int arr[5] = {0,1,2,3,4};
        const std::vector<int> v (arr, arr + sizeof(arr) / sizeof(int));
        std::vector<int>::const_iterator it = easyfind(v, 3);
        (void)it;
        // std::vector 테스트
        std::vector<int> vec;
        for(int i = 0; i < 5; i++)
            vec.push_back(i);
        std::vector<int>::iterator vec_it = easyfind(vec, 3);
        std::cout << "Found value 3 in vector at position: " << std::distance(vec.begin(), vec_it) << std::endl;
        
        // std::list 테스트
        std::list<int> lst;
        for(int i = 0; i < 5; i++)
            lst.push_back(i*10);
        std::list<int>::iterator lst_it = easyfind(lst, 40);
        std::cout << "Found value 30 in list at position: " << std::distance(lst.begin(), lst_it) << std::endl;
        
        // 찾지 못했을 때 예외 처리 테스트
        easyfind(vec, 6); // 이 줄은 예외를 발생시킬 것입니다
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}