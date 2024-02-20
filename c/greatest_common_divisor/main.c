#include <stdio.h>

int mabs(int x) { return x < 0 ? -x : x; }

int mod(int x, int y) {
  int res;
  res = x % y;
  if (res < 0) { res += mabs(y); }
  return res;
}

int gcd(int x, int y) {
  int new = mod(x, y);
  if (new == 0) { return y; }
  return gcd(y, new);
}

int main(void) {
  int first, second;
  scanf("%d%d", &first, &second);
  int res = gcd(first, second);
  printf("%d\n", res);
  return 0;
}
