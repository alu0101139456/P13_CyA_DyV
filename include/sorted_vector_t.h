#pragma once 

#include <vector>
#include <iostream>


class SortedVector_t: public std::vector<int> {
 private:
  int a_ = -999;        
 public:
  SortedVector_t(void):
      std::vector<int>() {}

  SortedVector_t(const std::vector<int>& vector_recibido):
      std::vector<int>(vector_recibido) {}

  ~SortedVector_t(void) {}
  void MergeSort(void);      
  void Write(std::ostream&) const;    
      
 private:
          
  void CreateVectorSentinel(int, int, std::vector<int>&);
  void Merge(const std::vector<int>&, const std::vector<int>&, int);
      
  void MergeSort(int, int);
  void MergeSort_it(void);
  void Merge(int, int, int);
};


std::ostream& operator<<(std::ostream& os, const SortedVector_t& v);