#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#define MAX_VAL 750
// void a(void){ system("leaks a.out");}
int main(int, char**)
{
    // atexit(a);    
    Array<int> a;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// int main() {
//     Array<int> arr(5);
    
//     // 배열 요소 초기화
//     for (int i = 0; i < 5; ++i) {
//         arr[i] = i * 2;
//     }
    
//     // 상수 참조를 통해 배열 요소를 읽음
//     const Array<int>& constArr = arr;
    
//     for (int i = -1; i < 5; ++i) {
//         try{
//         std::cout << constArr[i] << " "; // 상수 참조를 통해 읽기
//         }
//         catch(const std::exception &e)
//         {
//             std::cout << e.what() << std::endl;
//         }
//     }
//     std::cout << std::endl;
    
//     return 0;
// }