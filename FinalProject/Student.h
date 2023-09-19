#pragma once

//Includes
#include <string>
#include "degree.h"
#include <array>

//Student Class
class Student
{
public:
	//Constructor
	Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, const std::array<int, 3>& daysToComplete, DegreeProgram studentDegreeProgram);

	//Getters
	std::string GetStudentId();

	std::string GetFirstName();

	std::string GetLastName();

	std::string GetEmailAddress();

	int GetAge();

	std::array<int, 3> GetDaysToComplete();

	DegreeProgram GetDegreeProgram();

	//Setters
	void SetStudentId(std::string studentId);

	void SetFirstName(std::string firstName);

	void SetLastName(std::string lastName);

	void SetEmailAddress(std::string emailAddress);

	void SetAge(int age);

	void SetDaysToComplete(const std::array<int, 3>& daysToComplete);

	void SetDegreeProgram(DegreeProgram studentDegreeProgram);

	//Print Method
	void print();

private:
	//Private Variables
	
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	//int daysToComplete[3];
	std::array<int, 3> daysToComplete;

protected:
	DegreeProgram studentDegreeProgram;

};

