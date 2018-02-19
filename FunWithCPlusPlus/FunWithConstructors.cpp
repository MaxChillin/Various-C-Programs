#include <iostream>

class Entity
{
public:
	int x, y;

	Entity() {
		x = 0;
		y = 0;
		std::cout << "Created" << std::endl;
	}

	~Entity() {
		std::cout << "Destroyed" << std::endl;
	}
	void print() {
		std::cout << x << " " << y << std::endl;
	}

};

int main() {
	{// start of scope
	Entity e;
	e.print();

	}// end of scope
	std::cin.get();
}

