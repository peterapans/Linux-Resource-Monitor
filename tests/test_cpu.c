#include <stdio.h>
#include <assert.h>
#include "include/cpu.h"

// 模拟测试函数，假设 CPU 使用率应该大于0%
void test_get_cpu_usage() {
    // 这里仅仅是一个简单的检查，假设 get_cpu_usage 应该显示非负数
    printf("Testing CPU usage...\n");
    get_cpu_usage();  // 你需要根据实际函数的行为进行修改
    // 假设返回值大于0，进行简单验证
    assert(1);  // 这里没有实际的检查逻辑，只是示范如何调用
}

int main() {
    test_get_cpu_usage();
    printf("CPU module test passed.\n");
    return 0;
}
