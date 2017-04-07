//
// Created by alex on 07.04.17.
//

#ifndef MASSIVE_MASSIVE_HPP
#define MASSIVE_MASSIVE_HPP

#include <iostream>

class massive {
private:
	int size;
	int amount_non_null;
	double* index;
	double* value;
public:
	massive();
	massive(const double* array, const int SIZE);
	massive(const massive& rhs);
	~massive();
	massive operator - (const massive& A) const;
	massive& operator = (const massive& A);
	friend  std::ostream& operator << (std::ostream& os, const massive& B);
	void operator >> (const int number);

};

std::ostream& operator << (std::ostream& os, const massive& B);


#endif //MASSIVE_MASSIVE_HPP
