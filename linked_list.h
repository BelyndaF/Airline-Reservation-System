/*********************************************************************************
  Name :       Gracelyn Wilcox & Belinda Foley
  Class :      Data Structures
  Assignment : Project 3 - Airline Reservation
  Synopsis :   This program will allow the user to make reservations for a flight.
********************************************************************************/
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <string>

using namespace std;

struct Passenger      //structure to create a node full of passenger information and a pointer to the next node
{
  int passengerId;    //variable to store the unique passenger Id
  int seatNumber;     //variable to store a seat number between 1-50
  string firstName;   //string to store a passenger's first name
  string lastName;    //string to store a passenger's last name
  string address;     //string to store a passenger's address
  string phoneNumber; //string to store a passenger's phone number
  string menuItem;    //string to store a passenger's meal request
  char checkInResponse; //char to store a passenger's decision to check in or not

  Passenger* next;    //pointer to next node in the linked list
};

class Linked_list     //class to create a linked list of passengers
{
  public:
      Linked_list();  //constructor for linked list
      bool insert_Node(Passenger*);   //function to insert a new passenger into the linked list
      bool delete_Node(Passenger*);   //function to delete a passenger from the linked list
      bool taken_seat(int);           //function to determine if a seat has been taken
      Passenger* search_Node(int);    //function to search for a passenger in the linked list
      int list_Size();                //function to return the size of the linked list
      void print_list();              //function to print the linked list of passengers
      void meal_counter();            //function to count the number of each meal requested by all passengers
      void checkin_counter();         //function to count the number of passengers who have checked in and the number of passengers who have not checked in
      //~Linked_list();               //deconstructor of the linked list

    private:
      Passenger* head;                //head pointer of the linked list
};
//#include "linked_list.cpp"
#endif