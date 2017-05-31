
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "phonebook.h"

using namespace std;

Person::Person()
{
    name = "";
    phone = 0;
}

//assign the given parameters to name and phone
Person::Person(string new_name, int new_phone)
{
    name = new_name;
    phone = new_phone;
}

// get name
string Person::get_name() const
{
    return name;
}

// get number
int Person::get_phone() const
{
    return phone;
}

//compare current name with Person p's name
bool Person::operator<(Person p) const
{
    return name < p.get_name();
}

//print out name and phone
void Person::print() const
{
    cout << "Name: " << name << " Phone: " << phone;
}

// adds person to phone book
void add_people(vector<Person> &phone_book)
{
    bool continue_add = true;
    while (continue_add == true)
    {
        string response;
        cout << "Enter name or Q to quit: ";
        getline(cin, response);
        if (response == "Q" || response == "q")
        {
            continue_add = false;
        }
        
        int number;
        cout << "Enter a phone number: ";
        cin >> number;
        string clear;
        getline(cin, clear);
        
        Person P1(response, number);
        phone_book.push_back(P1);
        
        string answer;
        cout << "Add another name? (y/n) ";
        cin >> answer;
        string clear2;
        getline(cin, clear2);
        if (answer == "Y" || answer == "y")
        {
            continue_add = true;
        }
        else
        {
            continue_add = false;
        }
    }
}


//takes a name, return the index of the first Person with that name

int find (const vector<Person> &phone_book, string name)
{
    for(int i = 0; i < phone_book.size(); ++i)
        if (phone_book[i].get_name() == name)
            return i;
    
    return -1; 
}

//delete entry at index from phone_book
void erase(vector<Person> &phone_book, string name)
{
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (name == phone_book[i].get_name())
        {
            int position = i;
            for (int j = position; j < phone_book.size()-1; j++)
            {
                phone_book[j] = phone_book[j + 1];
            }
            phone_book.pop_back();
        }
    }
}

// sorts vector into alphabetical order
void sort(vector<Person> &phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    
}

//shuffles order of person objects in vector
void shuffle(vector<Person> &phone_book)
{
    for (int i = 0; i < phone_book.size(); i++)
    {
        int slot = rand() % (phone_book.size() - i) + i;
        swap(phone_book[i], phone_book[slot]);
    }
}

// reverses order of person objects in vector
void reverse(vector<Person> &phone_book)
{
    reverse(phone_book.begin(), phone_book.end());
    
}

//return phone number for the person at certain index
int lookup(const vector<Person> &phone_book, string name)
{
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (name == phone_book[i].get_name())
        {
            return phone_book[i].get_phone();
        }
    }
    
    return -1;
}

//print each person
void print(vector<Person> &phone_book)
{
    for (int i = 0; i < phone_book.size(); i++)
    {
        cout << "Name: " << phone_book[i].get_name();
        cout << " Phone: " << phone_book[i].get_phone() << "\n";
    }
}
