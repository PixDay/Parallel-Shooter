/*
** File name :
** pair.cpp
** File creator :
** Adrien Colombier
*/

#include "pair.hpp"

Pair::Pair(std::string const &first, std::string const &second):
_first(first),
_second(second)
{}

/* SETTERS */
void Pair::setFirst(std::string const &str)
{
    _first = str;
}

void Pair::setSecond(std::string const &str)
{
    _second = str;
}

void Pair::setPair(std::string const &first, std::string const &second)
{
    _first = first;
    _second = second;
}

/* GETTERS */
std::string Pair::getFirst(void) const
{
    return _first;
}

std::string Pair::getSecond(void) const
{
    return _second;
}
