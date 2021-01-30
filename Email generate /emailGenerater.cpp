#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
using namespace std;

const int MAX = 62;


// Returns a string of random alphabets of
// length n.
string printRandomString(int n)
{
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z', '0', '1',
        '2', '3', '4', '5', '6', '7', '8', '9' };

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];

    return res;
}

string printRandomStringA_Z(int n)
{
    char alphabet[52] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z' };

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % 52];

    return res;
}


int main()
{
    string email;
    string domain[] = { ".com", ".net", ".org" };
    auto start = chrono::system_clock::now();
    ofstream file("emailList.txt");
    for (int i = 0; i < 500000; ++i) {
        // srand(time(NULL));
        email = (printRandomString(5) + "." + printRandomString(4) + "@" + printRandomStringA_Z(5) + domain[rand() % 3]);
        file << email << " ";
    }
    file.close();
    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Duration: " << duration.count() << "s\n";
}
