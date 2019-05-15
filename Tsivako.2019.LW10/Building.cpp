#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Building.h"

using namespace std;

Building::Building(char* address, char* type, char* numberOfFloors, char* numberOfApartments, int lifetime)
{
	this->SetBuilding(address, type, numberOfFloors, numberOfApartments, lifetime);
}

void Building::SetBuilding(char* address, char* type, char* numberOfFloors, char* numberOfApartments, int lifetime)
{
	this->SetAddress(address);
	this->SetType(type);
	this->SetNumberOfFloors(numberOfFloors);
	this->SetNumberOfApartments(numberOfApartments);
	this->SetLifetime(lifetime);
}

void Building::SetAddress(char* address)
{
	strcpy(this->address, address);
}

void Building::SetType(char* type)
{
	strcpy(this->type, type);
}

void Building::SetNumberOfFloors(char* numberOfFloors)
{
	strcpy(this->numberOfFloors, numberOfFloors);
}

void Building::SetNumberOfApartments(char* numberOfApartments)
{
	strcpy(this->numberOfApartments, numberOfApartments);
}

void Building::SetLifetime(int year)
{
	if (year > 25 && year <= 0)
	{
		throw invalid_argument("Please enter valid year!");
	}

	this->lifetime = year;
}

char* Building::GetAddress()
{
	return this->address;
}

char* Building::GetType()
{
	return this->type;
}

char*  Building::GetNumberOfFloors()
{
	return this->numberOfFloors;
}

char*  Building::GetNumberOfApartments()
{
	return this->numberOfApartments;
}

int  Building::GetLifetime()
{
	return this->lifetime;
}

void Building::DisplayBuilding()
{
	cout << "Address: " << this->address << endl;
	cout << "Type: " << this->type << endl;
	cout << "Number of floors: " << this->numberOfFloors << endl;
	cout << "Number of apartments: " << this->numberOfApartments << endl;
	cout << "Lifetime: " << this->lifetime << endl;
}

void Building::EnterBuilding()
{
	const int N = 256;
	char address[N] = "", type[N] = "", numberOfFloors[N] = "", numberOfApartments[N] = "";
	cout << "Enter a address of the Building: ";
	cin.ignore();
	cin.getline(address, N, '\n');
	cout << "Enter a type of the Building: ";
	cin.getline(type, N, '\n');
	cout << "Enter the number of floors: ";
	cin.getline(numberOfFloors, N, '\n');
	cout << "Enter the number of apartments: ";
	cin.getline(numberOfApartments, N, '\n');

	int year;
	cout << "Enter the lifetime: ";
	cin >> year;
	cout << "\n";

	this->SetBuilding(address, type, numberOfFloors, numberOfApartments, year);
}