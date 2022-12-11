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
We created two classes (Board & Ultimate).<br>
Class Board : <br>
<ol>
  <li>Array of character with size of 9 which presents the indices of the game board.</li>
  <li>Two vectors (X,O) : each of them saves the moves of the player in the active board. </li>
  <li>Constructor initializes the boards (1-9).</li>
  <li>Undo function : takes two parameters (int index, bool turn), replace the index with a  character that represents the position of the index and pops out an element from the vector (depends on the turn).</li>
  <li>Play function : takes two parameters (int index, bool turn), edits the board by replacing the index with (X,O) depends on the turn.</li>
  <li>Score function : returns the score of the current board such as : <br>
      <ul>
        <li>‘1’ represents X won.</li>
        <li>‘-1’ represents O won.</li>
        <li>‘0’ represents Tie.</li>
    </ul>
  </li>
  <li>Empty function : returns a vector with all the available moves</li>
  <li>Check function : takes one parameter (int index), checks if the current index is available or not.</li>
  <li>PrintUp function : prints the first row.</li>
  <li>PrintMid function : prints the second row</li>
  <li>PrintDown function : prints the last row.</li>
  <li>12.	CheckXO function : takes one parameter (int index), returns ‘1’ if the index in the board is (X), returns ‘-1’ if the index in the board is (O) and returns ‘zero’ if the index is empty.</li>
  <li>13.	CalculaterSmall function : calculates the average of the current board by doing this:
First of all, stores the positions of  X and O in array , then check if there is any close spot to win like “1, zero ,1” (in the array 1 is X, zero is empty) and adds 2 to the average.<br>
 if there is a spot like (zero, 1 ,zero) adds 1 to the average and then returns the total average of the current board.
</ol>
