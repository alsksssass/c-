#include "Point.hpp"
#include <iostream>
int main()
{
	Point a(0,0);
	Point b(5,0);
	Point c(0,5);
	Point d = c;
	Point arr[] = {Point(1,1), Point(2,2), Point(5,5), Point(-1,1), Point(3,1), Point(5,0),Point(0,5), Point(2.5f,2.5f), Point(1,3),Point(4,1)};
	for (int i = 0; i < 10; i++)
	{
		std::cout << "삼각형 abc에 "<< i << "번  좌표"<< "(" << arr[i].get_x() << ", "<< arr[i].get_y() << ") " << "는" << std::endl;
		if (bsp(a, b, c, arr[i]))
			std::cout << " 내부에 있습니다." << std::endl;
		else
			std::cout << " 외부에 있습니다 " << std::endl;
	}
}
	/*P1(1, 1): 삼각형 내부에 있는 점
	P2(2, 2): 삼각형 내부에 있는 점
	P3(5, 5): 삼각형 외부에 있는 점
	P4(-1, 1): 삼각형 외부에 있는 점
	P5(3, 1): 삼각형 내부에 있는 점
	P6(5, 0): 삼각형의 변 위에 있는 점
	P7(0, 5): 삼각형의 변 위에 있는 점
	P8(2.5, 2.5): 삼각형 외부에 있는 점
	P9(1, 3): 삼각형 내부에 있는 점
	P10(4, 1): 삼각형 외부에 있는 점*/
