/*
* Andrew Chester - StudentList
* A program for managing a list of students
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

//Student structure, holds their first name, last name, id, and gpa
struct Student
{
  char fName[20];
  char lName[20];
  int id;
  float gpa;
};

//A function for printing out the students array
void printStudents(std::vector<Student*>* students)
{
  std::vector<Student*>::iterator it; //Iterator object, it's basically a pointer
  std::cout << std::fixed; //Fix the amount of decimal places
  std::cout << std::setprecision(2); //Set the amount of decimal places to 2
  for(it = (*students).begin(); it != (*students).end(); ++it) //Looping over the students vector
    std::cout << "Name: " << (**it).fName << " " << (**it).lName << ", ID: " << (**it).id  << ", GPA: " << (**it).gpa << std::endl; //Print out all the values by double dereferencing it because students is a pointer to a vector of pointers
}

//A function that creates a student
void createStudent(std::vector<Student*>* students)
{
  Student* pointer = new Student(); //Create a new pointer to a student, allocates the student to the heap

  //Gets the student's name
  std::cout << "Enter the student's first name: ";
  std::cin >> (*pointer).fName;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  //Gets the student's last name
  std::cout << "Enter the student's last name: ";
  std::cin >> (*pointer).lName;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  //Gets the student's id
  std::cout << "Enter the student's ID: ";
  std::cin >> (*pointer).id;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  //Gets the student's gpa
  std::cout << "Enter the student's GPA: ";
  std::cin >> (*pointer).gpa;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  students->push_back(pointer); //Adding the student pointer to the vector
}
//A function for deleting a student
void deleteStudent(std::vector<Student*>* students)
{
  //First gets an id from the user
  int id;
  GET_INPUT:
  std::cout << "Enter the id of the student you want to remove: ";
  std::cin >> id;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  //searches the student vector for the id
  std::vector<Student*>::iterator it;
  for(it = (*students).begin(); it != (*students).end(); ++it)
    if((**it).id == id) //If the id exists
    {
      (*students).erase(it); //Remove the student from the vector
      delete *it; //Delete the pointer, the pointer needs to be deleted because memory was allocated to heap in createStudent()
      return; //Exit the function
    }
  std::cout << "Couldn't find the student." << std::endl; //If the code reaches this point, that means it couldn't find any student with the entered id
}

int main()
{
  bool running = true; //Variable for the loop
  char command[7]; //Character array for storing the user's commands
  std::vector<Student*>* students = new std::vector<Student*>(0); //A pointer to a vector of pointers to structs(why not just have a pointer to a vector?)

  while(running)
  {
    //Get the command from the user
    std::cout << "Enter a command(ADD, PRINT, DELETE, QUIT): ";
    std::cin.get(command, 7);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    //Make the command upppercase
    for(int i = 0; i < sizeof(command); i++)
    {
      int asciiValue = (int)command[i];
      if(asciiValue >= 97 && asciiValue <= 122)
	     command[i] = (char)(asciiValue - 32);
    }

    if(strncmp(command, "QUIT", 7) == 0) //If the command is quit, then exit
    {
      std::cout << "Exiting" << std::endl;
      break;
    }
    else if(strncmp(command, "ADD", 7) == 0) //If the command is add, then run createStudent()
    {
      createStudent(students);
    }
    else if(strncmp(command, "PRINT", 7) == 0) //If the command print, then run printStudents()
    {
      printStudents(students);
    }
    else if(strncmp(command, "DELETE", 7) == 0)//IF the command is delete, then run deleteStudent()
    {
      deleteStudent(students);
    }
    else
    {
      std::cout << "Unable to recognize that command. " << std::endl; //If they enter something unrecognizable
    }
  }

  delete students;
  return 0;
}
