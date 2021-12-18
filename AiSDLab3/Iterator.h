#pragma once
//Base class for iterators
class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};