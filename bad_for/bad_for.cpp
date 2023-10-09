#include <iostream>

int main () {
  const int LEN_I = 4, LEN_J = 3;
  int arr[LEN_I][LEN_J] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  
  for (int i = 0, j = 0; i < LEN_I; j++, i += int(j % LEN_J == 0)) {
    std::cout << arr[i][j % LEN_J] << std::endl;
  }

  return 0;
}