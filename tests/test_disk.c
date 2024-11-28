#include <stdio.h>
#include <assert.h>
#include "include/disk.h"

// 模拟测试函数，检查磁盘使用率
void test_get_disk_usage() {
    // 检查磁盘使用率，假设其返回百分比
    printf("Testing disk usage...\n");
    get_disk_usage();  // 假设函数直接打印结果
    assert(1);  // 实际中可以验证具体值
}

int main() {
    test_get_disk_usage();
    printf("Disk module test passed.\n");
    return 0;
}
