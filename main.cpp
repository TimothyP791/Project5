#include <iomanip>
#include <iostream>

#include "BowCollection.hpp"

// Helper Class Definitions
struct AssertEquals {
  template <typename T, typename U>
  void operator() ( const std::string & test_name, const T & expected, const U & actual, bool equality_test = true ) {

    if( (actual == expected)  ==  equality_test )
    {
      std::cout << "[PASSED] " << test_name << ": ";
      std::cout << "Expected and received: " << actual << '\n';
    }
    else
    {
      std::cout << "[FAILED] " << test_name << " - Expected: \"" << expected << "\" to "
                << ( equality_test ? "match " : "not match ")
                << "Actual: \"" << actual << "\"\n";
    }
  }
};


int main() {
  AssertEquals assertEquals;

  // test hash functions
  assertEquals( "hashfct1(12345)", 1U, hashfct1(12345U) );
  assertEquals( "hashfct2(12345)", 2U, hashfct2(12345U) );
  assertEquals( "hashfct3(12345)", 3U, hashfct3(12345U) );
  assertEquals( "hashfct4(12345)", 4U, hashfct4(12345U) );
  assertEquals( "hashfct5(12345)", 5U, hashfct5(12345U) );
  assertEquals( "hashfct1(67890)", 6U, hashfct1(67890U) );
  assertEquals( "hashfct2(67890)", 7U, hashfct2(67890U) );
  assertEquals( "hashfct3(67890)", 8U, hashfct3(67890U) );
  assertEquals( "hashfct4(67890)", 9U, hashfct4(67890U) );
  assertEquals( "hashfct5(67890)", 0U, hashfct5(67890U) );

  BowCollection bowCollection;
  bowCollection.addBow("red", "butterfly", "smooth", 12345U);
  bowCollection.addBow("pink", "butterfly", "smooth", 23456U);
  assertEquals( "size after adding two bows", 2U, bowCollection.size() );

  BowCollection minniesBows1;
  minniesBows1.readTextfile("in1.txt");
  assertEquals( "size after reading in1.txt", 18U, minniesBows1.size() );

  assertEquals( "bestHashing() for in1.txt", 2U, minniesBows1.bestHashing() );

  BowCollection minniesBows2;
  minniesBows2.readTextfile("in2.txt");
  assertEquals( "size after reading in2.txt", 36U, minniesBows2.size() );
  assertEquals( "bestHashing() for in2.txt", 3U, minniesBows2.bestHashing() );

  minniesBows2.removeBow(88901);
  assertEquals( "size after removing 88901", 35U, minniesBows2.size() );
  assertEquals( "bestHashing() after removing 88901", 4U, minniesBows2.bestHashing() );
  return 1;
}
