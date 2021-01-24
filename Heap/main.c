#include <stdio.h>
#include <stdlib.h>

int heap[] = {1,3,6,5,9,8,12,5, 6,8,9,10,11,14,15,16,18,19,20, 21};

void print(int heap_size)
{
    for (int x=0 ; x< heap_size ; x++ )
    {
        printf("%d ",heap[x]);
    }
    printf("\n");
}

int leftChild(int i)
{
    return (2*i)+1;
}

int rightChild(int i)
{
    return (2*i) +2;
}

int parent(int i)
{
    return (i-1)/2;
}

/*Max Heap = {1, 2, 3}
      1           3
    /   \   =   /   \   = {3, 2, 1}
   2     3     2     1
*/
void max_heapify (int i, int heap_size)
{
    int left, right, largest, temp;
    left = leftChild(i);
    right = rightChild(i);

    if (left<=heap_size && heap[left] > heap[i])
    {
        largest = left;
    }
    else
    {
        largest =  i;
    }
    if(right <= heap_size && heap[right] > heap[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        max_heapify(largest, heap_size);
    }
}

/*Max Heap = {3, 1, 2}
      3           1
    /   \   =   /   \    = {1, 3, 2}
   1     2     3     2
*/
void min_heapify (int i, int heap_size)
{
    int left, right, lowest, temp;
    left = leftChild(i);
    right = rightChild(i);

    if (left<=heap_size && heap[left] < heap[i])
    {
        lowest = left;
    }
    else
    {
        lowest =  i;
    }
    if(right <= heap_size && heap[right] < heap[lowest])
    {
        lowest = right;
    }
    if(lowest != i)
    {
        temp = heap[i];
        heap[i] = heap[lowest];
        heap[lowest] = temp;
        max_heapify(lowest, heap_size);
    }
}

void build_max_heap(int heap_size)
{
    for(int i = heap_size/2-1; i>= 0; i--)
    {
        max_heapify(i, heap_size);
    }
}


int main()
{
    int heap_size = 20;

    printf("Initial Array \n");
    printf("--------------\n");
    print(heap_size);

    build_max_heap(heap_size);

    printf("\nAfter Heapify - Max-Heap \n");
    printf("---------------------------\n");
    print(heap_size);
    return 0;
}
