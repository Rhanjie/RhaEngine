#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED
#include "managerLibs.hpp"
#include "extension.hpp"

namespace rha{
    class cLogger{
        private:
         std::fstream file;
         bool exit;
        public:
         cLogger(const std::string& path);
         ~cLogger(){file.close();}

         inline bool getExit(){return exit;}
         cLogger &operator <<(const std::string& text);
    };
}

#endif // LOGGER_HPP_INCLUDED
