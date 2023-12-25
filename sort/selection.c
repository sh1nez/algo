#include <stdio.h>

#define SWAP(type, a, b) {type tmp; tmp = a; a = b; b = tmp;}

void sort(int *arr, register const size_t len)
{
	size_t min;
	size_t j;
	for (size_t i = 0; i<len-1; ++i){

		min = i;
		for (j = i; j<len; ++j){
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
			SWAP(int, arr[i], arr[min]);
	}

}

int main() 
{
	int arr[] =  {1, 4, 5, 2, 4, 1, 5, 9, 123, 23};

	register size_t len = sizeof(arr)/sizeof(arr[0]);
	sort(arr, len);
	for (size_t i = 0; i < len; ++i){
		printf("%d%c", arr[i], (i == len-1 ? '\n' : ' '));
	}
	
    return 0;
}

