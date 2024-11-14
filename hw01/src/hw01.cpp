#include <hw01.h>

int calculateDigitSum(int num) {
  int digitSum = 0;
  while (num > 0) {
    digitSum += num % 10;
    num /= 10;
  }
  return digitSum;
}

bool isNumberPrime(int num) {
  if (num < 2) return false;
  for (int divisor = 2; divisor * divisor <= num; ++divisor) {
    if (num % divisor == 0) {
      return false;
    }
  }
  return true;
}

int hw01(int low, int high) {
  if (low < 10 || low > 99 || high < 10 || high > 99 || low > high) {
    return -1;
  }

  int primeDigitSum = 0;

  for (int currentNum = low; currentNum <= high; ++currentNum) {
    if (isNumberPrime(currentNum)) {
      primeDigitSum += calculateDigitSum(currentNum);
    }
  }

  return primeDigitSum;
}
