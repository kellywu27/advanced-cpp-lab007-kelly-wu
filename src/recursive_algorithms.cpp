
#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    (void)n;

    if (n < 0) {
        throw std::invalid_argument("Factorial cannot use negative numbers");
    }

    // base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // recursive case
    return n * factorial(n - 1);
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    (void)n;

    if (n < 0) {
        throw std::invalid_argument("Factorial cannot use negative numbers");
    }

    int result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    (void)n;

    if (n < 0) {
        throw std::invalid_argument("Fibonacci cannot use negative numbers");
    }

    // base cases
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    // recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    (void)n;

    if (n < 0) {
        throw std::invalid_argument("Fibonacci cannot use negative numbers");
    }

    if (n == 0) {
        return 0;
    }

    int previous = 0;
    int current = 1;

    for (int i = 2; i <= n; i++) {
        int next = previous + current;
        previous = current;
        current = next;
    }

    return current;
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    (void)array;
    (void)target;

    // base case: empty array
    if (array.empty()) {
        return -1;
    }

    auto search = [&](auto&& self, int left, int right) -> int {
        // base case: target NOT found
        if (left > right) {
            return -1;
        }

        int middle = left + (right - left) / 2;

        // base case: target found
        if (array[middle] == target) {
            return middle;
        }

        // recursive case
        if (target < array[middle]) {
            return self(self, left, middle - 1);
        }

        return self(self, middle + 1, right);
    };

    return search(search, 0, static_cast<int>(array.size()) - 1);
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    (void)array;
    (void)target;

    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (array[middle] == target) {
            return middle;
        }

        if (target < array[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return -1;
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    (void)array;

    // base case: empty array
    if (array.empty()) {
        return 0;
    }

    // recursive case: add first element to sum of rest
    std::vector<int> rest(array.begin() + 1, array.end());
    return array[0] + arraySum(rest);
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    (void)array;

    int sum = 0;

    for (int i = 0; i < static_cast<int>(array.size()); i++) {
        sum += array[i];
    }

    return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    (void)array;

    // base case
    if (array.size() <= 1) {
        return;
    }

    // recursive case: swap first & last elements
    std::swap(array.front(), array.back());

    // recurse remaining middle elements
    std::vector<int> middle(array.begin() + 1, array.end() - 1);
    reverseArray(middle);

    // copy reversed middle back into original array
    for (int i = 1; i < static_cast<int>(array.size()) - 1; i++) {
        array[i] = middle[i - 1];
    }
}

// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    (void)array;

    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left < right) {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
}
