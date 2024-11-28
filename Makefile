CC = gcc
CFLAGS = -Wall -g

SRCS = src/main.c src/cpu.c src/memory.c src/disk.c src/gpu.c src/network.c
OBJS = $(SRCS:.c=.o)
EXEC = sys_monitor

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)   # 使用 Tab 缩进

clean:
	rm -f $(OBJS) $(EXEC)   # 使用 Tab 缩进
