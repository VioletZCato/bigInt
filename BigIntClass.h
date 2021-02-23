#pragma once
#include <String>
#include <cmath>
#include <vector>

using namespace std;

class bigInt {
		vector<int> bigVector;
		bool neg;
		int size = bigVector.size();
	public:
		bigInt() { //parameterless constructor
			bigVector.resize(1);
			bigVector[0] = 0;
			neg = false;
		}
		bigInt(int integer) { //integer constructor
			while (integer >= 10) {
				bigVector.push_front(integer % 10);
				integer /= 10;
			}
			bigVector.push_front(integer);
			if (integer < 0) {
				neg = true;
			}
			else {
				neg = false;
			}
		}
		bigInt(string str) { //string constructor
			int integer = stoi(str);
			while (integer >= 10) {
				bigVector.push_front(integer % 10);
				integer /= 10;
			}
			bigVector.push_front(integer);
			if (integer < 0) {
				neg = true;
			}
			else {
				neg = false;
			}
		}
		int toInt(bigInt bigint) { //takes a bigInt and returns an int of equivalent value
			int val = 0;
			int exp = 0;
			for (int c = bigint.size; c >= 0; c--) {
				val += bigint.bigVector[c] * (pow(10, exp));
				exp++;
			}
			if (bigint.neg) {
				val * -1;
			}
			return val;
		}
		string toString(bigInt bigint) {
			return to_string(toInt(bigint));
		}
		bigInt addition(bigInt first, bigInt second) { //adds two bigInts together, needs overload for +
			bigInt ans;
			if (first.neg == second.neg) {
				if (first.neg) {
					ans = sum(first, second);
					ans.neg = true;
				}
				else {
					ans = sum(first, second);
				}
			}
			else { 
				if (((|first| < |second|) && (first.neg)) || ((|second| < first) && (second.neg))) {
					ans = dif(first, second);
				}
				else {
					ans = dif(first, second);
					ans.neg = true;
				}
			}
			return ans;
		}
		bigInt subtraction(bigInt first, bigInt second) { //subtracts bigInts, needs overload for -
			bigInt ans;
			if (first.neg != second.neg) {
				if (second.neg) {
					ans = sum(first, second);
				}
				else {
					ans = sum(first, second);
					ans.neg = true;
				}
			}
			else {
				if (((!first.neg) && (first > second)) || (second.neg) && (first < second)) {
					ans = dif(first, second);
				}
				else {
					ans = dif(first, second);
					ans.neg = true;
				}
			}
			return ans;
		}
		bigInt multiplication(bigInt first, bigInt second) { //multiplies two bigints, needs overload for *
			bigInt prd;
			bigInt factor = second;
			factor.neg = false;
			for (int c = 0; c < factor; c++) {
				prd += first;
			}
			if (first.neg == second.neg) { prd.neg = false; }
			else { prd.neg = true; }
			return prd;
			
		}
		bigInt mulitplicationByInt(bigInt bigint, int i) { //multiplies one bigint by an int, should share * operator
			//this could also be done by calling bigInt multiplication and passing a the bigint with a call to the int-->bigint method
			bigInt prd;
			int factor = abs(i);
			for (int c = 0; c < factor; c++) {
				prd += bigint;
			}
			if (((bigint.neg) && (i < 0)) || ((!bigint.neg) && (i > -1))) {
				prd.neg = true;
			}
			else {
				prd.neg = false;
			}
			return prd;
		}
		bigInt division(bigInt first, bigInt second) { //divides two bigints, needs overload for /
			bigInt quo;
			bigInt dvd = first;
			dvd.neg = false;
			bigInt dvr = second;
			dvr.neg = false;
			
		}
		bigInt divisionbyInt(bigInt bigint, int i) { //divides a bigint by an int, should share / operator
			bigInt quo;
			bigInt dvd = bigint;
			dvd.neg = false;
			int dvr = abs(i);

		}
		bigInt divisionForInt(int i, bigInt bigint) { //divides an int by a bigint, should share / operator
			bigInt quo;
			int dvd = abs(i);
			bigInt dvr;
			dvr.neg = false;
		}
		bigInt pow(bigInt first, bigInt second) { //raises a bigint to the exponent of another, pow methods probably don't need overload, because they probably don't use ^
			bigInt pwr = first;
			bigInt exp = second;
			exp.neg = false;
			bigInt one = bigInt(1);
			bigInt zero;
			one.push_front(1);
			if (exp == 0) { return one; }
			else if (exp == 1) { return first; }
			else {
				for (int c = 2; c <= exp; c++) {
					pwr *= first;
				}
			}
			if (second.neg) {
				return zero;
			}
			
		}
		bigInt powByInt(bigInt bigint, int i) {  //raises a bigint to the exponent of an int
			bigInt pwr = bigint;
			int exp = abs(i);
			bigInt one = bigInt(1);
			bigInt zero;
			if (exp == 0) { return one; }
			else if (abs(exp) == 1) { return bigint; }
			else {
				for (int c = 2; c < exp; c++) {
					pwr *= bigint;
				}
			}
			if (i < 0) {
				return zero;
			}
		}
		bigInt powForInt(int i, bigInt bigint) { //raises an int to the exponent of a bigint
			int pwr = i;
			int exp = bigint;
			exp.neg = false;
			bigInt one = bigInt(1);
			bigInt zero;
			if (exp == zero) { return 1; }
			else if (exp == one) { return i; }
			else {
				for (int c = 2; c < toInt(exp); c++) {
					pwr *= pwr;
				}
			}
			if (bigint.neg) {
				return 0;
			}
		}
		void print(bigInt bigint) { //prints a bigint, without converting to any other data type first
			if (bigint.neg) {
				print('-');
			}
			for (int c = 0; c < bigint.size; c++) {
				print(bigint[c]);
			}
		}
		bool equal(bigInt first, bigInt second) { //determines whether two bigints are equal, needs overload for ==
			if (first.size != second.size) {
				return false;
			}
			else {
				for (int c = 0; c < first.size; c++) {
					if (first.bigVector[c] != second.bigVector[c]) {
						return false;
					}
				}
				return true;
			}
		}
		bool greater(bigInt first, bigInt second) { //determines whether a bigint is greater than another, needs overload for >
			if (first.size != second.size) {
				if (first.size > second.size) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				for (int c = 0; c < first.size; c++) {
					if (first.bigVector[c] > second.bigVector[c]) {
						return true;
					}
					else if (first.bigVector[c] < second.bigVector[c]) {
						return false;
					}
				}
				return false;
			}
		}
		bool greater_equal(bigInt first, bigInt second) { //combination of greater and equal functions, may not be necessary, but may need overload for >=
			if (first.size != second.size) {
				if (first.size > second.size) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				for (int c = 0; c < first.size; c++) {
					if (first.bigVector[c] > second.bigVector[c]) {
						return true;
					}
					else if (first.bigVector[c] < second.bigVector[c]) {
						return false;
					}
				}
				return true;
			}
		}
		bool lesser(bigInt first, bigInt second) { //just an inverse of the greater than method, needs overload for <
			if (!(first >= second)) {
				return true;
			}
			else {
				return false;
			}
		}
		bool lesser_equal(bigInt first, bigInt second) { //combination of equal and lesser methods, may need overload for <=
			if (!(first > second)) {
				return true;
			}
			else {
				return false;
			}
		}
	private:
		//sum method will return the positive sum of two bigInts - used in the addition and subtraction functions
		bigInt sum(bigInt first, bigInt second) {
			bigInt summation;
			int carry;
			bigInt top;
			bigInt bot;
			if (first < second) {
				top = second;
				bot = first;
				switch = true;
			}
			else {
				top = first;
				bot = second;
			}
			top.neg = false;
			bot.neg = false;
			top.bigVector.push_front(0);
			//until ?? can we make until(param) a thing? like while(!param)
			while (top.size != bot.size) {
				bot.bigVector.push_front(0);
			}
			for (int c = top.size - 1; c >= 0; c--) {
				int x = top.bigVector[c] + bot.bigVector[c] + carry;
				if (x > 9) {
					summation.bigVector.push_front(x % 10);
					carry = x / 10;
				}
				else {
					summation.bigVector.push_front(x);
				}
			}
			return summation;

		}
		//dif fucntion will return the positive difference of two bigInts - used in the addition and subtraction functions
		bigInt dif(bigInt first, bigInt second) {
			bigInt difference;
			bool carry = false;;
			bigInt top;
			bigInt bot;
			if (first == second) {
				difference.bigVector.push_front(0);
				return difference;
			}
			else if (first < second) {
				top = second;
				bot = first;
			}
			else {
				top = first;
				bot = second;
			}
			top.neg = false;
			bot.neg = false;
			while (top.size != bot.size) {
				bot.bigVector.push_front(0);
			}
			for (int c = top.size - 1; c >= 0; c--){
				int x;
				if (carry) {
					x = (top.bigVector[c] - 1) - bot.bigVector[c];
				}
				else {
					x = top.bigVector[c] - bot.bigVector[c];
				}
				carry = false;
				if (x < 0) {
					x = (10 + top.bigVector[c]) - bot.bigVector[c];
					carry = true;
				}
				difference.bigVector.push_front(x);
			}
			return difference;
		}
		/*
		*bigInt operator+(const bigInt&); //overloading operator, so + can be used to call bigInt add
		*same thing for subtraction(-), division(/)
		*same thing for comparatives.  There's already =, but there needs to be > and <.  >= might work if > and = are set up,
		 or maybe it needs to be written as well..?
		 !!! ohno! there's a = to assign but there needs to be a == as well. .equal() would work so maybe == just needs to direct to that
		*pow(bigInt first, bigInt second) {//stuff}
		*oh shoot. do i have to do root and log??
		*/
};
