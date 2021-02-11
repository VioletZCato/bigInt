#pragma once
#include <String>
#include <cmath>
#include <vector>

using namespace std;

class bigInt {
		vector<int> bigVector;
		bool negative;
		int size = bigVector.size();
	public:
		bigInt() { //parameterless constructor
			bigVector.resize(1);
			bigVector[0] = 0;
			negative = false;
		}
		bigInt(int integer) { //integer constructor
			while (integer >= 10) {
				bigVector.whatever_will_add_smth_to_the_front(integer % 10);
				integer /= 10;
			}
			bigVector.whatever_will_add_smth_to_the_front(integer);
			if (integer < 0) {
				negative = true;
			}
			else {
				negative = false;
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
				negative = true;
			}
			else {
				negative = false;
			}
		}
		int toInt(bigInt bigint) {
			int val = 0;
			int exp = 0;
			for (int c = bigint.size; c >= 0; c--) {
				val += bigint.bigVector[c] * (pow(10, exp));
				exp++;
			}
			if (bigint.negative) {
				val * -1;
			}
			return val;
		}
		bigInt add(bigInt first, bigInt second) { //add two bigInts
			bigInt larger;
			bigInt smaller;
			bigInt sum;
			if ((first.negative == second.negative) && first.negative) {
				sum.negative = true;
			}
			else if (first.negative == second.negative) {
				sum.negative = false;
			}
			else {
				return subtract(first, second);
			}
			int carry = 0;
			if (max(first.size, second.size) == first.size) {
				larger = first;
				smaller = second;
			}
			else {
				larger = second;
				smaller = first;
			}
			if (larger.size == smaller.size) { larger.whatever_will_add_smth_to_the_front(0); }
			for (int c = smaller.size-1; c >= 0; c--) { //this only goes to smaller.size, so add something to just smoosh the rest on there
				int temp = carry + smaller.bigVector[c] + larger.bigVector[c];
				carry = 0;
				sum.whatever_will_add_smth_to_the_front(temp % 10); //emplace not working ksdfnkjsdnfkjnsdkfnjsknd
				carry = temp / 10;
			}
			for (int c = larger.size - smaller.size; c >=0; c--) {
				if (c == smaller.size) {
					sum.whatever_will_add_smth_to_the_front(carry + larger.bigVector[c]);
				}
				sum.whatever_will_add_smth_to_the_front(larger.bigVector[c]);
			}
			return sum;
		}
		bigInt subtract(bigInt first, bigInt second) { //subtract bigInts
			bigInt larger;
			bigInt smaller;
			bigInt sum;
			if ((first.negative == second.negative) && first.negative) {
				sum.negative = true;
			}
			else if (first.negative == second.negative) {
				sum.negative = false;
			}
			else {
				return subtract(first, second);
			}
			int carry = 0;
			if (max(first.size, second.size) == first.size) {
				larger = first;
				smaller = second;
			}
			else {
				larger = second;
				smaller = first;
			}
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
	private:
		bigInt addition(bigInt first, bigInt second) { //add two bigInts absolute values only
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








		//bigInt operator+(const bigInt&); //overloading operator, so + can be used to call bigInt add

};