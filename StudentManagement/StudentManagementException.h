#pragma once

#include "Header.h"

class WrongDateException : public std::exception {
public:
	WrongDateException();
};

class OutLigitsException : public std::exception {
public:
	OutLigitsException();
};