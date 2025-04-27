/* This program reads binary temperature data for 365/366 days and writes to an ASCII text file. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 31
#define COLS 31
#define DAYS_IN_YEAR 366  // Maximum possible days in a year (leap year)

int main()
{
    float temperature[ROWS][COLS];
    int i, j, k;
    char output_line[2000];  
    FILE *fin, *fout;
    
    // Open input file in binary read mode
    // Place the grid file dowloaded in the base folder
    fin = fopen("pathtoMaxtempgridfile", "rb");
    if (fin == NULL) {
        fprintf(stderr, "Error: Cannot open input file 'Maxtemp_MaxT_2023.GRD'\n");
        return EXIT_FAILURE;
    }
    
    // Open output file in text write mode
    // Extracting temperature data(In our case is 1st Jan 2023)
    // Create a folder named actual_data to store parsed daily max temperature txt files
    fout = fopen("actual_data/IND010123MaxTemp.TXT", "w");
    if (fout == NULL) {
        fprintf(stderr, "Error: Cannot open output file 'India2023Temp.TXT'\n");
        fclose(fin);
        return EXIT_FAILURE;
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    for (k = 0; k < DAYS_IN_YEAR; k++) {
        size_t items_read = fread(temperature, sizeof(temperature), 1, fin);
        
        if (items_read != 1) {
            if (feof(fin)) {
                printf("Processed %d days of data\n", k);
                break;  
            } else {
                fprintf(stderr, "Error reading data for day %d\n", k + 1);
                break;
            }
        }
        
        // Write data for day 1 (or any specific day you want to output)
        if (k == 0) {  
            // fprintf(fout, "Temperature data for Day %d:\n", k + 1);
            
            for (i = ROWS-1; i >= 0; i--) {
                output_line[0] = '\0';
                for (j = 0; j < COLS; j++) {
                    char temp[10];
                    if(temperature[i][j] >= 99.89 && temperature[i][j] <= 99.91) {
                        strcpy(temp, "  -1  "); // Maintaining the same width as %6.2f
                    } else {
                        sprintf(temp, "%6.2f", temperature[i][j]);
                    }
                    
                    strcat(output_line, temp);
                }
                fprintf(fout, "%s\n", output_line);
            }
            // fprintf(fout, "\n");
        }
    }
    fclose(fin);
    fclose(fout);
    
    printf("Data processing complete. Results written to India2023Temp.TXT\n");
    return EXIT_SUCCESS;
}
