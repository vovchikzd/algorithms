#include <stdio.h>

unsigned long long mabs(unsigned long long x) { return x < 0 ? -x : x; }

unsigned long long mod(unsigned long long x, unsigned long long y) {
  unsigned long long res;
  res = x % y;
  if (res < 0) { res += mabs(y); }
  return res;
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
  while (y != 0) {
    unsigned long long new = mod(x, y);
    x = y; y = new;
  }
  return x;
}

int main(void) {
  unsigned long long first, second;
  scanf("%llu%llu", &first, &second);
  unsigned long long res = gcd(first, second);
  printf("%llu\n", res);
  return 0;
}
