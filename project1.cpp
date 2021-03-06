// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void displaySeats(char seats[15][30]);
int main()
{
	char seats[15][30];
	int ticket = 0;
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 30; j++)
			seats[i][j] = '#';
	double rowPrice[15];
	double totalSale = 0;
	for (int i = 0; i < 15; i++)
	{
		cout << "Enter the price for row" << i << endl;
		cin >> rowPrice[i];
	}
	displaySeats(seats);
	char status;
	do 
	{
		cout << "Welcome to theater, how many tickets you want to buy?";
		int n,r,c;
		cin >> n;
		cout << endl;
		double ticketPrice = 0;
		while (n > 0)
		{
			cout << "Enter Row and column of an avalible seat:";
			cin >> r;
			cin >> c;
			cout << endl;
			if (r <= 15 && c <= 30)
				if (seats[r - 1][c - 1] == '#')
				{
					seats[r - 1][c - 1] = '*';
					n--;
					ticket++;
					ticketPrice += rowPrice[r - 1];
				}
				else cout << "Seat has been taken." << endl;
			else cout << "Wrong number." << endl;
		}
		cout << "Total price is: " << ticketPrice << endl;
		displaySeats(seats);
		totalSale += ticketPrice;
		cout << "Total sale of tickets is: " << totalSale << endl;
		cout << ticket << " tickets have been sold." << endl;
		cout << 450 - ticket << " seats are avalible." << endl;
		for (int i = 0; i < 15; i++)
		{
			int numRow = 0;
			for (int j = 0; j < 30; j++)
			{
				if (seats[i][j] == '*')
					numRow++;
			}
			cout << "Row" << i + 1 << "has " << 30 - numRow << "avalible.  ";
		}
		cout << endl;
		cout << "Continue to run?(Y/N)";
		do
		{
			cin >> status;
		} while (status != 'Y' && status != 'N');
		
	} while (status == 'Y');
	return 0;
}
void displaySeats(char seats[15][30])
{
	cout << "\t";
	for(int a=0;a<3;a++)
		for (int s = 1; s < 11; s++)
		{
			cout << s % 10;
		}
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		printf("Row %-4d", i+1);
		for (int j = 0; j < 30; j++)
		{
			cout << seats[i][j];
		}
		cout << endl;
	}
}

