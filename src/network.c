#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/network.h"

// 用来存储上次的数据，做流量增量计算
static long long prev_rx_bytes = 0, prev_tx_bytes = 0;

void get_network_usage() {
    FILE *fp;
    char buffer[256];
    long long rx_bytes, tx_bytes;
    static long long total_rx_bytes = 0, total_tx_bytes = 0;

    // 打开 /proc/net/dev 文件来获取网络接口的流量数据
    fp = fopen("/proc/net/dev", "r");
    if (fp == NULL) {
        perror("无法读取 /proc/net/dev 文件");
        return;
    }

    // 跳过前两行头部信息
    fgets(buffer, sizeof(buffer), fp);
    fgets(buffer, sizeof(buffer), fp);

    // 读取每行数据
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char iface[16];
        int fields = sscanf(buffer, "%s %lld %*d %*d %*d %*d %*d %*d %lld", iface, &rx_bytes, &tx_bytes);
        
        if (fields == 3) {
            // 计算每个接口的流量
            if (strcmp(iface, "lo:") != 0) {  // 排除 lo (本地回环接口)
                long long rx_diff = rx_bytes - prev_rx_bytes;
                long long tx_diff = tx_bytes - prev_tx_bytes;

                // 累积流量
                total_rx_bytes += rx_diff;
                total_tx_bytes += tx_diff;

                printf("网络接口 %s:\n", iface);
                printf("  下载流量: %.2fMB (增量: %.2fMB)\n", total_rx_bytes / 1024.0 / 1024.0, rx_diff / 1024.0 / 1024.0);
                printf("  上传流量: %.2fMB (增量: %.2fMB)\n", total_tx_bytes / 1024.0 / 1024.0, tx_diff / 1024.0 / 1024.0);
            }
        }
    }

    // 更新上次的流量数据
    prev_rx_bytes = rx_bytes;
    prev_tx_bytes = tx_bytes;

    fclose(fp);
}
