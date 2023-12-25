#include <stdio.h>

#define SWAP(type, a, b) {type tmp = (a); (a) = (b); (b) = tmp;}


void sort(int *arr, register size_t len){
	for (size_t k = 0; k<len; ++k){
	   for (size_t i = 0; i < len - k; i++)
            if (arr[i] > arr[i + 1])
                SWAP(int, arr[i], arr[i + 1]);
	}
}

int main() {
	int arr[] =  {1, 4, 5, 2, 4, 1, 5, 9, 123, 23};

	register size_t len = sizeof(arr)/sizeof(arr[0]);
	sort(arr, len);
	for (size_t i = 0; i < len; ++i){
		printf("%d%c", arr[i], (i == len-1 ? '\n' : ' '));
	}
	
    return 0;
}

