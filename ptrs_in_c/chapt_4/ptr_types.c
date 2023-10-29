#include <stdio.h>

int main(void) {
  double d = 42.6;
  double *dp = &d;
  long *lp = (long *)&d;
  int *ip = (int *)&d;
  char *cp = (char *)&d;
  printf("*dp == %.8f, *lp == %ld, *ip == %d, *cp == %d\n", *dp, *lp, *ip, *cp);

  printf("Byte contents: ");
  for(int i = 0; i < sizeof d; i++) {
    printf("%d ", cp[i]);
  }

  return 0;
}