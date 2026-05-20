#include <iostream>
using namespace std;

// Function to find largest element in array recursively
int findLargest(int arr[], int size, int index, int largest)
{
    // Base case: if index reaches size, return largest found
    if (index == size)
    {
        return largest;
    }

    // Update largest if current element is bigger
    if (arr[index] > largest)
    {
        largest = arr[index];
    }

    // Recursive call for next index
    return findLargest(arr, size, index + 1, largest);
}

// Recursive function to check subset sum
bool subsetSum(int arr[], int size, int target, int index)
{
    // If target becomes 0, subset found
    if (target == 0)
    {
        return true;
    }

    // If array ends or target becomes negative
    if (index == size || target < 0)
    {
        return false;
    }

    // Include current element in sum
    bool include = subsetSum(arr, size, target - arr[index], index + 1);

    // Exclude current element
    bool exclude = subsetSum(arr, size, target, index + 1);

    // Return true if any possibility works
    return include || exclude;
}

// Function to find magic number
int magicNumber(int arr[], int size)
{
    // Base case: if array is empty
    if (size == 0)
    {
        return -1;
    }

    // Step 1: find largest number
    int largest = findLargest(arr, size, 0, arr[0]);

    // Step 2: create new array without largest element
    int newArr[100];
    int j = 0;
    bool removed = false;

    for (int i = 0; i < size; i++)
    {
        // Remove only first occurrence of largest
        if (arr[i] == largest && removed == false)
        {
            removed = true;
        }
        else
        {
            newArr[j] = arr[i];
            j++;
        }
    }

    // Step 3: check if largest can be formed by subset sum
    if (subsetSum(newArr, size - 1, largest, 0))
    {
        return largest; // magic number found
    }

    // Step 4: repeat process with remaining array
    return magicNumber(newArr, size - 1);
}

int main()
{
    // Input array
    int arr[] = { 2, 3, 5, 8, 13 };
    int size = 5;

    // Find magic number
    int result = magicNumber(arr, size);

    // Output result
    if (result != -1)
    {
        cout << "Magic Number is: " << result;
    }
    else
    {
        cout << "No Magic Number Found.";
    }

    return 0;
}