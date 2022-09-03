# Claude-A-Chess-Engine
This is my first attempt at making a chess engine. This project was undertaken to further my knowledge of C/C++.

The engine is now fully functionally and the engine is uci and xboard compatible with a console mode and a gui mode. This chess engine is compatible with chess GUIs like [Arena](http://www.playwitharena.de) and WinBoard. This engine was created with inspiration from many resources like the chess programming wiki, chess programming forums, [BlueFever's YouTube channel](https://www.youtube.com/user/BlueFeverSoft), and the source code of other engines like TCSP and Nero.

This engine features:
  * An Alpha-Beta Search and Quiesence Search (eliminate the horizon effect)
  * BitBoard representation of the board state and pawns
  * Move Evaluation and assigned scores for all pieces
  * Move Ordering (Most Valuable Victim Least Valuable Attacker)
  * Killer Heuristic that plays quiet moves depending on the beta cutoff
  * A Hashtable data structure that stores the principal variation moves and allows for quick lookup of past moves to increase search efficiency and improve time management
  
Things to consider adding to the engine in the future:
  * Time Managment
  * Root move ordering
  * Improve the evaluation method
  * Improving and tweaking the search method
