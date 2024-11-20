#include <iostream>
#include <string>

using namespace std;

int ClientInfo(string clientName[], string clientOrder[], int tableNumber[], int index) //index = 0
{
	cin.ignore();

	cout << "Client name: ";
	getline(cin, clientName[index]);
	cout << "What's your order? ";
	getline (cin, clientOrder[index]);
	cout << "Table number: ";
	cin >> tableNumber[index];
	index++;

	return index;
}

void UpdateInfo(string search, string clientName[], string clientOrder[], int tableNumber[], int response)
{
	string name, order;
	int number;
	

			cout << "Client Name: ";
			getline(cin, clientName[response - 1]) ;
			cout << "What's your order? ";
			getline (cin, clientOrder[response - 1]);
			cout << "Table number: ";
			cin >> tableNumber[response - 1];
			
			cout << "Update Successful!" << endl;

}

void DeleteInfo(string name, string clientName[], string clientOrder[], int tableNumber[])
{

	for (int x = 0; x < 10; x++)
	{
		if (clientName[x] == name)
		{

			clientName[x] = "";
			clientOrder[x] = "";
			tableNumber[x] = 0;

			cout << "Successfully Deleted!" << endl;
			break;
		}
	}
	{
		cout << "Record Doesn't Exist" << endl;
	}
}
void DeleteRecord(string clientName[], string clientOrder[], int tableNumber[])
{
	for (int x = 0; x < 10; x++)
	{
		clientName[x] = "";
		clientOrder[x] = "";
		tableNumber[x] = 0;
	}
	cout << "All records have been successfully deleted!" << endl;
}
void ListInfo(string clientName[], string clientOrder[], int tableNumber[])
{
	system("CLS");
	cout << "Current Information" << endl;
	cout << "===================================================================================================================" << endl;

	int counter = 0;
	for (int x = 0; x < 10; x++)
	{
		if (clientName[x] != "\0")
		{
			counter++;
			cout << " " << counter << "          " << clientName[x] << "          " << clientOrder[x] << "            " << tableNumber[x] << endl;
		}
	}

	if (counter == 0)
	{
		cout << "No record found!" << endl;
	}

	cout << "==================================================================================================================" << endl;
}

int main() {
	string clientName[10], clientOrder[10], ClientName, name, search;
	int tableNumber[10], option, index = 0, response = 0;

	do {
		cout << "1. Input information: " << endl;
		cout << "2. Update info" << endl;
		cout << "3. Delete specific info" << endl;
		cout << "4. Delete all records" << endl;
		cout << "5. Display all record" << endl;
		cout << "================================" << endl;

		cout << "Select option >> ";
		cin >> option;

		switch (option)
		{
		case 1:
			index = ClientInfo(clientName, clientOrder, tableNumber, index);
			system("CLS");
			break;

		case 2:
			cin.ignore();
			ListInfo(clientName, clientOrder, tableNumber);
			cout << "Enter your client number to update: ";
			cin >> response;
			cin.ignore();
			UpdateInfo(search, clientName, clientOrder, tableNumber, response);
			break;


		case 3:
			cin.ignore();
			cout << "Delete info by typing your input name: ";
			getline(cin, ClientName);
			DeleteInfo(name, clientName, clientOrder, tableNumber);
			system("CLS");
			break;


		case 4: DeleteRecord(clientName, clientOrder, tableNumber);
			break;

		case 5:
			ListInfo(clientName, clientOrder, tableNumber);
			break;

		}

	} while (option != 6);

	return 0;
}