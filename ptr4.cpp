#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int ran[4] = {2, 2, 2, 4};
struct Player
{
	int score;
	string name;
};
Player player[100];
int score = 0;
int counter = 0;
void menu();
Digit(int x)
{
	int cnt = 0;
	while (x) 
	{
		x /= 10;
		cnt++;
	}
	if (cnt == 0)
		cnt++;
	return cnt;
}
void up(int arry[4][4])
{
	int row, column;
	for(int j = 0; j < 4; j++)
	{
		row = 0;
		column = j;
		for(int i = 1; i < 4; i++)
		{
			if(arry[i][j] != 0)
			{
				if(arry[i-1][j] == 0 || arry[i-1][j] == arry[i][j])
				{
					if(arry[row][column] == arry[i][j])
					{
						arry[row][column] *= 2;
						arry[i][j] = 0;
						score += arry[row][column];
					}
					else
					{
						if(arry[row][column] == 0)
						{
							arry[row][column] = arry[i][j];
							arry[i][j] = 0;
						}
						else
						{
							arry[++row][column] = arry[i][j];
							arry[i][j] = 0;
						}
					}
					score += arry[row][column];
				}
				else row++;
			}
		}
	}
}

void down(int arry[4][4])
{
	int row, column;
	for(int j = 0; j < 4; j++)
	{
		row = 3;
		column = j;
		for(int i = 2; 0<= i; i--)
		{
			if(arry[i][j] != 0)
			{
				if(arry[i+1][j] == 0 || arry[i+1][j] == arry[i][j])
				{
					if(arry[row][column] == arry[i][j])
					{
						arry[row][column] *= 2;
						arry[i][j] = 0;
					}
					else
					{
						if(arry [row][column] == 0)
						{
							arry[row][column] = arry[i][j];
							arry[i][j] = 0;
						}
						else
						{
							arry[--row][column] = arry[i][j];
							arry[i][j] = 0;
						}
					}
					score += arry[row][column];
				}
				else row--;
			}
		}
	}
}

void left(int arry[4][4])
{
	int row, column;
	for(int i = 0; i < 4; i++)
	{
		row = i;
		column = 0;
		for(int j = 1; j < 4; j++)
		{
			if(arry[i][j] != 0)
			{
				if(arry[i][j-1] == 0 || arry[i][j-1] == arry[i][j])
				{
					if(arry[row][column] == arry[i][j])
					{
						arry[row][column] *= 2;
						arry[i][j] = 0;
					}
					else
					{
						if(arry[row][column] == 0)
						{
							arry[row][column] = arry[i][j];
							arry[i][j] = 0;
						}
						else
						{
							arry[row][++column] = arry[i][j];
							arry[i][j] = 0;
						}
					}
					score += arry[row][column];
				}
				else column++;
			}
		}
	}
}

void right(int arry[4][4])
{
	int row, column;
	for(int i = 0; i < 4; i++)
	{
		row = i;
		column = 3;
		for(int j = 2; 0 <= j; j--)
		{
			if(arry[i][j] != 0)
			{
				if(arry[i][j+1] == 0 || arry[i][j+1] == arry[i][j])
				{
					if(arry[row][column] == arry[i][j])
					{
						arry[row][column] *= 2;
						arry[i][j] = 0;
					}
					else
					{
						if(arry[row][column] == 0)
						{
							arry[row][column] = arry[i][j];
							arry[i][j] = 0;
						}
						else
						{
							arry[row][--column] = arry[i][j];
							arry[i][j] = 0;
						}
					}
					score += arry[row][column];
				}
				else column--;
			}
		}
	}
}

void addblock(int arry[4][4])
{
	int row, column;
	srand(time(0));
	while(1)
	{
		row = rand() % 4;
		column = rand() % 4;
		if(arry[row][column] == 0)
		{
			arry[row][column] = ran[rand() % 4];
			break;
		}
	}

}

void disp(int arry[4][4])
{
	//line 1
cout << '\n';
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << "\n\n";

cout << " \u2503  ";
if(arry[0][0] == 0)
    cout << ' ';
else 
{
    if(arry[0][0] == 2)
        cout << "\033[0;31m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 4)
        cout << "\033[0;32m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 8)
        cout << "\033[0;33m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 16)
        cout << "\033[0;34m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 32)
        cout << "\033[0;35m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 64)
        cout << "\033[0;36m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 128)
        cout << "\033[0;44m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 256)
        cout << "\033[0;41m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 512)
        cout << "\033[0;42m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 1024)
        cout << "\033[0;45m" << arry[0][0] << "\033[0m";
    else if(arry[0][0] == 2048)
        cout << "\033[0;46m" << arry[0][0] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[0][0])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[0][1] == 0)
    cout << ' ';
else 
{
    if(arry[0][1] == 2)
        cout << "\033[0;31m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 4)
        cout << "\033[0;32m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 8)
        cout << "\033[0;33m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 16)
        cout << "\033[0;34m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 32)
        cout << "\033[0;35m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 64)
        cout << "\033[0;36m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 128)
        cout << "\033[0;44m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 256)
        cout << "\033[0;41m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 512)
        cout << "\033[0;42m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 1024)
        cout << "\033[0;45m" << arry[0][1] << "\033[0m";
    else if(arry[0][1] == 2048)
        cout << "\033[0;46m" << arry[0][1] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[0][1])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[0][2] == 0)
    cout <<"\033[0;31m" << ' ' <<"\033[0m";
else 
{
    if(arry[0][2] == 2)
        cout << "\033[0;31m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 4)
        cout << "\033[0;32m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 8)
        cout << "\033[0;33m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 16)
        cout << "\033[0;34m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 32)
        cout << "\033[0;35m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 64)
        cout << "\033[0;36m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 128)
        cout << "\033[0;44m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 256)
        cout << "\033[0;41m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 512)
        cout << "\033[0;42m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 1024)
        cout << "\033[0;45m" << arry[0][2] << "\033[0m";
    else if(arry[0][2] == 2048)
        cout << "\033[0;41m" << arry[0][2] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[0][2])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[0][3] == 0)
    cout << ' ';
else 
{
    if(arry[0][3] == 2)
        cout << "\033[0;31m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 4)
        cout << "\033[0;32m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 8)
        cout << "\033[0;33m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 16)
        cout << "\033[0;34m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 32)
        cout << "\033[0;35m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 64)
        cout << "\033[0;36m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 128)
        cout << "\033[0;44m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 256)
        cout << "\033[0;41m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 512)
        cout << "\033[0;42m"<< arry[0][3]  << "\033[0m";
    else if(arry[0][3] == 1024)
        cout << "\033[0;45m" << arry[0][3] << "\033[0m";
    else if(arry[0][3] == 2048)
        cout << "\033[0;46m" << arry[0][3] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[0][3])); i++)
    cout << ' ';
cout << "\u2503  ";//6 2 space
cout << "\n\n";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << "\n\n";
 //line2
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << "\n\n";

cout << " \u2503  ";
if(arry[1][0] == 0)
    cout << ' ';
else 
{
    if(arry[1][0] == 2)
        cout << "\033[0;31m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 4)
        cout << "\033[0;32m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 8)
        cout << "\033[0;33m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 16)
        cout << "\033[0;34m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 32)
        cout << "\033[0;35m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 64)
        cout << "\033[0;36m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 128)
        cout << "\033[0;44m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 256)
        cout << "\033[0;41m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 512)
        cout << "\033[0;42m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 1024)
        cout << "\033[0;45m" << arry[1][0] << "\033[0m";
    else if(arry[1][0] == 2048)
        cout << "\033[0;46m" << arry[1][0] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[1][0])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[1][1] == 0)
    cout << ' ';
else 
{
    if(arry[1][1] == 2)
        cout << "\033[0;31m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 4)
        cout << "\033[0;32m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 8)
        cout << "\033[0;33m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 16)
        cout << "\033[0;34m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 32)
        cout << "\033[0;35m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 64)
        cout << "\033[0;36m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 128)
        cout << "\033[0;44m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 256)
        cout << "\033[0;41m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 512)
        cout << "\033[0;42m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 1024)
        cout << "\033[0;45m" << arry[1][1] << "\033[0m";
    else if(arry[1][1] == 2048)
        cout << "\033[046" << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[1][1])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[1][2] == 0)
    cout << ' ';
else 
{
    if(arry[1][2] == 2)
        cout << "\033[0;31m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 4)
        cout << "\033[0;32m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 8)
        cout << "\033[0;33m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 16)
        cout << "\033[0;34m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 32)
        cout << "\033[0;35m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 64)
        cout << "\033[0;36m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 128)
        cout << "\033[0;44m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 256)
        cout << "\033[0;41m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 512)
        cout << "\033[0;42m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 1024)
        cout << "\033[0;45m" << arry[1][2] << "\033[0m";
    else if(arry[1][2] == 2048)
        cout << "\033[0;46m" << arry[1][2] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[1][2])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[1][3] == 0)
    cout << ' ';
else 
{
    if(arry[1][3] == 2)
        cout << "\033[0;31m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 4)
        cout << "\033[0;32m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 8)
        cout << "\033[0;33m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 16)
        cout << "\033[0;34m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 32)
        cout << "\033[0;35m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 64)
        cout << "\033[0;36m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 128)
        cout << "\033[0;44m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 256)
        cout << "\033[0;41m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 512)
        cout << "\033[0;42m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 1024)
        cout << "\033[0;45m" << arry[1][3] << "\033[0m";
    else if(arry[1][3] == 2048)
        cout << "\033[0;46m" << arry[1][3] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[1][3])); i++)
    cout << ' ';
cout << "\u2503  ";//6 2 space
cout << "\n\n";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << "\n\n";
 //line3
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << "\n\n";

cout << " \u2503  ";
if(arry[2][0] == 0)
    cout << ' ';
else 
{
    if(arry[2][0] == 2)
        cout << "\033[0;31m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 4)
        cout << "\033[0;32m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 8)
        cout << "\033[0;33m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 16)
        cout << "\033[0;34m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 32)
        cout << "\033[0;35m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 64)
        cout << "\033[0;36m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 128)
        cout << "\033[0;44m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 256)
        cout << "\033[0;41m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 512)
        cout << "\033[0;42m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 1024)
        cout << "\033[0;45m" << arry[2][0] << "\033[0m";
    else if(arry[2][0] == 2048)
        cout << "\033[0;46m" << arry[2][0] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[2][0])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[2][1] == 0)
    cout << ' ';
else 
{
    if(arry[2][1] == 2)
        cout << "\033[0;31m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 4)
        cout << "\033[0;32m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 8)
        cout << "\033[0;33m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 16)
        cout << "\033[0;34m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 32)
        cout << "\033[0;35m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 64)
        cout << "\033[0;36m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 128)
        cout << "\033[0;44m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 256)
        cout << "\033[0;41m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 512)
        cout << "\033[0;42m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 1024)
        cout << "\033[0;45m" << arry[2][1] << "\033[0m";
    else if(arry[2][1] == 2048)
        cout << "\033[0;46m" << arry[2][1] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[2][1])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[2][2] == 0)
    cout << ' ';
else 
{
    if(arry[2][2] == 2)
        cout << "\033[0;31m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 4)
        cout << "\033[0;32m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 8)
        cout << "\033[0;33m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 16)
        cout << "\033[0;34m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 32)
        cout << "\033[0;35m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 64)
        cout << "\033[0;36m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 128)
        cout << "\033[0;44m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 256)
        cout << "\033[0;41m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 512)
        cout << "\033[0;42m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 1024)
        cout << "\033[0;45m" << arry[2][2] << "\033[0m";
    else if(arry[2][2] == 2048)
        cout << "\033[0;46m" << arry[2][2] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[2][2])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[2][3] == 0)
    cout << ' ';
else 
{
    if(arry[2][3] == 2)
        cout << "\033[0;31m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 4)
        cout << "\033[0;32m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 8)
        cout << "\033[0;33m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 16)
        cout << "\033[0;34m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 32)
        cout << "\033[0;35m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 64)
        cout << "\033[0;36m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 128)
        cout << "\033[0;44m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 256)
        cout << "\033[0;41m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 512)
        cout << "\033[0;42m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 1024)
        cout << "\033[0;45m" << arry[2][3] << "\033[0m";
    else if(arry[2][3] == 2048)
        cout << "\033[0;46m" << arry[2][3] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[2][3])); i++)
    cout << ' ';
cout << "\u2503  ";//6 2 space
cout << "\n\n";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << "\n\n";

cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << " \u250D\u2501\u2501\u2501\u2501\u2501\u2501\u2513  ";
cout << "\n\n";
 //line4	
cout << " \u2503  ";
if(arry[3][0] == 0)
    cout << ' ';
else 
{
    if(arry[3][0] == 2)
        cout << "\033[0;31m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 4)
        cout << "\033[0;32m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 8)
        cout << "\033[0;33m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 16)
        cout << "\033[0;34m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 32)
        cout << "\033[0;35m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 64)
        cout << "\033[0;36m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 128)
        cout << "\033[0;44m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 256)
        cout << "\033[0;41m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 512)
        cout << "\033[0;42m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 1024)
        cout << "\033[0;45m" << arry[3][0] << "\033[0m";
    else if(arry[3][0] == 2048)
        cout << "\033[0;46m" << arry[3][0] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[4][0])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[3][1] == 0)
    cout << ' ';
else 
{
    if(arry[3][1] == 2)
        cout << "\033[0;31m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 4)
        cout << "\033[0;32m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 8)
        cout << "\033[0;33m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 16)
        cout << "\033[0;34m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 32)
        cout << "\033[0;35m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 64)
        cout << "\033[0;36m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 128)
        cout << "\033[0;44m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 256)
        cout << "\033[0;41m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 512)
        cout << "\033[0;42m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 1024)
        cout << "\033[0;45m" << arry[3][1] << "\033[0m";
    else if(arry[3][1] == 2048)
        cout << "\033[0;46m" << arry[3][1] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[3][1])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[3][2] == 0)
    cout << ' ';
else 
{
    if(arry[3][2] == 2)
        cout << "\033[0;31m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 4)
        cout << "\033[0;32m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 8)
        cout << "\033[0;33m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 16)
        cout << "\033[0;34m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 32)
        cout << "\033[0;35m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 64)
        cout << "\033[0;36m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 128)
        cout << "\033[0;44m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 256)
        cout << "\033[0;41m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 512)
        cout << "\033[0;42m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 1024)
        cout << "\033[0;45m" << arry[3][2] << "\033[0m";
    else if(arry[3][2] == 2048)
        cout << "\033[0;46m" << arry[3][2] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[3][2])); i++)
    cout << ' ';
cout << "\u2503  ";
cout << " \u2503  ";
if(arry[3][3] == 0)
    cout << ' ';
else 
{
    if(arry[3][3] == 2)
        cout << "\033[0;31m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 4)
        cout << "\033[0;32m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 8)
        cout << "\033[0;33m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 16)
        cout << "\033[0;34m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 32)
        cout << "\033[0;35m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 64)
        cout << "\033[0;36m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 128)
        cout << "\033[0;44m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 256)
        cout << "\033[041m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 512)
        cout << "\033[0;42m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 1024)
        cout << "\033[0;45m" << arry[3][3] << "\033[0m";
    else if(arry[3][3] == 2048)
        cout << "\033[0;46m" << arry[3][3] << "\033[0m";
}
for (int i = 1; i <= (4 - Digit(arry[3][3])); i++)
    cout << ' ';
cout << "\u2503  ";//6 2 space
cout << "\n\n";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << " \u2517\u2501\u2501\u2501\u2501\u2501\u2501\u251B  ";
cout << "\n\n";
}

int check(int tmp[4][4],int arry[4][4])
{
	int fl=1,i,j;
	for(int i = 0; i < 4; i++)
    	for(int j = 0; j < 4; j++)
    		if(tmp[i][j] != arry[i][j])
    		{
    			fl = 0;
    			break;
			}
	return fl;
}

int checkover(int arry[4][4])
{
	int fl = 0, gl = 0, i, j;
	for(i = 0; i < 4; i++)
    	for(int j = 0; j < 4; j++)
    		if(arry[i][j] == 0)
    		{
    			fl = 1;
				break;
			}

	for(i = 0; i < 3; i++)
    	for(int j = 0; j < 3; j++)
    		if(arry[i+1][j] == arry[i][j] || arry[i][j+1] == arry[i][j])
    		{
    			gl = 1;
    			break;
			}

	if(fl || gl) return 1;
	else return 0;
}
void menu()
{
	cout << "\033[0;36m" << "2048 is a single-player and puzzle game.\nThe goal of the game is to reach 2048 by using tiles with a power of two on each of them.\n";
	cout << "\033[0m";
	cout << "\033[0;33m" << "\n1)New game.\n";
	cout << "\n2)Leaderboard.\n";
	cout <<"\n3)Exit.\n" << "\033[0m";
}
int main()
{
	while(1)
	{

		int option;
		cout<< "\033[0;35m" << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue" << "\033[0m";
		getch();
		system("cls");
		menu();
		cin >> option;
		if(option == 1)
		{
			counter++;
			system("cls");
			cout << "What is your name? \n";
			cin >> player[counter].name;
			system("cls");
		}
		if(option == 2)
		{
			system("cls");
			for (int i = counter; 0 < i; i--)
			{
				cout << "name : " << player[i].name << "  " << "score : " << player[i].score << '\n';
			}
			cout << "\n\n\nMenu? \nEnter 2\n";
			int enter;
			cin >> enter;
			while (enter != 2)
				cin >> enter;
			system("cls");
			continue;
		}
		else if(option == 3)
		{
			system("cls");
			exit(0);
		}
		int i1,i2,i3,i4;
		int arry[4][4] = {0}, tmp[4][4] = {0};
		srand(time(0));
		i1 = rand() % 4;
		i2 = rand() % 4;
		while(1)
		{
			i3 = rand() % 4;
			i4 = rand() % 4;	
			if(i3 != i1 && i4 != i2)
				break;
		}
		arry[i1][i2] = ran[rand() % 4];
		arry[i3][i4] = ran[rand() % 4];
		cout<<"\n\t\tPress WASD to quit the game";
		cout<<"\n\n\n\n";
		getch();
		system("cls");
		disp(arry);
		int move;
		while (1)
    	{
    		for(int i = 0; i < 4; i++)
    			for(int j = 0; j < 4; j++)
    				tmp[i][j] = arry[i][j];
    		move = getch();
    		system("cls");
    		if(move == 119 || move == 72)
				up(arry);
	    	if(move == 115 || move == 80)
				down(arry);
	    	if(move == 97 || move == 75)
				left(arry);
	    	if(move == 100 || move == 77)
				right(arry);
			if(move == 27) 
				break;
			if(!check(tmp, arry))
				addblock(arry);
			disp(arry);
			if(!checkover(arry))
			{
				system("cls");
				cout << "\033[0;31m" << "\n\n\t\t\tGAME OVER!!!\n\n\n" << "\033[0m";
				player[counter].score = score;
				int counterr = counter - 1;
				while (counterr >= 1 && player[counterr].score < player[counterr + 1].score)
				{
					swap(player[counterr], player[counterr + 1]);
					counterr--;
				}
				cout << "Menu? \nEnter 2\n";
				int enter;
				cin >> enter;
				while (enter != 2)
					cin >> enter;
				system("cls");
				break;
			}
			else
			{
				int number = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (arry[i][j] == 2048)
						{
							number++;
						}
					}
				}
				if (number > 0)
				{
					cout << "\033[0;36m" << "Winner" << "\033[0m";
					int random_character;
					cin >> random_character;
					system ("cls");
					menu();
				}
			}
		}
	}

	return 0;
}