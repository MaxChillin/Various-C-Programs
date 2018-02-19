//#include <iostream>
//#include "Print.h"
//
///*
//	When we add the '*' to the int type we are telling the function that we are going to pass the
//	memory address not just the value. 
//*/
//void increment(int* value) {
//	/*
//		If we used value++ without the * it would change the memory address, but now we are
//		incrementing the value not the address.
//		value++ would increment the memory address.
//		*value++ would increment the memory address first then de-reference value.
//		(*value)++ de-references the variable first then increments the value.
//	*/
//	(*value)++;
//}
//
///*
//	Now we are telling the function that we want to pass the variabale by reference
//*/
//void decrement(int& value) {
//	value--;
//}
//
//int main() {
//
//	int a = 5;
//	/*
//		The & next to the type indicates that this is a reference which is also known as an Alias
//	*/
//	int& reference = a;
//
//	/*
//		By adding the & infront of the veriable 'a' we are now passing the memory address of where 'a'
//		is stored in memory
//	*/
//	decrement(a);
//	println(a);
//
//
//	std::cin.get();
//}