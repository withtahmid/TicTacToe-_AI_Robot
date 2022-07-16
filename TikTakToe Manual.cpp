#include<bits/stdc++.h>
using namespace std;

vector<char>v(10);
vector<bool>notChoosen(10);
string player1;
string player2;
int player1won = 0, player2won = 0, draw = 0;
int num_of_match = 0;
void printBoard()
{
	cout<<endl<<endl;
	cout << v[1] << " | "<<v[2] << " | "<<v[3] << endl;
	cout << v[4] << " | "<<v[5] << " | "<<v[6] << endl;
	cout << v[7] << " | "<<v[8] << " | "<<v[9] << endl;
	cout<<endl;
}

int someoneWon()
{

	if(v[1] == v[2] && v[2] == v[3])
	{
		if(v[1] == 'X')
			return 1;
		else if(v[1] == 'O')
			return 2;
	}
	else if(v[4] == v[5] && v[5] == v[6])
	{
		if(v[4] == 'X')
			return 1;
		else if(v[4] == 'O')
			return 2;

	}
	else if(v[7] == v[8] && v[8] == v[9])
	{
		if(v[7] == 'X')
			return 1;
		else if(v[7] == 'O')
			return 2;
	}
	else if(v[1] == v[4] && v[4] == v[7])
	{
		if(v[1] == 'X')
			return 1;
		else if(v[1] == 'O')
			return 2;
	}
	else if(v[2] == v[5] && v[5] == v[8])
	{
		if(v[2] == 'X')
			return 1;
		else if(v[2] == 'O')
			return 2;
	}
	else if(v[3] == v[6] && v[6] == v[9])
	{
		if(v[3] == 'X')
			return 1;
		else if(v[3] == 'O')
			return 2;
	}
	else if(v[1] == v[5] && v[5] == v[9])
	{
		if(v[1] == 'X')
			return 1;
		else if(v[1] == 'O')
			return 2;
	}
	else if(v[3] == v[5] && v[5] == v[7])
	{
		if(v[3] == 'X')
			return 1;
		else if(v[3] == 'O')
			return 2;
	}

	return -1;

}




bool indexIsCorrect(int index)
{
	return notChoosen[index] && index>=1 && index <= 9;
}
void play()
{
	
	fill(v.begin(), v.end(), ' ');
	fill(notChoosen.begin(), notChoosen.end(), true );
	int round = 1;

	while(round <10)
	{
		printBoard();

		round&1 ? cout<<player1 : cout<<player2 ;cout<<"'s Term: ";

		int index; 
		cin>>index;
		while(!indexIsCorrect(index))
		{
			if(index<1 || index>9)
			{
				cout<<"Choose between 1 to 9: ";
			}
			else {
				cout <<"You are silecting a Already Chooseen index\nChoose again correctly: ";
			}
			cin>>index;
		}
		if(round & 1)
		{
			v[index] = 'X';
			notChoosen[index] = false;
		}
		else
		{
			v[index] = 'O';
			notChoosen[index] = false;
		}
		++round;
		int who = someoneWon();
		if(who == 1)
		{
			player1won++;
			printBoard();
			cout<<endl<<player1<<" won the match!"<<endl<<endl;
			return;
		}
		else if(who == 2)
		{
			player2won++;
			printBoard();
			cout<<endl<<player2<<" won the match!"<<endl<<endl;
			return;
		}
		 
		 if(round == 10 && who == -1)
		 {
		 	draw ++;
		 	printBoard();
		 	cout<<"Both played very well !!!"<<endl;
		 	return;
		 }

	}
}

void showScores()
{
	cout<<"\n\nMatch no: "<<num_of_match<<endl;
	cout<<player1<<" has won "<<player1won<<" matches\n";
	cout<<player2<<" has won "<<player2won<<" matches\n";
	cout<<"Draw: "<<draw<<endl<<endl;
}
int  main()
{
	cout<<"Enter Player 1's Name: ";
	getline(cin,player1);
	cout<<"Enter Player 2's Name: ";
	getline(cin,player2);
	play();
	while(true)
	{
		num_of_match++;
		showScores();
		cout<<"Want to play again(Y/y): ";
		char option;
		cin>>option;
		cin.ignore();
		if(option == 'Y' || option == 'y')
		{
			play();
		}
		else
		{
			break;
		}
	}
}