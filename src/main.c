#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/cpu.h"
#include "include/memory.h"
#include "include/disk.h"
#include "include/gpu.h"
#include "include/network.h"  

int main() {
    while (1) {
        printf("\n===== 系统资源监视器 =====\n");
        get_cpu_usage();
        get_memory_usage();
        get_disk_usage();
        get_gpu_usage();
        get_network_usage();  // 添加网络流量监控
        printf("=========================\n");
        sleep(1);  // 每秒更新一次
    }

    return 0;
}
