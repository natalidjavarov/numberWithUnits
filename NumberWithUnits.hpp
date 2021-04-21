#pragma once
#include <string>
#include <iostream>
#include <stdbool.h>
#include <map>
namespace ariel
{

    static std::map<std::string, std::string> units_from_file; 
    class NumberWithUnits
    {

    private:
        double _num;       
        std::string _unit; 
    public:
        NumberWithUnits(double num, std::string unit) : _num(num), _unit(unit) {} 
        ~NumberWithUnits() {}         

        static void read_units(std::ifstream &units_file);
        NumberWithUnits operator+(const NumberWithUnits &num);
        NumberWithUnits &operator+=(const NumberWithUnits &num);
        NumberWithUnits operator+(); 
        NumberWithUnits operator-(const NumberWithUnits &num);
        NumberWithUnits &operator-=(const NumberWithUnits &num);
        NumberWithUnits operator-(); 
       
        bool operator>(const NumberWithUnits &num) const;
        bool operator>=(const NumberWithUnits &num) const;
        bool operator<(const NumberWithUnits &num) const;
        bool operator<=(const NumberWithUnits &num) const;
        bool operator==(const NumberWithUnits &num) const;
        bool operator!=(const NumberWithUnits &num) const;

        NumberWithUnits &operator++();
        NumberWithUnits operator++(int dummy_flag_for_postfix_increment);
        friend std::ostream &operator<<(std::ostream &out, const NumberWithUnits &num);
        friend std::istream &operator>>(std::istream &in, NumberWithUnits &num);

        friend NumberWithUnits operator*( double num ,NumberWithUnits &n);
        friend NumberWithUnits operator*( NumberWithUnits &n,double num);
    
    };

}