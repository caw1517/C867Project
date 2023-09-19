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

	void ParseStudentInformation(const std::string& studentInfo);

	void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

private:
	Student* classRosterArray[5];
};

