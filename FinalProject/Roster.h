#pragma once

//Includes
#include "Student.h"
#include "degree.h"

#include <iostream>
#include<sstream>
#include <vector>

class Roster
{
public:
	Roster();

	~Roster();

	void ParseStudentInformation(const std::string& studentInfo);

	void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void remove(std::string studentId);

	void PrintAll();

	void printAverageDaysInCourse(std::string studentId);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);
	
	std::array<Student*, 5> GetClassRosterArray();

private:
	std::array<Student*, 5> classRosterArray;
	//Student* classRosterArray[5];
};

