#include <stdio.h>

int main(void) {
  int a[] = {1, 2, 3, 4, 5};
  int size_a = sizeof a / sizeof *a;
  for (int i = 0; i < size_a; i++) {
    printf("a[%d] bites [ ", a[i]);
    char *cp = (char *) (a + i);
    for (int j = 0; j < sizeof *a; j++) {
      printf("%d ", cp[j]);
    }
    printf("]\n");
  }
  return 0;
}