#include<iostream>
#include <vector>

// Swap helper method.
bool swap(int& a, int& b);

// Merge sort helper method.
void Merge(std::vector<int>& items, int start, int end, int mid);

/*
[Bubble Sort]

Time Complexity:
Worst: O(n^2)
Average: O(n^2)
Best: O(n^2)

Space Complexity: O(1)
*/
void BubbleSort(std::vector<int>& items, int start, int end)
{
  for(int i = start; i < end; i++)
  {
    for(int j = start; j < end - i; j++)
    {
      if(items[j] > items[j + 1])
      {
        swap(items[j], items[j + 1]);
      }
    }
  }
}

/*
[Insertion Sort]

Time Complexity:
Worst: O(n^2)
Average: O(n^2)
Best: O(n)

Space Complexity: O(1)
*/
void InsertionSort(std::vector<int>& items, int start, int end)
{
  for(int i = start + 1; i < end + 1; i++)
  {
    int temp = items[i];
    int j = i - 1;
    while(j >= start && items[j] > temp)
    {
      items[j + 1] = items[j];
      j--;
    }
    items[j + 1] = temp;
  }
}

/*
[Merge Sort]

Time Complexity:
Worst: O(n long n)
Average: O(n long n)
Best: O(n long n)

Space Complexity: O(n)
*/
void MergeSort(std::vector<int>& items, int start, int end)
{
  if(start < end)
  {
    int mid = (start + end) / 2;
    MergeSort(items, start, mid);
    MergeSort(items, mid + 1, end);
    Merge(items, start, end, mid);
  }
}
// Merges items into one list in sorted order
void Merge(std::vector<int>& items, int start, int end, int mid)
{
  int size = end - start + 1;

  std::vector<int> temp(size);

  int first1 = start;
  int last1 = mid;

  int first2 = mid + 1;
  int last2 = end;

  int index = 0;
  while(first1 <= mid && first2 <= end)
  {
    if(items[first1] < items[first2])
    {
      temp[index] = items[first1];
      first1++;
    }
    else
    {
      temp[index] = items[first2];
      first2++;
    }
    index++;
  }

  while(first1 <= mid)
  {
    temp[index] = items[first1];
    first1++;
    index++;
  }
  while(first2 <= end)
  {
    temp[index] = items[first2];
    first2++;
    index++;
  }

  for(int i = 0; i < size; i++)
  {
    items[start] = temp[i];
    start++;
  }
}


/*
[Iterative Merge Sort]

Time Complexity:
Worst: O(n long n)
Average: O(n long n)
Best: O(n long n)

Space Complexity: O(n)
*/
void IterativeMergeSort(std::vector<int>& items, int start, int end)
{
  int size = (end - start) + 1;
  std::vector<int> temp(size);

  // Iterate over the array splits into separate lists
  for(int inputs = 1; inputs < size; inputs *= 2)
  {
    // Merge separate lists
    for(int left = start, new_index = left - start; left < size + start; left += 2 * inputs, new_index += 2 * inputs)
    {
      // Find the mid and end of the separate lists
      int right = ((left + 2 * inputs - 1) < (size + start - 1)) ? (left + 2 * inputs - 1) : (size + start - 1);
      int mid = ((left + inputs - 1) < (size+ start - 1)) ? (left + inputs - 1) : (size + start - 1);

      // Iterators
      int i = left;
      int j = mid + 1;
      int k = new_index;
      
      // Iterate over both lists sorting them into the temp
      while(i <= mid && j <= right)
      {
        if(items[i] <= items[j])
        {
          temp[k] = items[i];
          i++;
        }
        else
        {
          temp[k] = items[j];
          j++;
        }
        k++;
      }

      // Copy remaining
      while(i <= mid)
      {
        temp[k] = items[i];
        i++;
        k++;
      }
      while(j <= right)
      {
        temp[k] = items[j];
        k++;
        j++;
      }

      // Copy sorted temp array list back into the original array
      for(int x = left, y = new_index; x <= right; x++, y++)
      {
        items[x] = temp[y];
      }
    }
  }
}

/*
[Shell Sort]

Time Complexity:
Worst: O(n^2)
Average: O(n^(3/2))
Best: O(n log n)

Space Complexity: O(1)
*/
void ShellSort(std::vector<int>& items, int start, int end)
{
  int size = end - start + 1;

  // Create gap
  for(int gap = size / 2; gap > 0; gap /= 2)
  {
    // Iterate over items comparing from origin to gap
    for(int i = start + gap; i < end + 1; i++)
    {
      int temp = items[i];
      int j;
      for(j = i; j >= gap + start && items[j - gap] > temp; j -= gap)
      {
        items[j] = items[j - gap];
      }
      items[j] = temp;
    }
  }
}

/*
[Quick Sort]

Time Complexity:
Worst: O(n^2)
Average: O(n log n)
Best: O(n log n)

Space Complexity: O(log n)
*/
void QuickSort(std::vector<int>& items, int start, int end)
{
  if(start >= end)
  {
    return;
  }

  int mid = (start + end) / 2;

  // Creates a good pivot by sorting first, mid, and last.
  if(items[start] > items[end])
  {
    swap(items[start], items[end]);
  }
  if(items[start] > items[mid])
  {
    swap(items[start], items[mid]);
  }
  if(items[mid] > items[end])
  {
    swap(items[mid], items[end]);
  }

  // Set pivot
  int pivot = items[mid];
  swap(items[mid], items[end]);

  // Set left and right indexs
  int left_index = start;
  int right_index = end - 1;
  bool done = false;

  while(!done)
  {
    // Find element in the left index that is greater than pivot
    while(items[left_index] < pivot)
    {
      left_index++;
    }
    // Find element in the right index that is less than pivot
    while(items[right_index] > pivot)
    {
      right_index--;
    }

    // If elements found swap and iterate
    if(right_index > left_index)
    {
      swap(items[left_index], items[right_index]);
      left_index++;
      right_index--;
    }
    // If elements not found 
    else
    {
      swap(items[left_index], items[end]);
      QuickSort(items, start, left_index - 1);
      QuickSort(items, left_index + 1, end);
      done = true;
    }
  }
}

// Swaps two values integer values
bool swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
  return true;
}