#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/memory.h"

void get_memory_usage() {
    FILE *fp;
    char key[64];
    long value, mem_total = 0, mem_free = 0;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("无法读取/proc/meminfo");
        return;
    }

    while (fscanf(fp, "%s %ld", key, &value) != EOF) {
        if (strcmp(key, "MemTotal:") == 0) {
            mem_total = value;
        }
        if (strcmp(key, "MemFree:") == 0) {
            mem_free = value;
        }
        if (mem_total && mem_free) break;
    }
    fclose(fp);

    double mem_used = mem_total - mem_free;
    double mem_usage = 100.0 * mem_used / mem_total;
    printf("内存使用率: %.2f%% (%.2fMB / %.2fMB)\n", mem_usage, mem_used / 1024.0, mem_total / 1024.0);
}
