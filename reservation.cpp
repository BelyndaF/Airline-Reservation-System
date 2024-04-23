/********************************************************************************
  Name :       Gracelyn Wilcox & Belinda Foley
  Class :      Data Structures
  Assignment : Project 3 - Airline Reservation
  Synopsis :   This program will allow the user to make reservations for a flight.
********************************************************************************/ 
#include "reservation.h"
#include "linked_list.h"
#include <iostream>
#include <string>

using namespace std;

Reservation::Reservation() : passenger_list() //constructor for passenger list
{
    nextPassengerId = 0;  //initializes passenger ID to 0 and prepares for incrementation 
}

char Reservation::menu()
{
/*  This is the menu for the user. The menu displays the choices the user has. The user will enter a character, and that character will be returned to be used in the start function of the reservation class.*/

  string choice;
  cout << "\n ---------------Airline Reservation Menu---------------\n";
  cout << "\t 1.\tEnter a reservation\n";
  cout << "\t 2.\tCancel a reservation\n";
  cout << "\t 3.\tPrint a passenger list\n";
  cout << "\t 4.\tSearch for a passenger\n";
  cout << "\t 5.\tChange Reservation Seat\n";
  cout << "\t 6.\tChange Reservation Food\n";
  cout << "\t 7.\tPrint Food Menu\n";
  cout << "\t 8.\tPrint Checkin Menu\n";
  cout << "\t 0.\tEXIT\n";

  cout << "\nPlease enter the number of your choice: ";
  cin  >> choice;	// user input

  return choice[0];	// returns user input
}

void Reservation::start()
{
/* once this function is called, a loop will be created that allows the user to input how they want the list to be manipulated. Functions include insert, remove, print,search, changeSeat, and changeFood. If user enters '0', then the loop will terminate.*/

  bool done = false;	// done boolean

  do{

    char choice = menu(); //get the choice from the user
    switch(choice)
    /*this switch compares the choice entered
      by the user to determine which function
      to call.*/
    {
      case '1': insert(); break;
      case '2': remove(); break;
      case '3': print(); break;
      case '4': search(); break;
      case '5': change_seat(); break;
      case '6': change_food(); break;
      case '7': print_meal_report(); break;
      case '8': print_checkin_report(); break;
      case '0': done = true; break;
    default: cout << "ERROR: INVALID INPUT, Please select a correct number: " << endl;
    }
  } while(!done); // if done, then quit, else continue

cout << "\nThank you for using my simulation." << endl;

}

void Reservation::search()
{
    int input;
    cout << "\nEnter the ID number you would like to search: " << endl;
    cin >> input;
    passenger_list.search_Node(input); // search for passenger node
}

void Reservation::insert()
{
  
  Passenger* newPassenger = new Passenger(); // make new passenger node
  
  newPassenger->passengerId = nextPassengerId++; // increment the passengerID
  
    cin.ignore(); // Ignore leftover newline
    cout << "\nPassenger's first name: ";
    getline(cin, newPassenger->firstName);  // set first name 
    
    cout << "\nPassenger's last name: ";
    getline(cin, newPassenger->lastName);   // set last name
    
    cout << "\nPassenger's address: ";
    getline(cin, newPassenger->address);  // set address
    
    cout << "\nPassenger's phone number: ";
    getline(cin, newPassenger->phoneNumber);  // set phone number
    
    cout << "\nPassenger's seat number (1-50): ";
    cin >> newPassenger->seatNumber;  // set seat number
    while (newPassenger->seatNumber > 51 || newPassenger->seatNumber <= 0 ||           passenger_list.taken_seat(newPassenger->seatNumber)){
      // while the seat number is greater than 50, less than 1, or taken, ask for a new seat number
        cout << "ERROR: Seat is not available" << endl;
        cout << "Please enter a new seat number (1-50): ";
        cin >> newPassenger->seatNumber;
    }
    
    cin.ignore(); // Ignore leftover newlin
    cout << "\nPassenger's menu item: ";
    newPassenger->menuItem = select_Menu_Item();  // set menu item

    cin.ignore();
    cout << "Do you want to check in now? (Y/N): " << endl;
    cin >> newPassenger->checkInResponse;  // set response
  
    newPassenger->next = NULL;

    if (!passenger_list.insert_Node(newPassenger)) 
    {
        cout << "An error occurred. The passenger could not be added." << endl;
    } else {
        cout << "Passenger added successfully!" << endl;
    }

  
}

void Reservation::remove()
{
    int input;
  cout << "\nEnter a passenger id to remove reservation: " <<endl;
  cin >> input;
  passenger_list.delete_Node(passenger_list.search_Node(input));  // delete node after searching for node

}

void Reservation::print()
{
    cout << "Passenger List:" << endl;
    passenger_list.print_list();  // print the list
}

string Reservation::select_Menu_Item()
{
  string mealChoice;
  int mealOption;
  
  cout << "\n -------------- Meal Menu -----------\n";
  cout << "\t 1.\tPizza\n";
  cout << "\t 2.\tPasta\n";
  cout << "\t 3.\tSalad\n";
  cout << "\t 4.\tSandwhich\n";
  cout << "\t 5.\tVeggie Meal\n";

  cout << "\nPlease enter the number of your choice: ";
  //cin.ignore();
  cin >> mealOption;  // set meal option
  while (mealOption != 1 && mealOption != 2 && mealOption != 3 &&  mealOption != 4 && mealOption != 5) {
    // while the meal option is not 1, 2, 3, 4, or 5, ask for a new meal option
    cout << "ERROR: INVALID INPUT, Please select a correct number: " << endl;
    cin >> mealOption;
  }

  switch (mealOption)
  {
    case 1: mealChoice = "Pizza"; break;
    case 2: mealChoice = "Pasta"; break;
    case 3: mealChoice = "Salad"; break;
    case 4: mealChoice = "Sandwhich"; break;
    case 5: mealChoice = "Veggie Meal"; break;
    default:  cout << "ERROR: Food didn't register." << endl;
  }

  return mealChoice;       // set meal choice         
}




void Reservation::change_food()
{
  int passengerID;
  string newMenuItem;
  Passenger* currentPassenger;
  
  cout << "Please enter the passenger ID you would like to change the menu item for: " << endl;
  cin >> passengerID;
  currentPassenger = passenger_list.search_Node(passengerID); // find the passenger node
  
  if (currentPassenger != nullptr) {
    cout << "Please select the new menu item you would like to change to: " << endl;
    //cin << newMenuItem;
    
    currentPassenger->menuItem = select_Menu_Item(); // go through other functions to change the menu item

    cout << "Menu item changed successfully!" << endl;
  }
}



void Reservation::change_seat()
{
  int passengerID;
  int newSeatNumber;
  Passenger* currentPassenger;
  
  cout << "Please enter the passenger ID you would like to change the seat for: " << endl;
  cin >> passengerID;
  currentPassenger = passenger_list.search_Node(passengerID);   // find the passenger node

  if (currentPassenger != nullptr) {
    cout << "Please select the new seat you would like to change to (1-50): " << endl;
    cin >> newSeatNumber;  // set new seat number

    while (newSeatNumber > 51 || newSeatNumber <= 0 || passenger_list.taken_seat(newSeatNumber)){
      // while the seat number is greater than 50, less than 1, or taken, ask for a new seat number
        cout << "ERROR: Seat is not available" << endl;
        cout << "Please enter a new seat number (1-50): ";
        cin >> newSeatNumber;
    }
      currentPassenger->seatNumber = newSeatNumber; // reset the seat number

      cout << "Seat changed successfully!" << endl;
  }
  else {
    cout << "Passenger not found." << endl;
  }

}

void Reservation::print_meal_report()
{
  cout << "\n\n-----------PASSENGER MEAL REPORT -----------" << endl;
  passenger_list.meal_counter();  // print the meal report with meal counter

  cout << "----------END PASSENGER MEAL REPORT -----------" << endl;
}

void Reservation::print_checkin_report()
{
  cout << "\n\n-------------PASSENGER CHECKIN REPORT --------------" << endl;
  passenger_list.checkin_counter();  // print the checkin report with checkin counter
  cout << "------------- END PASSENGER CHECKIN REPORT --------------" << endl;
}