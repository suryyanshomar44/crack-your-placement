int findMinDiff(int arr[], int n, int m)
{
    
  // m is number of students
  //n is size of array
    if (m == 0 || n == 0)
        return 0;
  
    sort(arr, arr + n);
  
    if (n < m)
        return -1;
  
    int mini = INT_MAX;
  
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < mini)
            mini = diff;
    }
    return mini;
}
