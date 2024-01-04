#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BowCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  unsigned int d = barcode/10000;
  d = d%10;
  return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  unsigned int d = barcode/1000;
  d = d%10;
  return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  unsigned int d = barcode/100;
  d = d%10;
  return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  unsigned int d = barcode/10;
  d = d%10;
  return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
  unsigned int d = barcode/1;
  d = d%10;
  return d;
}

// Constructor for struct Bow
Bow::Bow(string bowColor, string bowShape, string bowTexture,
		 unsigned int barcode):bowColor_(bowColor),bowShape_(bowShape),
				       bowTexture_(bowTexture),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void BowCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string bowColor;
    string bowShape;
    string bowTexture;
    unsigned int barcode;
    while (myfile >> bowColor >> bowShape >> bowTexture >> barcode) {
			if (bowColor.size() > 0)
      	addBow(bowColor, bowShape, bowTexture, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void BowCollection::addBow(string bowColor, string bowShape, string bowTexture, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified bow to Minnie's collection of bows (i.e., to all hash tables)
  Bow bowA; //= {bowColor,bowShape,bowTexture,barcode};
  hT1[barcode]=bowA;
  hT2[barcode] = bowA;
  hT3[barcode] = bowA;
  hT4[barcode] = bowA;
  hT5[barcode] = bowA;
}

bool BowCollection::removeBow(unsigned int barcode) {

  if (hT1.find(barcode) != hT1.end()){
    hT1.erase(barcode);
    hT2.erase(barcode);
    hT3.erase(barcode);
    hT4.erase(barcode);
    hT5.erase(barcode);
    return true;
  }
  else
  return false;
}

unsigned int BowCollection::bestHashing() {
  unsigned int balance1, balance2, balance3, balance4, balance5;
  unsigned int max = 0;
  unsigned int min = 100;
  for (unsigned i=0; i<10; ++i) { //loop through each bucket and determin min and max size
      cout << hT1.bucket_size(i); //also calculate balance this is done for each hash table.
      if (hT1.bucket_size(i) < min)
          {
          min = hT1.bucket_size(i);
          }
          if (hT1.bucket_size(i) > max)
            {
            max = hT1.bucket_size(i);
            }
            }

            balance1 = max - min;
            cout << " DEBUG: " << balance1 << endl;
            max = 0;
            min = 100;
          for (unsigned i=0; i<10; ++i) {
            cout << hT2.bucket_size(i);
            if (hT2.bucket_size(i) < min)
              {
                min = hT2.bucket_size(i);
              }
              if (hT2.bucket_size(i) > max)
                {
                  max = hT2.bucket_size(i);
                }
                }
                balance2 = max - min;
                cout << " DEBUG: " << balance2 << endl;
                max = 0;
                min = 100;
            for (unsigned i=0; i<10; ++i) {
              cout << hT3.bucket_size(i);
              if (hT3.bucket_size(i) < min)
                {
                  min = hT3.bucket_size(i);
                }
                if (hT3.bucket_size(i) > max)
                  {
                    max = hT3.bucket_size(i);
                  }
                  }
                  balance3 = max - min;
                  cout << " DEBUG: " << balance3 << endl;
                  max = 0;
                  min = 100;
                for (unsigned i=0; i<10; ++i) {
                  cout << hT4.bucket_size(i);
                  if (hT4.bucket_size(i) < min)
                    {
                      min = hT4.bucket_size(i);
                    }
                  if (hT4.bucket_size(i) > max)
                    {
                      max = hT4.bucket_size(i);
                    }
                    }
                    balance4 = max - min;
                    cout << " DEBUG: " << balance4 << endl;
                    max = 0;
                    min = 100;
                  for (unsigned i=0; i<10; ++i) {
                    cout << hT5.bucket_size(i);
                    if (hT5.bucket_size(i) < min)
                      {
                        min = hT5.bucket_size(i);
                      }
                      if (hT5.bucket_size(i) > max)
                      {
                        max = hT5.bucket_size(i);
                      }
                      }
                      balance5 = max - min;
                      cout << " DEBUG: " << balance5 << endl;
                    if (balance1 <= balance2 && balance1 <= balance3 && balance1 <= balance4 && balance1 <= balance5)
                    { //compare balance of each hash table to see which has the lowest balance done in each if statement.
                      return 1;
                    }
                      if (balance2 <= balance1 && balance2 <= balance3 && balance2 <= balance4 && balance2 <= balance5)
                      {
                        return 2;
                      }
                        if (balance3 <= balance1 && balance3 <= balance2 && balance3 <= balance4 && balance3 <= balance5)
                        {
                          return 3;
                        }
                          if (balance4 <= balance1 && balance4 <= balance2 && balance4 <= balance3 && balance4 <= balance5)
                          {
                            return 4;
                          }
                            if (balance5 <= balance1 && balance5 <= balance2 && balance5 <= balance3 && balance5 <= balance4)
                            {
                              return 5;
                            }
                            return 0;
}


size_t BowCollection::size() {
	if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size()))
  	throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}
