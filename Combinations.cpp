/*
 * File: Combinations.cpp
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

#include <iostream>
#include "console.h"
using namespace std;

/*
 * Calculate the combination of c(n, k).
 * See https://en.wikipedia.org/wiki/Combination
 */
int c(int n, int k) {
    // TODO: make more efficient by taking shortcuts such as the (n, 1) value
    // in a row is n
    if (n == 0 || k == n || k == 0) {
        return 1;
    } else {
        return c(n - 1, k - 1) + c(n - 1, k);
    }
}

/*
 * Helper function for unit tests. Determine whether two integers are
 *   of the same value.
 */
bool assertEquals(int expected, int received) {
    if (expected == received) {
        return true;
    } else {
        cout << "TEST FAILURE -- Expected: " << expected << ", Received: " <<
          received << endl;
        return false;
    }
}

/*
 * Perform unit tests on the combinations function.
 */
void testC() {
    assertEquals(1, c(0, 0));
    assertEquals(1, c(1, 0));
    assertEquals(1, c(1, 1));
    assertEquals(1, c(3, 0));
    assertEquals(3, c(3, 1));
    assertEquals(3, c(3, 2));
    assertEquals(1, c(3, 3));
    assertEquals(1, c(7, 0));
    assertEquals(7, c(7, 1));
    assertEquals(21, c(7, 2));
    assertEquals(35, c(7, 3));
    assertEquals(35, c(7, 4));
    assertEquals(21, c(7, 5));
    assertEquals(7, c(7, 6));
    assertEquals(1, c(7, 7));
}

/*
 * Perform tests and show combination values.
 */
int main() {
    // TODO: time different methods of computing the triangle and show the times
    // TODO: try multi-threadded method
    testC();
    cout << "c(3, 1): " << c(3, 1) << endl;
    cout << "c(10, 5): " << c(10, 5) << endl;
    return 0;
}
