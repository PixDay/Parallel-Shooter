/*
** File name :
** pair.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include <string>

class Pair
{
    public:
        Pair(std::string const &first, std::string const &second);
        ~Pair() = default;

        /* SETTERS */
        void setFirst(std::string const &str);
        void setSecond(std::string const &str);
        void setPair(std::string const &first, std::string const &second);

        /* GETTERS */
        std::string getFirst(void)  const;
        std::string getSecond(void) const;

    private:
        std::string _first;
        std::string _second;
};