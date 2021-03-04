#include <algorithm>

using namespace std;
int isSameReflection(char* word1, char* word2) {
  reverse(word1, word1+strlen(word1));

  if (strcmp(word1,word2)) {
    return -1;
  }
  return 1;
}

