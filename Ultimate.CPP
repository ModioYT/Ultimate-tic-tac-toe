// By :  Muhmmad Farraj && Somaia Omar 
#include <bits/stdc++.h>
using namespace std;
class Board {
	char board[9];
	vector<int> x, o;
  public:
	Board() {
		for (int i = 0; i < 9; i++)
			board[i] = '1' + i;
	}
	void undo(int index, bool turn) {
		board[index - 1] = '0' + index;
		if (turn)
			x.pop_back();
		else
			o.pop_back();
	}
	void play(int index, bool turn) {

		if (turn == 1) {
			board[index - 1] = 'X';
			x.push_back(index);
		}
		else {
			board[index - 1] = 'O';
			o.push_back(index);
		}
	}
	int score() {
		if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
			return 1;
		if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
			return 1;
		if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
			return 1;
		if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
			return 1;
		if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
			return 1;
		if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
			return 1;
		if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
			return 1;
		if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
			return 1;
		if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
			return -1;
		if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
			return -1;
		if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
			return -1;
		if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
			return -1;
		if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
			return -1;
		if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
			return -1;
		if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
			return -1;
		if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
			return -1;
		if (o.size() + x.size() == 9)
			return 0;
		return 10;
	}
	vector<int> Empty() {
		vector<int> m;
		for (int i = 1; i <= 9; i++)
			if (check(i))
				m.push_back(i);
		return m;
	}
	bool check(int index) {
		for (int i = 0; i < x.size(); i++)
			if (index == x[i])
				return 0;
		for (int i = 0; i < o.size(); i++)
			if (index == o[i])
				return 0;
		return 1;
	}

	void PrintUp() {
		for (int i = 0; i < 3; i++)
			cout << board[i] << " ";


	}
	void PrintMid() {
		for (int i = 3; i < 6; i++)
			cout << board[i] << " ";


	}
	void PrintDown() {
		for (int i = 6; i < 9; i++)
			cout << board[i] << " ";

	}
	int CheckXO(int inx) {
		for (auto ch : x) {
			if (ch == inx)
				return 1;
		}
		for (auto ch : o) {
			if (ch == inx)
				return -1;
		}
		return 0;
	}
	int CalculaterSmall() { 
		int Scores[9];
		int avg = 0;
		for (int i = 1; i <= 9; i++)
			Scores[i - 1] = CheckXO(i);
		bool flag[9] = { true,true,true,true,true,true,true,true,true };
		if (Scores[0] == 1) {
			if (Scores[1] != -1 || Scores[2] != -1) {
				if (Scores[1] == 1 || Scores[2] == 1) {
					avg += 2;
					flag[0] = false;
				}
			}
			if (Scores[3] != -1 || Scores[6] != -1) {
				if (Scores[3] == 1 || Scores[6] == 1) {
					avg += 2;
					flag[1] = false;
				}
			}
			if (Scores[4] != -1 || Scores[8] != -1) {
				if (Scores[4] == 1 || Scores[8] == 1) {
					avg += 2;
					flag[2] = false;
				}
			}
		}

		if (Scores[1] == 1) {
			if ((Scores[0] != -1 || Scores[2] != -1) && flag[0]) {
				if (Scores[0] == 1 || Scores[2] == 1) {
					avg += 2;
					flag[0] = false;
				}
			}
			if (Scores[4] != -1 || Scores[7] != -1) {
				if (Scores[4] == 1 || Scores[7] == 1) {
					avg += 2;
					flag[3] = false;
				}
			}

		}
		if (Scores[2] == 1) {
			if ((Scores[1] != -1 || Scores[0] != -1) && flag[0]) {
				if (Scores[1] == 1 || Scores[0] == 1) {
					avg += 2;
					flag[0] = false;
				}
			}
			if (Scores[5] != -1 || Scores[8] != -1) {
				if (Scores[5] == 1 || Scores[8] == 1) {
					avg += 2;
					flag[4] = false;
				}
			}
			if (Scores[4] != -1 || Scores[6] != -1) {
				if (Scores[4] == 1 || Scores[6] == 1) {
					avg += 2;
					flag[5] = false;
				}
			}
		}
		if (Scores[3] == 1) {
			if ((Scores[0] != -1 || Scores[6] != -1) && flag[1]) {
				if (Scores[0] == 1 || Scores[6] == 1) {
					avg += 2;
					flag[1] = false;
				}
			}
			if (Scores[4] != -1 || Scores[5] != -1) {
				if (Scores[4] == 1 || Scores[5] == 1) {
					avg += 2;
					flag[6] = false;
				}
			}
		}
		if (Scores[4] == 1) {
			if ((Scores[0] != -1 || Scores[8] != -1) && flag[2]) {
				if (Scores[0] == 1 || Scores[8] == 1) {
					avg += 2;
					flag[2] = false;
				}
			}
			if ((Scores[1] != -1 || Scores[7] != -1) && flag[3]) {
				if (Scores[1] == 1 || Scores[7] == 1) {
					avg += 2;
					flag[3] = false;
				}
			}
			if ((Scores[2] != -1 || Scores[6] != -1) && flag[5]) {
				if (Scores[2] == 1 || Scores[6] == 1) {
					avg += 2;
					flag[5] = false;
				}
			}
			if ((Scores[3] != -1 || Scores[5] != -1) && flag[6]) {
				if (Scores[3] == 1 || Scores[5] == 1) {
					avg += 2;
					flag[6] = false;
				}
			}
		}
		if (Scores[5] == 1) {
			if ((Scores[2] != -1 || Scores[8] != -1) && flag[4]) {
				if (Scores[2] == 1 || Scores[8] == 1) {
					avg += 2;
					flag[4] = false;
				}
			}
			if ((Scores[3] != -1 || Scores[4] != -1) && flag[6]) {
				if (Scores[3] == 1 || Scores[4] == 1) {
					avg += 2;
					flag[6] = false;
				}
			}
		}
		if (Scores[6] == 1) {
			if ((Scores[0] != -1 || Scores[3] != -1) && flag[1]) {
				if (Scores[0] == 1 || Scores[3] == 1) {
					avg += 2;
					flag[1] = false;
				}
			}
			if (Scores[7] != -1 || Scores[8] != -1) {
				if (Scores[7] == 1 || Scores[8] == 1) {
					avg += 2;
					flag[7] = false;
				}
			}
			if ((Scores[2] != -1 || Scores[4] != -1) && flag[5]) {
				if (Scores[2] == 1 || Scores[4] == 1) {
					avg += 2;
					flag[5] = false;
				}
			}
		}
		if (Scores[7] == 1) {
			if ((Scores[1] != -1 || Scores[4] != -1) && flag[3]) {
				if (Scores[1] == 1 || Scores[4] == 1) {
					avg += 2;
					flag[3] = false;
				}
			}
			if ((Scores[6] != -1 || Scores[8] != -1) && flag[7]) {
				if (Scores[6] == 1 || Scores[8] == 1) {
					avg += 2;
					flag[7] = false;
				}
			}
		}
		if (Scores[8] == 1) {
			if ((Scores[6] != -1 || Scores[7] != -1) && flag[7]) {
				if (Scores[6] == 1 || Scores[7] == 1) {
					avg += 2;
					flag[7] = false;
				}
			}
			if ((Scores[2] != -1 || Scores[5] != -1) && flag[4]) {
				if (Scores[2] == 1 || Scores[5] == 1) {
					avg += 2;
					flag[4] = false;
				}
			}
			if ((Scores[0] != -1 || Scores[4] != -1) && flag[2]) {
				if (Scores[0] == 1 || Scores[4] == 1) {
					avg += 2;
					flag[2] = false;
				}
			}
		}
		if (Scores[0] == 1 && flag[0] && flag[1] && flag[2]) {
			avg++;
		}
		if (Scores[1] == 1 && flag[0] && flag[3]) {
			avg++;
		}
		if (Scores[2] == 1 && flag[0] && flag[4] && flag[5]) {
			avg++;
		}
		if (Scores[3] == 1 && flag[1] && flag[6]) {
			avg++;
		}
		if (Scores[4] == 1 && flag[2] && flag[3] && flag[5] && flag[6]) {
			avg++;
			//bigger advantge
		}
		if (Scores[5] == 1 && flag[4] && flag[6]) {
			avg++;
		}
		if (Scores[6] == 1 && flag[1] && flag[5] && flag[7]) {
			avg++;
		}
		if (Scores[7] == 1 && flag[3] && flag[7]) {
			avg++;
		}
		if (Scores[8] == 1 && flag[2] && flag[7] && flag[4]) {
			avg++;
		}




		// O Scores
		if (Scores[0] == -1) {
			if (Scores[1] != 1 || Scores[2] != 1) {
				if (Scores[1] == -1 || Scores[2] == -1) {
					avg -= 2;
					flag[0] = false;
				}
			}
			if (Scores[3] != 1 || Scores[6] != 1) {
				if (Scores[3] == -1 || Scores[6] == -1) {
					avg -= 2;
					flag[1] = false;
				}
			}
			if (Scores[4] != 1 || Scores[8] != 1) {
				if (Scores[4] == -1 || Scores[8] == -1) {
					avg -= 2;
					flag[2] = false;
				}
			}
		}

		if (Scores[1] == -1) {
			if ((Scores[0] != 1 || Scores[2] != 1) && flag[0]) {
				if (Scores[0] == -1 || Scores[2] == -1) {
					avg -= 2;
					flag[0] = false;
				}
			}
			if (Scores[4] != 1 || Scores[7] != 1) {
				if (Scores[4] == -1 || Scores[7] == -1) {
					avg -= 2;
					flag[3] = false;
				}
			}

		}
		if (Scores[2] == -1) {
			if ((Scores[1] != 1 || Scores[0] != 1) && flag[0]) {
				if (Scores[1] == -1 || Scores[0] == -1) {
					avg -= 2;
					flag[0] = false;
				}
			}
			if (Scores[5] != 1 || Scores[8] != 1) {
				if (Scores[5] == -1 || Scores[8] == -1) {
					avg -= 2;
					flag[4] = false;
				}
			}
			if (Scores[4] != 1 || Scores[6] != 1) {
				if (Scores[4] == -1 || Scores[6] == -1) {
					avg -= 2;
					flag[5] = false;
				}
			}
		}
		if (Scores[3] == -1) {
			if ((Scores[0] != 1 || Scores[6] != 1) && flag[1]) {
				if (Scores[0] == -1 || Scores[6] == -1) {
					avg -= 2;
					flag[1] = false;
				}
			}
			if (Scores[4] != 1 || Scores[5] != 1) {
				if (Scores[4] == -1 || Scores[5] == -1) {
					avg -= 2;
					flag[6] = false;
				}
			}
		}
		if (Scores[4] == -1) {
			if ((Scores[0] != 1 || Scores[8] != 1) && flag[2]) {
				if (Scores[0] == -1 || Scores[8] == -1) {
					avg -= 2;
					flag[2] = false;
				}
			}
			if ((Scores[1] != 1 || Scores[7] != 1) && flag[3]) {
				if (Scores[1] == -1 || Scores[7] == -1) {
					avg -= 2;
					flag[3] = false;
				}
			}
			if ((Scores[2] != 1 || Scores[6] != 1) && flag[5]) {
				if (Scores[2] == -1 || Scores[6] == -1) {
					avg -= 2;
					flag[5] = false;
				}
			}
			if ((Scores[3] != 1 || Scores[5] != 1) && flag[6]) {
				if (Scores[3] == -1 || Scores[5] == -1) {
					avg -= 2;
					flag[6] = false;
				}
			}
		}
		if (Scores[5] == -1) {
			if ((Scores[2] != 1 || Scores[8] != 1) && flag[4]) {
				if (Scores[2] == -1 || Scores[8] == -1) {
					avg -= 2;
					flag[4] = false;
				}
			}
			if ((Scores[3] != 1 || Scores[4] != 1) && flag[6]) {
				if (Scores[3] == -1 || Scores[4] == -1) {
					avg -= 2;
					flag[6] = false;
				}
			}
		}
		if (Scores[6] == -1) {
			if ((Scores[0] != 1 || Scores[3] != 1) && flag[1]) {
				if (Scores[0] == -1 || Scores[3] == -1) {
					avg -= 2;
					flag[1] = false;
				}
			}
			if (Scores[7] != 1 || Scores[8] != 1) {
				if (Scores[7] == -1 || Scores[8] == -1) {
					avg -= 2;
					flag[7] = false;
				}
			}
			if ((Scores[2] != 1 || Scores[4] != 1) && flag[5]) {
				if (Scores[2] == 1 || Scores[4] == -1) {
					avg -= 2;
					flag[5] = false;
				}
			}
		}
		if (Scores[7] == -1) {
			if ((Scores[1] != 1 || Scores[4] != 1) && flag[3]) {
				if (Scores[1] == -1 || Scores[4] == -1) {
					avg -= 2;
					flag[3] = false;
				}
			}
			if ((Scores[6] != 1 || Scores[8] != 1) && flag[7]) {
				if (Scores[6] == -1 || Scores[8] == -1) {
					avg -= 2;
					flag[7] = false;
				}
			}
		}
		if (Scores[8] == -1) {
			if ((Scores[6] != 1 || Scores[7] != 1) && flag[7]) {
				if (Scores[6] == -1 || Scores[7] == -1) {
					avg -= 2;
					flag[7] = false;
				}
			}
			if ((Scores[2] != 1 || Scores[5] != 1) && flag[4]) {
				if (Scores[2] == -1 || Scores[5] == -1) {
					avg -= 2;
					flag[4] = false;
				}
			}
			if ((Scores[0] != 1 || Scores[4] != 1) && flag[2]) {
				if (Scores[0] == -1 || Scores[4] == -1) {
					avg -= 2;
					flag[2] = false;
				}
			}
		}
		if (Scores[0] == -1 && flag[0] && flag[1] && flag[2]) {
			avg--;
		}
		if (Scores[1] == -1 && flag[0] && flag[3]) {
			avg--;
		}
		if (Scores[2] == -1 && flag[0] && flag[4] && flag[5]) {
			avg--;
		}
		if (Scores[3] == -1 && flag[1] && flag[6]) {
			avg--;
		}
		if (Scores[4] == -1 && flag[2] && flag[3] && flag[5] && flag[6]) {
			avg--;
			//bigger advantge
		}
		if (Scores[5] == -1 && flag[4] && flag[6]) {
			avg--;
		}
		if (Scores[6] == -1 && flag[1] && flag[5] && flag[7]) {
			avg--;
		}
		if (Scores[7] == -1 && flag[3] && flag[7]) {
			avg--;
		}
		if (Scores[8] == -1 && flag[2] && flag[7] && flag[4]) {
			avg--;
		}
		return avg;
	}
};

class Ultimate {
	Board B[9];
	bool turn;
	map<int,int> Wx, Wo, Tie;
	    int diff;
  public:
	void Undo(int Board, int Index, int Turn){
	  B[Board - 1].undo(Index, Turn);
	}
	Ultimate() {
		 cout<<"choose the difficulty level From 1 to 7 (1 is the weakest , 7 is the strongest)"<<endl;

    while(true){
      cin>>diff;
      if(diff>0 && diff<8)
      break;
 cout<<"choose the difficulty level From 1 to 7 (1 is the weakest , 7 is the strongest)"<<endl;
    }
		turn = 1;
		for (int i = 1; i <= 9; i++) {
			Wx[i] = -1;
			Wo[i] = -1;
			Tie[i] = -1;
		}
	}
	void Print() {
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 3; j++) {//1 2 3    1 2 3     1 2 3
				B[i + j].PrintUp();
				cout << "    ";
			}
			cout << endl;

			for (int j = 0; j < 3; j++) {//4 5 6    4 5 6    4 5 6
				B[i + j].PrintMid();
				cout << "    ";
			}
			cout << endl;

			for (int j = 0; j < 3; j++) {//1 2 3    1 2 3     1 2 3
				B[i + j].PrintDown();
				cout << "    ";
			}
			cout << endl;
			cout << endl;


		}
		cout << endl;
	}
	void Play(int Board, int Index, bool T) {
		B[Board - 1].play(Index, T);
	}
	void CheckerBoard() {
		for (int q = 0; q < 9; q++) {
			if (B[q].score() == 0)
				Tie[q + 1] = 1;
			else if (B[q].score() == 1)
				Wx[q + 1] = 1;
			else if (B[q].score() == -1)
				Wo[q + 1] = 1;
			else
			{
				Wx[q + 1] = -1;
				Wo[q + 1] = -1;
				Tie[q + 1] = -1;
			}
		}
	}
	bool CheckerIndex(int Board, int Index) {
		bool S = B[Board - 1].check(Index);
		return S;
	}
	bool AvailableBoard(int ind) {
		if (B[ind - 1].score() == 10)
			return true;

		return false;
	}
	int BigWin() {
		if (Wx[1] == 1 && Wx[2] == 1 && Wx[3] == 1)
			return 2000;
		if (Wx[4] == 1 && Wx[5] == 1 && Wx[6] == 1)
			return 2000;
		if (Wx[9] == 1 && Wx[8] == 1 && Wx[7] == 1)
			return 2000;
		if (Wx[1] == 1 && Wx[4] == 1 && Wx[7] == 1)
			return 2000;
		if (Wx[2] == 1 && Wx[5] == 1 && Wx[8] == 1)
			return 2000;
		if (Wx[3] == 1 && Wx[6] == 1 && Wx[9] == 1)
			return 2000;
		if (Wx[1] == 1 && Wx[5] == 1 && Wx[9] == 1)
			return 2000;
		if (Wx[3] == 1 && Wx[5] == 1 && Wx[7] == 1)
			return 2000;
		if (Wo[1] == 1 && Wo[2] == 1 && Wo[3] == 1)
			return -2000;
		if (Wo[4] == 1 && Wo[5] == 1 && Wo[6] == 1)
			return -2000;
		if (Wo[7] == 1 && Wo[8] == 1 && Wo[9] == 1)
			return -2000;
		if (Wo[1] == 1 && Wo[4] == 1 && Wo[7] == 1)
			return -2000;
		if (Wo[2] == 1 && Wo[5] == 1 && Wo[8] == 1)
			return -2000;
		if (Wo[3] == 1 && Wo[6] == 1 && Wo[9] == 1)
			return -2000;
		if (Wo[1] == 1 && Wo[5] == 1 && Wo[9] == 1)
			return -2000;
		if (Wo[3] == 1 && Wo[5] == 1 && Wo[7] == 1)
			return -2000;
      for(int i=0;i<9;i++){
		if (Wo[i+1] !=1 && Wx[i+1]!=1 && Tie[i+1]!=1)
    return 100;

    }
			return 0;

	}
	int Calculater() {
		int AVG = 0;
		int Scores[9];
		CheckerBoard();
		for (int a = 0; a < 9; a++) {
			if (Wx[a + 1] == 1)
				Scores[a] = 15;
			else if (Wo[a + 1] == 1)
				Scores[a] = -15;
			else if (Tie[a + 1] == 1)
				Scores[a] = -999999;
			else Scores[a] = B[a].CalculaterSmall();

		}
		for (int i = 0; i < 9; i++)
			if (Scores[i] != -999999)
				AVG += Scores[i];

		return AVG;
	}
	vector<int> All(int index) {
		vector<int> emp(0);

		if (!AvailableBoard(index))
			return emp;
		emp = B[index - 1].Empty();
		return emp;
	}
  
	int Minmax(int table, int Index, int Depth, int alpha, int beta, bool Turn) {
		int Max = -INT_MAX;
		int Min = INT_MAX;
		if (Depth == 0)
			return Calculater();
		if (Turn) {
			B[table].play(Index, Turn);
			CheckerBoard();
			int Score = BigWin();
			if (Score != 100)
				return Score;//3.76 
			vector<int> emp;
			if (AvailableBoard(Index)) {
				emp = B[Index - 1].Empty();
				for (auto x : emp) {
					int v = Minmax(Index - 1, x, Depth - 1, alpha, beta, !Turn);
					if (Depth != 1)
						Undo(Index, x, !Turn);
					CheckerBoard();
					Min = min(v, Min);
					beta = min(beta, Min);
					if (beta <= alpha)
						break;
				}
				return Min;
			}
			else
			{
				for (int i = 1; i <= 9; i++)
				{
					vector<int> em = All(i);
					for (auto x : em) {
						int v = Minmax(i - 1, x, Depth - 1, alpha, beta, !Turn);
						if (Depth != 1)

							Undo(i, x, !Turn);
						if (Depth != 1)
							CheckerBoard();
						Min = min(v, Min);
						beta = min(beta, Min);
						if (beta <= alpha)
							break;
					}
				}
				return Min;
			}
		}
		else {
			B[table].play(Index, Turn);
			CheckerBoard();
			int Score = BigWin();
			if (Score != 100)
				return Score;//3.76 
			vector<int> emp;
			if (AvailableBoard(Index)) {
				emp = B[Index - 1].Empty();
				for (auto x : emp) {
					int v = Minmax(Index - 1, x, Depth - 1, alpha, beta, !Turn);

					if (Depth != 1)
						Undo(Index, x, !Turn);
					CheckerBoard();

					Max   = max(Max, v);
					alpha = max(alpha, Max);
					if (beta <= alpha)
						break;
				}
				return Max;
			}
			else
			{
				for (int i = 1; i <= 9; i++)
				{
					vector<int> em = All(i);
					for (auto x : em) {
						int v = Minmax(i - 1, x, Depth - 1, alpha, beta, !Turn);

						if (Depth != 1)
							Undo(i, x, !Turn);
						CheckerBoard();
						Max = max(Max, v);
						alpha = max(alpha, Max);
						if (beta <= alpha)
							break;
					}
				}
				return Max;
			}
		}
	}
	void Start() {
		cout << "Choose a board to play on" << endl;
		int Table, Index = 0;
		bool Taken = false;
		while (true) {
			cin >> Table;
			if (Table > 0 && Table < 10)
				break;
			cout << "choose from 1-9 you smart" << endl;
		}
		while (true) {

			if (Taken) {
				while (true) {
					cout << "Choose a board to play on" << endl;
					cin >> Table;
					if (Table > 0 && Table < 10 && AvailableBoard(Table)) {
						Taken = false;
						break;
					}
					cout << "Invaild Input , try again." << endl;
				}
			}
			cout << "You are on board number " << Table << " Choose an Index to play on" << endl;
			while (true) {

				cin >> Index;
				if (CheckerIndex(Table, Index) && Index > 0 && Index < 10)
					break;
				cout << "This postion is unavailable, choose another one" << endl;
			}
			Play(Table, Index, turn);
			CheckerBoard();
			if (BigWin() == 10) {
				cout << "X IS THE CHAMPION";
				break;
			}
			else
				if (BigWin() == -10) {
					cout << "O IS THE CHAMPION";
					break;
				}
           else
           if (BigWin() == 0) {
					cout << "Tie";
					break;
				}
			turn = !turn;

			int best = 999999, ind = -1;
			vector<int> emp;
			if (AvailableBoard(Index)) {
				emp = B[Index - 1].Empty();
				for (auto x : emp) {
					int v = Minmax(Index - 1, x, 6, -99999999, 99999999, turn);
					Undo(Index, x, turn);
					CheckerBoard();
					if (v < best) {
						best = v;
						ind = x;
					}
				}
			}
			else
			{
				for (int i = 1; i <= 9; i++)
				{
					vector<int> em = All(i);
					for (auto x : em) {
						int v = Minmax(i - 1, x, 6, -99999999, 99999999, turn);
						Undo(i, x, turn);
						CheckerBoard();
						if (v < best) {
							best = v;
							ind = x;
							Index = i;
						}
					}
				}
			}
			cout << "AI Played on board " << Index << " and on index " << ind << endl;
			Play(Index, ind, turn);
			Print();
			turn = !turn;
      			CheckerBoard();

			if (Wx[ind] == 1 || Wo[ind] == 1 || Tie[ind] == 1)
				Taken = true;
			else
				Table = ind;

			if (BigWin() == 2000) {
				cout << "X IS THE CHAMPION";
				break;
			}
			else
				if (BigWin() == -2000) {
					cout << "O IS THE CHAMPION";
					break;
				} else
           if (BigWin() == 0) {
					cout << "Tie";
					break;
				}


		}

	}
};

int main() {
	Ultimate s;
	s.Start();
	return 0;
}
