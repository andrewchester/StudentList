#include <iostream>
#include <vector>
#include <string.h>

struct Student
{
  char fName[20];
  char lName[20];
  int id;
  float gpa;
};

void printStudents(std::vector<Student>* students)
{
  
  std::vector<Student>::iterator it;
  for(it = (*students).begin(); it != (*students).end(); ++it)
    std::cout << "Name: " << (*it).fName << " " << (*it).lName << ", ID: " << (*it).id << ", GPA: " << (*it).gpa << std::endl;
}

void createStudent(std::vector<Student>* students)
{
  Student testStudent;

  std::cout << "Enter the student's first name: ";
  std::cin.get(testStudent.fName, 20);

  std::cin.clear();
  std::cin.ignore(100, '\n');

  std::cout << "Enter the student's last name: ";
  std::cin.get(testStudent.lName, 20);

  std::cin.clear();
  std::cin.ignore(100, '\n');

  std::cout << "Enter the student's ID: ";
  std::cin >> testStudent.id;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  std::cout << "Enter the student's GPA: ";
  std::cin >> testStudent.gpa;
  
  std::cin.clear();
  std::cin.ignore(100, '\n');

  (*students).push_back(testStudent);
}

int main()
{

  bool running = true;

  char command[6];

  std::vector<Student>* students = new std::vector<Student>(0);
  
  while(running)
  {
    std::cout << "Enter a command(ADD, PRINT, DELETE, QUIT): ";
    std::cin.get(command, 6);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    for(int i = 0; i < sizeof(command); i++)
    {
      int asciiValue = (int)command[i];
      if(asciiValue >= 97 && asciiValue <= 122)
	     command[i] = (char)(asciiValue - 32);
    }

    if(strncmp(command, "QUIT", 5) == 0)
    {
      std::cout << "Exiting" << std::endl;
      break;
    }
    else if(strncmp(command, "ADD", 5) == 0)
    {
      createStudent(students);
    }
    else if(strncmp(command, "PRINT", 5) == 0)
    {
      printStudents(students);
    }
  }

  delete students;
  return 0;
}
