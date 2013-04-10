/*
 * File: CachingCombinationAlgorithm.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * Copyright 2013 <Eric Beach>
 * This file defines a class that class that uses caching to compute
 *  recursively Pascale's Triangle.
 * [TODO: rewrite the documentation]
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <time.h>
#include "CachingCombinationAlgorithm.h"
#include "Tester.h"

/*
 * Constructor. Necessary to initialize array values used in caching.
 */
CachingCombinationsAlgorithm::CachingCombinationsAlgorithm() {
  /*
   * Since C++ doesn't initialize default values,
   *   set a default value so that
   *   integers in memory do not confuse program.
   */
  for (int row = 0; row < CombinationAlgorithm::NUM_ROWS_COMPUTED; row++) {
    for (int col = 0; col < row + 1; col ++) {
        cachedValue[row][col] = -1;
    }
  }
}

/*
 * Compute Pascale's Triangle value for a given number.
 * Partial credit to: http://stackoverflow.com/questions/15580291/
 *   "How to efficiently calculate a row in pascal's triangle?"
 */
int CachingCombinationsAlgorithm::performCombinationComputation(int n, int k) {
    if (n == 0 || k == n || k == 0) {
        return 1;
    } else if (k == 1 || k == (n - 1)) {
        return n;
    } else if (cachedValue[n][k] >= 0) {
        return cachedValue[n][k];
    } else {
        int result = performCombinationComputation(n - 1, k - 1) +
        performCombinationComputation(n - 1, k);
        cachedValue[n][k] = result;
        return result;
    }
}


/*
 * Compute the amount of time taken to calculate the first {numRows} rows of
 *   Pascale's Triangle {numIterations} times.
 */
double CachingCombinationsAlgorithm::getComputeTime(int numRows,
                                                    int numIterations) {
    double beginTime = clock();

    for (int iteration = 0; iteration < numIterations; iteration++) {
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < row + 1; col++) {
                performCombinationComputation(row, col);
            }
        }
    }

    double endTime = clock();
    return (endTime - beginTime);
}

/*
 * Run unit tests on the performCombinationComputation() method.
 */
void CachingCombinationsAlgorithm::runTests() {
    // TODO: Find a way to pass into tester a reference to
    //    perform CombinationComputation so there is only one
    //    set of assertEquals() in the code base
    Tester::assertEquals(1, performCombinationComputation(0, 0));
    Tester::assertEquals(1, performCombinationComputation(1, 0));
    Tester::assertEquals(1, performCombinationComputation(1, 1));
    Tester::assertEquals(1, performCombinationComputation(3, 0));
    Tester::assertEquals(3, performCombinationComputation(3, 1));
    Tester::assertEquals(3, performCombinationComputation(3, 2));
    Tester::assertEquals(1, performCombinationComputation(3, 3));
    Tester::assertEquals(1, performCombinationComputation(7, 0));
    Tester::assertEquals(7, performCombinationComputation(7, 1));
    Tester::assertEquals(21, performCombinationComputation(7, 2));
    Tester::assertEquals(35, performCombinationComputation(7, 3));
    Tester::assertEquals(35, performCombinationComputation(7, 4));
    Tester::assertEquals(21, performCombinationComputation(7, 5));
    Tester::assertEquals(21, performCombinationComputation(7, 5));
    Tester::assertEquals(7, performCombinationComputation(7, 6));
    Tester::assertEquals(1, performCombinationComputation(7, 7));
    // TODO: test for largest value permitted for an integer
    // Tester::assertEquals(30045015, performCombinationComputation(30, 20));
    // Tester::assertEquals(77558760, performCombinationComputation(29, 15));
}
