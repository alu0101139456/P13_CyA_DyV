/**
 * @file main.cpp
 * @author Ángel Julián Bolaño Campos (alu0101139456@ull.edu.es)
 * @brief Práctica 13: Divide y Vencerás
 * @version 0.1
 * @date 13-01-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t.h"

#define LIMIT 999
#define SIZE   80

using namespace std;

int main(void) {	
  default_random_engine generator;
  uniform_int_distribution<int> distribution(-LIMIT, LIMIT);    
  
  SortedVector_t vector_generado;
  
  for(int i = 0; i < SIZE; i++)
    vector_generado.push_back(distribution(generator));
      
  cout << "Vector desordenado: \n" << vector_generado << endl;
  
  vector_generado.MergeSort();
  
  cout << "Vector ordenado: \n" << vector_generado << endl;
    
	return 0;
}