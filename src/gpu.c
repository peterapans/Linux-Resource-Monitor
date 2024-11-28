#include <stdio.h>
#include <stdlib.h>
#include "include/gpu.h"

void get_gpu_usage() {
    FILE *fp;
    char buffer[256];
    char utilization[16], memory_usage[16];
    int gpu_usage, mem_used, mem_total;

    // 使用 nvidia-smi 命令获取 GPU 信息
    fp = popen("nvidia-smi --query-gpu=utilization.gpu,memory.used,memory.total --format=csv,noheader,nounits", "r");
    if (fp == NULL) {
        perror("无法执行nvidia-smi命令");
        return;
    }

    // 解析 GPU 使用率和显存信息
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d, %d, %d", &gpu_usage, &mem_used, &mem_total);
        double mem_usage = 100.0 * mem_used / mem_total;

        printf("GPU使用率: %d%%\n", gpu_usage);
        printf("显存使用率: %.2f%% (%dMB / %dMB)\n", mem_usage, mem_used, mem_total);
    } else {
        printf("无法读取GPU信息，请确保系统安装了NVIDIA驱动并支持nvidia-smi。\n");
    }
    pclose(fp);
}
