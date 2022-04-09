//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Instructor Name: San Yeung
//Section: 109
//Date: 4/8/22
//File: main.cpp
//Purpose: make an infestation of bees program in C++ (HW 6)

#include "insectFncs.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  ifstream fin;
  ofstream fout;
  
  const int countriesRows=10;
  const int countriesCols=10;
  char countriesArray[countriesRows][countriesCols]={};
  
  string inputFile="input.txt";
  fin.open(inputFile.c_str());
  
  processInputFile(fin, countriesArray, countriesRows, countriesCols);
  
  airdrop(fin, countriesArray);
  
  string outputFile="output.txt";
  fout.open(outputFile.c_str());

  for(int i=0; i<countriesRows; i++)
  {
    for(int j=0; j<countriesCols; j++)
    {
      fout<<countriesArray[i][j]<<" ";
    }
    fout<<endl;
  }

  fin.close();
  fout.close();

  return 0;
}
