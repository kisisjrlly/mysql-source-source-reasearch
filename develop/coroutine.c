#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(int src[], int dest[], int size) {
    int rounds = size / 8;

    int i = 0;
    switch (size % 8)
    {
    case 0:
        while (!(rounds == 0))
        {
            rounds = rounds - 1;
            dest[i] = src[i];
            i = i + 1;

        case 7:
            dest[i] = src[i];
            i = i + 1;
        case 6:
            dest[i] = src[i];
            i = i + 1;
        case 5:
            dest[i] = src[i];
            i = i + 1;
        case 4:
            dest[i] = src[i];
            i = i + 1;
        case 3:
            dest[i] = src[i];
            i = i + 1;
        case 2:
            dest[i] = src[i];
            i = i + 1;
        case 1:
            dest[i] = src[i];
            i = i + 1;
        };
    }
}

int main () {
        int size = 20;
        int dest[size], src[size];

        // Assign some random values to src[] 
        int i;
        for (i=0; i<size; i++)
                src[i] = rand()%2;

        copy(src, dest, size);

        for (i=0; i<size ; i++)
                printf("%d\t%d\n", src[i], dest[i]);
}
