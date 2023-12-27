#include <stdio.h>

#define swap(type, a, b) { type tmp = a; a = b; b = tmp;}

#define HEAPSIZE 100

struct MaxHeap{
	int* arr;
	int current;
	int MAX;
};

int insert(struct MaxHeap *heap, int num)
{
	if (heap -> current == heap -> MAX)
		return 1;
	heap->arr[heap->current] = num;
	int pos = heap->current++;
	while (heap->arr[pos] > heap->arr[pos/2]){
		swap(int, heap->arr[pos], heap->arr[pos/2])
		pos /= 2;
	}
	return 0;
}
void heapifyDown(struct MaxHeap* heap, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;

    if (left < heap->current && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    } else if (right < heap->current && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    if (largest != idx) {
        swap(int, heap->arr[idx], heap->arr[largest])
        heapifyDown(heap, largest);
    }
}

int main()
{
	int arr[HEAPSIZE] = {0};
	struct MaxHeap heap = {arr, 0, HEAPSIZE};
	insert(&heap, 1);
	insert(&heap, 7);
	insert(&heap, 2);
	insert(&heap, 12);
	insert(&heap, 3);
	insert(&heap, 22);
	insert(&heap, 21);
	arr[0] = 2;
	heapifyDown(&heap, 0);
	printf("%d", arr[0]);
}
