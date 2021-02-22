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
				bigVector.whatever_will_add_smth_to_the_front(integer % 10);
				integer /= 10;
			}
			bigVector.whatever_will_add_smth_to_the_front(integer);
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
				bigVector.whatever_will_add_smth_to_the_front(integer % 10);
				integer /= 10;
			}
			bigVector.whatever_will_add_smth_to_the_front(integer);
			if (integer < 0) {
				neg = true;
			}
			else {
				neg = false;
			}
		}
		int toInt(bigInt bigint) {
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
		bigInt addition(bigInt first, bigInt second) { //add two bigInts
			bigInt sum;
			if (first.neg == second.neg) {
				if (first.neg) {
					sum = add(first, second);
					sum.neg = true;
				}
				else {
					sum = add(first, second);
				}
			}
			else { 
				if (((first < second) && (first.neg)) || ((second < first) && (second.neg))) {
					sum = sub(first, second);
				}
				else {
					sum = sub(first, second);
					sum.neg = true;
				}
			}
			return sum;
		}
		bigInt subtraction(bigInt first, bigInt second) { //subtract bigInts
			bigInt dif;
			if (first.neg != second.neg) {
				if (second.neg) {
					dif = add(first, second);
				}
				else {
					dif = add(first, second);
					dif.neg = true;
				}
			}
			else {
				if (((!first.neg) && (first > second)) || (second.neg) && (first < second)) {
					dif = sub(first, second);
				}
				else {
					dif = sub(first, second);
					dif.neg = true;
				}
			}
			return dif;
		}
		bigInt multiplication(bigInt first, bigInt second) {
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
		bigInt pow(bigInt first, bigInt second) {
			bigInt pwr = first;
			bigInt exp = second;
			exp.neg = false;
			if (exp == 0) { return 1; }
			else if (exp == 1) { return first; }
			else {
				for (int c = 2; c <= exp; c++) {
					pwr = multiplication(pwr, first);
				}
			}
			bigInt one = bigInt(1);
			if (second.neg) {
				if (toInt(pwr) == 1) { return one; }
				else { 
					bigInt zero = bigInt(0);
					return zero;
				}
			}
			
		}
		bool equal(bigInt first, bigInt second) {
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
		bool greater(bigInt first, bigInt second) { //comparative, is first > second 
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
		bool greater_equal(bigInt first, bigInt second) {
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
		bool lesser(bigInt first, bigInt second) { //comparative
			if (!(first >= second)) {
				return true;
			}
			else {
				return false;
			}
		}
		bool lesser_equal(bigInt first, bigInt second) {
			if (!(first > second)) {
				return true;
			}
			else {
				return false;
			}
		}
	private:
		//making a new attempt at a sum class, using greater/less than functions from before
		bigInt sum(bigInt first, bigInt second) {
			bigInt sum;
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
			top.bigVector.whatever_will_add_smth_to_the_front(0);
			//until ?? can we make until(param) a thing? like while(!param)
			while (top.size != bot.size) {
				bot.bigVector.whatever_will_add_Smth_to_the_front(0);
			}
			for (int c = top.size - 1; c >= 0; c--) {
				int x = top.bigVector[c] + bot.bigVector[c] + carry;
				if (x > 9) {
					sum.bigVector.whatever_will_add_smth_to_the_front(x % 10);
					carry = x / 10;
				}
				else {
					sum.bigVector.whatever_will_add_smth_to_the_front(x);
				}
			}
			return sum;

		}
		//similarly, my new attempt at a diff class
		bigInt diff(bigInt first, bigInt second) {
			bigInt diff;
			bool carry = false;;
			bigInt top;
			bigInt bot;
			if (first == second) {
				sum.bigVector.whatever_will_add_smth_to_the_front(0);
				return sum;
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
				bot.bigVectorwhatever_will_add_Smth_to_the_front(0);
			}
			for (int c = top.size - 1; c >= 0; c--){
				int x;
				if (top.bigVector[c] < bot.bigVector[c]) {
					x = (10 + top.bigVector[c]) - bot.bigVector[c];
					carry = true;
				}
				else {
					x = top.bigVector[c] - bot.bigVector[c];
				}
				bool = false; //THIS IS WHERE I LEFT OFF
			}
		}

		
		bigInt add(bigInt first, bigInt second) { //add two bigInts absolute values only
			bigInt larger;
			bigInt smaller;
			bigInt sum;
			int carry = 0;
			if (max(first.size, second.size) == first.size) {
				larger = first;
				smaller = second;
			}
			else {
				larger = second;
				smaller = first;
			}
			smaller.neg = false;
			larger.neg = false;
			if (larger.size == smaller.size) { larger.whatever_will_add_smth_to_the_front(0); }
			for (int c = smaller.size - 1; c >= 0; c--) { //this only goes to smaller.size, so add something to just smoosh the rest on there
				int temp = carry + smaller.bigVector[c] + larger.bigVector[c];
				carry = 0;
				sum.whatever_will_add_smth_to_the_front(temp % 10); //emplace not working ksdfnkjsdnfkjnsdkfnjsknd
				carry = temp / 10;
			}
			for (int c = larger.size - smaller.size; c >= 0; c--) {
				if (c == smaller.size) {
					sum.whatever_will_add_smth_to_the_front(carry + larger.bigVector[c]);
				}
				sum.whatever_will_add_smth_to_the_front(larger.bigVector[c]);
			}
			return sum;
		}
		bigInt sub(bigInt first, bigInt second) { //subtract two bigInts absolute values only
			//stuff
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
