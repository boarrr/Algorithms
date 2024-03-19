void insertionSort(int* arr)
{
  int i, j, current;

  for (i = 1; i < SIZE; i++)
  {
    current = arr[i];
    j = i;

    while (arr[j - 1] > current && j > 0)
    {
      arr[j] = arr[j - 1];
      j = j - 1;
    }

    arr[j] = current;
  }
}