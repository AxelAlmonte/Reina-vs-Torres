/*

Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- ⁠Octavio Ramírez - 1132995
- ⁠José Pinales - 1133255
- Christian Acosta - 1132698

*/
#include <iostream>
#include <string>
using namespace std;

void InicializarTablero(char tablero[8][8], int t[2][2], int rx, int ry)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero[i][j] = ' ';
		}
	}
	tablero[rx][ry] = 'Q';
	tablero[t[0][0]][t[0][1]] = 'T';
	tablero[t[1][0]][t[1][1]] = 'T';
}
void ImprimirTablero(char tablero[8][8])
{
	cout << "    A  B  C  D  E  F  G  H " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << "  |";
		for (int j = 0; j < 8; j++)
		{
			cout << tablero[i][j] << " |";
		}
		cout << endl;
	}
}

int main()
{
	char tablero[8][8];
	int t[2][2];
	int rx;
	int ry;
	cout << "Reina vs Torres" << endl;
	do {
		cout << "Inserte la fila de la primera torre: ";
		cin >> t[0][0]; t[0][0]--;
		cout << "Inserte la columna de la primera torre: ";
		cin >> t[0][1]; t[0][1]--;
	} while (t[0][0] < 0 || t[0][0] > 7 || t[0][1] < 0 || t[0][1] > 7);
	do {
		cout << "Inserte la fila de la segunda torre: ";
		cin >> t[1][0]; t[1][0]--;
		cout << "Inserte la columna de la segunda torre: ";
		cin >> t[1][1]; t[1][1]--;
		
	} while ((t[1][0] == t[0][0] && t[1][1] == t[0][1]) || t[1][0] < 0 || t[1][0] > 7 || t[1][1] < 0 || t[1][1] > 7);

	do{
		cout << "Inserte la fila de la reina: ";
		cin >> rx; rx--;
		cout << "Inserte la columna de la reina: ";
		cin >> ry; ry--;

	} while ((rx == t[0][0] && ry == t[0][1]) || (rx == t[1][0] && ry == t[1][1]) || rx < 0 || rx > 7 || ry < 0 || ry > 7);

	InicializarTablero(tablero, t, rx, ry);
	cout << "\n\n";
	ImprimirTablero(tablero);

	return 0;
}
