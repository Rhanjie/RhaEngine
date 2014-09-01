#include "logger.hpp"

using namespace rha;
cLogger::cLogger(const std::string& path): exit(0){
    file.open(path.c_str(), std::ios::out|std::ios::app);
    if(!file.is_open()){
        std::cout<<"A fatal error occurred logger!";
        this->exit=true;
    }
} cLogger &cLogger::operator <<(const std::string& text){
    file<<text<<"\n";
    file.flush();
    if(check_phrase(text, "ERROR")){
        this->exit=true;
    } return *this;
}
