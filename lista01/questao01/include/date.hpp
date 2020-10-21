// file: date.h
// author: Bernt A Oedegaard.
#ifndef _DATE_H_
#define _DATE_H_

#include <iostream> 

using namespace std;

class date { 
protected:
	int year_; 
	int month_; 
	int day_;
public:
	date();
	date(const int& d, const int& m, const int& y);
	bool valid(void) const;
	int day() const; 
	int month() const; 
	int year() const;
	void setday (const int& day );
	void setmonth (const int& month ); 
	void setyear (const int& year );
	date operator ++(); // prefix 
	date operator ++(int); // postfix 
	date operator --(); // prefix 
	date operator --(int); // postfix
};
bool operator == (const date&, const date&); // comparison operators 
bool operator != (const date&, const date&);
bool operator < (const date&, const date&);
bool operator > (const date&, const date&);
bool operator <= (const date&, const date&); 
bool operator >= (const date&, const date&);
ostream& operator << ( ostream& os, const date& d); // output operator 

#endif