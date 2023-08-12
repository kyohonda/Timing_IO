#include <stdio.h>
#include <time.h>

int main() {
    double CPU_time_use;
    clock_t start_time, end_time;
    double CPU_time_NonIO, CPU_time_IO;
    int i;
    
    // non-I/O operation
    start_time = clock();
    for (i=0;i<1000000000;i++) {
        int result = i+1;
    }
    end_time = clock();
    CPU_time_NonIO = (end_time-start_time)/CLOCKS_PER_SEC;

    // I/O operation
    start_time = clock();
    for (i=0;i<100000;i++) {
        printf("Use I/O operation\n");
    }
    end_time = clock();
    CPU_time_IO = (end_time-start_time)/CLOCKS_PER_SEC;

    printf("Non-I/O operation take %f seconds\n", CPU_time_NonIO);
    printf("I/O operation take %f seconds\n", CPU_time_IO);
    return 0;
}
