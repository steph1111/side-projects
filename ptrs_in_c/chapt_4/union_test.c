#include <stdio.h>

union S {
  double d;
  long l;
  int i;
  char c;
};

int main(void) {
  union S s = {42.6};
  printf("*dp == %.8f, *lp == %ld, *ip == %d, *cp == %d\n", s.d, s.l, s.i, s.c);
  return 0;
}