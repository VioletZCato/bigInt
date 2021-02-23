#include <iostream>
#include <string>
#include "BigIntClass.h"

using namespace std;

void main () {
	bool x;
	cout << "This will test the different methods and feature of the bigint class.\n"
	"It will test each method, the constructors, and conversions back to known data types." <<endl;
	x = 0 == toInt(bigInt()); //uses parameterless constructor, converts to int to check (that its equal to 0, the expected value)
	result(x); //calls function to print whether or not it was successful
	x = 5 == toInt(bigInt(5)); //uses int constructor, converts to int to check
	result(x);
	x = 15 == toInt(bigInt(15)); //uses int constructor, but with 2 diit number this time
	result(x);
	x = -7 == toInt(bigInt(-7)); //uses int constructor, but with a negative number
	result(x);
	x = "7" == toString(bigInt("77")); //uses string constructor, but with only one char
	result(x);
	x = "104" == toString(bigInt("104")); //uses string constructor, with a full string
	result(x);
	x = "-55" == toString(bigInt("-55")); //uses string constructor, with a negative sign
	result(x);
	x = 85 == toInt(bigInt("85")); //uses string constructor, with int converter (string --> bigint --> int)
	result(x);
	x = "85" == toString(bigInt(85)); //uses int constructor, with int converter (int --> bigint --> string)
	result(x);
	x = 8 == toInt(bigInt(3) + bigInt(5));
	cout << "addition with two positive numbers (1)" << endl;
	result(x);
	x = 8 == toInt(bigInt(5) + bigInt(3));
	cout << "addition with two positive numbers (2)" << endl;
	result(x);
	x = -2 == toInt(bigInt(3) + bigInt(-5));
	cout << "addition with one negative number (1)" << endl;
	result(x);
	x = 2 == toInt(bigInt(-3) + bigInt(5));
	cout << "addition with one negative number (2)" << endl;
	result(x);
	x = ? == toInt(bigInt(5) + bigInt(-3));
	cout << "addition with one negative number (3)" << endl;
	result(x);
	x = ? == toInt(bigInt(-5) + bigInt(3));
	cout << "addition with one negative number (4)" << endl;
	result(x);
	x = -8 == toInt(bigInt(-3) + bigInt(-5));
	cout << "addition with two negative numbers (1)" << endl;
	result(x);
	x = -8 == toInt(bigInt(-5) + bigInt(-3));
	cout << "addition with to negative numbers (2)" << endl;
	result(x);
	x = -2 == toInt(bigInt(3) - bigInt(5));
	cout << "subtraction with two positive numbers (1)" << endl;
	result(x);
	x = 2 == toInt(bigInt(5) - bigInt(3));
	cout << "subtraction with two positive numbers (2)" << endl;
	result(x);
	x = ? == toInt(bigInt(?) - bigInt(?)); //this is where I left off
}

void result (bool trial) {
	if (trial) {
		cout << " succeeded" << endl;
	}
	else {
		cout << " failed" << endl;
	}
}

/* either need to inject code, make really complicated system of managing objects/data from iostream, or write a test program.
Probably the test program, like: return (addition(bigInt(3),bigInt(5)) == 8) but do serveral for each: make one test it, make one
in a call, etc.*/ 