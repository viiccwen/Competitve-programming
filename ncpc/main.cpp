#include <stdio.h>

int main() {
  int a = 26;
  int b = (a++) + (a++);
  printf("%d", b);

  return 0;
}