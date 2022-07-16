/**
 * Dev: MD TAHMID AHMED RAKIB
 * JUNE 2022
 * BSC in CSE at NSU-202
 * github/withtahmid
 * withtahmid@gmail.com
 * */

#include<bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
vector<string>messeges;
vector<char>v(10);
vector<bool>notChoosen(10);
int iWon = 0, youWon = 0, draw = 0;
int num_of_match = 0;
char myMove = 'X', opponent = 'O';

bool isMoveLeft(vector<char>board)
{
	 for(int i = 1; i<10; i++)
	 {
	 	if(board[i] == ' ')
	 		return  true;
	 }
	 return false;
}

int evaluate(vector<char>board)
{

	if(board[1] == board[2] && board[2] == board[3])
	{
		if(board[1] == 'X')
			return 10;
		else if(board[1] == 'O')
			return -10;
	}
	if(board[4] == board[5] && board[5] == board[6])
	{
		if(board[4] == 'X')
			return 10;
		else if(board[4] == 'O')
			return -10;

	}
	if(board[7] == board[8] && board[8] == board[9])
	{
		if(board[7] == 'X')
			return 10;
		else if(board[7] == 'O')
			return -10;
	}
	if(board[1] == board[4] && board[4] == board[7])
	{
		if(board[1] == 'X')
			return 10;
		else if(board[1] == 'O')
			return -10;
	}
	if(board[2] == board[5] && board[5] == board[8])
	{
		if(board[2] == 'X')
			return 10;
		else if(board[2] == 'O')
			return -10;
	}
	if(board[3] == board[6] && board[6] == board[9])
	{
		if(board[3] == 'X')
			return 10;
		else if(board[3] == 'O')
			return -10;
	}
	if(board[1] == board[5] && board[5] == board[9])
	{
		if(board[1] == 'X')
			return 10;
		else if(board[1] == 'O')
			return -10;
	}
	if(board[3] == board[5] && board[5] == board[7])
	{
		if(board[3] == 'X')
			return 10;
		else if(board[3] == 'O')
			return -10;
	}

	return 0;

}


void messegesFill()
{
	messeges.push_back("Oh no! Let me think for for a while :/ ");
	messeges.push_back("I knew it!");
	messeges.push_back("Oh! that was cleaver!!");
	messeges.push_back("Won't let you win man!");
	messeges.push_back("You are wasting your time.");
	messeges.push_back("complete your assignment!!");
	messeges.push_back("I am invencible!");
	messeges.push_back("You can't beat a computer :p");
	messeges.push_back("Nice play :D");
	messeges.push_back("you are playing very well!");
	messeges.push_back("Smart move!");
	messeges.push_back("Your Faculty hates you!");
	messeges.push_back("HA! HA! HA!");
	messeges.push_back("WOW!");
	messeges.push_back("Smart move!");
}


bool contains(string str, char c)
{
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] == c)
			return true;
	}
	return false;
}

bool matchOver()
{
	int possibility = 0;
	string str;
	str += v[1];
	str += v[2];
	str += v[3];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}

	str = "";
	str += v[4];
	str += v[5];
	str += v[6];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}

	str = "";
	str += v[7];
	str += v[8];
	str += v[9];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}
	str = "";
	str += v[1];
	str += v[4];
	str += v[7];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}

	str = "";
	str += v[2];
	str += v[5];
	str += v[8];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}

	str = "";
	str += v[3];
	str += v[6];
	str += v[9];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}

	str = "";
	str += v[1];
	str += v[5];
	str += v[9];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}

	str = "";
	str += v[3];
	str += v[5];
	str += v[7];
	if(contains(str,'X') && contains(str,'O'))
	{
		possibility++;
	}

	return possibility ==  8;

}

int minimax(vector<char> board, int depth, bool isMax)
{
	int score = evaluate(board);

	if(score == 10 || score == -10)
		return score;
	if(isMoveLeft(board) == false)
		return 0;

	if(isMax)
	{
		int best = -1000;

		for(int i = 1; i<10; i++)
		{
			if(board[i] == ' ')
			{
				board[i] = myMove;

				best = max(best, minimax(board, depth+1, !isMax));

				board[i] = ' ';
			}
		}

		return best;
	}
	else
	{
		int best = 1000;

		for(int i = 1; i<10; i++)
		{
			if(board[i] == ' ')
			{
				board[i] = opponent;

				best = min(best, minimax(board, depth+1, !isMax));

				board[i] = ' ';
			}
		}

		return best;
	}

}

int findBestMove(vector<char>board)
{
	int best = -1000;
	int indx = -1;
	for(int i = 1; i<10; i++ )
	{
		if(board[i] == ' ')
		{
			board[i] = myMove;

			int valueForThis = minimax(board, 1 , false);
			board[i] = ' ';
			if(valueForThis>best)
			{
				best = valueForThis;
				indx = i;
			}
		}
	}

	return indx;
}

void printBoard()
{
//	cout<<"------------------------------------\n\n";
	cout<<endl; 
	cout <<"\t"<< v[1] << " | "<<v[2] << " | "<<v[3] << endl;
	cout <<"\t"<< v[4] << " | "<<v[5] << " | "<<v[6] << endl;
	cout <<"\t"<< v[7] << " | "<<v[8] << " | "<<v[9] << endl;
	cout<<"\n------------------------------------\n\n"; 
}

void directionBoard()
{
	cout<<"------------------------------------\n\n"; 
	cout<<"\t" << 1 << " | "<< 2 << " | "<< 3 << endl;
	cout<<"\t" << 4 << " | "<< 5 << " | "<< 6 << endl;
	cout<<"\t"  << 7 << " | "<< 8 << " | "<< 9 << endl;
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
	if(v[4] == v[5] && v[5] == v[6])
	{
		if(v[4] == 'X')
			return 1;
		else if(v[4] == 'O')
			return 2;

	}
	if(v[7] == v[8] && v[8] == v[9])
	{
		if(v[7] == 'X')
			return 1;
		else if(v[7] == 'O')
			return 2;
	}
	if(v[1] == v[4] && v[4] == v[7])
	{
		if(v[1] == 'X')
			return 1;
		else if(v[1] == 'O')
			return 2;
	}
	if(v[2] == v[5] && v[5] == v[8])
	{
		if(v[2] == 'X')
			return 1;
		else if(v[2] == 'O')
			return 2;
	}
	if(v[3] == v[6] && v[6] == v[9])
	{
		if(v[3] == 'X')
			return 1;
		else if(v[3] == 'O')
			return 2;
	}
	if(v[1] == v[5] && v[5] == v[9])
	{
		if(v[1] == 'X')
			return 1;
		else if(v[1] == 'O')
			return 2;
	}
	if(v[3] == v[5] && v[5] == v[7])
	{
		if(v[3] == 'X')
			return 1;
		else if(v[3] == 'O')
			return 2;
	}

	return -1;

}
bool noneCanWin()
{
	vector<char> board = v;
	for(int i = 1; i <= 10; i++)
	{
		if(board[i] == ' ')
		{
			board[i] = 'O';
			break;
		}
	}
	return evaluate(board) == 0;
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
	int who;
	while(round <10)
	{
		printBoard();

		cout<<"Your term [ O ] : ";
		char input;
		cin>>input;
		if(input == 'n' || input == 'N')
		{
			cout<<"Give up ?\n";
			return;
		}
		int index; 
		index = input - '0';
		while(!indexIsCorrect(index))
		{
			if(index<1 || index>9)
			{
				cout<<"Why are you acting idiot?\nChoose between 1 to 9: ";
			}
			else {
				cout <<"You don't know the game?\nChoose correctly: ";
			}
			cin>>input;
			if(input == 'n' || input == 'N')
			{
				cout<<"Give up ?\n";
				return;
			}
			index = input - '0';
		}

		v[index] = 'O';
		notChoosen[index] = false;
		round++;
		
		who = someoneWon();
		if(who == 1)
		{
			iWon++;
			num_of_match++;
			printBoard();
			cout<<endl<<"I won the match!"<<endl<<endl;
			return;
		}
		else if(who == 2)
		{
			youWon++;
			num_of_match++;
			printBoard();
			cout<<endl<<"Oh No !!! You won the match :/"<<endl<<endl;
			return;
		}
		
		if(round == 10 && who == -1)
		{
		 	draw ++;
		 	num_of_match++;
		 	printBoard();
		 	cout<<"We both played very well !!!"<<endl<<endl;
		 	return;
		}

	 	if(matchOver())
		{
			draw ++;
			num_of_match++;
		 	printBoard();
		 	cout<<"No one can win this match."<<endl<<endl;
		 	return;
		}
		 
		int i_choose;
		if(round<10)
		{
			srand((unsigned) time(0));

			int messegesIndx = abs(rand())%messeges.size();
			cout<<"\n\n====================================\n"; 
			cout<<'\t'<<messeges[messegesIndx]<<endl;
			cout<<"====================================\n"; 
			 i_choose = findBestMove(v);
			if(messegesIndx == 0)
			{
				usleep(3000000);
				cout<<"Okay! ";
				cout<<"I choose: "<<i_choose<<endl;
			}
			
			v[i_choose] = 'X';
			notChoosen[i_choose] = false; 
			round++;
			
			who = someoneWon();

			if(who == 1)
			{
				iWon++;
				num_of_match++;
				printBoard();
				cout<<endl<<"I won the match!"<<endl<<endl;
				return;
			}
			else if(who == 2)
			{
				youWon++;
				num_of_match++;
				printBoard();
				cout<<endl<<"You won the match :/ "<<endl<<endl;
				return;
			}
			if(round == 10 && who == -1)
			{
			 	draw ++;
			 	num_of_match++;
			 	printBoard();
			 	cout<<"We both played very well !!!"<<endl<<endl;
			 	return;
			}
			if(matchOver())
			{
				draw ++;
				num_of_match++;
				printBoard();
				cout<<"I choose: "<<i_choose<<endl;
			 	cout<<"And no one can win this match."<<endl<<endl;
			 	return;
			}
			
		}
		if(round == 9 && noneCanWin())
		{
			draw++;
			num_of_match++;
			cout<<"I choose: "<<i_choose<<endl;
			cout<<"And No one can win this match."<<endl<<endl;
			return;
		}
		
		

	}
}

void showScores()
{
	cout<<"\n--------------------------------------\n";
	cout<<"\tTotal played "<<num_of_match<<" matches\n";
	cout<<"\tI alone won "<<iWon<<" matches\n";
	cout<<"\tYou all won "<<youWon<<" matches\n";
	cout<<"\tDraw "<<draw<<" matches"<<endl;
	cout<<"--------------------------------------\n";
	cout<<endl;
}


void readFromFile()
{
	FILE *fptr;
	fptr = fopen("score.txt","rb");
	if(fptr != NULL)
	{
		fscanf(fptr,"%d %d %d %d",&num_of_match, &iWon, &youWon, &draw);
		fclose(fptr);
	}
	
}

void writeScore()
{
	FILE *fptr;
	fptr = fopen("score.txt","w");
	if(fptr != NULL)
	{
		fprintf(fptr,"%d %d %d %d",num_of_match, iWon, youWon, draw);
	}
	fclose(fptr);
	showScores();
}

int  main()
{
	readFromFile();
	directionBoard();
	cout<<"\n----------------------------------------------------";
	cout<<"\nBoxes are numbered from 1 to 9 as shown above\nYour mark is 'O', my mark is 'X'.\npress 'n' while playing to play new match\n";
	cout<<"\n----------------------------------------------------\n";

	messegesFill();
	play();
	writeScore();
	while(true)
	{
		cout<<"Want to play again? (y/n): ";
		char option;
		cin>>option;
		cin.ignore();
		if(option == 'y' || option == 'Y'){	
			play();
			writeScore();
		}
		
		else {
			break;
		}	
	}
	showScores();
} 