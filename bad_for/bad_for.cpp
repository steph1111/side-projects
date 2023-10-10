#include <iostream>

int main () {
  const int LEN_I = 4, LEN_J = 3;
  int arr[LEN_I][LEN_J] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  
  for (int i = 0, j = 0; i < LEN_I; j = (j + 1) % LEN_J, i += int(j == 0)) {
    std::cout << arr[i][j] << std::endl;
  }

  return 0;
}