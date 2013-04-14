/*
 * File: BasicCombinationAlgorithm.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * This file implements the BasicCombinationAlgorithm() class, which
 *   provides a simple method of computing a combination value.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */


#include <time.h>
#include "BasicCombinationAlgorithm.h"
#include "Tester.h"


/*
 * Recursively perform the combination of n, k.
 * This is the basic method of computing a combination recursively, done
 *    for the core of the CS106b assignment.
 */
unsigned int BasicCombinationAlgorithm::performCombinationComputation(
                                                            int n, int k) {
    if (n == 0 || k == n || k == 0) {
        return 1;
    } else {
        return performCombinationComputation(n - 1, k - 1) +
          performCombinationComputation(n - 1, k);
    }
}

/*
 * Calculate how long it takes to compute the combinations for Pascal's
 *   Triangle a specific number of times using this class's method for
 *   computing.
 */
double BasicCombinationAlgorithm::getComputeTime(int numRows,
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
    return (endTime - beginTime) / CLOCKS_PER_SEC;
}

/*
 * Run unit tests on the performCombinationComputation() method.
 */
void BasicCombinationAlgorithm::runTests() {
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
    Tester::assertEquals(30045015, performCombinationComputation(30, 20));
    Tester::assertEquals(77558760, performCombinationComputation(29, 15));
    Tester::assertEquals(6435, performCombinationComputation(15, 7));
}
