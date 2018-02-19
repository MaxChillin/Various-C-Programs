//#include <iostream>
//
//
//class Entity {
//public:
//	int x, y;
//	/*
//	Default parameters are away to allow the function to be called with no parameters
//	and have the function itself assign a default value.
//	If we call myFunc() with no parameters it will assign 0 to each variable.
//	*/
//	void myFunc(int x = 0, int y = 0, int z = 0) {
//		std::cout << "X = " << x << " Y = " << y << " Z = " << z << std::endl;
//	}
//
//
//};
//int main() {
//	
//	Entity e;
//
//	e.myFunc(3, 4, 5);
//	e.myFunc(3, 4);
//	e.myFunc(3);
//	e.myFunc();
//
//	std::cin.get();
//}