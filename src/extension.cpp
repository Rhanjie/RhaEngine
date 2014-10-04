#include "extension.hpp"

bool check_phrase(const std::string& text, const std::string& phrase){
    size_t searched_phrase=text.find(phrase);
    if(searched_phrase==std::string::npos){
        return false;
    }
    return true;
}
std::string getLocalTime(){
    struct tm* data;
    char hour[80];
    time_t timeAuxiliary;

    time(&timeAuxiliary);
    data=localtime(&timeAuxiliary);

    strftime(hour, 80, "%H:%M:%S", data);
    return hour;
}
