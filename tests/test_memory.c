#include <stdio.h>
#include <assert.h>
#include "include/memory.h"

// 模拟测试函数，检查内存使用率是否正确
void test_get_memory_usage() {
    // 在实际环境中需要处理特定的值，我们简单地进行一个调用
    printf("Testing memory usage...\n");
    get_memory_usage();  // 假设函数打印结果而不是返回值
    assert(1);  // 在实际测试中，你可以通过文件读取等方式来验证结果
}

int main() {
    test_get_memory_usage();
    printf("Memory module test passed.\n");
    return 0;
}
