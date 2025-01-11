// Nicholas Neitenbach
// bigint.hpp
// 02/06/2023
//

#ifndef bigint_hpp_
#define bigint_hpp_

#include <iostream>


const int CAPACITY = 400;


class bigint {
public:
	bigint();
	bigint(int);
	bigint(const char[]);

	void   debugPrint (std::ostream&) const;
	bool   operator== (const bigint&);
	int    operator[] (int)           const;
	bigint operator*  (bigint);
	bigint operator+  (const bigint&) const;
	bigint timesDigit (int)           const;
	bigint times10    (int)           const;
	
	

	friend std::ostream& operator << (std::ostream&, bigint);
	friend std::istream& operator >> (std::istream&, bigint&);

	

private:

	int arr[CAPACITY];

};

//std::istream& operator>>(std::istream&, bigint&);

#endif
