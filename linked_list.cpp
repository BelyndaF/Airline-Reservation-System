/********************************************************************************
  Name :       Gracelyn Wilcox & Belinda Foley
  Class :      Data Structures
  Assignment : Project 3 - Airline Reservation
  Synopsis :   This program will allow the user to make reservations for a flight.
********************************************************************************/ 
#include "linked_list.h"
#include <iostream>
using namespace std;

Linked_list::Linked_list()  //constructor
{
  head = NULL;
}

bool Linked_list::insert_Node(Passenger* newNode)
{
  // inserting into an empty list or before the first node
    if (head == NULL || head->lastName.compare(newNode->lastName) > 0) {
        newNode->next = head; // The next node after newNode is the current head
        head = newNode; // Make newNode the new head
        return true;
    }

    // Find the first node that comes alphabetically before newNode (based on last_name)
    Passenger* current = head;
    while (current->next != NULL && current->next->lastName.compare(newNode->lastName) < 0) {
        current = current->next; // Increment to the next node
    }

    // Insert newNode after the current node
    newNode->next = current->next;
    current->next = newNode;

    return true;
}

void Linked_list::print_list()
{
    Passenger* current = head; // Start from the head of the list
    while (current != NULL) {
        cout << "\nID: " << current->passengerId
             << "\nName: " << current->firstName << " " << current->lastName
             << "\nAddress: " << current->address
             << "\nPhone: " << current->phoneNumber
             << "\nSeat Number: " << current->seatNumber
             << "\nMenu Item: " << current->menuItem
             << "\nChecked in (Y/N)?: " << current->checkInResponse;
        cout <<"\n_________________________"<< endl;
        current = current->next; // Increment to the next node
    }
}

/*Linked_list::~Linked_list()
{
  if (head == NULL)
    return;
  else{
    Passenger* del;
    while(head != NULL)
    {
      del = head;
      head = head ->next;
      delete del;
    }
  }
} 
*/

/*
int Linked_list::list_Size()
{
  Node * temp = head;
  int cnt=0;
  while(temp != NULL)
  {
    cnt++;
    temp = temp -> next;
  }
  return cnt;
}
*/

Passenger* Linked_list::search_Node(int id)
{
 
  //int position = 1;
  if(head == NULL)
  {
    cout << "ERROR: The passenger was not found." << endl;
    return NULL;
  }
  else if ( head->passengerId == id)
  {
    //  print passenger's business to show we found them
    cout << "-----------PASSENGER INFORMATION-----------" << endl;
    cout << "Passenger Name: " << head->firstName << " " << head->lastName << endl;
    cout << "Passenger Address: " << head->address << endl;
    cout << "Passenger Phone: " << head->phoneNumber << endl;
    return head;
  }
  else
  {
    Passenger* temp = head->next;
    while( temp != NULL && temp->passengerId != id)
    {
      temp = temp->next;
    }
    if (temp != NULL)
    {
      //cout << "The following passenger has been found: " << endl;
      cout << "Passenger Name: " << temp->firstName << " " << temp->lastName << endl;
      cout << "Passenger Address: " << temp->address << endl;
      cout << "Passenger Phone: " << temp->phoneNumber << endl;
      return temp;
    }
    else // didn't find anything
    {
      cout << "ERROR: The passenger was not found." << endl;
      return NULL;
    }
  }
}

bool Linked_list::delete_Node(Passenger* n)
{
  if (head == NULL) // if nothing is in the list
  {
    cout << "\nERROR: The list is empty. Please enter passenger information." << endl;
    return false;
  }
  else if (n == NULL) // if the node is not in the list
  {
    cout << "\nERROR: Information incomplete. Please enter passenger information." << endl;
    return false;
  }
  else if (head == n) // if the node is on the list
  {
    Passenger* del;
    del = head;
    head = head->next;
    cout << "The passenger has been successfully deleted from the passenger list." << endl;
    delete del;
    return true;
  }	
  Passenger* previous, *current;
  previous = head;
  current = head->next;
  while ( current != NULL && current != n) 
  {
    previous = current;
    current = current->next;
  }
  if (current != NULL) //found what we are looking for
  {
    Passenger* del;
    del = current;
    previous->next = current->next;
    delete del;
    cout << "The passenger has been successfully deleted from the passenger list." << endl;
    return true;
  }
    else
    {
      return false;
    }
}

  bool Linked_list:: taken_seat( int seatNumber) {
    Passenger *temp = head;

    while ( temp != NULL) { // while the list is not empty - check to see if the seat number is taken
      if (temp->seatNumber == seatNumber) {
        return true; // true doesn't always mean good
      }

      temp = temp->next; // and go to the next
    }
    return false;
  }

void Linked_list::meal_counter() // set the meal counts to zero
{
  int pizzaCounter = 0;
  int pastaCounter = 0;
  int saladCounter = 0;
  int sandwhichCounter = 0;
  int veggieMealCounter = 0;

  Passenger* current = head;

  while(current != NULL) // while the current node is not null - count the number of each meal
  {
    if (current->menuItem == "Pizza"){ pizzaCounter++; }
    else if (current->menuItem == "Pasta") { pastaCounter++; }
    else if (current->menuItem == "Salad") { saladCounter++; }
    else if (current->menuItem == "Sandwhich") { sandwhichCounter++; }
    else if (current->menuItem == "Veggie Meal") { veggieMealCounter++; }
    else { cout << "No meals are currently registered." << endl; }

    current = current->next;
  }
// print out each meal counter
  cout << "Pizza: " << pizzaCounter << endl;
  cout << "Pasta: " << pastaCounter << endl;
  cout << "Salad: " << saladCounter << endl;
  cout << "Sandwhich: " << sandwhichCounter << endl;
  cout << "Veggie Meal: " << veggieMealCounter << endl;
}

void Linked_list::checkin_counter()
{
  Passenger* current = head;
  int checkInCounter = 0;
  int notCheckedInCounter = 0;

  cout << "The following passengers have checked in: " << endl;
  while(current != NULL) // while the current node is not null - count the number of each person who has checked in
  {
    if (current->checkInResponse == 'Y' || current->checkInResponse == 'y')
    {
      checkInCounter++;  // add to the counter
      cout << "Passenger ID: " << current->passengerId << endl;
      cout << "Passenger Name: " << current->firstName << " " << current->lastName << endl;
    }
    else {
      notCheckedInCounter++; // or add to the other counter
    }
    current = current->next;
    
  }
// print all that you have counted
  cout << checkInCounter << " passengers have checked in." << endl;
  cout << notCheckedInCounter << " passengers have not checked in." << endl;

}