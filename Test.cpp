
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "doctest.h"
#include "NumberWithUnits.hpp"

using namespace ariel;
using namespace std;

ifstream units_file{"units.txt"};
TEST_CASE("operator (+),(-)"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};//2000 m
    NumberWithUnits b{10, "m"};//1000 cm
    NumberWithUnits c{7, "kg"};//7000 g
    NumberWithUnits d{1, "ton"};//1000 kg
    NumberWithUnits e{30, "hour"};//1800 min
    NumberWithUnits f{5, "min"};//300 sec
    NumberWithUnits g{3, "USD"};//9.99 ILS

    CHECK_EQ(a+b , NumberWithUnits{2.01, "km"});
    CHECK_EQ(b+a , NumberWithUnits{2010, "m"});
    CHECK_EQ(a-b , NumberWithUnits{1.99, "km"});
    CHECK_EQ(b-a , NumberWithUnits{-1990, "m"});
    CHECK_THROWS(c+g);
    CHECK_THROWS(g+c);
    CHECK_THROWS(d+e);
    CHECK_THROWS(e+d);
    CHECK_THROWS(b+g);
  



}
TEST_CASE("operator (+=),(-=)"){
     NumberWithUnits a{5, "km"};
    NumberWithUnits b{7000, "m"};
    CHECK((a += b) == NumberWithUnits{12, "km"});
    CHECK(a == NumberWithUnits{12, "km"});
    CHECK((b += a) == NumberWithUnits{12000, "m"});
    CHECK(b == NumberWithUnits{12000, "m"});

}

TEST_CASE("operator (>), (<), (>=), (<=), (==), (!=)")
{
    NumberWithUnits::read_units(units_file);

    CHECK_GT(NumberWithUnits{8000, "m"}, NumberWithUnits{0.5, "km"});
    CHECK_NE(NumberWithUnits{0.5, "km"}, NumberWithUnits{8000, "m"});
    CHECK_NE(NumberWithUnits{30, "km"}, NumberWithUnits{8000, "m"});
   
}
TEST_CASE("increase/dacrease operator"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{7,"hour"};
    CHECK(a++ == NumberWithUnits{7, "hour"});
    CHECK(a == NumberWithUnits{8, "hour"});
    CHECK(++a == NumberWithUnits{9, "hour"});
    CHECK(a == NumberWithUnits{9, "hour"});
}


