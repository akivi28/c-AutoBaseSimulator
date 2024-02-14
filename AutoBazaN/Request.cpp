#include "Request.h"

Request::Request() : carForRequest{new Car}, driverForRequest{new Driver},
goodsForRequest{}, time {0},place{0}
{
}

void Request::Generate()
{
	goodsForRequest.Init();
	int random = 1 + rand() % 8;
	switch (random)
	{
	case 1:
		place = "Lviv";
		time = Lviv;
		break;
	case 2:
		place = "Ternopil";
		time = Ternopil;
		break;
	case 3:
		place = "Vinnica";
		time = Vinnica;
		break;
	case 4:
		place = "Kyiv";
		time = Kyiv;
		break;
	case 5:
		place = "Kherson";
		time = Kherson;
		break;
	case 6:
		place = "Kharkiv";
		time = Kharkiv;
		break;
	case 7:
		place = "Melitopol";
		time = Melitopol;
		break;
	case 8:
		place = "Mariupol";
		time = Mariupol;
		break;
	default:
		break;
	}
}

void Request::InitDriver(Driver& sourceDriver)
{
	//sourceDriver.SetState("on the way");
	driverForRequest = &sourceDriver;

}

void Request::InitCar(Car& sourceCar)
{
	carForRequest = &sourceCar;
}

void Request::ClearDriver()
{
	Driver cleardriver;
	driverForRequest = new Driver;
}

void Request::ClearCar()
{
	Car clearcar;
	carForRequest = new Car;
}

void Request::Print()
{
	
	cout << "# # # # # # # # # # # # # # # #" << endl;
 	if (carForRequest->GetCarruing() == 0)//carForRequest->GetCarruing() == 0
	{
		cout << "null" << endl;
	}
	else
	{
		carForRequest->Print();
	}

	if (driverForRequest->GetExp() == 0)//driverForRequest->GetExp() == 0
	{
		cout << "null" << endl;
	}
	else
	{
		driverForRequest->Print();
	}

	if (goodsForRequest.GetWeight() == 0)
	{
		cout << "null" << endl;
	}
	else
	{
		goodsForRequest.Print();
	}
	cout << "Direction : " << place << " : " << time << " h " << endl;
	cout << "# # # # # # # # # # # # # # # #" << endl;
}

void Request::SetArrivalTime(int globalTime)
{
	arrivalTime = globalTime + time;
}

int Request::GetArrivalTime()
{
	return arrivalTime;
}

void Request::RequestArrive()
{
	carForRequest->SetState("free");
	driverForRequest->SetState("free");
	goodsForRequest.SetState("arrived");
}

