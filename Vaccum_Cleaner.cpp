#include <iostream>

using namespace std;

int main() {
   int floor[5][5] = { {0, 0, 0, 0, 0},   // 0 represents a clean tile
                       {0, 1, 0, 1, 0},   // 1 represents a dirty tile
                       {0, 0, 1, 0, 0},
                       {1, 0, 0, 1, 1},
                       {0, 0, 0, 1, 0} };
   int row = 0, col = 0;  // start at the top left corner
   int cleaned = 0;       // number of cleaned tiles

   while (cleaned < 15) {   // continue until all 15 tiles are cleaned
      // clean the current tile
      floor[row][col] = 0;
      cleaned++;

      // move to the next tile
      if (row % 2 == 0) {  // even rows move right
         if (col < 4) {
            col++;
         }
         else {  // at the end of a row, move down
            row++;
         }
      }
      else {  // odd rows move left
         if (col > 0) {
            col--;
         }
         else {  // at the end of a row, move down
            row++;
         }
      }
   }

   cout << "Cleaning complete. " << cleaned << " tiles cleaned." << endl;
   
   return 0;
}
