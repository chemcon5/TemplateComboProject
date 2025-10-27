//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;



//Your getShippingCost here - don't forget the Doxygen comment!
double getShippingCost(int ShippingMethod, double cost_of_order) { 
   double ShippingCost = 0; 
   if (ShippingMethod == 1) {
      cout << "Drone Delivery" << endl;
      if (cost_of_order < 100) {
          cout << "Not Available" << endl;
      }
      else if (cost_of_order >=100 && cost_of_order < 500) {
           ShippingCost == 50;
      }
      else (cost_of_order >= 500) {
        ShippingCost = order_cost * 0.1;
   }
   if (ShippingMethod == 2) {
      cout << "2 day delivery" << endl;
      if (cost_of_order <= 300) {
         ShippingCost = order_cost * 0.02 + 10
      }
      else (cost_of_order > 300) {
         cout << "Free" << endl;
      }
   }
   if (ShippingMethod == 3) {
      cout << "Standard Delivery" << endl;
      if (cost_of_order < 35) {
         ShippingCost = "$5"
      }
      else if (cost_of_order = 35 || <100) {
         ShippingCost = "$8"
      }
      else (cost_of_order => 100) {
         cout << "Free" << endl;
      }
   }
}

int main() {
   cout << "Enter the cost of your order: " << endl;
   cin >> ShippingMethod >> endl;
   cout << "Total is" << endl;
}
///----------------------------------------------------------------------------------
/// Tests
/// Uncomment tests to work on them. Make sure any test that does not compile or
/// causes a crash gets commented back out. Any test that runs should be left
/// on (uncommented), even if the test fails.
///----------------------------------------------------------------------------------

TEST_CASE( "getShippingCost Drone" ) {
   cout << "1: getShippingCost Drone" << endl;
   CHECK( getShippingCost(1, 100) == doctest::Approx(50) );
   CHECK( getShippingCost(1, 400) == doctest::Approx(50) );
   CHECK( getShippingCost(1, 615) == doctest::Approx(61.5) );
}

TEST_CASE( "getShippingCost 2-Day" ) {
   cout << "2: getShippingCost 2-Day" << endl;
   CHECK( getShippingCost(2, 120) == doctest::Approx(12.4) );
   CHECK( getShippingCost(2, 300) == doctest::Approx(16) );
   CHECK( getShippingCost(2, 350) == doctest::Approx(0) );
}

TEST_CASE( "getShippingCost Standard" ) {
   cout << "3: getShippingCost Standard" << endl;
   CHECK( getShippingCost(3, 10) == doctest::Approx(5) );
   CHECK( getShippingCost(3, 50) == doctest::Approx(8) );
   CHECK( getShippingCost(3, 200) == doctest::Approx(0) );
}

TEST_CASE( "getShippingCost Invalid" ) {
   cout << "4: getShippingCost Invalid" << endl;
   CHECK( getShippingCost(1, 50) == doctest::Approx(-1) );   // Drone under $100
   CHECK( getShippingCost(4, 150) == doctest::Approx(-1) );  // Invalid method
   CHECK( getShippingCost(0, 600) == doctest::Approx(-1) );  // Invalid method
}
