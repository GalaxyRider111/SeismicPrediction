//
// Created by Rares Gabriel on 21/05/2025.
//

#ifndef CUTREMUR_H
#define CUTREMUR_H


#include <stdio.h>

void moving_average(float data[], float result[], int size, int window) {
    for (int i = 0; i <= size - window; i++) {
        float sum = 0.0;
        for (int j = 0; j < window; j++) {
            sum += data[i + j];
        }
        result[i + window - 1] = sum / window;
    }
}

void cutremure() {
    float numar_cutremure[] = {
        32, 30, 29, 34, 34, 36, 28, 27, 30, 33, 35, 31,
        29, 28, 32, 30, 27, 33, 31, 29, 34, 32, 28, 30,
        33, 31, 29, 28, 36, 35, 30, 33, 29, 27, 30, 32
    };

    float magnitudine_medie[] = {
        2.96, 2.84, 3.04, 2.65, 2.91, 2.98, 3.10, 2.95, 2.88, 2.76, 2.85, 2.90,
        3.00, 2.87, 2.93, 2.91, 2.95, 2.86, 2.88, 3.01, 2.90, 2.84, 2.79, 2.89,
        3.01, 2.90, 2.93, 2.88, 2.97, 3.00, 2.85, 2.92, 2.88, 2.83, 2.91, 2.94
    };

    int size = sizeof(numar_cutremure) / sizeof(numar_cutremure[0]);
    int window_size = 3;

    float *rez_cutremure  = malloc(size * sizeof *rez_cutremure);
    float *rez_magnitudine = malloc(size * sizeof *rez_magnitudine);
    if (!rez_cutremure || !rez_magnitudine) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        rez_cutremure[i] = -1;
        rez_magnitudine[i] = -1;
    }

    moving_average(numar_cutremure, rez_cutremure, size, window_size);
    moving_average(magnitudine_medie, rez_magnitudine, size, window_size);

    FILE *fp = fopen("rezultate_cutremure.csv", "w");
    if (fp == NULL) {
        perror("Eroare fisier");
        return;
    }

    fprintf(fp, "Luna,Cutremure,MA_Cutremure,Magnitudine,MA_Magnitudine\n");

    for (int i = 2; i < size; i++) {
        fprintf(fp, "%d,%.0f,", i - 1, numar_cutremure[i]);

        if (i >= window_size - 1)
            fprintf(fp, "%.2f,", rez_cutremure[i]);
        else
            fprintf(fp, ",");

        fprintf(fp, "%.2f,", magnitudine_medie[i]);

        if (i >= window_size - 1)
            fprintf(fp, "%.2f\n", rez_magnitudine[i]);
        else
            fprintf(fp, "\n");
    }


    free(rez_magnitudine);
    free(rez_cutremure);
    fclose(fp);
    printf("Data SAVED\n");

}



#endif //CUTREMUR_H
