/*
 * File: Combinations.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
using namespace std;

int c(int n, int k) {
    if (n == 0 || k == n || k == 0) {
        return 1;
    } else {
        return c(n - 1, k - 1) + c(n - 1, k);
    }
}

bool assertEquals(int expected, int received) {
    if (expected == received) {
        return true;
    } else {
        cout << "TEST FAILURE -- Expected: " << expected << ", Received: " <<
          received << endl;
        return false;
    }
}

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

int main() {
    testC();
    cout << c(3, 1) << endl;
    return 0;
}
