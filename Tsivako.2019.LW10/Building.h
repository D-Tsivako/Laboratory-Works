#ifndef building_h
#define building_h

const int N = 25;

class Building
{
public:
	Building() {}
	Building(char*, char*, char*, char*, int);
	~Building() {}
	void SetAddress(char*);
	void SetType(char*);
	void SetNumberOfFloors(char*);
	void SetNumberOfApartments(char*);
	void SetLifetime(int);
	void SetBuilding(char*, char*, char*, char*, int);

	char* GetAddress();
	char* GetType();
	char* GetNumberOfFloors();
	char* GetNumberOfApartments();
	int GetLifetime();
	
	void EnterBuilding();
	void DisplayBuilding();
private:
	char address[N]{}, type[N]{}, numberOfFloors[N]{}, numberOfApartments[N]{};
	int lifetime;
};

#endif
