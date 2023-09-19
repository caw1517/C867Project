//Includes
#include <iostream>

#include "Student.h"
#include "degree.h"
#include "Roster.h"

//Main Function
int main()
{
	//Initialize Roster
	Roster newRoster;
	
	const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Canaan,White,w_canaan@yahoo.com,22,1,4,3,SOFTWARE" };

	for (std::string studentInfo : studentData)
	{
		newRoster.ParseStudentInformation(studentInfo);
	}

	return 0;
}