#pragma once
#include <string>
#include <unordered_map>
using std::string;

//******************************
// Struct and classes
//******************************

// struct to store all the info about a particular bow
struct Bow{
  string bowColor_;
  string bowShape_;
  string bowTexture_;
  unsigned int barcode_;
  Bow(string bowColor="", string bowShape="", string bowTexture="",
	  unsigned int barcode=10000);
};

// THIS FUNCTION IS COMPLETE
// unary function to return the hash value based on
// the first digit of some unique 5-digit key
unsigned int hashfct1(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the second digit of some unique 5-digit key
unsigned int hashfct2(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the third digit of some unique 5-digit key
unsigned int hashfct3(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the fourth digit of some unique 5-digit key
unsigned int hashfct4(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the fifth digit of some unique 5-digit key
unsigned int hashfct5(unsigned int);


//******************************
// Typedef for custom hash table
//******************************
typedef std::unordered_map<unsigned int, Bow, decltype(&hashfct1)> CustomHashTable;


// class to store the bow collection
class BowCollection {
public:
  // function that adds the specified bow to Minnie's collection of bows. TO BE COMPLETED
  void addBow(string bowColor, string bowShape, string bowTexture, unsigned int barcode);

  // removes a specified bow from Minnie's collection of bows; if successful,
  // then it returns true; TO BE COMPLETED
  bool removeBow(unsigned int barcode);

  // identifies which hash function (among the five provided, fct1 - fct5)
  // computes the most balanced hash table; TO BE COMPLETED
  unsigned int bestHashing();

  // Load information from a text file
  // with the given filename; THIS FUNCTION IS COMPLETE
  void readTextfile(string filename);

  // size of a hashtable. Throws exception if the sizes differ. Completed
  size_t size();

  // construcor that initializes 5 hashtables with different hash functions
  BowCollection():
    hT1{10,hashfct1},
    hT2{10,hashfct2},
    hT3{10,hashfct3},
    hT4{10,hashfct4},
    hT5{10,hashfct5}  { }

private:
  CustomHashTable hT1, hT2, hT3, hT4, hT5;
  // add other private member variables as needed
};
