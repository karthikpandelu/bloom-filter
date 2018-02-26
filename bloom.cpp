#include <iostream>
#include <cstring>

using namespace std;

class BloomFilter{
private:
  int bloom[100];
  int a, b, c;    //variables to store function values
  //first hash function
  int fun1_bloom(char str[]){
    int n = strlen(str);
    int sum = 0;
    for(int i=0; i<n; i++){
      sum = sum + int(str[i]);
    }
    sum = sum % 100;
    return sum;
  }
  //second hash function
  int fun2_bloom(char str[]){
    int n = strlen(str);
    int sum = 0;
    sum = int(str[0]) + int(str[n-1]);

    sum = sum % 100;

    return sum;
  }
  //third hash function
  int fun3_bloom(char str[]){
    int n = strlen(str);
    n = n/2;
    int sum = 0;
    sum = int(str[n-1]) + int(str[n]) + int(str[n+1]);

    sum = sum %100;

    return sum;
  }

public:
  //constructor to initialise hash table and set all the indixes to 0
  BloomFilter(){
    cout << "Initialising hash table for bloom filter" << endl;
    for (int i=0; i<100; i++) {
      bloom[i] = 0;
    }
  }
//fubnction to add elements into the bloom filter
  void insertElement(char str[]){
    a = fun1_bloom(str);
    b = fun2_bloom(str);
    c = fun3_bloom(str);

    bloom[a] = 1;
    bloom[b] = 1;
    bloom[c] = 1;

    cout << "Element added to the list" << endl;
  }

//function to search for an element
  void searchElement(char str[]){
    a = fun1_bloom(str);
    b = fun2_bloom(str);
    c = fun3_bloom(str);

    if(bloom[a]==1&&bloom[b]==1&&bloom[c]==1){
      cout << "\"" << str << "\" may be present" << endl;
    }
    else{
      cout << "\"" << str << "\" definitely not present" << endl;
    }
  }
};

int main() {
  BloomFilter blm; //object declaration
  char ch;
  char str[50];

  while(1){
    cout << "-------------------------------------------------" << endl;
    cout << "Enter your choice:\n1.Enter element into the filter\n2.Search element in the filter\n3.Exit" << endl;
    cin >> ch;
    switch (ch) {
      case '1':cout << "Enter a word to be added" << endl;
            cin >> str;
            blm.insertElement(str);
            break;
      case '2':cout << "Enter the word to be searched" << endl;
            cin >> str;
            blm.searchElement(str);
            break;
      case '3':cout << "Exiting..!" << endl;
            exit(0);
      default: cout << "Enter correct option" << endl;
    }

  }
  return 0;
}
