#include "stdafx.h"
#include "Airport.h"


Airport::Airport(const char*n, int l)
{
	setName(n); setStripLen(l);
}

void Airport::setName(const char *n) {
	if (n != NULL && n != "") {
		this->name = n;
	}
}

void Airport::setStripLen(int l) {
	if (l > 0) {
		this->stripLen = l;
	}
}


Airport::~Airport()
{
}
