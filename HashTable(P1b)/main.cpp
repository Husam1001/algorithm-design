#include<bits/stdc++.h>
#include "HashTable.cpp"
using namespace std;

//Driver method to test map class
int main()
{
	HashMap<int, string> *h = new HashMap<int, string>;
	ifstream file("emailList.txt");
	string email;

	 auto start_insertion = chrono::system_clock::now();

     //read from file and insert the data
	while (file >> email)
	  {
		  h->insertNode(h->hashfunction(email),email);
	  }
	  file.close();

	  auto end_insertion = chrono::system_clock::now();
	  chrono::duration<double> insertion_duration = end_insertion - start_insertion;
	  cout << "Insertion Duration: " << insertion_duration.count() << "s\n";

	//h->display();

	//cout << h->sizeofMap() <<endl;

    string search_email;
    while(true){
        cout<<"Enter email to search: ";
        cin>>search_email;
	auto start = chrono::system_clock::now();
	cout << h->get(h->hashfunction(search_email));
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Duration: " << duration.count() << "s\n";

    }
	return 0;
}
