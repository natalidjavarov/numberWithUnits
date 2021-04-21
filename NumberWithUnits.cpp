#include "NumberWithUnits.hpp"
#include <iostream>

namespace ariel
{

        void NumberWithUnits::read_units(std::ifstream &units_file) {}

        NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &num)
        {
                return NumberWithUnits(5,"hours");
        }
        NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &num)
        {
                return *this;
        }

        NumberWithUnits NumberWithUnits::operator+()
        {
               return NumberWithUnits(5,"hours");
        }
        NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &num)
        {
               return NumberWithUnits(5,"hours");
        }
        NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &num)
        {
                return *this;
        }
       
        NumberWithUnits NumberWithUnits::operator-()
        {
               return NumberWithUnits(5,"hours");
        }

    
        bool NumberWithUnits::operator>(const NumberWithUnits &num) const{
                return false;
                }
        bool NumberWithUnits::operator>=(const NumberWithUnits &num) const{ 
                return false; 
                }
        bool NumberWithUnits::operator<(const NumberWithUnits &num) const{
                 return false; 
                 }
        bool NumberWithUnits::operator<=(const NumberWithUnits &num) const{
                 return false; 
                 }
        bool NumberWithUnits::operator==(const NumberWithUnits &num) const{
                 return false; 
                 }
        bool NumberWithUnits::operator!=(const NumberWithUnits &num) const{
                 return false; 
                 }

        
        NumberWithUnits &NumberWithUnits::operator++()
        {
                return *this;
        }

       
        NumberWithUnits NumberWithUnits::operator++(int dummy_flag_for_postfix_increment)
        {
                return NumberWithUnits(5,"hours");
        }

        
        std::ostream &operator<<(std::ostream &out, const NumberWithUnits &num)
        {
                return (out << "name");
        }
        std::istream &operator>>(std::istream &in, NumberWithUnits &num)
        {
                int a = 0;
                return (in >> a);
        }

        NumberWithUnits operator*(double num, NumberWithUnits &n)
        {
                return NumberWithUnits(5,"hours");
        }

        NumberWithUnits operator*(NumberWithUnits &n, double num)
        {
                return NumberWithUnits(5,"hours");
        }


}