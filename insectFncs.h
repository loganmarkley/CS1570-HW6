#ifndef INSECTFNCS_H
#define INSECTFNCS_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//desc: given a ifstream, the countriesArray char 2d array is filled with the countries listed in the input file
//pre: this should be called at the start of the inputfile when it lists the countries.
//post: countriesArray is successfully filled with countries and their respective infestations
void processInputFile(ifstream & fin, char countriesArray[][10], const int arrayRows, const int arrayCols);

//desc: given the input stream, it reads all of the coordinates and performs a airdrop at that coordinate. It will also call infest() to deal with the airdrops
//pre: fin must be at the part of the input file where it lists coordinates "0 1" for example
//post: all airdrop coordinates from fin are successfully read and airdrops of insects are performed.
void airdrop(ifstream & fin, char countriesArray[][10]);

//desc: the only purpose of this is to have a nested for loop to call mutate() for all of the surrounding countries of an airdrop.
//pre: insect must be 'B' 'W' or 'T' based on the insect that is infesting the airdrop coordinate.
//post: mutate() is succesfully called for every surrounding country of the airdrop
void infest(char countriesArray[][10], const int rowCord, const int colCord, const char insect);

//desc: the insect at (rowCord, colCord) will be overriden by a stronger insect or it will mutate into a stronger insect depending on what the insect parameter holds
//pre: insect must be 'B' 'W' or 'T' based on the insect that is occupying the country at (rowCord, colCord)
//post: the insect at (rowCord, colCord) is succesfully changed to a higher insect or stays the same.
void mutate(char countriesArray[][10], const int rowCord, const int colCord, const char insect);
#endif
