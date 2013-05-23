#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <assert.h>


std::vector<std::string> VectReadFile(const std::string& name);

std::ostream& operator << (std::ostream& stream, const std::vector<std::string> & vect);

void VectorSortCopy(std::vector<std::string> &v);

void VectorSortMove(std::vector<std::string> &v);

std::list<std::string> ListReadFile(const std::string& name);

std::ostream& operator << (std::ostream& stream, const std::list<std::string> & vect);

void ListSortCopy(std::list<std::string> &v);

void ListSortMove(std::list<std::string> &v);

void removeshortstrings(std::list<std::string> &list, unsigned int len);