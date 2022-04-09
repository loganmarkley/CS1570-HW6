#include "insectFncs.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;


void processInputFile(ifstream & fin, char countriesArray[][10], const int arrayRows, const int arrayCols)
{
  for(int i=0; i<arrayRows; i++)
  {
    for(int j=0; j<arrayCols; j++)
    {
      fin >> countriesArray[i][j];
    }
  }
  return;
}

void airdrop(ifstream & fin, char countriesArray[][10])
{
  int rowCord=0;
  int colCord=0;
  fin >> rowCord;
  fin >> colCord;
  do
  {
    switch(countriesArray[rowCord][colCord]){
      case '_':
        countriesArray[rowCord][colCord]='B';
        break;
      case 'B':
        infest(countriesArray, rowCord, colCord, 'B');
        break;
      case 'W':
        infest(countriesArray, rowCord, colCord, 'W');
        break;
      case 'T':
        infest(countriesArray, rowCord, colCord, 'T');
        break;
    }
    
    fin >> rowCord;
    fin >> colCord;
  } while(fin);
  return;
}

void infest(char countriesArray[][10], const int rowCord, const int colCord, const char insect)
{
  for(int i=rowCord-1; i<=rowCord+1; i++)
  {
    for(int j=colCord-1; j<=colCord+1; j++)
    {
      if(i>-1 && j>-1 && i<10 && j<10 && (i!=rowCord || j!=colCord)) //does not mutate the airdrop location or if the cord is off the board.
        mutate(countriesArray, i, j, insect);
    }
  }
  return;
}

void mutate(char countriesArray[][10], const int rowCord, const int colCord, const char insect)
{
  switch(insect){
    case 'B':
      switch(countriesArray[rowCord][colCord]){
        case '_':
          countriesArray[rowCord][colCord]='B';
          break;
        case 'B':
          countriesArray[rowCord][colCord]='W';
          break;
      }
      break;
      
    case 'W':
      switch(countriesArray[rowCord][colCord]){
        case '_':
          countriesArray[rowCord][colCord]='W';
          break;
        case 'B':
          countriesArray[rowCord][colCord]='W';
          break;
        case 'W':
          countriesArray[rowCord][colCord]='T';
          break;
      }
      break;
      
    case 'T':
      switch(countriesArray[rowCord][colCord]){
        case '_':
          countriesArray[rowCord][colCord]='T';
          break;
        case 'B':
          countriesArray[rowCord][colCord]='T';
          break;
        case 'W':
          countriesArray[rowCord][colCord]='T';
          break;
      }
      break;
    }
  return;
}
