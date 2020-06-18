#include <iostream>
// #include <string>
using namespace std;

string shorten_word(string word)
{
  if (word.length() <= 10)
  {
    return word;
  }
  else
  {
    int len{word.length() - 2};
    string result;
    result = word[0] + to_string(len) + word[word.length() - 1];
    return result;
  }
}

int main()
{
  int n{};
  cin >> n;

  string alist[n];
  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    alist[i] = shorten_word(s);
  }

  for (auto const &value : alist)
  {
    cout << value << "\n";
  }

  return 0;
}
