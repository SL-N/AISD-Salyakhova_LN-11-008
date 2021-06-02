#include <iostream>

using namespace std;

int naiveSearch(string& pattern, string& input)
  {
      int j = 0;
      for (int i = 0; i <= input.length() - pattern.length(); i++)
      {
          for (j = 0; j < pattern.length(); j++)

              if (input[i + j] != pattern[j])
                  break;

          if (j == pattern.length())
              return i;
      }
      return -1;
  }


int hInit(unsigned int strLen) {
  int d = 52;
  int  p = 65713;

  int h = 1;
  for(unsigned int i=1; i < strLen; i++) {
    h = (h*d) % p;
  }

  return h;
}

int ringHash(char* str, unsigned int strLen, int prevHash, int *h) {
  int d = 52;
  int  p = 65713;

  if(*h == 0) {
    *h = hInit(strLen);
  }

  if(prevHash == 0) {
    for(unsigned int i=0; i<strLen; i++) {
      prevHash += (d*prevHash + (int)str[i]) % p;
    }
    if(prevHash < 0) {
      prevHash += p;
    }

    return prevHash;
  }
  else {
    int hash = (d * (prevHash - (int)str[0] * (*h)) + (int)str[strLen]) % p;
    if(hash < 0) {
      hash += p;
    }

    return hash;
  }
}

int rabinKarpSearch(char* text, char* str) {
  unsigned int strLen = strlen(str);
  unsigned int textLen = strlen(text);
  int h = 0;

  int strHash = ringHash(str, strLen, 0, &h);
  int textHash = ringHash(text, strLen, 0, &h);

  for(unsigned int k = 0; k <= (textLen-strLen); k++) {
    if(strHash == textHash) {
      for(unsigned int i = 0; (i < strLen) && (str[i] == text[k+i]); i++) {
        if(i == (strLen-1)) {
          return k;
        }
      }
    }
    textHash = ringHash(&text[k], strLen, textHash, &h);
  }
  return -1;
}
