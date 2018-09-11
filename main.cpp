#include <iostream>
#include <vector>
#include <string.h>

struct Student
{
  char fName[20];
  char lName[20];
  int id;
  double gpa;
};

void createStudent(std::vector<Student>* students)
{
  (*students).
}

int main()
{

  bool running = true;

  char command[5];
  
  std::vector<Student>* students;
  
  while(running)
  {
    std::cout << "Enter a command(ADD, PRINT, DELETE, QUIT): ";
    std::cin.get(command, 5);
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
      std::cout << "Exiting";
      break;
    }
    else if(strncmp(command, "ADD", 5) == 0)
    {
      createStudent();
    }
  }
    
  return 0;
}
