//
// Created by alex on 07.04.17.
//

#include <cstring>
#include "massive.hpp"

massive::massive() :
		size(0),
		amount_non_null(0)
{
	this->index = nullptr;
	this->value = nullptr;
}

massive::massive(const double* array, const int SIZE) :
size(SIZE),
amount_non_null(0)
{
	int new_size = 0;

	for (int i = 0; i < SIZE; i++)
		if (array[i] != 0)
			new_size++;

	if (new_size != 0) {
		value = new double[new_size];
		index = new double[new_size];
	}

		for (int i = 0; i < SIZE; i++)
			if (array[i] != 0) {
				value[amount_non_null] = array[i];
				index[amount_non_null] = i;
				amount_non_null++;
			}

}

massive::~massive()
{
	delete [] value;
	delete [] index;
}

massive
massive::operator-(const massive& A) const
{
	massive new_massive;

	if (A.size > this->size)
		new_massive.size = A.size;
	else new_massive.size = this->size;

	if (A.amount_non_null == 0 && this->amount_non_null == 0)
		return new_massive;

	new_massive.index = new double[A.amount_non_null + this->amount_non_null];
	new_massive.value = new double[A.amount_non_null + this->amount_non_null];

	new_massive. amount_non_null = A.amount_non_null + this->amount_non_null;

	memcpy(new_massive.index, this -> index, this -> amount_non_null * sizeof(double));
	memcpy(new_massive.value, this -> value, this -> amount_non_null * sizeof(double));

	int h = 0;

	for (int i = 0; i < A.amount_non_null; i++) {
		int  flag = 0;

		for (int j = 0; j < this->amount_non_null; j++)
			if (A.index[i] == this->index[j]) {
				new_massive.value[j] = this->value[j] - A.value[i];
				flag = 1;
				break;
			}

		if(flag == 0) {
			new_massive.index[this->amount_non_null + h] = A.index[i];
			new_massive.value[this->amount_non_null + h] = -A.value[i];
			h++;
		}

		flag = 0;
	}

	h = 0;
	for (int i = 0; i < new_massive.amount_non_null ; i++) {
		if (new_massive.value[i] != 0) {
			h++;
		}
	}

	if(h == new_massive.amount_non_null)
		return new_massive;

	double* new_value = new double[h];
	double* new_index = new double[h];

	int counter = 0;
	for (int i = 0; i < new_massive.amount_non_null ; i++) {
		if (new_massive.value[i] != 0) {
			new_value[counter] = new_massive.value[i];
			new_index[counter] = new_massive.index[i];
			counter++;
		}
	}

	delete[] new_massive.value;
	delete[] new_massive.index;


	new_massive.index = new_index;
	new_massive.value = new_value;

	return  new_massive;
}


std::ostream&
operator<<(std::ostream& os, const massive& B)
{
	int flag = 0;
	for (int i = 0; i < B.size; ++i) {
		for (int j = 0; j < B.amount_non_null; j++)
			if (i == B.index[j]){
				os << B.value[j] << "; ";
				flag = 1;
				break;
			}
		if (flag == 0)
			os << 0 << "; ";
		flag = 0;
	}

	os << std::endl;

	return os;
}

void
massive::operator >>(const int number)
{
	for (int i = 0; i < this->amount_non_null; i++) {
		if (this -> index[i] > this -> size - 1 - number)
			this->index[i] = - size  + this->index[i] + number;
		else this->index[i] += number;
	}
}

massive&
massive::operator=(const massive& A)
{
	delete[] this->value;
	delete[] this->index;

	this->size = A.size;
	this->amount_non_null = A.amount_non_null;

	this->value = new double[A.amount_non_null];
	this->index = new double[A.amount_non_null];

	memcpy(this->value,A.value,A.amount_non_null * sizeof(double));
	memcpy(this->index,A.index,A.amount_non_null * sizeof(double));


	return *this;
}

massive::massive(const massive& rhs) :
		size(rhs.size),
		amount_non_null(rhs.amount_non_null)
{
	this->value = new double[rhs.amount_non_null];
	this->index = new double[rhs.amount_non_null];

	memcpy(this->value,rhs.value,rhs.amount_non_null * sizeof(double));
	memcpy(this->index,rhs.index,rhs.amount_non_null * sizeof(double));
}
