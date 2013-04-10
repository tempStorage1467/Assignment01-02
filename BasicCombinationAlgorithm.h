/*
 * File: BasicCombinationAlgorithm.h
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */


#ifndef BASICCOMBINATIONALGORITHM_H_
#define BASICCOMBINATIONALGORITHM_H_

#include <iostream>
#include "CombinationAlgorithm.h"

/*
 * Define a class prototype that performs a very basic computation
 *   of combination values. The class implements the CombinationAlgorithm
 *   interface.
 */
class BasicCombinationAlgorithm: public CombinationAlgorithm {
 public:
    // Compute how long it takes calculate Pascale's Triangle.
    double getComputeTime(int numRows, int numIterations);

    // Run unit tests.
    void runTests();
 protected:
    // Calculate an individual combination value.
    int performCombinationComputation(int n, int k);
};

#endif  // BASICCOMBINATIONALGORITHM_H_
