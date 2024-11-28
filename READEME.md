# 系统资源监视器

## 项目简介

系统资源监视器是一个运行在 Linux 系统上的轻量级工具，用于实时监控系统的资源使用情况。它可以显示以下资源的实时使用情况：

- CPU 使用率
- 内存使用率
- 磁盘使用率
- GPU 使用率（需要支持 `nvidia-smi`）
- 网络流量监控（实时显示网络接口的流入和流出流量）

本项目采用 C 语言实现，基于 Linux 的 `/proc` 文件系统和系统命令，提供高效、快速的资源监控功能。

---

## 功能特性

1. **CPU 使用率监控**  
   实时显示 CPU 使用率（以百分比表示）。

2. **内存使用率监控**  
   实时显示内存使用情况，包括总内存、已用内存和空闲内存。

3. **磁盘使用率监控**  
   显示磁盘分区的已用空间和总空间的百分比。

4. **GPU 使用率监控**  
   使用 `nvidia-smi` 命令获取 GPU 的实时利用率和显存使用情况（需要 NVIDIA 驱动支持）。

5. **网络流量监控**  
   实时显示系统网络接口的流入和流出流量。

---

## 项目结构

```
project_root/
|-- docs/
|   |-- design_document.md         # 项目设计文档
|   |-- user_manual.md             # 用户手册
|
|-- src/
|   |-- main.c                    # 主程序入口
|   |-- cpu.c                     # CPU模块实现
|   |-- memory.c                  # 内存模块实现
|   |-- disk.c                    # 磁盘模块实现
|   |-- gpu.c                     # GPU模块实现
|   |-- network.c                 # 网络流量监控模块实现
|   |-- include/
|       |-- cpu.h                 # CPU模块头文件
|       |-- memory.h              # 内存模块头文件
|       |-- disk.h                # 磁盘模块头文件
|       |-- gpu.h                 # GPU模块头文件
|       |-- network.h             # 网络流量监控模块头文件
|
|-- tests/
|   |-- test_cpu.c                 # CPU模块的单元测试
|   |-- test_memory.c              # 内存模块的单元测试
|   |-- test_disk.c                # 磁盘模块的单元测试
|   |-- test_gpu.c                 # GPU模块的单元测试
|   |-- test_network.c             # 网络流量监控模块的单元测试
|
|-- Makefile                       # 用于构建和测试项目的Makefile
|-- README.md                      # 项目说明文件
|-- LICENSE.txt                    # 项目许可证
```

---

## 使用指南

### 1. 环境要求

- 操作系统：Linux
- 编译器：GCC
- 必须具备以下条件：
  - NVIDIA GPU 驱动和 `nvidia-smi` 工具（如果监控 GPU）
  - Linux 内核支持 `/proc` 文件系统
  - 网络接口支持，系统应允许读取网络流量

### 2. 编译项目

进入项目目录并运行以下命令：

```bash
make
```

成功后，会生成一个名为 `sys_monitor` 的可执行文件。

如果没有 `make` 工具，可以手动运行以下命令编译：

```bash
gcc src/main.c src/cpu.c src/memory.c src/disk.c src/gpu.c src/network.c -o sys_monitor
```

### 3. 运行程序

执行以下命令启动系统资源监视器：

```bash
./sys_monitor
```

程序会每秒刷新一次资源使用情况，按下 `Ctrl+C` 终止程序。

---

## 示例输出

程序运行时的输出示例如下：

```
===== 系统资源监视器 =====
CPU使用率: 12.35%
内存使用率: 65.48% (3214.00MB / 4915.00MB)
磁盘使用率: 45.32% (45300MB / 100000MB)
GPU使用率: 8%
显存使用率: 30.00% (1536MB / 5120MB)
网络流量：
  eth0: 接收流量: 10.12KB/s，发送流量: 5.34KB/s
=========================
```

---

## 运行测试

1. 编译并运行测试：

    试文件放置在 `tests` 目录下，可以使用以下命令进行编译和测试：

    ```bash
    gcc tests/test_cpu.c src/cpu.c -o test_cpu
    gcc tests/test_memory.c src/memory.c -o test_memory
    gcc tests/test_disk.c src/disk.c -o test_disk
    gcc tests/test_gpu.c src/gpu.c -o test_gpu
    gcc tests/test_network.c src/network.c -o test_network
    ```

    然后运行测试：

    ```bash
    ./test_cpu
    ./test_memory
    ./test_disk
    ./test_gpu
    ./test_network
    ```

2. 输出示例：

    如果所有的单元测试通过，你应该会看到类似如下的输出：

    ```bash
    Testing CPU usage...
    CPU module test passed.
    
    Testing memory usage...
    Memory module test passed.
    
    Testing disk usage...
    Disk module test passed.
    
    Testing GPU usage...
    GPU module test passed.
    
    Testing network traffic...
    Network module test passed.
    ```

---

## 常见问题

1. **为什么没有 GPU 数据？**  
   请确保你的系统安装了 NVIDIA 驱动，并支持 `nvidia-smi`。

2. **如何修改刷新时间？**  
   修改 `src/main.c` 中的 `sleep(1)`，将 `1` 替换为所需的秒数，然后重新编译。

3. **程序运行时提示权限不足？**  
   请确保用户有读取 `/proc` 文件系统和运行 `nvidia-smi` 的权限。

4. **如何查看网络流量？**  
   程序默认会显示所有网络接口的流量数据。如果系统中有多个网络接口，可能会显示多个接口的流量数据。

---

## 开发与扩展

1. **功能扩展**  
   - 可以增加更多的监控功能，例如温度监控、进程监控等。
   - 支持更多的硬件设备监控，如硬盘温度、系统电池状态等。

2. **代码改进**  
   - 优化文件读取性能。
   - 支持更多的 Linux 系统命令。
   - 提供图形界面显示监控结果（如使用 GTK 或 Qt）。

---

## 许可证

本项目使用 [MIT License](LICENSE.txt) 开源。

---

### 主要更新

1. **新增网络流量监控**：
   - 添加了网络流量监控的描述，并在输出中展示了网络接口的流量信息。

2. **测试部分更新**：
   - 增加了 `test_network.c` 作为网络流量监控模块的单元测试。

3. **功能扩展部分**：
   - 提到了将来可以扩展监控更多系统资源的功能，并提供了其他建议的功能扩展。

### 注意事项

- 确保在 `src/network.c` 和 `include/network.h` 中实现了网络流量监控的相关代码。
- 在测试部分中增加了 `test_network.c` 的相关单元测试。
