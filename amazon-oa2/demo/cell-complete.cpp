// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
using namespace std;
int* cellCompete(int* cells, int days)
{
  int* c1 = new int[8];
  for (int i = 0; i < 8; ++i) {
    c1[i] = cells[i];
  }
  int c2[8] = {};

  for (int i = 0; i < days; ++i) {
    if (c1[0] == 1 && c1[1] == 0) {
      c2[0] = 0;
    }
    if (c1[7] == 1 && c1[6] == 0) {
      c2[7] = 0;
    }

    for (int j = 1; j < 6; ++j) {
      if ( c1[j-1] == c1[j+1]) {
        c2[j] = 0;
        continue;
      }
      c2[j] = 1;
    }

    for (int k = 0; k < 8; ++k) {
      c1[k] = c2[k];
    }
  }

  return c1;
}
// FUNCTION SIGNATURE ENDS

