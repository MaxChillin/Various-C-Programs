#include <iostream>


class Entity {
public:
	int x, y;
	
	Entity() :
		x(0), y(2)
	{
		std::cout << "Entity created with x = " << x << " and y = " << y << std::endl;
	}

	

};
int main() {
	Entity e;
	std::cin.get();
}
