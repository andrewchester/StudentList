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

void printStudents(const std::vector<Student>* students)
{
  Student* arr[students.size()] = students;
  for(int i = 0; i < sizeof(arr); i++)
  {
    std::cout << arr[i].fName << std::endl;
  }
}

void createStudent(std::vector<Student>* students)
{
  (*students).push_back(Student());
  std::cout << "Enter the student's first name:";
  std::cin >>  (*students)[(*students).size()].fName;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  std::cout << "Enter the student's last name: ";
  std::cin >> (*students)[(*students).size()].lName;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  std::cout << "Enter the student's ID: ";
  std::cin >> (*students)[(*students).size()].id;

  std::cin.clear();
  std::cin.ignore(100, '\n');

  std::cout << "Enter the student's GPA: ";
  std::cin >> (*students)[(*students).size()].gpa;

  std::cin.clear();
  std::cin.ignore(100, '\n');
}

int main()
{

  bool running = true;

  char command[5];

  std::vector<Student>* students = new std::vector<Student>;

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
      std::cout << "Exiting" << std::endl;
      break;
    }
    else if(strncmp(command, "ADD", 5) == 0)
    {
      createStudent(students);
    }
    else if(strncmp(command, "PRINT", 5) == 0)
    {
      printStudents(*students);
    }
  }

  delete students;
  return 0;
}
