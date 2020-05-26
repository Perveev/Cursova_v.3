

#include <iostream>
#include <string>
#include <fstream>

std::string filename1 = "KIYKI-19-1.txt", filename2 = "KIYKI-19-2.txt", filename3 = "KIYKI-19-3.txt", filename4 = "KIYKI-19-4.txt", filename5 = "KIYKI-19-5.txt";



struct Group
{
	std::string FIO;
	int status;
	double mark;
	int srok;
	double dopball;
}arrGroup;
struct nure {
	std::string subject;
	double credits;
}SubArr;
struct sortlist {
	std::string filename;
	double bal;
}arrSort;

int size(std::string filename, int sizeGroup) {
	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line)) {
		sizeGroup++;
	}
	file.close();
	return sizeGroup;
}
void ListGroup(std::string filename) {

	int sizeGroup = 0;
	sizeGroup = size(filename, sizeGroup);
	if (sizeGroup == 0) {
		std::cout << "The group is empty, first add students\n";
		return;
	}


	std::ifstream fout;
	fout.open(filename, std::ios_base::in | std::ios_base::app | std::ios_base::out);
	Group* arrGroup = new Group[sizeGroup];
	for (int i = 0; i < sizeGroup; i++)
	{
		fout >> arrGroup[i].FIO;
		fout >> arrGroup[i].status;
		fout >> arrGroup[i].mark;
		fout >> arrGroup[i].srok;
		fout >> arrGroup[i].dopball;
	}
	for (int i = 0; i < sizeGroup; i++)
	{
		std::cout << i + 1 << ")" << arrGroup[i].FIO << "\n";


	}
}
void resetStudent(std::string filename) {
	
	int sizeGroup = 0;
	sizeGroup = size(filename, sizeGroup);
	if (sizeGroup == 0) {
		std::cout << "The group is empty, first add students\n";
		return;
	}


	std::ifstream fin; std::string tempFIO; int st;
	fin.open(filename, std::ios_base::in | std::ios_base::app | std::ios_base::out);
	Group* arrGroup = new Group[sizeGroup];
	for (int i = 0; i < sizeGroup; i++)
	{
		fin >> arrGroup[i].FIO;
		fin >> arrGroup[i].status;
		fin >> arrGroup[i].mark;
		fin >> arrGroup[i].srok;
		fin >> arrGroup[i].dopball;
	}
	fin.close();
	for (int i = 0; i < sizeGroup; i++)
	{

		std::cout << i + 1 << ")" << arrGroup[i].FIO << "\n";


	}
	int a, z, x;
	
	
	std::string b;
	int q, l;

	bool p = true;
	while (p) {
		std::cout << "Which number in the list to change\n";
		std::cin >> b;
		l = b.find_first_not_of("1234567890");


		if (l == -1)
		{
			a = std::stoi(b);
			if (a > 0 && a < sizeGroup+1 ) {

				p = false;

			}
			else {
				std::cout << "\nInput error, try again\n";
			}
		}
		else {
			std::cout << "\nInput error, try again\n";
		}

	}


	std::getline(std::cin, arrGroup[a - 1].FIO);
	std::cout << "Enter last name\n";
	std::getline(std::cin, arrGroup[a - 1].FIO);
	z = arrGroup[a - 1].FIO.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	arrGroup[a - 1].FIO.erase(arrGroup[a - 1].FIO.find_last_not_of(" \n\r\t") + 1);
	if (z == 0 || size(arrGroup[a - 1].FIO) == 0)
	{
		bool flag = false;
		for (int i = 0; flag == false; i++)
		{
			std::cout << "Input error, try again\n";
			std::cout << "Enter last name\n";
			std::getline(std::cin, arrGroup[a - 1].FIO);
			z = arrGroup[a - 1].FIO.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
			arrGroup[a - 1].FIO.erase(arrGroup[a - 1].FIO.find_last_not_of(" \n\r\t") + 1);

			if (z == -1 && size(arrGroup[a - 1].FIO) > 0)
			{
				flag = true;
			}

		}
	}


	
	

	bool o = true;
	while (o) {
		std::cout << "Student on a budget or contract 1(budget),0(contract)\n";
		std::cin >> b;
		l = b.find_first_not_of("1234567890");

		if (l == -1)
		{
			int t = std::stoi(b);
			if (t == 0 || t == 1) {
				arrGroup[a - 1].status = t;
				o = false;
			}
			else {
				std::cout << "\nInput error, try again\n";
			}
			
		}
		else {
			std::cout << "\nInput error, try again\n";
		}

	}

	std::fstream clear_file(filename, std::ios_base::out);
	clear_file.close();

	std::ofstream fout;
	fout.open(filename, std::ios_base::in | std::ios_base::out);
	for (int i = 0; i < sizeGroup; i++)
	{
		std::string temp; int t;
		fout << arrGroup[i].FIO << " " << arrGroup[i].status << " " << arrGroup[i].mark << " " << arrGroup[i].srok << " " << arrGroup[i].dopball << "\n";
	}
}
int AddStudent(std::string filename) {

	int sizeGroup = 0;
	sizeGroup = size(filename, sizeGroup);
	



	std::ofstream fin; std::string tempFIO; int st;


	fin.open(filename, std::ios_base::in | std::ios_base::app | std::ios_base::out);
	int z;

	std::getline(std::cin, tempFIO);
	std::cout << "Enter last name\n";
	std::getline(std::cin, tempFIO);
	z = tempFIO.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	tempFIO.erase(tempFIO.find_last_not_of(" \n\r\t") + 1);
	if (z == 0 || size(tempFIO) == 0)
	{
		bool flag = false;
		for (int i = 0; flag == false; i++)
		{
			std::cout << "Input error, try again\n";
			std::cout << "Enter last name\n";
			std::getline(std::cin, tempFIO);
			z = tempFIO.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
			tempFIO.erase(tempFIO.find_last_not_of(" \n\r\t") + 1);

			if (z == -1 && size(tempFIO) > 0)
			{
				flag = true;
			}

		}
	}
	std::string b;
	int q, l;


	bool o = true;
	while (o) {
		std::cout << "Student on a budget or contract 1(budget),0(contract)\n";
		std::cin >> b;
		l = b.find_first_not_of("1234567890");

		if (l == -1)
		{
			int t = std::stoi(b);
			if (t == 0 || t == 1) {
				st = t;
				o = false;
			}
			else {
				std::cout << "\nInput error, try again\n";
			}

		}
		else {
			std::cout << "\nInput error, try again\n";
		}

	}


	fin << tempFIO << " " << st << " " << 0 << " " << 0 << " " << 0 << "\n";
	sizeGroup++;
	return  sizeGroup;
}

int DeleteStudent(std::string filename) {

	int sizeGroup = 0;
	sizeGroup = size(filename, sizeGroup);
	if (sizeGroup == 0) {
		std::cout << "The group is empty, first add students\n";
		return 0;
	}


	Group* arrGroup = new Group[sizeGroup];

	std::ifstream fout;
	std::ofstream fin;

	fout.open(filename, std::ios_base::out | std::ios_base::in);
	for (int i = 0; i < sizeGroup; i++)
	{
		fout >> arrGroup[i].FIO;
		fout >> arrGroup[i].status;
		fout >> arrGroup[i].mark;
		fout >> arrGroup[i].srok;
		fout >> arrGroup[i].dopball;

	}
	fout.close();

	for (int i = 0; i < sizeGroup; i++)
	{

		std::cout << i + 1 << ")" << arrGroup[i].FIO << "\n";


	}

	std::fstream clear_file(filename, std::ios_base::out);
	clear_file.close();

	ListGroup(filename);
	int size;
	size = sizeGroup - 1;
	int k;
	
	

	std::string b;
	int q, l;

	bool p = true;
	while (p) {
		std::cout << "Enter the number in the list\n";
		std::cin >> b;
		l = b.find_first_not_of("1234567890");


		if (l == -1)
		{
			k = std::stoi(b);
			if (k > 0 && k < sizeGroup+1) {

				p = false;

			}
			else {
				std::cout << "\nInput error, try again\n";
			}
		}
		else {
			std::cout << "\nInput error, try again\n";
		}

	}

	
	for (int i = k - 1; i < size; i++)
	{


		arrGroup[i].FIO = arrGroup[i + 1].FIO;
		arrGroup[i].status = arrGroup[i + 1].status;
		arrGroup[i].mark = arrGroup[i + 1].mark;
		arrGroup[i].srok = arrGroup[i + 1].srok;
		arrGroup[i].dopball = arrGroup[i + 1].dopball;



	}
	sizeGroup--;

	fin.open(filename, std::ios_base::in | std::ios_base::out);
	for (int i = 0; i < sizeGroup; i++)
	{
		std::string temp; int t;
		fin << arrGroup[i].FIO << " " << arrGroup[i].status << " " << arrGroup[i].mark << " " << arrGroup[i].srok << " " << arrGroup[i].dopball << "\n";
	}
	return size;
}
void group() {
	int a, q;  bool w = true; bool r = true; bool e = true; bool t = true; bool y = true; bool u = true;


	while (w) {
		
		
		std::string b;
		int z;

		bool p = true;
		while (p) {
			std::cout << "\nChoose a group:\n 1:KIYKI-19-1\n 2:KIYKI-19-2\n 3:KIYKI-19-3\n 4:KIYKI-19-4\n 5:KIYKI-19-5\n 0:Back\t 9: Main Menu\n";
			std::cin >> b;
			z = b.find_first_not_of("1234567890");


			if (z == -1)
			{
				a = std::stoi(b);
				p = false;
			}
			else {
				std::cout << "There is no such option, try again\n\n";
			}

		}

		switch (a)
		{

		case 1:
			while (t) {
				
				
				p = true;
				while (p) {
					std::cout << "\n\nSelect:\n 1:Add Student\t 2:Remove student\t 3:Change student\t 4: View List\t 0:Back\t 9: Main Menu\n";
					std::cin >> b;
					z = b.find_first_not_of("1234567890");


					if (z == -1)
					{
						q = std::stoi(b);
						p = false;
					}
					else {
						std::cout << "There is no such option, try again\n\n";
					}

				}


				switch (q)
				{
				case 1:
					AddStudent(filename1);
					break;
				case 2:
					DeleteStudent(filename1);
					break;
				case 3:
					resetStudent(filename1);
					break;
				case 4:
					ListGroup(filename1);
					break;

				case 0:
					t = false;
					break;
				case 9:
					return;
				default:
					std::cout << "There is no such option, try again\n";
					break;
				}

			}
			t = true;
			break;

		case 2:
			while (e) {
				
				

				p = true;
				while (p) {
					std::cout << "\n\nSelect:\n 1:Add Student\t 2:Remove student\t 3:Change student\t 4: View List\t 0:Back\t 9: Main Menu\n";
					std::cin >> b;
					z = b.find_first_not_of("1234567890");


					if (z == -1)
					{
						q = std::stoi(b);
						p = false;
					}
					else {
						std::cout << "There is no such option, try again\n\n";
					}

				}

				switch (q)
				{
				case 1:
					AddStudent(filename2);
					break;
				case 2:
					DeleteStudent(filename2);
					break;
				case 3:
					resetStudent(filename2);
					break;
				case 4:
					ListGroup(filename2);
					break;
				case 0:
					e = false;
					break;
				case 9:
					return;
				default:
					std::cout << "There is no such option, try again\n";
					break;
				}

			}
			e = true;
			break;
		case 3:
			while (r) {
				p = true;
				while (p) {
					std::cout << "\n\nSelect:\n 1:Add Student\t 2:Remove student\t 3:Change student\t 4: View List\t 0:Back\t 9: Main Menu\n";
					std::cin >> b;
					z = b.find_first_not_of("1234567890");


					if (z == -1)
					{
						q = std::stoi(b);
						p = false;
					}
					else {
						std::cout << "There is no such option, try again\n\n";
					}

				}

				switch (q)
				{
				case 1:
					AddStudent(filename3);
					break;
				case 2:
					DeleteStudent(filename3);
					break;
				case 3:
					resetStudent(filename3);
					break;
				case 4:
					ListGroup(filename3);
					break;
				case 0:
					r = false;
					break;
				case 9:
					return;
				default:
					std::cout << "There is no such option, try again\n";
					break;
				}

			}
			r = true;
			break;
		case 4:
			while (y) {
				p = true;
				while (p) {
					std::cout << "\n\nSelect:\n 1:Add Student\t 2:Remove student\t 3:Change student\t 4: View List\t 0:Back\t 9: Main Menu\n";
					std::cin >> b;
					z = b.find_first_not_of("1234567890");


					if (z == -1)
					{
						q = std::stoi(b);
						p = false;
					}
					else {
						std::cout << "There is no such option, try again\n\n";
					}

				}

				switch (q)
				{
				case 1:
					AddStudent(filename4);
					break;
				case 2:
					DeleteStudent(filename4);
					break;
				case 3:
					resetStudent(filename4);
					break;
				case 4:
					ListGroup(filename4);
					break;
				case 0:
					y = false;
					break;
				case 9:
					return;
				default:
					std::cout << "There is no such option, try again\n";
					break;
				}

			}
			y = true;
			break;
		case 5:
			while (u) {
				p = true;
				while (p) {
					std::cout << "\n\nSelect:\n 1:Add Student\t 2:Remove student\t 3:Change student\t 4: View List\t 0:Back\t 9: Main Menu\n";
					std::cin >> b;
					z = b.find_first_not_of("1234567890");


					if (z == -1)
					{
						q = std::stoi(b);
						p = false;
					}
					else {
						std::cout << "There is no such option, try again\n\n";
					}

				}

				switch (q)
				{
				case 1:
					AddStudent(filename5);
					break;
				case 2:
					DeleteStudent(filename5);
					break;
				case 3:
					resetStudent(filename5);
					break;
				case 4:
					ListGroup(filename5);
					break;
				case 0:
					u = false;
					break;
				case 9:
					return;
				default:
					std::cout << "There is no such option, try again\n";
					break;
				}

			}
			u = true;
			break;
		case 0:
			w = false;
			break;
		case 9:
			return;
		default:
			std::cout << "There is no such option, try again\n";
			break;
		}


	}

}
double subjects(nure* SubArr, int n) {
	double crSum = 0;
	int z, x;
	for (int i = 0; i < n; i++)
	{
		std::getline(std::cin, SubArr[i].subject);

		std::cout << "Enter the subject name: ";
		std::getline(std::cin, SubArr[i].subject);
		z = SubArr[i].subject.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
		SubArr[i].subject.erase(SubArr[i].subject.find_last_not_of(" \n\r\t") + 1);

		if (z == 0 || size(SubArr[i].subject) == 0)
		{
			bool flag = false; bool t = true;
			for (int k = 0; flag == false; k++)
			{
				std::cout << "Input error, try again\n";
				std::cout << "Enter the subject name:";

				std::getline(std::cin, SubArr[i].subject);

				z = SubArr[i].subject.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
				SubArr[i].subject.erase(SubArr[i].subject.find_last_not_of(" \n\r\t") + 1);

				

				if (z == -1 && size(SubArr[i].subject) > 0 && t)
				{
					flag = true;
				}

			}
		}
		
		



		

		std::string b; int x, t;
		bool p = true;
		while (p) {
			std::cout << "Enter the number of credits of the subject: ";
			std::cin >> b;
			x = b.find_first_not_of("1234567890");


			if (x == -1)

			{
				t = std::stoi(b);
				if (t > 0)
				{
					SubArr[i].credits = t;
					p = false;

				}
				else {
					std::cout << "Input error, try again\n\n";
				}

			}
			else {
				std::cout << "Input error, try again\n\n";
			}

		}



		crSum += SubArr[i].credits;
	}
	return crSum;
}
void marksGruop(std::string filename, int n, nure* SubArr, double crSum) {
	int sizeGroup = 0;
	sizeGroup = size(filename, sizeGroup);
	if (sizeGroup == 0) {
		std::cout << "The group is empty, first add students\n";
		return;
	}


	std::ifstream fout;
	fout.open(filename, std::ios_base::in | std::ios_base::app | std::ios_base::out);
	Group* arrGroup = new Group[sizeGroup];
	for (int i = 0; i < sizeGroup; i++)
	{
		fout >> arrGroup[i].FIO;
		fout >> arrGroup[i].status;
		fout >> arrGroup[i].mark;
		fout >> arrGroup[i].srok;
		fout >> arrGroup[i].dopball;

	}
	fout.close();
	std::cout << "all subject delivered on time ? 1(on time),0(not on time)";
	for (int i = 0; i < sizeGroup; i++)
	{
		
		
		std::string b; int x,t;
		bool p = true;
		while (p) {
			std::cout << "\n" << i + 1 << ")" << arrGroup[i].FIO << "\t";
			std::cin >> b;
			x = b.find_first_not_of("1234567890");


			if (x == -1)

			{
				t = std::stoi(b);
				if (t==0||t==1)
				{
					arrGroup[i].srok = t;
					p = false;
					
				}
				else {
					std::cout<< "Input error, try again\n\n";
				}
				 
			}
			else {
				std::cout << "Input error, try again\n\n";
			}

		}


		


	}
	std::cout << "How much the student have extra points?(0-40)";
	for (int i = 0; i < sizeGroup; i++)
	{
		std::string b; int x, t;
		bool p = true;
		while (p) {
			std::cout << "\n" << i + 1 << ")" << arrGroup[i].FIO << "\t";
			std::cin >> b;
			x = b.find_first_not_of("1234567890");


			if (x == -1)

			{
				t = std::stoi(b);
				if (t >= 0 && t <= 40)
				{
					arrGroup[i].dopball = t;
					p = false;

				}
				else {
					std::cout << "Input error, try again\n\n";
				}

			}
			else {
				std::cout << "Input error, try again\n\n";
			}

		}
		
	}
	for (int i = 0; i < sizeGroup; i++)
	{
		arrGroup[i].mark = 0;
	}

	for (int i = 0; i < n; i++)
	{
		std::string b; int x, t;
		std::cout << "Enter grades for students" << " from discipline " << SubArr[i].subject << "\n";
		for (int j = 0; j < sizeGroup; j++)
		{
			

			bool p = true;
			while (p) {
				std::cout << "\n" << i + 1 << ")" << arrGroup[j].FIO << "\t";
				std::cin >> b;
				x = b.find_first_not_of("1234567890");


				if (x == -1)

				{
					t = std::stoi(b);
					if (t >= 0 && t <= 100)
					{
						arrGroup[j].mark += t*SubArr[i].credits;
						p = false;

					}
					else {
						std::cout << "\nInput error, try again\n";
					}

				}
				else {
					std::cout << "\nInput error, try again\n";
				}

			}



		}
	}
	for (int i = 0; i < sizeGroup; i++)
	{
		arrGroup[i].mark = (arrGroup[i].mark / crSum) * 0.9 + (arrGroup[i].dopball / 4);
	}
	std::ofstream fin;
	fin.open(filename, std::ios_base::in | std::ios_base::out);
	for (int i = 0; i < sizeGroup; i++)
	{
		fin << arrGroup[i].FIO << " " << arrGroup[i].status << " " << arrGroup[i].mark << " " << arrGroup[i].srok << " " << arrGroup[i].dopball << "\n";

	}
}
double mid(std::string filename) {
	int sizeGroup = 0;
	sizeGroup = size(filename, sizeGroup);
	if (sizeGroup == 0) {
		std::cout << "The group is empty, first add students\n";
		return 0;
	}

	double midbal = 0;
	std::ifstream fout;
	fout.open(filename, std::ios_base::in | std::ios_base::app | std::ios_base::out);
	Group* arrGroup = new Group[sizeGroup];
	for (int i = 0; i < sizeGroup; i++)
	{
		fout >> arrGroup[i].FIO;
		fout >> arrGroup[i].status;
		fout >> arrGroup[i].mark;
		fout >> arrGroup[i].srok;
		fout >> arrGroup[i].dopball;
	}
	fout.close();

	for (int i = 0; i < sizeGroup; i++)
	{

		midbal += arrGroup[i].mark;

	}
	midbal = midbal / sizeGroup;
	return midbal;
}
void midmarklist() {

	sortlist arrSort[5]{
		{"KIYKI-19-1",0},
		{"KIYKI-19-2",0},
		{"KIYKI-19-3",0},
		{"KIYKI-19-4",0},
		{"KIYKI-19-5",0}
	};


	arrSort[0].bal = mid(filename1);
	arrSort[1].bal = mid(filename2);
	arrSort[2].bal = mid(filename3);
	arrSort[3].bal = mid(filename4);
	arrSort[4].bal = mid(filename5);

	bool t = true;
	while (t) {
		t = false;
		for (int i = 0; i < 5; i++) {
			if (arrSort[i].bal < arrSort[i + 1].bal) {

				std::swap(arrSort[i].bal, arrSort[i + 1].bal);
				std::swap(arrSort[i].filename, arrSort[i + 1].filename);

				t = true;
			}
		}
	}

	std::cout << "Group average \n\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << arrSort[i].filename << '\t' << arrSort[i].bal << '\n';

	}
	std::cout << "\n\n";
}
void lastGroup() {
	sortlist arrSort[5]{
		{"KIYKI-19-1",0},
		{"KIYKI-19-2",0},
		{"KIYKI-19-3",0},
		{"KIYKI-19-4",0},
		{"KIYKI-19-5",0}
	};
	arrSort[0].bal = mid(filename1);
	arrSort[1].bal = mid(filename2);
	arrSort[2].bal = mid(filename3);
	arrSort[3].bal = mid(filename4);
	arrSort[4].bal = mid(filename5);
	bool n = true;
	std::cout << "List of lagging groups\n\n";

	for (int i = 0; i < 5; i++)
	{
		if (arrSort[i].bal < 60) {
			std::cout << arrSort[i].filename << '\n';
			n = false;
		}
	}
	if (n) {
		std::cout << "No list of lagging groups\n";
	}
	std::cout << "\n\n";
}
void otlichnikiGroup() {
	sortlist arrSort[5]{
		{"KIYKI-19-1",0},
		{"KIYKI-19-2",0},
		{"KIYKI-19-3",0},
		{"KIYKI-19-4",0},
		{"KIYKI-19-5",0}
	};
	arrSort[0].bal = mid(filename1);
	arrSort[1].bal = mid(filename2);
	arrSort[2].bal = mid(filename3);
	arrSort[3].bal = mid(filename4);
	arrSort[4].bal = mid(filename5);
	bool n = true;
	std::cout << "Leading Group List\n\n";

	for (int i = 0; i < 5; i++)
	{
		if (arrSort[i].bal >= 90) {
			std::cout << arrSort[i].filename << '\n';
			n = false;
		}
	}
	if (n) {
		std::cout << "No leading Group List\n";
	}
	std::cout << "\n\n";
}
void reitListGroup(std::string filename) {
	int sizeGroup = 0;
	sizeGroup = size(filename, sizeGroup);

	std::ifstream fout;
	fout.open(filename, std::ios_base::in | std::ios_base::app | std::ios_base::out);
	Group* arrGroup = new Group[sizeGroup];
	for (int i = 0; i < sizeGroup; i++)
	{
		fout >> arrGroup[i].FIO;
		fout >> arrGroup[i].status;
		fout >> arrGroup[i].mark;
		fout >> arrGroup[i].srok;
		fout >> arrGroup[i].dopball;

	}
	fout.close();
	bool t = true;
	while (t) {
		t = false;
		for (int i = 0; i < 5; i++) {
			if (arrGroup[i].mark < arrGroup[i + 1].mark) {

				std::swap(arrGroup[i].mark, arrGroup[i + 1].mark);
				std::swap(arrGroup[i].FIO, arrGroup[i + 1].FIO);


				t = true;
			}
		}
	}
	std::cout << "Group Rating List\n\n";
	for (int i = 0; i < sizeGroup; i++)
	{
		std::cout << arrGroup[i].FIO << '\t' << arrGroup[i].mark << '\n';
	}
	std::cout << "\n\n";
}
void AllReit() {
	int sizeGroup = 0;
	int sizeGroup1 = size(filename1, sizeGroup);
	int sizeGroup2 = size(filename2, sizeGroup1);
	int sizeGroup3 = size(filename3, sizeGroup2);
	int sizeGroup4 = size(filename4, sizeGroup3);
	int sizeGroup5 = size(filename5, sizeGroup4);
	Group* AllGroup = new Group[sizeGroup5];

	std::ifstream fout;
	fout.open(filename1, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = 0; i < sizeGroup1; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename2, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup1; i < sizeGroup2; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename3, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup2; i < sizeGroup3; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename4, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup3; i < sizeGroup4; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename4, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup4; i < sizeGroup5; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();


	bool t = true;
	while (t) {
		t = false;
		for (int i = 0; i < sizeGroup5 - 1; i++) {
			if (AllGroup[i].mark < AllGroup[i + 1].mark) {

				std::swap(AllGroup[i].mark, AllGroup[i + 1].mark);
				std::swap(AllGroup[i].FIO, AllGroup[i + 1].FIO);
				std::swap(AllGroup[i].srok, AllGroup[i + 1].srok);
				std::swap(AllGroup[i].dopball, AllGroup[i + 1].dopball);
				std::swap(AllGroup[i].status, AllGroup[i + 1].status);


				t = true;
			}
		}
	}
	std::cout << "Completed without re-issuance\n\n";
	for (int i = 0; i < sizeGroup5; i++)
	{
		if (AllGroup[i].srok == 1)
		{
			std::cout << AllGroup[i].FIO << "\t" << AllGroup[i].mark << "\n";
		}
	}
	std::cout << " \n\nDelivered with re-assignments\n\n";
	for (int i = 0; i < sizeGroup5; i++)
	{
		if (AllGroup[i].srok == 0)
		{
			std::cout << AllGroup[i].FIO << "\t" << AllGroup[i].mark << "\n";
		}
	}
}
void stependList() {
	int sizeGroup = 0;
	int sizeGroup1 = size(filename1, sizeGroup);
	int sizeGroup2 = size(filename2, sizeGroup1);
	int sizeGroup3 = size(filename3, sizeGroup2);
	int sizeGroup4 = size(filename4, sizeGroup3);
	int sizeGroup5 = size(filename5, sizeGroup4);
	Group* AllGroup = new Group[sizeGroup5];

	std::ifstream fout;
	fout.open(filename1, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = 0; i < sizeGroup1; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename2, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup1; i < sizeGroup2; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename3, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup2; i < sizeGroup3; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename4, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup3; i < sizeGroup4; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename4, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup4; i < sizeGroup5; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();



	bool t = true;
	while (t) {
		t = false;
		for (int i = 0; i < sizeGroup5 - 1; i++) {
			if (AllGroup[i].mark < AllGroup[i + 1].mark) {

				std::swap(AllGroup[i].mark, AllGroup[i + 1].mark);
				std::swap(AllGroup[i].FIO, AllGroup[i + 1].FIO);
				std::swap(AllGroup[i].srok, AllGroup[i + 1].srok);
				std::swap(AllGroup[i].dopball, AllGroup[i + 1].dopball);
				std::swap(AllGroup[i].status, AllGroup[i + 1].status);


				t = true;
			}
		}
	}
	int sizeStip = 0;
	for (int i = 0; i < sizeGroup5 - 1; i++)
	{
		if (AllGroup[i].status == 1)
		{


			sizeStip++;
		}
	}
	Group* StepArr = new Group[sizeStip];
	for (int i = 0; i < sizeGroup5 - 1; i++)
	{
		if (AllGroup[i].status == 1) {
			int j = 0;
			StepArr[j].FIO = AllGroup[i].FIO;
			StepArr[j].srok = AllGroup[i].srok;

			j++;
		}
	}
	std::cout << "Scholarship receive\n\n";
	for (int i = 0; i < sizeStip * 0.44; i++)
	{



		if (AllGroup[i].srok == 1)
		{
			std::cout << AllGroup[i].FIO << '\n';


		}

	}
	std::cout << "\n\n";
}
void ListBud_Srok() {
	int sizeGroup = 0;
	int sizeGroup1 = size(filename1, sizeGroup);
	int sizeGroup2 = size(filename2, sizeGroup1);
	int sizeGroup3 = size(filename3, sizeGroup2);
	int sizeGroup4 = size(filename4, sizeGroup3);
	int sizeGroup5 = size(filename5, sizeGroup4);
	Group* AllGroup = new Group[sizeGroup5];

	std::ifstream fout;
	fout.open(filename1, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = 0; i < sizeGroup1; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename2, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup1; i < sizeGroup2; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename3, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup2; i < sizeGroup3; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename4, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup3; i < sizeGroup4; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	fout.open(filename4, std::ios_base::in | std::ios_base::app | std::ios_base::out);

	for (int i = sizeGroup4; i < sizeGroup5; i++)
	{
		fout >> AllGroup[i].FIO;
		fout >> AllGroup[i].status;
		fout >> AllGroup[i].mark;
		fout >> AllGroup[i].srok;
		fout >> AllGroup[i].dopball;

	}
	fout.close();
	std::cout << "Scholarship could receiven\n";
	for (int i = 0; i < sizeGroup5 - 1; i++)
	{
		if (AllGroup[i].srok == 1 && AllGroup[i].status == 1)
		{
			std::cout << AllGroup[i].FIO << '\n';
		}
	}
	std::cout << "\n\n";
}

void lists() {
	int c; int v; int n; bool m = true; bool j = true; int h; bool f = true; bool e = true;
	
	std::string b;
	int q,x;

	bool p = true;
	while (p) {
		std::cout << "Select:\n 1: Group Lists\n 2: Lists of the entire course\n 0: Back\n";
		std::cin >> b;
		x = b.find_first_not_of("1234567890");


		if (x == -1)
		{
			c = std::stoi(b);
			p = false;
		}
		else {
			std::cout << "There is no such option, try again\n\n";
		}

	}

	
	switch (c)
	{
	case 1:


		while (j) {
			
			
			std::string b;
			int q, x;

			bool p = true;
			while (p) {
				std::cout << "Select\n 1: Reiting Group\n 2:List of lagging groups\n 3:Leading Group List\n 4: Group members list\n 0: Back\t 9: Main Menu\n";
				std::cin >> b;
				x = b.find_first_not_of("1234567890");


				if (x == -1)
				{
					v = std::stoi(b);
					p = false;
				}
				else {
					std::cout << "There is no such option, try again\n\n";
				}

			}

			switch (v)
			{
			case 1:

				while (m) {
					
					
					std::string b;
					int q, x;

					bool p = true;
					while (p) {
						std::cout << "\nChoose a group:\n 1:KIYKI-19-1\n 2:KIYKI-19-2\n 3:KIYKI-19-3\n 4:KIYKI-19-4\n 5:KIYKI-19-5\n 0:Back\t 9: Main Menu\n";
						std::cin >> b;
						x = b.find_first_not_of("1234567890");


						if (x == -1)
						{
							n = std::stoi(b);
							p = false;
						}
						else {
							std::cout << "There is no such option, try again\n\n";
						}

					}
					switch (n)
					{
					case 1:
						reitListGroup(filename1);
						break;
					case 2:
						reitListGroup(filename2);
						break;
					case 3:
						reitListGroup(filename3);
						break;
					case 4:
						reitListGroup(filename4);
						break;
					case 5:
						reitListGroup(filename5);
						break;
					case 0:
						m = false;
						break;
					case 9:
						return;
					default:
						std::cout << "There is no such option, try again\n";
						break;
					}

				}
				m = true; break;

			case 2:
				lastGroup();
				break;
			case 3:
				otlichnikiGroup();
				break;
			case 4:
				while (e) {
					
					std::string b;
					int q, x;

					bool p = true;
					while (p) {
						std::cout << "\nChoose a group:\n 1:KIYKI-19-1\n 2:KIYKI-19-2\n 3:KIYKI-19-3\n 4:KIYKI-19-4\n 5:KIYKI-19-5\n 0:Back\t 9: Main Menu\n";
						std::cin >> b;
						x = b.find_first_not_of("1234567890");


						if (x == -1)
						{
							n = std::stoi(b);
							p = false;
						}
						else {
							std::cout << "There is no such option, try again\n\n";
						}

					}
					switch (n)
					{
					case 1:
						ListGroup(filename1);
						break;
					case 2:
						ListGroup(filename2);
						break;
					case 3:
						ListGroup(filename3);
						break;
					case 4:
						ListGroup(filename4);
						break;
					case 5:
						ListGroup(filename5);
						break;
					case 0:
						e = false;
						break;
					case 9:
						return;
					default:
						std::cout << "There is no such option, try again\n";
						break;
					}
				}

			case 0:
				j = false;
				break;
			case 9:
				return;
			default:
				std::cout << "There is no such option, try again\n";
				break;

			}

		}
		j = true;
		break;
	case 2:
		while (f) {
			
			
			std::string b;
			int q, x;

			bool p = true;
			while (p) {
				std::cout << "Chosse\n 1: Rating list of groups\n 2: List of scholarship applicants\n 3: List of scholarship holders\n 0: Back\t 9: Main Menu\n";
				std::cin >> b;
				x = b.find_first_not_of("1234567890");


				if (x == -1)
				{
					h = std::stoi(b);
					p = false;
				}
				else {
					std::cout << "There is no such option, try again\n\n";
				}

			}


			switch (h)
			{
			case 1:
				AllReit();
				break;
			case 2:
				ListBud_Srok();
				break;
			case 3:
				stependList();
				break;
			case 0:
				f = false;
				break;
			case 9:
				return;
			default:
				std::cout << "There is no such option, try again\n";
				break;
			}
		}
		f = true;
		break;

	default:
		std::cout << "There is no such option, try again\n";
		break;

	}


}


int main()
{
	std::string n;
	int m, k,a,z;
	double crSum = 0;


	bool l = true;
	while (l)
	{
		std::cout << "How many subjects? : ";
		std::cin >> n;
		z = n.find_first_not_of("123456789");
		if (z == -1) {
			m = std::stoi(n);
			l = false;
		}
		else {
			std::cout << "Input error, try again\n\n";
		}
	}

	nure* SubArr = new nure[m];

	bool t = true;
	while (t)
	{
		std::string b;

		bool p = true;
		while (p) {
			std::cout << "Choose what you want to do:\n 1: Edit group\n 2: Enter subjects\n 3: Enter subject grades for all groups\n 4: View Lists\n 0: End\n";
			std::cin >> b;
			z = b.find_first_not_of("1234567890");
		    
			
			if (z==-1)
			{
				a = std::stoi(b);
				p = false;
			}
			else {
				std::cout << "There is no such option, try again\n\n";
			}
		 
		}
		
		bool k = false;

		switch (a)
		{
		case 1:

			group();
			break;
		case 2:
			
			crSum = subjects(SubArr, m);
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (i!=j)
					{
						if (SubArr[i].subject == SubArr[j].subject) {
							k = true;

						}
					}
					

				}
			}
			if (k)
			{
				std::cout << "\nThe item name is repeated, enter the items again!\n\n";

				crSum = 0;
			}
			break;
		case 3:

			if (crSum != 0 )
			{
				std::cout << "Enter grades for KIUKI - 19 - 1 group\n";
				marksGruop(filename1, m, SubArr, crSum);

				std::cout << "Enter grades for KIUKI - 19 - 2 group\n";
				marksGruop(filename2, m, SubArr, crSum);

				std::cout << "Enter grades for KIUKI - 19 - 3 group\n";
				marksGruop(filename3, m, SubArr, crSum);

				std::cout << "Enter grades for KIUKI - 19 - 4 group\n";
				marksGruop(filename4, m, SubArr, crSum);

				std::cout << "Enter grades for KIUKI - 19 - 5 group\n";
				marksGruop(filename5, m, SubArr, crSum);
			}
			else
			{
				std::cout << "Enter items first\n";
			}
			break;
		case 4:

			lists();

			break;
		case 0:
			return 0;
		default:
			std::cout << "There is no such option, try again\n\n";
			break;
		}
	}
}
