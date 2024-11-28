#include <stdio.h>
#include <stdlib.h>
#include "include/cpu.h"

void get_cpu_usage() {
    FILE *fp;
    char buffer[128];
    long user, nice, system, idle;
    static long prev_user = 0, prev_nice = 0, prev_system = 0, prev_idle = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("无法读取/proc/stat");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %ld %ld %ld %ld", &user, &nice, &system, &idle);
    fclose(fp);

    long total_diff = (user + nice + system + idle) - (prev_user + prev_nice + prev_system + prev_idle);
    long idle_diff = idle - prev_idle;

    if (total_diff != 0) {
        double cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;
        printf("CPU使用率: %.2f%%\n", cpu_usage);
    }

    prev_user = user;
    prev_nice = nice;
    prev_system = system;
    prev_idle = idle;
}
