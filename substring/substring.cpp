#include <algorithm>

#include <iostream>

#include "substring.hpp"

Substr::Substr(std::string _superstr, int _min_length): 
	superstr(_superstr), min_length(_min_length)
{
	len = superstr.length();
	perms = ((len * (len + 1)) / 2 );

	for(int i = 0; i < min_length - 1; i++) {
		perms -= (len - i);
	}

	substr = new std::string[perms];
}

Substr::~Substr(void)
{
	delete[] substr;
}

void Substr::ret_substrings(void)
{
	int ind = 0;

	for(int i = 0; i < len; i++) {
		for(int j = 1; j < len - i; j++, ind++) {
			for(int k = 0; k <= j; k++) {
				substr[ind] += superstr[k + i];
			}
		}
	}
}

void Substr::sort_substrings(void)
{
	std::sort(substr, substr + perms, lencomp);
}

void Substr::sort_substrings(std::string* _substr, int _len)
{
	std::sort(_substr, _substr + _len, lencomp);
}

bool Substr::lencomp(std::string &str1, std::string &str2)
{
	return str1.length() < str2.length();
}

std::string Substr::ret_minimum(void)
{
	for(int i = 0; i < perms - 1; i++) {
		for(int j = i + 1; j < perms; j++) {
			if(substr[i] == substr[j]) {
				return substr[i];
			}
		}
	}

	return NULL;
}
