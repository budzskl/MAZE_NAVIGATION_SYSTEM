//-------------------------------------------------
// Author: Dawid Budz
// Project 6: Escape the Labrynth
// Course: CS211, UIC
//-------------------------------------------------

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct ROW {
    T*  Cols;     // array of column elements
    size_t NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // array of ROWs
  size_t  NumRows;  // total # of rows (0..NumRows-1)
    
public:
  // default constructor:
  Grid() {
    Rows = new ROW[4];  // 4 rows
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r].Cols = new T[4];
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (size_t c = 0; c < Rows[r].NumCols; ++c) {
        Rows[r].Cols[c] = T();  // default value for type T:
      }
    }
  }
  //parametized constructor
  Grid(size_t R, size_t C) {
    //initialize rows and num rows using parameter R
    Rows = new ROW[R];
    NumRows = R;
    //loop to add columns
    for(size_t r = 0; r < NumRows; r++){
      Rows[r].Cols = new T[C];
      Rows[r].NumCols = C;

      for(size_t c = 0; c < Rows[r].NumCols; c++){
        Rows[r].Cols[c] = T();
      }
    }
  }

  // destructor:
  virtual ~Grid() {
    //loops to delete columns and then rows at the end
      for(size_t r = 0; r < NumRows; r++){
        delete[] Rows[r].Cols;
      }
      delete[] Rows;
  }
  // copy constructor
  Grid(const Grid<T>& other) {
    //same code as parameter, but slight tweaks with using other and its variables instead of R or C
    NumRows = other.NumRows;
    Rows = new ROW[NumRows];
    for(size_t r = 0; r < NumRows; r++){
        Rows[r].Cols = new T[other.Rows[r].NumCols];
        Rows[r].NumCols = other.Rows[r].NumCols;
        for(size_t c = 0; c < Rows[r].NumCols; c++){
          Rows[r].Cols[c] = other.Rows[r].Cols[c];
        }
      }

  }
  //overloaded operator
  Grid& operator=(const Grid& other) {
    if(this != &other){
        //clears space
        for(size_t r = 0; r < NumRows; r++){
            delete[] Rows[r].Cols;
        }
        delete[] Rows;
        //adds other's data
        NumRows = other.NumRows;
        Rows = new ROW[NumRows];
        for(size_t r = 0; r < NumRows; r++){
            Rows[r].Cols = new T[other.Rows[r].NumCols];
            Rows[r].NumCols = other.Rows[r].NumCols;
            for(size_t c = 0; c < Rows[r].NumCols; c++){
                Rows[r].Cols[c] = other.Rows[r].Cols[c];
            }
        }

    }

    return *this;
      
  }
  // returns number of rows
  size_t numrows() const {
    return NumRows;
  }
  // returns column size
  size_t numcols(size_t r) const {
    return Rows[r].NumCols;
  }
  // returns grid size
  size_t size() const {
    return NumRows * Rows[0].NumCols;
  }
  // accesses grid values
  T& operator()(size_t r, size_t c) {
    if(r >= NumRows || c >=Rows[0].NumCols){
        throw logic_error("Error"); 
    }
    
    return Rows[r].Cols[c]; 
  }

  void _output() {
    for(size_t r = 0; r < NumRows; r++){
        for(size_t c = 0; c < Rows[r].NumCols; c++){
            cout << Rows[r].Cols[c] << " ";
        }
    }
  }
};
