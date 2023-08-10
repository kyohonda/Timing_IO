#include <stdio.h>
#include <time.h>

int main() {
    double CPU_time_use;
    clock_t start_time, end_time;
    int i;
    
    // non-I/O operation
    start_time = clock();
    int result = 0;
    for (i=0;i<1000000;i++) {
        result = result+i;
    }
    end_time = clock();
    CPU_time_use = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("Non-I/O operation take %f seconds\n", CPU_time_use);

    // I/O operation
    start_time = clock();
    for (i=0;i<1000000;i++) {
        printf("Use I/O operation\n");
    }
    end_time = clock();
    CPU_time_use = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("I/O operation take %f seconds\n", CPU_time_use);

    return 0;
}
