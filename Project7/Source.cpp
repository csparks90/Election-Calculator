#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int nOfCan;		//Number of candidates variable.
double votePer = 0;	//Vote percentage
double totalVotes = 0;	//Total Vote Tally
int mostVotes = 0;	//Variable to help track winner
string winner = "";		//string to output winner of election

int main()
{
	cout << "Please enter the number of candidates >> ";
	cin >> nOfCan;
	cout << endl;


	string* canArray = new string[nOfCan];	//dynamic candidate name array
	int* voteArray = new int[nOfCan];	//dynamic vote array

	for (int i = 0; i < 5; i++)	//block to properly input candidate and vote data
	{
		cout << "Please enter Last name of candidate >> ";
		cin >> canArray[i];
		cout << endl;

		cout << "Please enter " << canArray[i] << " votes >> ";
		cin >> voteArray[i];
		cout << endl;

		if (voteArray[i] > mostVotes)
		{
			winner = canArray[i];
			mostVotes = voteArray[i];
		}
		

		totalVotes = totalVotes + voteArray[i];
	}	//end of input

	cout << " Candidate" << setw(20) << "Votes Received" << setw(20) << "% of Total Votes" << endl;
	cout << "*-------------------------------------------------*" << endl;
	for (int i = 0; i < 5; i++)	//loop to properly output candidate name, vote, and vote percentage numbers
	{
		cout << canArray[i] << setw(20 - canArray[i].length());
		cout << voteArray[i] << setw(20);
		cout << fixed << showpoint << setprecision(2);
		votePer = (voteArray[i] * 100) / totalVotes;
		cout << votePer << endl;

	}
	
	cout << "Total" << setw(16) << static_cast<int>(totalVotes) << endl << endl;
	cout << "The Winner of the Election is: " << winner << endl;


	delete[] canArray;
	delete[] voteArray;


	return 0;
}