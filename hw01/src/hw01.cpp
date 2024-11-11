#include <hw01.h>

int hw01(int start, int end)
{
  if (start < 10 || start > 99 || end < 10 || end > 99 || start > end) {
    return -1;
  }

  int totalSum = 0;
  // Ищем простые числа в диапазоне и считаем сумму их цифр
  for (int i = start; i <= end; ++i) {
    bool isPrime = true;
    if (i < 2) isPrime = false;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      int sum = 0;
      int number = i;
      while (number > 0) {
        sum += number % 10;
        number /= 10;
      }
      totalSum += sum;
    }
  }

  return totalSum;
}