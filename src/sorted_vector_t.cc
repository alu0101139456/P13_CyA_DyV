#include "sorted_vector_t.h"

#include <climits>
#include <iomanip>


void SortedVector_t::MergeSort(void) {
  MergeSort(0, size() - 1);
  // MergeSort_it();
}

void SortedVector_t::Write(std::ostream& os) const {
  const int sz = size();
  os << "< ";
  for(int i = 0; i < sz; i++)
      os << std::setw(5) << at(i);
  os << "> ";
}


void SortedVector_t::MergeSort(int l, int r) {
  if (l < r) {
      int c = (l + r) / 2;
      MergeSort(l, c);
      MergeSort(c + 1, r);
      Merge(l, c, r);
  }
}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void SortedVector_t::Merge(int l, int c, int d) {
  vector<int> v1,v2;
  
  CreateVectorSentinel(l, c, v1);
  CreateVectorSentinel(c+1, d, v2);

  Merge(v1, v2, l);

}
void SortedVector_t::CreateVectorSentinel(int l, int r, vector<int>& v) {
  v.clear();
  for(int i = l; i <= r; i++)
    v.push_back(at(i));
  
  v.push_back(INT_MAX);
}

void SortedVector_t::Merge(const vector<int>& v1, const vector<int>& v2, int l) {
  const int sz = v1.size() + v2.size() - 2;
  int inx1 = 0;
  int inx2 = 0;

  for (int i=0; i < sz; i++) {
    if (v1[inx1] < v2[inx2]) {
      at(l + i) = v1[inx1];
      if ( v1[inx1] > a_)  a_ = v1[inx1];
      inx1 ++;
    } else  {
      at(l + i) = v2[inx2];
      if ( v2[inx2] > a_)  a_ = v2[inx2];
      inx2 ++;
    }
  }
}
void SortedVector_t::MergeSort_it(void) {
  int n = size();
  for (short vm = 1; vm <= n - 1; vm = 2 * vm) {
    for (short int l = 0; l < n - 1; l += 2 * vm) {
      int c = std::min(l + vm - 1, n - 1);
      int r = std::min(l + 2 * vm - 1, n - 1);
      Merge(l, c, r);
    }
  }
}
    


std::ostream& operator<<(std::ostream& os, const SortedVector_t& v)
{
    v.Write(os);
    return os;
}