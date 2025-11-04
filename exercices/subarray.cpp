#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

void summ (int arr[],int i,int j,int *arr1){
  int s = 0;
  for (size_t k = i; k < j; k++)
  {
    s = s + arr[k];
  }
  arr1[i] = s;
  
}

int main() {
  int n;
  cout << "enter the size of the array" << endl;
  cin >> n;
  int *arr = new int [n];
  for (int i =0; i<n; i++ ){
    cout << "enter arr [" << i<< "]" << endl;
    cin >> arr[i];
  }
  cout << endl ;
  for (auto j = 0 ; j<n;j++)
  {
    cout << arr[j] << "," ;
  }
  cout << endl ;
  int arr1 [n] ;
  for (size_t i = 0; i < n; i++)
  {
    if (arr[i]==0)
    {
      arr[i]=-1;
    }
    arr1[i]=-1;
  }
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = n; j > 0; j--)
    {
      summ(arr,i,j,&arr1);
    }
  }
  
  cout << "the longest sequence is : "  << max(arr1) << endl;
  
  

  
  
  }
  




    






