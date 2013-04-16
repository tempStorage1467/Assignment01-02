/*
 * File: Combinations.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 1 - Pt. 2 - Combinations
 * This file is the starter project for the Combinations problem.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <iostream>
#include <string>
#include "console.h"
#include "BasicCombinationAlgorithm.h"
#include "CachingCombinationAlgorithm.h"
#include "Tester.h"

using namespace std;

/*
 * Calculate the combination of c(n, k).
 * This is the basic method of computing, done for the core of the
 *   CS106b assignment.
 * See https://en.wikipedia.org/wiki/Combination
 *
 * This function is not invoked in the program apart from printing the
 *   first ten rows of the triangle as it is so inefficient and
 *   more efficient recursive implementations exist.
 */
int c(int n, int k) {
    if (n == 0 || k == n || k == 0) {
        return 1;
    } else {
        return c(n - 1, k - 1) + c(n - 1, k);
    }
}

/*
 * Create a string that pads the 
 */
string getInitialColumnSpacing(int currentRowNum, int maxNumRows) {
    int numSpaces = (maxNumRows - currentRowNum)/2;
    string space;
    for (int i = 0; i < 2*numSpaces; i++) {
        space += " ";
    }
    return space;
}

/*
 * Print Pascale's Triangle to the console.
 */
void printPascalTriangle(const int numRows) {
    string initialColSpacing;
    for (int row = 0; row < numRows; row++) {
        cout << getInitialColumnSpacing(row, numRows);
        for (int col = 0; col < row + 1; col++) {
            cout << c(row, col) << " ";
        }
        cout << endl;
    }
}

/*
 * Perform tests and show combination values.
 */
int main() {
    printPascalTriangle(10);

    cout << endl << endl << endl;
    cout << "Computating many Pascale's Triangles with varying algorithms" <<
    "... please wait" << endl;

    // Clock Basic Pascal's Triangle Algorithm
    BasicCombinationAlgorithm compute = BasicCombinationAlgorithm();
    compute.runTests();
    double result = compute.getComputeTime(
                            CombinationAlgorithm::NUM_ROWS_COMPUTED,
                            CombinationAlgorithm::NUM_TRIANGLE_ITERATIONS);
    cout << "Basic Computation Algorithm calculated a " <<
      CombinationAlgorithm::NUM_ROWS_COMPUTED << " row triangle " <<
      CombinationAlgorithm::NUM_TRIANGLE_ITERATIONS << " times in " <<
      result << " seconds" << endl;

    // Clock Pascal's Triangle Algorithm with caching
    CachingCombinationsAlgorithm computeCache = CachingCombinationsAlgorithm();
    computeCache.runTests();
    result = computeCache.getComputeTime(
                            CombinationAlgorithm::NUM_ROWS_COMPUTED,
                            CombinationAlgorithm::NUM_TRIANGLE_ITERATIONS);
    cout << "Caching Computation Algorithm calculated a " <<
      CombinationAlgorithm::NUM_ROWS_COMPUTED << " row triangle " <<
      CombinationAlgorithm::NUM_TRIANGLE_ITERATIONS << " times in " <<
    result << " seconds" << endl;

    return 0;
}
