#include <iostream>
#include <string>

using String = std::string;

class Cat
{
	String m_Name;

public:
	/*
		This is the default constructor
	*/
	Cat() : m_Name("Unknown") {}

	/*
		This is an argument constructor which take a name argument passed by reference and
		assigning name to the m_Name class variable by a member initializer list
	*/
	Cat(const String& name) : m_Name(name) {}

	const String& getName() const { 
		return m_Name; 
	}
};

int main(int argc, char** argv) {

	/*
		This calls the default constructor 
		Cleosaurus() : m_Name("Unknown") {}		   
		This object is allocated on the stack
		and will be automatically deleted when
		it leaves the scope and the stack pointer is cleared
	*/ 											
	Cat cat1; 							
	std::cout << cat1.getName() << std::endl;

	/*
		This calls the argument constructor 
		Cleosaurus(const String& name) : m_Name(name) {}
		This object is allocated on the stack
		and will be automatically deleted when
		it leaves the scope and the stack pointer is cleared
	*/ 
	Cat cat2("Cleosaurus"); 
	std::cout << cat2.getName() << std::endl;

	/*
		This is another way to call the argument constructor 
		Cleosaurus(const String& name) : m_Name(name) {}
		This object is allocated on the stack
		and will be automatically deleted when
		it leaves the scope and the stack pointer is cleared
	*/ 
	Cat cat3 = Cat("Azlan");
	std::cout << cat3.getName() << std::endl;

	/*
		To created an object on the heap we need a few things.
		First we need to make the object a pointer by using
		the "*" next we need to use the keyword "new"
		and finally we need to call "delete" to free
		the memory from the heap otherwise we will
		create a memory leak
	*/
	Cat* cat4 = new Cat("Turd");
	/*
		Now there are two ways we can call our getName
		method. We can either use the -> operator
	*/
	std::cout << cat4->getName() << std::endl;

	/*
		Or we can dereference the object and then
		use the "." operator like normal
	*/
	std::cout << (*cat4).getName() << std::endl;


	delete cat4;
	std::cin.get();
}