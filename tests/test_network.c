#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "include/network.h"

void test_get_network_traffic() {
    // 模拟网络流量监控
    printf("Testing network traffic monitoring...\n");
    
    // 我们有一个名为 eth0 的网络接口
    char interface[] = "eth0";
    
    long rx_bytes_before, tx_bytes_before;
    long rx_bytes_after, tx_bytes_after;
    
    // 获取初始的接收和发送字节数
    int ret = get_network_traffic(interface, &rx_bytes_before, &tx_bytes_before);
    assert(ret == 0 && "Failed to get initial network traffic");

    // 延迟一秒以获取新的流量数据
    sleep(1);
    
    // 获取更新后的接收和发送字节数
    ret = get_network_traffic(interface, &rx_bytes_after, &tx_bytes_after);
    assert(ret == 0 && "Failed to get updated network traffic");

    // 检查网络流量是否增长
    assert(rx_bytes_after >= rx_bytes_before && "Received bytes should have increased");
    assert(tx_bytes_after >= tx_bytes_before && "Transmitted bytes should have increased");
    
    printf("Network traffic test passed.\n");
}

int main() {
    // 运行网络流量监控测试
    test_get_network_traffic();

    return 0;
}
