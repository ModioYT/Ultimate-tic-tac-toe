# Ultimate Tic Tac Toe Game
<h1>Before you continue , Check this website to read the game rules:</h1>
https://www.thegamegal.com/2018/09/01/ultimate-tic-tac-toe/

<h1>Ultimate tic tac toe game prject details: </h1>
<p>First of all the goal of this project was to practice the <b>MiniMax & Alpha-Beta Pruning</b> Algorithm and try to implement an advanced level of tic tac toe.</p>
<h1>Our Algorithm achievements :</h1>
<p>We test our Algorithm by playing verses another AI , so far we have beaten an Extremely-hard AI which is a proof that our algorithm is working :))</p>

![image](https://user-images.githubusercontent.com/97745482/206928468-34df200f-7ab9-485b-88e9-106ec143a6df.png)

<h1>Code explanation step by step : </h1>
<p>What we did is simple:<br>
We created two classes (Board & Ultimate).<br></p>
<h1>Class Board :</h1>
 <p>
<ol>
  <li>Array of character with size of 9 which presents the indices of the game board.</li>
  <li>Two vectors (X,O) : each of them saves the moves of the player in the active board. </li>
  <li><h3>Constructor :</h3> initializes the boards (1-9).</li>
  <li><h3>Undo function : </h3>takes two parameters (int index, bool turn), replace the index with a  character that represents the position of the index and pops out an element from the vector (depends on the turn).</li>
  <li><h3>Play function :</h3> takes two parameters (int index, bool turn), edits the board by replacing the index with (X,O) depends on the turn.</li>
  <li><h3>Score function : </h3>returns the score of the current board such as : <br>
      <ul>
        <li>‘1’ represents X won.</li>
        <li>‘-1’ represents O won.</li>
        <li>‘0’ represents Tie.</li>
    </ul>
  </li>
  <li><h3>Empty function : </h3>returns a vector with all the available moves</li>
  <li><h3>Check function :</h3> takes one parameter (int index), checks if the current index is available or not.</li>
  <li><h3>PrintUp function :</h3> prints the first row.</li>
  <li><h3>PrintMid function :</h3> prints the second row</li>
  <li><h3>PrintDown function :</h3> prints the last row.</li>
  <li><h3>CheckXO function :</h3> takes one parameter (int index), returns ‘1’ if the index in the board is (X), returns ‘-1’ if the index in the board is (O) and returns ‘zero’ if the index is empty.</li>
  <li><h3>CalculaterSmall function :</h3> calculates the average of the current board by doing this:
First of all, stores the positions of  X and O in array , then check if there is any close spot to win like “1, zero ,1” (in the array 1 is X, zero is empty) and adds 2 to the average.<br>
 if there is a spot like (zero, 1 ,zero) adds 1 to the average and then returns the total average of the current board.
  </ol>
 </p>
<h1>Class Ultimate :</h1>
<ol>
  <li>We defined an array (B) of type “Board” with size of 9 which represents the single boards on the screen.</li>
  <li>We defined a Boolean “turn” which represents the current turn.</li>
  <li>We defined 3 maps of type <int, int> : </li>
  <ul>
    <li>Wx : stores which board ‘X’ closed</li>
    <li>Wo : stores which board ‘O’ closed.</li>
    <li>Tie : stores which board has no available indices to play on (full board).</li>
  </ul>
  <li><h3>Undo function :</h3> takes three parameters (int Board, int Index,  int Turn), this function uses the  parameter (Board)-1  to call the correct small board in “B”, then it calls the function undo in the object B (Board) and sends Index and Turn as parameters.</li>
  <li><h3>Constructor Ultimate :</h3> initialize the turn with 1 and initialize the maps (Wx,Wo,Tie) to -1.</li>
  <li><h3>Print function :</h3> prints each single board on the screen.</li>
  <li><h3>Play function :</h3> takes three parameters (int Board, int Index, bool T), this function uses the  parameter (Board)-1  to call the correct small board in “B”, then it calls the function play in the object B (Board) and sends Index and T as parameters.</li>
  <li><h3>CheckerBoard function :</h3> loops all the boards in ‘B’ and checks if the board is closed or not by calling the score function in ‘B’ :
    <ul>
      <li>If it was zero assign one to map Tie with key (iterator+1).</li>
      <li>If it was 1 assign one to map Wx with key (iterator+1).</li>
      <li>If it was -1 assign one to map Wo with key (iterator+1).</li>
      <li>else, assign -1 to Wx & Wo & Tie with key (iterator+1).</li>
    </ul>
  </li>
  <li><h3>CheckerIndex :</h3> takes two parameters (int Board, int Index), checks if the Index on the B[Board-1] is available by calling check function in object ‘B’ and returns its value.</li>
  <li><h3>AvailableBoard : </h3>takes one parameter (int ind), checks if the score of B[ind-1] is equal 10 (available to play) return true, otherwise return false.</li>
  <li><h3>BigWin function :</h3> checks if there are any winner in the game by using the maps (Wx, Wo, Tie) : 
    <ul>
      <li>If the winner was X return 2000.</li>
      <li>If the winner was O return -2000.</li>
      <li>If there is no winner in the game loop and check all the indices if there is a -1 return 100, which means the board is available to play, else return zero which means Tie.</li>
    </ul></li>
  <li><h3>Calculater function (it wasn’t perfect) :</h3> we defined an int AVG and array of integers with size of 9 (Scores[9]), and calls the function CheckerBoard (to update{ Wx, Wo, Tie } to get the final board status), loops from 0 to 9 and do this:
    <ul>
      <li>If Wx[a+1] equals 1, assign 15 to Scores[a].</li>
      <li>If Wo[a+1] equals 1, assign -15 to Scores[a].</li>
      <li>If Tie[a+1] equals 1, assign -999999 (which means this board is closed) to Scores[a].</li>
      <li>Else calls the function CalculaterSmall from B[a] and assign the results to Scores[a].</li>
    </ul>
  Loops from 0 to 9 and  if Scores[i] is not equal to -999999 add the Scores[i] value to AVG , finally returns AVG.</li>
  <li>1All function :takes one parameter (int index), define a vector of type int with size zero called emp and calls the function AvailableBoard with parameter index if the result was true returns emp, otherwise calls the Empty function from B[index-1] , assign it to emp  and returns emp.</li>
  <li><h3>Minimax function (Alpha Beta Pruning ) : takes six parameters (int table, int Index, int Depth, int alpha, int beta, bool Turn)</h3>
  First of all, we defined int Max = - INT_MAX, Min = INT_MAX, the base case is if the Depth = zero, it returns the result of calling the function Calculator , If the Turn was one:
    <ul>
      <li>Calls the function play in the object B[table] and sends Index and Turn.</li>
      <li>Calls the CheckerBoard function.</li>
      <li>We defined an int (Score) and saved the result of calling the BigWin function in it, if the Score != 100 return the Score.</li>
      <li>We defined a vector of int (emp), we check if the board is available by calling AvailableBoard function and pass the Index as a parameter, if it is true :
        <ul>
          <li>Assign B[Index-1].Empty() to emp.</li>
          <li>Loops on the emp elements { for(auto x : emp)}, defined int v and assign the result of the Minmax(Index-1, x, Depth-1, alpha, beta, !Turn).</li>
          <li>Inside the loop; if the Depth != 1, calls the Undo(Index, x, !Turn).</li>
          <li>Inside the loop; calls the CheckerBoard function, assign the minimum value between v & Min to Min, Min = min(v,Min), assign the minimum value between beta & Min to beta, beta = min(beta,Min).
</li>
          <li>If (beta <= alpha) breaks from the loop.</li>
          <li>Return Min.</li>
        </ul>
        If the result of the AvailableBoard function was false : 
    </ul>
  </li>
  <li></li>
  <li></li>
  



</ol>

