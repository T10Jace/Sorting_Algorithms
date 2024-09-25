# Author: Jace Riley
# Date:   September 23, 2024


CC = g++

CFLAGS = -c -Wall -Wextra

TARGET = sort

all: $(TARGET)

$(TARGET): main.o selection_sort.o merge_sort.o quicksort.o	
	$(CC) main.o selection_sort.o merge_sort.o quicksort.o -o $(TARGET)

main.o: main.cpp selection_sort.h merge_sort.h quicksort.h
	$(CC) $(CFLAGS) main.cpp

selection_sort.o: selection_sort.cpp selection_sort.h
	$(CC) $(CFLAGS) selection_sort.cpp

merge_sort.o: merge_sort.cpp merge_sort.h
	$(CC) $(CFLAGS) merge_sort.cpp

quicksort.o: quicksort.cpp quicksort.h
	$(CC) $(CFLAGS) quicksort.cpp

clean:						 
	$(RM) $(TARGET) *.o *~