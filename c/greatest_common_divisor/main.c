#include <stdio.h>

int mabs(int x) { return x < 0 ? -x : x; }

int mod(int x, int y) {
  int res;
  res = x % y;
  if (res < 0) { res += mabs(y); }
  return res;
}

int gcd(int x, int y) {
  while (y != 0) {
    int new = mod(x, y);
    x = y; y = new;
  }
  return x;
}

int main(void) {
  int first, second;
  scanf("%d%d", &first, &second);
  int res = gcd(first, second);
  printf("%d\n", res);
  return 0;
}
