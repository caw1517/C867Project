#include "Roster.h"

Roster::Roster() {}

void Roster::ParseStudentInformation(const std::string& studentInfo)
{
	//Create the tokens vector
	std::vector<std::string> tokens;

	//Init SStream
	std::stringstream ss(studentInfo);
	std::string token;

	//Add each individual token into the vector
	while (std::getline(ss, token, ','))
	{
		tokens.push_back(token);
	}

	//Extract the data for everything but days to complete
	std::string studentId = tokens[0];
	std::string firstName = tokens[1];
	std::string lastName = tokens[2];
	std::string emailAddress = tokens[3];

	//Convert age from string to int
	int age = std::stoi(tokens[4]);

	//Pull out Days to complete courses
	int days[3];
	for (int x = 0; x < 3; x++)
	{
		days[x] = std::stoi(tokens[5 + x]);
	}

	//Init degree program enum
	DegreeProgram degree;

	//Set degree program according to ENUM
	if (tokens[8] == "SECURITY")
	{
		degree = DegreeProgram::SECURITY;
	}
	else if (tokens[8] == "NETWORK")
	{
		degree = DegreeProgram::NETWORK;
	}
	else if (tokens[8] == "SOFTWARE")
	{
		degree = DegreeProgram::SOFTWARE;
	}
	else
	{
		//Error
		std::cout << "Invalid degree program" << std::endl;
		return;
	}
	
	//Create the student object
	Student newStudent(studentId, firstName, lastName, emailAddress, age, days, degree);

	//Add the student to the roster
}

//Add to roster
void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{

}
