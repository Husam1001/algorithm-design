#include <iostream>
#include <fstream>
#include <chrono>
// 1. Include HashTable.cpp.
#include "HashTable.cpp"
#include <string>
using namespace std;
int main()
{
    int number_Of_Email;
    cout<<"Enter the number of email to be inserted: ";
    cin>>number_Of_Email;
    // 2. Declare a hashtable of int named "ht", size is 11.
    HashTable<string> ht(number_Of_Email - (number_Of_Email * 0.1));
    ifstream file("emailList.txt");
    string email;
    int counter=0;
    auto start = chrono::system_clock::now();
    while (file >> email&&counter<number_Of_Email) {
        ht.insert(email);
        counter++;
    }
    file.close();
    auto end = chrono::system_clock::now();
    cout << endl;
    chrono::duration<double> duration = end - start;
    // Display ht.
    cout << ht << endl;
    cout << "Insertion Duration: " << duration.count() << "s\n";
    while (true) {
        string target;
        cout << "Target to retrieve: ";
        cin >> target;
        // 4. Retrieve the target from ht.
        auto startS = chrono::system_clock::now();
        if (ht.retrieve(target))
            cout << "Target found\n";
        else
            cout << "Target not found\n";
        auto endS = chrono::system_clock::now();
        chrono::duration<double> durationS = endS - startS;
        cout << "Duration: " << durationS.count() << "s\n";
    }
}
