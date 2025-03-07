#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>     
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: sum-nbo <files...>\n");
        return 1;
    }

    uint32_t total_sum = 0;

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "rb");

        uint32_t number;
        size_t read_size;
        
        while ((read_size = fread(&number, sizeof(uint32_t), 1, file)) == 1) {
            number = ntohl(number);

            if (i == 1) {
                printf("%u(0x%04x)", number, number);
            } else {
                printf(" + %u(0x%04x)", number, number);
            }
            total_sum += number;
        }

        if (!feof(file)) {
            printf("\nIncomplete 4-byte block encountered in file %s\n", argv[i]);
        }

        fclose(file);
    }

    printf(" = %u(0x%04x)\n", total_sum, total_sum);

    return 0;
}
