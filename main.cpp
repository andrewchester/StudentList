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

void createStudent()
{
  
}

int main()
{

  bool running = true;

  char command[5];
  
  std::vector<int>* students;
  
  while(running)
  {
    std::cout << "Enter a command(ADD, PRINT, DELETE, QUIT): ";
    std::cin.get(command, 5);
    std::cin.clear();
    std::cin.ignore(100, '/n');

    for(int i = 0; i < strlen(command); i++)
    {
      int asciiValue = (int)command[i];
      if(asciiValue >= 97 && asciiValue <= 122)
	command[i] = (char)(asciiValue - 32);
    }
  }
      
  
  return 0;
}
