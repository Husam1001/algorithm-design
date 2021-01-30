#include <iostream>

#include <vector>

#include <fstream>

#include <chrono>

#include "priority_queue.cpp"

int main()
{
    PriorityQueue<string> pq;

    ifstream file("emailList.txt");

    string email;
    int i=0;
    int numbrt_Of_email = 0;
    cout<<"How many email to be enqueue: ";
    cin>>numbrt_Of_email;

   cout << "\nEnqueue\t: PriorityQueue\n";
    auto start = chrono::system_clock::now();

    while (file >> email && i<numbrt_Of_email) {

        pq.enqueue(email);

        i++;
    }

    file.close();

    auto end = chrono::system_clock::now();

    cout << endl;

    chrono::duration<double> duration = end - start;

    cout << "Duration: " << duration.count() << "s\n";

    auto start_dequeue = chrono::system_clock::now();

    cout << "\nDequeue\t: PriorityQueue\n";

    for (int i = 0; i < (numbrt_Of_email * 0.1); i++) {

        pq.dequeue();
    }

    // pq.print();   //use to print the queue

    auto end_dequeue = chrono::system_clock::now();

    cout << endl;

    chrono::duration<double> dequeue_duration = end_dequeue - start_dequeue;

    cout << "Dequeue Duration: " << dequeue_duration.count() << "s\n";
}
