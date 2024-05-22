#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char buf[256];
  char mapping[32] = {
      // TODO
      [0 ... 15] = 0,

      0b100000, // А
      0b101000, // Б
      0b011101, // В
      0b111100, // Г

      // TODO
  };

  while (1) {
    fgets(buf, sizeof buf, stdin);
    int n = strlen(buf);
    printf("got %d bytes\n", n);

    for (int i = 0; buf[i] != 0; i++) {
      // printf("hex %d: %x\n", i, buf[i]);

      // Russian unicode has 2 bytes, we ignore every first byte.
      if (i % 2 == 1) {

        int index = buf[i] & 0b011111;
        // printf("index %d\n", index);
        int code = mapping[index];
        printf("code %06b\n", code);
      }
    }
  }
  return 0;
}
