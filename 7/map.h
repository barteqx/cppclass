#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>



const int prime_number = 1000000007;

struct cmp {
    bool operator( ) ( const std::string& string1, const std::string& string2 ) const {
        auto p2 = string2.begin();
        for(auto p1 = string1.begin(); p1 != string1.end(); ++p1) {
            if(p2 == string2.end())
                return false;
            if(tolower(*p1) < tolower(*p2))
                return true;
            if(tolower(*p1) > tolower(*p2))
                return false;
            p2++;
        }
        if(p2 != string2.end())
            return true;
        return false;
    }
};

struct hash {
    unsigned int operator () (const std::string& str) const {
        int base = 128;
        int h = 0;
        int b = 1;
        for(auto p = str.begin(); p != str.end(); ++p) {
            int ch = tolower(*p);
            h = (h + ch*b) % prime_number;
            b = (b*base) % prime_number;
        }
        return h;
    }
};

struct equals {
    bool operator () (const std::string& string1, const std::string& string2) const {
        cmp c;
        return !c(string1,string2) && !c(string2,string1);
    }
};

std::vector<std::string> readfile(const std::string& name);

std::ostream& operator << (std::ostream& stream, const std::vector<std::string> & vect);

std::map<std::string, unsigned int, cmp> frequencytable(const std::vector<std::string> & text);

std::unordered_map<std::string, unsigned int, hash, equals> frequencytable_hash( const std::vector<std::string > & text);

std::ostream& operator << (std::ostream& stream, const std::map<std::string, unsigned int, cmp> & m);
