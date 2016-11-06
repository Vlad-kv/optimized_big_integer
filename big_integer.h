#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <iostream>

// Vladislav Kiselyov   M3239
class big_integer {
public:
	typedef unsigned int loc_t;
private:
	typedef long long buf_t;
	static const long long pw_loc_t = 31;
	static const long long size_loc_t = ((buf_t)1) << pw_loc_t;
	static const int start_max_size = 2;
	
	int mutable max_size, real_size;
	loc_t mutable *a;
	char mutable inv;
	
	void upd_max_size(int new_max_size) const;

	void check_max_size() const;
	void upd_real_size() const;

	void add(big_integer const& s);
	void sub(big_integer const& s);

	int cmp(big_integer const& s) const;
	int abs_cmp(big_integer const& s);

	void left_shift(int shift);
	void right_shift(int shift);
	
	void duplicate();
	
	void init(buf_t c);
	void cancel_small_obj_opt() const;
public:

	big_integer();
	big_integer(big_integer const& v);
	big_integer(int t);
	explicit big_integer(std::string const& str);

	~big_integer();

	big_integer& operator+=(big_integer const& v);
	big_integer& operator-=(big_integer const& v);

	big_integer& operator*=(big_integer const& v);
	big_integer& operator/=(big_integer const& divider1);
	big_integer& operator%=(big_integer const& v);

	big_integer& operator=(big_integer const& v);

	big_integer& operator++();
	big_integer operator++(int);
	big_integer& operator--();
	big_integer operator--(int);

	big_integer& operator&=(big_integer const& v);
	big_integer& operator|=(big_integer const& v);
	big_integer& operator^=(big_integer const& v);

	big_integer& operator<<=(int shift);
	big_integer& operator>>=(int shift);

	big_integer operator+() const;
	big_integer operator-() const;
	big_integer operator~() const;

	friend bool operator==(big_integer const& a, big_integer const& s);
	friend bool operator!=(big_integer const& a, big_integer const& s);
	friend bool operator< (big_integer const& a, big_integer const& s);
	friend bool operator> (big_integer const& a, big_integer const& s);
	friend bool operator<=(big_integer const& a, big_integer const& s);
	friend bool operator>=(big_integer const& a, big_integer const& s);

	friend std::string to_string(big_integer const& a);
};

big_integer operator+(big_integer c, big_integer const& v);
big_integer operator-(big_integer c, big_integer const& v);
big_integer operator*(big_integer c, big_integer const& v);
big_integer operator/(big_integer c, big_integer const& v);
big_integer operator%(big_integer c, big_integer const& v);

big_integer operator&(big_integer c, big_integer const& v);
big_integer operator|(big_integer c, big_integer const& v);
big_integer operator^(big_integer c, big_integer const& v);

big_integer operator<<(big_integer c, int shift);
big_integer operator>>(big_integer c, int shift);

std::string to_string(big_integer const& a);
std::ostream& operator<<(std::ostream& out, big_integer const& c);

#endif // BIG_INTEGER_H
