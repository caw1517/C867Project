#include "roster.h"

//Constructor
Roster::Roster() 
{
	//Init classRoster to empty
	for (int x = 0; x < classRosterArray.size(); x++)
	{
		classRosterArray[x] = nullptr;
	}
}

//Destructor
Roster::~Roster()
{
	//Loop through all of the elements
	for (int x = 0; x < classRosterArray.size(); x++)
	{
		//Delete
		delete classRosterArray[x];
		classRosterArray[x] = nullptr;
	}
}

//Parse Student Info
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
	std::array<int, 3> days;
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

	//Add the student to the roster
	add(studentId, firstName, lastName, emailAddress, age, days[0], days[1], days[2], degree);
}

//Add to roster
void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	//Convert days to array
	std::array<int, 3> days = { daysInCourse1, daysInCourse2, daysInCourse3 };

	//Create the student object
	Student* newStudent = new Student(studentId, firstName, lastName, emailAddress, age, days, degreeProgram);

	//Find open space to add student to class array
	for (int x = 0; x < classRosterArray.size(); x++)
	{
		//Check if the spot is null
		if (!classRosterArray[x])
		{
			//Add the student and exit the function
			classRosterArray[x] = newStudent;
			return;
		}
	}

	//If this is ran there is no room in the array
	std::cout << "Roster full" << std::endl;

	//Delete the student to prevent excess memory usage
	delete newStudent;
}

//Remove Student
void Roster::remove(std::string studentId)
{
	//Holder for student found
	bool studentFound = false;

	//Find the student
	for (int x = 0; x < classRosterArray.size(); x++)
	{
		if (classRosterArray[x] && classRosterArray[x]->GetStudentId() == studentId)
		{
			//Once found, delete from classRoster
			delete classRosterArray[x];
			
			//Remove pointer
			classRosterArray[x] = nullptr;

			//Break out of loop
			studentFound = true;
			break;

		}
	}

	//If student was not found throw error
	if (!studentFound)
	{
		std::cout << "Student was not found. Please enter another ID" << std::endl;
	}
}

//Print all
void Roster::PrintAll()
{
	//Loop through all students
	for (Student* student : classRosterArray)
	{
		//Make sure the student exists
		if (student)
		{
			student->print();
		}
	}
}

//Print average days in course
void Roster::printAverageDaysInCourse(std::string studentId)
{
	//Holder for student found
	bool studentFound = false;

	//Find the student
	for (int x = 0; x < classRosterArray.size(); x++)
	{
		if (classRosterArray[x]->GetStudentId() == studentId)
		{
			//Put the days into a local array
			std::array<int, 3> days = classRosterArray[x]->GetDaysToComplete();

			//Get the average of all 3
			double averageDays = (days[0] + days[1] + days[2]) / 3;

			//Print out and exit loop
			std::cout << "Average number of days in 3 classes: " << averageDays << std::endl;

			studentFound = true;
			break;

		}
	}

	//If student was not found throw error
	if (!studentFound)
	{
		std::cout << "Student was not found. Please enter another ID" << std::endl;
	}
}

//Print invalid emails
void Roster::printInvalidEmails()
{
	//Placeholder for error
	bool allValid = true;

	//Loop through each student
	for (Student* student : classRosterArray)
	{
		//Make sure student is valid
		if (student == nullptr)
		{
			continue;
		}

		//Get the email of that student
		std::string studentEmail = student->GetEmailAddress();

		//Check if email is valid
		if (studentEmail.find(' ') != std::string::npos || studentEmail.find('@') == std::string::npos || studentEmail.find('.') == std::string::npos)
		{
			//Invalid
			std::cout << studentEmail << std::endl;
			allValid = false;
		}
	}

	if (allValid)
	{
		std::cout << "All emails are valid." << std::endl;
	}
}

//Print by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	std::cout << "Students in Degree program of " << degreeProgram << ": " << std::endl;
	//Find All students by degree
	for (Student* student : classRosterArray)
	{
		if (student->GetDegreeProgram() == degreeProgram)
		{
			std::cout << student->GetStudentId() << "\t"
				<< "First Name: " << student->GetFirstName() << "\t"
				<< "Last Name: " << student->GetLastName() << "\t"
				<< "Age: " << student->GetAge() << "\t"
				<< "daysInCourse: {" << student->GetDaysToComplete()[0] << ", " << student->GetDaysToComplete()[1] << ", " << student->GetDaysToComplete()[2] << "} "
				<< "Degree Program: " << student->GetDegreeProgram() <<  std::endl;
		}
	}
}

std::array<Student*, 5> Roster::GetClassRosterArray()
{
	return classRosterArray;
}
