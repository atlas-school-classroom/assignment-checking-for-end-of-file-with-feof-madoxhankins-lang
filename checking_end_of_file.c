#include <stdio.h>

int main() {
// 
    FILE *fp;

    char buffer[256];

    fp = fopen("example.txt", "r");

    if (fp == NULL) {

        perror("Error opening file");

        return 1;

    }

    while (1) {

        if (fgets(buffer, 256, fp) == NULL) {

            if (feof(fp))

                break;

            if (ferror(fp)) {

                perror("Error reading file");

                fclose(fp);

                return 1;

            }

        } else {

            printf("%s", buffer);

        }

    }

    fclose(fp);

    return 0;

}

