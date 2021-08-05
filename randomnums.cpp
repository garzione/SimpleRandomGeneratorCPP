/*
Justin Garzione

Random Numbers Exercise

This exercise is intended to prompt the
user to enter the size of a list, which
will dynamically add elements, generating
random numbers each time between 1-150.
Stastical numbers will be generated on 
this list including total, mean, median,
and range.
*/

#include<iostream>
#include<iterator>
#include<algorithm>
#include<list>
#include <ctime>
using namespace std;

int main()
{
    //Declare int variables
    int num, i,ran,total = 0;

    //List and iterators
    list<int>rndm;
    list<int>::iterator rit;
    ostream_iterator<int> osit(cout, "\n");

    //Prompt
    cout << "Please enter the number of elements in your list: " ;
    cin >> num;
    cout << endl;

    //Seed it 
    srand(time(0));
    //Loop until size and add to list, new rand each iteration
    for(i = 0; i < num; i++)
    {
        ran = rand() % 150 + 1;
        rndm.push_back(ran);		

    }
    //Sort the list
    rndm.sort();

    //Effectively print the numbers by copying to output stream
    copy(rndm.begin(), rndm.end(), osit);

    //Take the deference value of the iterator and sum it up each iteration
    for(rit = rndm.begin();rit != rndm.end(); rit++)
    {
        total+=*rit;


    }
    //Total
    cout << "The total is: " << total << endl;

    //Mean is total over list size - 3 decimals...have to cast it
    printf("The mean is: %.3f\n",(double)total/rndm.size());

    //Bring iterator to list beginning
    rit = rndm.begin();

    //Move iterator up halfway
    for(i = 0; i < rndm.size()/2 ; i ++)
    {
        rit++;
    }

    //Iterator stays at the point above from loop, just dereference
    cout << "The median is: " << *rit << endl;

    //Range is back minus front with sorted list
    cout << "The range is: " << rndm.back() - rndm.front() << endl;

return 0;
}