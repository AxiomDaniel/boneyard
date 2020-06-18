#include <iostream>
using namespace std;

int case_one(int alist[], int size, int ptr)
{
  while (ptr >= 0)
  {
    if (alist[ptr] > 0)
    {
      return ptr + 1;
    }
    ptr--;
  }
  return 0;
}

int case_two(int alist[], int size, int ptr)
{
  int k_val{alist[ptr]};
  while (ptr < size)
  {
    if (alist[ptr] != k_val)
    {
      return ptr;
    }
    ptr++;
  }
  return size;
}

int main()
{
  int n{}, k{}, a{};
  cin >> n;
  cin >> k;

  int alist[n];
  for (int i = 0; i < n; i++)
  {
    cin >> alist[i];
  }

  int ptr{k - 1}; // because k is 1-indexed.
  int result{};
  // Case 1: k is negative or zero.
  // Traverse leftward till you meet a non-negative number, then return the index + 1 to indicate number that passed. If reached the end, then return 0.
  if (alist[ptr] <= 0)
  {
    result = case_one(alist, n, ptr);
  }
  // case 2: k is positive.
  // Capture value at k, then traverse rightward until the number is dissimilar. Then return that index + 1
  else
  {
    result = case_two(alist, n, ptr);
  }
  cout << to_string(result) << "\n";
}