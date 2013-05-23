#include "map.h"

std::ostream& operator << ( std::ostream& stream, const std::vector< std::string > & vect )
{
    for( auto p = vect. begin( ); p != vect. end( ); ++ p )
        stream << *p << "\n";
    return stream;
}

std::map< std::string, unsigned int, cmp > frequencytable( const std::vector< std::string > & text )
{
    std::map< std::string, unsigned int, cmp > table;
    for( auto p = text. begin( ); p != text. end( ); ++ p )
        table[*p]++;
    return table;
}

std::unordered_map<std::string, unsigned int, hash, equals > frequencytable_hash( const std::vector<std::string > & text )
{
    std::unordered_map<std::string, unsigned int, hash, equals > table;
    for( auto p = text. begin( ); p != text. end( ); ++ p )
        table[*p]++;
    return table;
}

std::vector<std::string> readfile(const std::string& name) {

    std::ifstream input(name.c_str());
    std::vector<std::string> strings;
    std::string word = "";
	
    while (input.good() && !input.eof()) {
        int c = input.get();
        if (isspace(c) || ispunct(c)) {
            if (!word.empty()) {
            	strings.push_back(std::move(word));
            	word.clear();
            }
        }
        else word.push_back(c);
    }

    if (!word.empty()) strings.push_back(std::move(word));
    strings.back().pop_back();
    return strings;
}

std::ostream& operator << ( std::ostream& stream, const std::map< std::string, unsigned int, cmp > & m )
{
    for(auto p = m.begin(); p != m.end(); ++p)
        stream << p->first << " " << p->second << std::endl;
    return stream;
}
