#include "map.h"

int main () {
    std::cout << frequencytable(std::vector<std::string>({"AA", "tHiS", "aA", "Aa", "aa", "this", "THIS"}));

    hash h;
    std::cout << h("ABCd") << " " << h("cbad") << "\n";
    equals e;
    std::cout << e("xxxDFg", "XXXdfG") << "\n";

    std::vector<std::string> words = readfile("book");
    
    auto table = frequencytable(words);
    auto table2 = frequencytable_hash(words);
    std::cout << "psychedelic: " << table["psychedelic"] << std::endl;
    std::string top_word, top_word_hash;
    unsigned int max_occ = 0, max_occ_hash = 0;
    for( auto p = table.begin(); p != table.end(); ++p ) {
        if(p->second > max_occ) {
            max_occ = p->second;
            top_word = p->first;
        }
    }
    for( auto p = table2.begin(); p != table2.end(); ++p ) {
        if(p->second > max_occ_hash) {
            max_occ_hash = p->second;
            top_word_hash = p->first;
        }
    }
    std::cout << "Word with most occurrences: " << top_word << " " << max_occ << std::endl;
    std::cout << "Word with most occurrences(hash): " << top_word_hash << " " << max_occ_hash << std::endl;
    return 0;
}
