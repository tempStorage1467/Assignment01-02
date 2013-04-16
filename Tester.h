/*
 * File: Tester.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 1 - Pt. 2 - Combinations
 * This file defines a class used to perform unit tests.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef TESTER_H_
#define TESTER_H_

#include <iostream>
using namespace std;

/*
 * Define the prototype of a class whose static members assist in
 *   performing unit tests.
 */
class Tester {
  public:
  /*
   * Helper function for unit tests. Determine whether two integers are
   *   of the same value.
   */
  static bool assertEquals(int expected, int received) {
    if (expected == received) {
        return true;
    } else {
        cout << "TEST FAILURE -- Expected: " << expected << ", "
          << "Received: " << received << endl;
        return false;
    }
  }
};

#endif  // TESTER_H_
