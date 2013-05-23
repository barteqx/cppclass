#include "readfile.h"

std::vector<std::string> VectReadFile(const std::string& name) {

	std::ifstream input(name.c_str());
	std::vector<std::string> strings;
	std::string word = "";

	while (input.good() && !input.eof()) {
		int c = input.get();
		if (isspace(c) || ispunct(c)) {
			if (!word.empty()) strings.push_back(std::move(word));
		}
		else word.push_back(c);
	}

	if (!word.empty()) strings.push_back(std::move(word));

	assert(strings.back().back() == EOF); //in case the last symbol of the last word is EOF
	strings.back().pop_back();

	return strings;
}

std::ostream& operator << ( std::ostream& stream, const std::vector<std::string> & vect ) {
	for (auto p = vect.begin(); p != vect.end(); ++p) {
		stream << *p << "\n";
	}
	return stream;
}

void VectorSortCopy(std::vector<std::string> &v) {
	for (auto j = v.begin(); j != v.end(); ++j)
		for (auto i = v.begin(); i != j; ++i) {
			if (*i > *j) {
				// string is copied
				std::string s = *i;
				*i = *j;
				*j = s;
			}
		}
}

void VectorSortMove(std::vector<std::string> &v) {
	for (auto j = v.begin(); j != v.end(); ++j)
		for (auto i = v.begin(); i != j; ++i) {
			if (*i > *j) {
				// string is moved (not copied) = should be faster
				// but argument of move is empty after it's call
				std::string s = std::move(*i);
				*i = std::move(*j);
				*j = std::move(s);
			}
		}
}

// LIST FUNCTIONS

std::list<std::string> ListReadFile(const std::string& name) {

	std::ifstream input(name.c_str());
	std::list<std::string> strings;
	std::string word = "";

	while (input.good() && !input.eof()) {
		int c = input.get();
		if (isspace(c)) {
			if (!word.empty()) strings.push_back(std::move(word));
		}
		else word.push_back(c);
	}

	if (!word.empty()) strings.push_back(std::move(word));

	assert(strings.back().back() == EOF); //in case the last symbol of the last word is EOF
	strings.back().back() = ' ';

	return strings;
}

std::ostream& operator << ( std::ostream& stream, const std::list<std::string> & vect ) {
	for (auto p = vect.begin(); p != vect.end(); ++p) {
		stream << *p << "\n";
	}
	return stream;
}

void ListSortCopy(std::list<std::string> &v) {
	for (auto j = v.begin(); j != v.end(); ++j)
		for (auto i = v.begin(); i != j; ++i) {
			if (*i > *j) {
				// string is copied
				std::string s = *i;
				*i = *j;
				*j = s;
			}
		}
}

void ListSortMove(std::list<std::string> &v) {
	for (auto j = v.begin(); j != v.end(); ++j)
		for (auto i = v.begin(); i != j; ++i) {
			if (*i > *j) {
				// string is moved (not copied) = should be faster
				// but argument of move is empty after it's call
				std::string s = std::move(*i);
				*i = std::move(*j);
				*j = std::move(s);
			}
		}
}

void removeshortstrings(std::list<std::string> &list, unsigned int len) {
	list.remove_if([&len](const std::string& s) -> bool {return s.size() < len;});
}