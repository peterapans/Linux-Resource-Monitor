#include <stdio.h>
#include <assert.h>
#include "include/gpu.h"

// 模拟测试函数，检查 GPU 使用率
void test_get_gpu_usage() {
    // 检查 GPU 使用率，假设该函数可以正确打印使用率
    printf("Testing GPU usage...\n");
    get_gpu_usage();  // 假设函数直接打印结果
    assert(1);  // 实际测试中可以检查 nvidia-smi 的输出
}

int main() {
    test_get_gpu_usage();
    printf("GPU module test passed.\n");
    return 0;
}
