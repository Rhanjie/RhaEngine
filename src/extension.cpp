#include "extension.hpp"

bool check_phrase(const std::string& text, const std::string& phrase){
    size_t searched_phrase=text.find(phrase);
    if(searched_phrase==std::string::npos){
        return false;
    }
    return true;
}
