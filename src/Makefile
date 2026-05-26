CC = gcc

CFLAGS = -Wall


SRCS = main.c utils.c basic/bubble_sort.c basic/insertion_sort.c basic/selection_sort.c advanced/merge_sort.c advanced/quick_sort.c advanced/shell_sort.c

TARGET = SortingC

all: $(TARGET)

# Proses kompilasi
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	del $(TARGET).exe