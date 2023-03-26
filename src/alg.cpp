// Copyright 2021 NNTU-CS
int countPairs2(int *arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value)
        result++;
    }
  }
  if (result > 0)
    return result;
  else
    return 0;
}
int countPairs1(int *arr, int len, int value) {
  int quantity = 0;
  int end = len;
  while (arr[end] > value)
    end--;
  for (int i = 0; i < end-1; i++)
    for (int j = i+1; j < end; j++) {
    if (arr[i] + arr[j] == value)
      quantity++;
  }
  if (quantity > 0)
    return quantity;
  else
    return 0;
}

int help(int *arr, int start, int end, int difference, int quantity) {
  if (end >= start) {
    int midle = start+(end-start)/2;
    if (arr[midle] == difference) {
      quantity++;
      quantity = help(arr, start, midle-1, difference, quantity);
      quantity = help(arr, midle+1, end, difference, quantity);
    }
    if (arr[midle] < difference) {
      quantity = help(arr, midle+1, end, difference, quantity);
    }
    if (arr[midle] > difference) {
      quantity = help(arr, start, midle-1, difference, quantity);
    }
  }
  return quantity;
}
int countPairs3(int *arr, int len, int value) {
  int quantity = 0;
  for (int i = 0; i < len/2+1; i++) {
    if (value > arr[i]) {
        int difference = value-arr[i];
        quantity = help(arr, i+1, len, difference, quantity);
    }
    }
  if (quantity > 0)
    return quantity;
  else
    return 0;
}
