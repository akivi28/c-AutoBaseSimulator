#include "—ontrol—enter.h"

int —ontrol—enter::time;

—ontrol—enter::—ontrol—enter() : cars{0}, drivers{0},request{0}
{
}

void —ontrol—enter::Init()
{
	for (int i = 0; i < 5; i++)
	{
		Car tmp;
		Driver tmpd;
		Request tmpr;

		tmp.Init();
		tmpd.Init();
		tmpr.Generate();

		cars.push_back(tmp);
		drivers.push_back(tmpd);
		request.push_back(tmpr);
	}
}

void —ontrol—enter::AddDriver()
{
	Driver tmp;
	tmp.Init();
	drivers.push_back(tmp);
}

void —ontrol—enter::AddCar()
{
	Car tmp;
	tmp.Init();
	cars.push_back(tmp);
}

void —ontrol—enter::AddRequest()
{
	Request tmp;
	tmp.Generate();
	request.push_back(tmp);
}

bool —ontrol—enter::ComparisonByExperience(Goods& sourceGood, Driver& sourceDriver)
{
	if((sourceGood.GetType() == "clothes" || sourceGood.GetType() == "bed linen"|| sourceGood.GetType() ==  "toys"))
	{
		return true;
	}

	if(sourceGood.GetType() == "furniture" || sourceGood.GetType() == "food" || sourceGood.GetType() == "books")
	{
		if (sourceDriver.GetExp() < 5)
		{
			cout << "Driver experience must be more than 5 years" << endl;
			return false;
		}
		else
			return true;
	}

	if (sourceGood.GetType() == "medicines" || sourceGood.GetType() == "electronics" || sourceGood.GetType() == "glass")
	{
		if (sourceDriver.GetExp() < 10)
		{
			cout << "Driver experience must be more than 10 years" << endl;
			return false;
		}
		else
			return true;
	}
}

void —ontrol—enter::Menu(int numOfReq)
{
	//cout << endl << "1 - add driver\n2 - add car\n3 - add request\n4 - fill out a request\n5 - another request\n";
	vector<string>menu;
	int selectOpt = 0;
	char key;
	menu.push_back("add driver");
	menu.push_back("add car");
	menu.push_back("add request");
	menu.push_back("fill out a request");
	menu.push_back("another request");

	do
	{
		Show();
		for (int i = 0; i < menu.size(); i++)
		{
			if (i == selectOpt)
			{
				cout << menu[i] << " <-" << endl;
			}
			else
			{
				cout << menu[i] << endl;
			}
		}
		key = _getch();
		if (key == 80)
		{
			if (selectOpt < menu.size() - 1)
			{
				selectOpt++;
			}
			else
			{
				selectOpt = 0;
			}
		}
		if (key == 72) { // ÒÚÂÎÍ‡ ‚‚Âı
			if (selectOpt > 0)
			{
				selectOpt--;
			}
			else
			{
				selectOpt = menu.size() - 1;
			}
		}
		system("cls");
	} while (key!=13);
	
	/*int tr = 0;
	cin >> tr;*/

	switch (selectOpt+1)
	{
	case 1:
	{
		AddDriver();
		break;
	}
	case 2:
	{
		AddCar();
		break;
	}
	case 3:
	{
		AddRequest();
		break;
	}
	case 4:
	{
		FillingRequest(numOfReq);
		break;
	}
	case 5:
	{
		if (numOfReq >= request.size() - 1)
		{
			cout << "no requests other than the current one" << endl;
			system("pause");
		}
		else
		{
			swap(request[numOfReq], request[numOfReq + rand() % (request.size() - numOfReq)]);
		}
		break;
	}
	default:
		break;
	}
}

void —ontrol—enter::Start()
{
	Init();

	while (true)
	{
		Menu(Show());
	}
}

void —ontrol—enter::StartSimulation()
{
	Init();
	for (int i = 0; i < 5; i++)
	{
		AddDriver();
		AddCar();
		AddRequest();
	}
	for (int i = 0; i < drivers.size(); i++)
	{
		for (int i = 0; i < drivers.size()-1; i++)
		{
			if (drivers[i].GetExp() > drivers[i + 1].GetExp())
			{
				swap(drivers[i], drivers[i + 1]);
			}
		}
	}
	while (true)
	{
		Sleep(500);
		Show();
		AutoFillRequest(Show());
		if (Show() > request.size()-10)
		{
			int ran = 10 + rand() % 30;
			for (int i = 0; i < ran; i++)
			{
				AddRequest();
			}
		}
		
	}
	
}

void —ontrol—enter::FillingRequest(int numOfReq)
{
	Show();
	bool flag = false;
	int driv;
	while (flag != true)
	{
		cout << "input numb of driver ";
		cin >> driv;
		if (driv <= 0 || driv > drivers.size())
		{
			cout << "Invalid index" << endl;
			continue;
		}

		if (drivers[driv-1].GetState() == "on the way")
		{
			cout << "This driver is busy, choose another" << endl;
			continue;
		}

		flag = ComparisonByExperience(request[numOfReq].GetGood(), drivers[driv - 1]);
	}
	request[numOfReq].InitDriver(drivers[driv-1]);
	Show();
	flag = false;
	int carind;
	while (flag!=true)
	{
		cout << "input numb of car ";
		cin >> carind;
		if (carind <=0 || carind > cars.size())
		{
			cout << "Invalid index" << endl;
			continue;
		}
		if (cars[carind - 1].GetState() == "on the way")
		{
			cout << "This car on the way, choose another" << endl;
			continue;
		}
		if (cars[carind-1].GetCarruing() < request[numOfReq].GetGood().GetWeight())
		{
			cout << "Carruing must be more than " << request[numOfReq].GetGood().GetWeight() << " T" << endl;
		}
		else
		{
			flag = true;
		}
	}
	request[numOfReq].InitCar(cars[carind - 1]);
	Show();
	time += 5;
	while (flag)
	{
		int choise;
		cout << "send an request?\n1 - yes\n2 - clear and exit on menu\n";
		cin >> choise;
		if (choise ==1 || choise == 2)
		{
			if (choise == 1)
			{
				request[numOfReq].GetGood().SetState("on the way");
				request[numOfReq].SetArrivalTime(time);
			}
			if (choise == 2)
			{
				drivers[driv - 1].SetState("free");
				cars[carind - 1].SetState("free");
				request[numOfReq].ClearCar();
				request[numOfReq].ClearDriver();
			}
			flag = false;
		}
	}
	
}

int —ontrol—enter::Show()
{
	system("cls");
	cout << "time :" << time << endl;
	for (int i = 0; i < cars.size(); i++)
	{
		cout << i + 1 << ") ";
		cars[i].Print();
	}
	cout << endl;
	for (int i = 0; i < drivers.size(); i++)
	{
		cout << i + 1 << ") ";
		drivers[i].Print();
	}
	cout << endl;

	
	int it = 0;

	while (request[it].GetGood().GetState()== "on the way" || request[it].GetGood().GetState() == "arrived")
	{
		if (request[it].GetArrivalTime()==time)
		{
			request[it].RequestArrive();
		}
		it++;
		if (it == request.size()-1)
		{
			break;
		}
	}

	//ÔÓ·ÎÂÏ‡, ÍÓ„‰‡ Á‡ˇ‚ÍË ‚ÒÂ Á‡ÔÓÎÌÂÌ˚ ÓÌ Ì‡˜ËÌ‡ÂÚ Â‰‡ÍÚËÓ‚‡Ú¸ ÛÊÂ ‚˚ÔÓÎÌÂÌÛ˛ 
	//ÌÂ Á‡·˚Ú¸ ÔÓÏÂÌˇÚ¸ ‚ Generate ˜ÚÓ·˚ „ÂÌÂËÓ‚‡ÎËÒ¸ ‚ÒÂ „ÓÓ‰‡ 
	// 
	//ÏÂÌ˛ ‚ Á‡ÔÓÎÌÂÌËË Á‡ˇ‚ÍË 
	//ÒËÏÛÎˇˆËˇ 


	cout << "number of requests in the queue : " << request.size() - it << endl;
	cout << "number of completed requests : " << it << endl;
	cout << "current request :" << endl << endl;

	if (request[it].GetGood().GetState() == "awaiting")
	{
		request[it].Print();
	}

	/*cout << endl << endl;
	for (int i = 0; i < request.size(); i++)
	{
		request[i].Print();
	}*/

	return it;
}

bool —ontrol—enter::AutoCompareCar(Goods& sourceGood, Car& sourceCar)
{
	if (sourceCar.GetState()=="on the way")
	{
		return false;
	}
	if (sourceCar.GetCarruing() < sourceGood.GetWeight())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool —ontrol—enter::AutoCompareDriver(Goods& sourceGood, Driver& sourceDriver)
{
	if (sourceDriver.GetState() == "on the way")
	{
		return false;
	}
	if ((sourceGood.GetType() == "clothes" || sourceGood.GetType() == "bed linen" || sourceGood.GetType() == "toys"))
	{
		return true;
	}

	if (sourceGood.GetType() == "furniture" || sourceGood.GetType() == "food" || sourceGood.GetType() == "books")
	{
		if (sourceDriver.GetExp() < 5)
		{
			return false;
		}
		else
			return true;
	}

	if (sourceGood.GetType() == "medicines" || sourceGood.GetType() == "electronics" || sourceGood.GetType() == "glass")
	{
		if (sourceDriver.GetExp() < 10)
		{
			return false;
		}
		else
			return true;
	}
}

void —ontrol—enter::AutoFillRequest(int numOfReq) 
{
	bool flagDriver = false;
	bool flagCar = false;

	for (int i = 0; i < drivers.size(); i++)
	{
		if (flagCar && flagDriver)
		{
			request[numOfReq].SetArrivalTime(time);
			Show();
			cout << "arrival time : " << request[numOfReq].GetArrivalTime() << endl;
			Sleep(500);
			request[numOfReq].GetCar().SetState("on the way");
			request[numOfReq].GetDriver().SetState("on the way");
			request[numOfReq].GetGood().SetState("on the way");
			request[numOfReq].GetDriver().SetSalary(request[numOfReq].GetDriver().GetSalary() + time * 10);
			break;
		}
		if (!flagDriver)
		{
			if (AutoCompareDriver(request[numOfReq].GetGood(), drivers[i]))
			{
				request[numOfReq].InitDriver(drivers[i]);
				flagDriver = true;
				Show();
				Sleep(500);
			}
		}
		if (!flagCar)
		{
			if (AutoCompareCar(request[numOfReq].GetGood(),cars[i]))
			{
				request[numOfReq].InitCar(cars[i]);
				flagCar = true;
				Show();
				Sleep(500);
			}
		}
		if (i == drivers.size()-1 && (!flagCar || !flagDriver))
		{
			swap(request[numOfReq], request[numOfReq + rand() % (request.size()-1 - numOfReq+1)]);
			cout << "swap" << endl;
			if (request[numOfReq].GetDriver().GetExp() > 0)
			{
				request[numOfReq].ClearDriver();
			}
			if (request[numOfReq].GetCar().GetCarruing() > 0)
			{
				request[numOfReq].ClearCar();
			}
			Sleep(500);
			Show();
			
		}
	}
	
	time += 5;
}