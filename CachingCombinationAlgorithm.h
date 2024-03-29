/*
 * File: CachingCombinationAlgorithm.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 1 - Pt. 2 - Combinations
 * This file defines class that uses caching to compute Pascale's Triangle
 *   and implements the CombinationAlgorithm interface.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef CACHINGCOMBINATIONALGORITHM_H_
#define CACHINGCOMBINATIONALGORITHM_H_

#include <iostream>
#include "CombinationAlgorithm.h"

/*
 * Define the prototype for a class that computes Pascale's Triangle
 *  using caching. The class will implement the CombinationAlgorithm
 *  interface.
 */
class CachingCombinationsAlgorithm: public CombinationAlgorithm {
 public:
    // Constructor to initialize private values.
    CachingCombinationsAlgorithm();

    // Compute the length of time taken by this algorithm
    //   to calculate Pascale's Triangle.
    double getComputeTime(int numRows, int numIterations);

    // Run unit tests on this algorithm.
    void runTests();
 protected:
    // Perform an individual combination calculation.
    unsigned int performCombinationComputation(int n, int k);

    // Two dimentional array to store cached calculation results.
    unsigned int cachedValue
          [CombinationAlgorithm::NUM_ROWS_COMPUTED]
          [CombinationAlgorithm::NUM_ROWS_COMPUTED];
};

#endif  // CACHINGCOMBINATIONALGORITHM_H_
