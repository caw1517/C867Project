#include "Student.h"
#include <iostream>

//Constructor
Student::Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age,const std::array<int, 3>& daysToComplete, DegreeProgram studentDegreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToComplete = daysToComplete;
	this->studentDegreeProgram = studentDegreeProgram;
}

//Getters
std::string Student::GetStudentId()
{
	return studentId;
}

std::string Student::GetFirstName()
{
	return firstName;
}

std::string Student::GetLastName()
{
	return lastName;
}

std::string Student::GetEmailAddress()
{
	return emailAddress;
}

int Student::GetAge()
{
	return age;
}

std::array<int, 3> Student::GetDaysToComplete()
{
	return daysToComplete;
}

DegreeProgram Student::GetDegreeProgram()
{
	return studentDegreeProgram;
}

//Setters
void Student::SetStudentId(std::string studentId)
{
	this->studentId = studentId;
}

void Student::SetFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Student::SetLastName(std::string lastName)
{
	this->firstName = lastName;
}

void Student::SetEmailAddress(std::string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::SetAge(int age)
{
	this->age = age;
}

void Student::SetDaysToComplete(const std::array<int, 3>& daysToComplete)
{
	this->daysToComplete = daysToComplete;
}

void Student::SetDegreeProgram(DegreeProgram studentDegreeProgram)
{
	this->studentDegreeProgram = studentDegreeProgram;
}

//Print Method
void Student::print()
{
	std::cout << "Student Id: " << studentId << std::endl;
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Email Address: " << emailAddress << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Days To Complete: " << std::endl;
	for (size_t x = 0; x < daysToComplete.size(); x++)
	{
		std::cout << "Course " << x+1 << ": " << daysToComplete[x] << std::endl;
	}
	std::cout << "Degree Program: " << studentDegreeProgram<< std::endl;

}