/*
Fecha: 8/10/26
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- Octavio Ramírez - 1132995
- José Pinales - 1133255
- Christian Acosta - 1132698

Realizar un programa C++ que genere los movimientos posibles (según las reglas del ajedrez)
de una Reina amenazada por dos Torres enemigas. 
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
	tablero[rx][ry] = 'R';
	tablero[t[0][0]][t[0][1]] = 'T';
	tablero[t[1][0]][t[1][1]] = 'T';
}

// Calcular ataques de las torres
bool CasillaAtacada(int t[2][2], int fila, int colm)
{
	for (int k = 0; k < 2; k++)
	{
		if (fila == t[k][0] || colm == t[k][1])
		{
			return true;
		}
	}
	return false;
}

//Calcular movimientos de la reina + clasificar + obstaculos
void MovimientosReina(char tablero[8][8], int t[2][2], int rx, int ry)
{
	int di[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
	int dj[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

	for (int d = 0; d < 8; d++)
	{
		int fila = rx + di[d];
		int colm = ry + dj[d];

		while (fila >= 0 && fila <= 7 && colm >= 0 && colm <= 7 && tablero[fila][colm] != 'T')
		{
			if (CasillaAtacada(t, fila, colm))
			{
				tablero[fila][colm] = 'x'; // peligrosa
			}
			else
			{
				tablero[fila][colm] = 'v'; // segura
			}
			fila += di[d];
			colm += dj[d];
		}
	}
}

void ImprimirTablero(char tablero[8][8])
{
	cout << "     A   B   C   D   E   F   G   H " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << "  | ";
		for (int j = 0; j < 8; j++)
		{
			cout << tablero[i][j] << " | ";
		}
		cout << endl;
	}
}

void leerEntero(string mensaje, int& pDato)
{
	string datoString;
	size_t position;
	bool error;

	do
	{
		try
		{
			cout << mensaje;
			cin >> datoString;
			pDato = stoi(datoString, &position);

			if (datoString.length() != position) {
				error = true;
				cout << "Entrada invalida, ingrese un numero entero\n" << endl;
			}
			else {
				error = false;
			}
		}
		catch (const exception&)
		{
			error = true;
			cout << "Entrada invalida, ingrese un numero entero\n" << endl;
		}
	} while (error);
}

int main()
{
	char tablero[8][8];
	int t[2][2];
	int rx;
	int ry;
	bool valido;
	bool continuar = true;
	char respuesta;
	while (continuar)
	{
		system("cls");

		cout << "Reina vs Torres" << endl;

		// Torre 1
		do {
			leerEntero("Inserte la fila de la primera torre: ", t[0][0]); t[0][0]--;
			leerEntero("Inserte la columna de la primera torre: ", t[0][1]); t[0][1]--;

			if (t[0][0] < 0 || t[0][0] > 7 || t[0][1] < 0 || t[0][1] > 7)
			{
				valido = false;
				cout << "Error: la fila y la columna deben estar entre 1 y 8.\n" << endl;
			}
			else
			{
				valido = true;
			}
		} while (!valido);

		// Torre 2
		do {
			leerEntero("Inserte la fila de la segunda torre: ", t[1][0]); t[1][0]--;
			leerEntero("Inserte la columna de la segunda torre: ", t[1][1]); t[1][1]--;

			if (t[1][0] < 0 || t[1][0] > 7 || t[1][1] < 0 || t[1][1] > 7)
			{
				valido = false;
				cout << "La fila y la columna deben estar entre 1 y 8.\n" << endl;
			}
			else if (t[1][0] == t[0][0] && t[1][1] == t[0][1])
			{
				valido = false;
				cout << "Esa casilla ya esta ocupada por la primera torre.\n" << endl;
			}
			else
			{
				valido = true;
			}
		} while (!valido);

		// Reina
		do {
			leerEntero("Inserte la fila de la reina: ", rx); rx--;
			leerEntero("Inserte la columna de la reina: ", ry); ry--;

			if (rx < 0 || rx > 7 || ry < 0 || ry > 7)
			{
				valido = false;
				cout << "Error: la fila y la columna deben estar entre 1 y 8.\n" << endl;
			}
			else if (rx == t[0][0] && ry == t[0][1])
			{
				valido = false;
				cout << "Error: esa casilla ya esta ocupada por la primera torre.\n" << endl;
			}
			else if (rx == t[1][0] && ry == t[1][1])
			{
				valido = false;
				cout << "Error: esa casilla ya esta ocupada por la segunda torre.\n" << endl;
			}
			else
			{
				valido = true;
			}
		} while (!valido);

		InicializarTablero(tablero, t, rx, ry);

		MovimientosReina(tablero, t, rx, ry);

		cout << "\n\n";
		ImprimirTablero(tablero);

		cout << "\n\nDesea continuar? (s/n): ";
		cin >> respuesta;
		if (respuesta == 'n' || respuesta == 'N') {
			continuar = false;
		}
	}
	return 0;
}
