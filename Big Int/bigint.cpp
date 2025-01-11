// nicholas neitenbach
// bigint.cpp
// 02/06/2023
//

#include "bigint.hpp"
#include <iostream>

// default constructor initializing bigint to zero
bigint::bigint() {
	for(int i = 0; i < CAPACITY; ++i) {
		arr[i] = 0;
	}
}

// constructor to initialize a bigint to a const char[]
bigint::bigint(int x) {
	for(int i = 0; i < CAPACITY; ++i) {
		arr[i] = x % 10; // populating index i with the end digit of x
		x /= 10; // slicing off the last digit of x
	}
}

// 
bigint::bigint(const char numChar[]) {
	int len = 0;

	for(int i = 0; i < CAPACITY; ++i) {
        arr[i] = 0;
	}

	while(numChar[len] != '\0') {
		++len;
	}

	int k = 0;

	for(int i = len - 1; i >= 0; --i) {
		arr[k] = int(numChar[i]) - int('0');
		++k;
	}
}

// 
void bigint::debugPrint(std::ostream& out) const {
	for(int i = CAPACITY - 1; i >= 0; --i) {
		out << arr[i] << "|" << std::endl;
	}
}

//
std::ostream& operator << (std::ostream& out, bigint rhs) {
	int j = 0;
		for(int i = CAPACITY - 1; i > 0; --i) {
			if(rhs.arr[i] != 0) {
				out << rhs.arr[i];
					++j;
			}
			if (j == 80)
			out << std::endl;
			j = 0;
		}
		out << rhs.arr[0];
		return out; 
	}



bool bigint::operator == (const bigint& rhs) {
	for(int i = 0; i < CAPACITY; ++i) {
		if(arr[i] != rhs.arr[i]) {
			return false;
		}
	}
	return true;
}

std::istream& operator>>(std::istream& in, bigint& rhs){
	// bigint test;
	// cin >> test;

	char c = 0;
	char charArr[CAPACITY] = {0};
	int length = 0;

	while (in >> c) {
		if(c == ':'){
			break;
			charArr[length++] = c;
		}
	}
	charArr[length] = '\0';
	int track = 0;
	for(int i = length - 1; i >=0; --i){
		rhs.arr[track] = charArr[i] - '0'; // i don't know why this is throwing an error,
		++track;
	}
	return in;
}


bigint bigint::operator+(const bigint& rhs) const {
	bigint result;
	int carry = 0;

	for (int i = 0; i < CAPACITY; ++i) {
		int temp = arr[i] + rhs.arr[i] + carry;
		result.arr[i] = temp % 10;
		carry = temp / 10;
	}
	return result;
}

int bigint::operator[](int x) const {
	if (x < 0 || x > CAPACITY - 1) {
		return 0;
	}
	else
	return arr[x];
}

bigint bigint::timesDigit(int x) const {
	bigint result;
	int carry = 0;
	int temp = 0;
	for (int i = 0; i < CAPACITY; ++i) {
		temp = (arr[i] * x) + temp;
		carry = temp % 10;
		temp /= 10;
		result.arr[i] = carry % 10;
	}
	return result;

}

bigint bigint::times10(int x) const{ 
    bigint temp;
    if(x == 0){
        temp = *(this);
        return temp;
    }

    if(x > 0)
        for (int i = CAPACITY - x - 1; i >= 0; --i)
            temp.arr[i + x] = arr[i];
    return temp;
}

bigint bigint::operator*(bigint rhs){ 
    bigint product;
    for(int i = 0; i < CAPACITY; ++i)
        product = product + (timesDigit(rhs.arr[i])).times10(i);
    
    return product; 
}