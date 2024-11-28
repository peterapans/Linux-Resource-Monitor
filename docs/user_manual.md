# 用户手册

## 1. 项目简介

系统资源监视器是一个 Linux 命令行工具，用于实时监控系统的资源使用情况。它显示以下资源的使用情况：
- CPU 使用率
- 内存使用率
- 磁盘使用率
- GPU 使用率（需要支持 `nvidia-smi`）
- 网络流量（流入/流出）

本工具基于 C 语言开发，通过 Linux 的 `/proc` 文件系统以及系统命令来获取和展示数据。

## 2. 安装与编译

### 2.1 环境要求

- 操作系统：Linux
- 编译器：GCC（GNU 编译器）
- NVIDIA GPU 驱动和 `nvidia-smi`（仅在监控 GPU 时需要）
- Linux 内核支持 `/proc` 文件系统

### 2.2 安装步骤

1. 克隆或下载项目源码：
    ```bash
    git clone https://github.com/peterapans/Linux-Resource-Monitor
    ```

2. 进入项目目录：
    ```bash
    cd sys_monitor
    ```

3. 编译项目：
    如果系统已安装 `make` 工具，可以直接运行 `make` 命令进行编译：
    ```bash
    make
    ```
    如果没有 `make`，可以手动编译：
    ```bash
    gcc src/main.c src/cpu.c src/memory.c src/disk.c src/gpu.c src/network.c -o sys_monitor
    ```

4. 生成的可执行文件 `sys_monitor` 会在项目根目录下。

### 2.3 运行程序

编译完成后，运行以下命令启动系统资源监视器：
```bash
./sys_monitor
