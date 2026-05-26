CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include

SRCS = main.c \
$(wildcard src/basic/*.c) \
$(wildcard src/advanced/*.c) \
$(wildcard src/utils/*.c)

OBJS = $(SRCS:.c=.o)

Target = program_sorting

all: $(Target)

$(Target): $(OBJS)
	$(CC) $(CFLAGS) -o $(Target) $(OBJS)
	@echo "== [Sukses] Program behasil bos! jalankan dengan ./$(Target) =="

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(Target)
	@echo "Clean bos"