#include<stdio.h>
#include<stdlib.h>
int binary_non_recursive(int arr[], int size, int key)
{
    int low = 0, high = size - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int binary_recursive(int arr[], int low, int high, int key)
{
    int mid;

    if(low > high)
        return -1;

    mid = (low + high) / 2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binary_recursive(arr, mid + 1, high, key);
    else
        return binary_recursive(arr, low, mid - 1, key);
}

int interpolation_non_recursive(int arr[], int size, int key)
{
    int low = 0, high = size - 1, pos;

    while(low <= high && key >= arr[low] && key <= arr[high])
    {
        if(arr[low] == arr[high])
        {
            if(arr[low] == key)
                return low;
            return -1;
        }

        pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if(arr[pos] == key)
            return pos;
        else if(arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int interpolation_recursive(int arr[], int low, int high, int key)
{
    int pos;

    if(low > high || key < arr[low] || key > arr[high])
        return -1;

    if(arr[low] == arr[high])
    {
        if(arr[low] == key)
            return low;
        return -1;
    }

    pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    if(arr[pos] == key)
        return pos;
    else if(arr[pos] < key)
        return interpolation_recursive(arr, pos + 1, high, key);
    else
        return interpolation_recursive(arr, low, pos - 1, key);
}

int main()
{
    int size;
    int i;
    int choice;
    int key;
    int result;

    printf("\n enter size of array\n");
    scanf("%d", &size);

    int arr[size];

    printf("\n enter elements in sorted order\n");

    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n enter your choice of search!\n");
    printf("\n 1. binary search non recursive");
    printf("\n 2. binary search recursive");
    printf("\n 3. interpolation search recursive");
    printf("\n 4. interpolation search non recursive");
    printf("\n");

    scanf("%d", &choice);

    printf("\n enter element to search\n");
    scanf("%d", &key);

    switch(choice)
    {
        case 1:
            result = binary_non_recursive(arr, size, key);
            break;

        case 2:
            result = binary_recursive(arr, 0, size - 1, key);
            break;

        case 3:
            result = interpolation_recursive(arr, 0, size - 1, key);
            break;

        case 4:
            result = interpolation_non_recursive(arr, size, key);
            break;

        default:
            printf("\n invalid choice\n");
            return 0;
    }

    if(result == -1)
        printf("\n element not found\n");
    else
        printf("\n element found at position %d\n", result + 1);

    return 0;
}
