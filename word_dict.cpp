#include <iostream>
#include <vector>
#include <string>
#define MAX 3
using namespace std;

vector<string> dict;

int move[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void find_word(int node)
{

    vector<int> stack;
    stack.push_back(node);
    while (!stack.empty())
    {
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, r, c;
        cin >> w >> r >> c;
        for (int i = 0; i < w; i++)
        {
            string newWord;
            cin >> newWord;
            dict.push_back(newWord);
        }
        string letters[MAX][MAX];

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> letters[i][j];
            }
        }

        dict.clear();
    }
}