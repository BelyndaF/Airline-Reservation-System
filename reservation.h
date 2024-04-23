/*********************************************************************************
  Name :       Gracelyn Wilcox & Belinda Foley
  Class :      Data Structures
  Assignment : Project 3 - Airline Reservation
  Synopsis :   This program will allow the user to make reservations for a flight.
********************************************************************************/ 
#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <iostream>
#include <fstream>	
#include <cstdlib>
using namespace std;
#include "linked_list.h"	

class Reservation
{
  public:
    Reservation();		// constructor initializes data to database
      char menu();		//reservation system menu  
      void start();		// starts user input
      void search();		// allows user to display specific passenger info
      void insert();		// allows user to make a new passenger reservation
      void remove();		// allows user to cancel a reservation
      void print();		// prints list of all passengers
      void change_food();	// user can change food preference of passenger
      void change_seat(); // user can change seat of passenger if available
    //void copyDatabase();	// linked_list is initialized to database
      string select_Menu_Item(); //This function promts the user with a menu of options and returns the user's selection as a string
      void print_meal_report(); //This function prints the total number of each meal reserved by all passengers
      void print_checkin_report(); //This function returns the passenger ID, first name, and last name of all passengers who have checked in along with the total number of passengers who have checked in and total number of passengers who have not checked in

  private:
    Linked_list passenger_list;	// declare an object of the linked list class
    //int id;							// stores id for search functions
    int nextPassengerId;  //integer incrementing passenger id number from 0 for unique passenger numbers
};



#endif