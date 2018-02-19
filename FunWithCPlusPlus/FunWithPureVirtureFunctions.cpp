//#include <iostream>
//#include <string>
//
///*
//	This class acting like an interface in Java. By setting the getClassName method = 0
//	it says every class that inherits from it must define its own version of that
//	method.
//*/
//class Printable
//{
//public:
//	virtual std::string getClassName() = 0;
//};
//
//class Entity : public Printable {
//public:
//	std::string getClassName() override { return "Entity"; }
//};
//
//class Player : public Printable {
//public:
//	std::string getClassName() override { return "Player"; }
//};
//
///*
//	The nice thing about pure virtual functions is that they allow you to create functions
//	like this print function and pass any of the inherited class members to it.
//*/
//void Print(Printable* obj) {
//	std::cout << obj->getClassName() << std::endl;
//}
//
//int main() {
//	Entity* e = new Entity();
//	Player* p = new Player();
//	Print(e);
//	Print(p);
//
//	std::cin.get();
//}