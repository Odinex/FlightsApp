#pragma once
class Airport
{
private:
	const char* name;
	int stripLen;
public:
	const char* getName() { return this->name; }
	void setName(const char*n);
	void setStripLen(int l);
	int getStripLen() { return this->stripLen; }
	Airport(const char* n, int len);
	Airport() : Airport("летище", 150) {}
	~Airport();
};

