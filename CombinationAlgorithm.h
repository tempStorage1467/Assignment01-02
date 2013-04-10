/*
 * File: CombinationAlgorithm.h
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file defines an abstract interface that each Pascale Triangle
 *   algorithm implements.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef COMBINATIONALGORITHM_H_
#define COMBINATIONALGORITHM_H_

#include <iostream>

/*
 * An abstract interface with the methods that each algorithm that
 *  computed combination values needs to implement along with
 *  constant values used by each algorithm and some contexts that
 *  call those algorithms.
 */
class CombinationAlgorithm {
 public:
    // The number of times to construct Pascale's Triangle.
    static const int NUM_TRIANGLE_ITERATIONS = 5000;

    // The number of rows to construct in Pascale's Triangle.
    static const int NUM_ROWS_COMPUTED = 15;

 protected:
    // Perform an individual combination calculation.
    virtual int performCombinationComputation(int n, int k) = 0;

    // Clock how long it took to construct a Triangle repeatedly.
    virtual double getComputeTime(int numRows, int numIterations) = 0;

    // Run unit tests for this method of computing combinations.
    virtual void runTests() = 0;
};

#endif  // COMBINATIONALGORITHM_H_
