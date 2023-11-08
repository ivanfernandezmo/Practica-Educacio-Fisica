#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	int casella = 1, tirada = 0, numDauInicial = 1, numDau, contador6 = 0;

	// per mostrar la tirada inicial
	printf("Iniciem el joc:\n");
	printf("Tirada[%02d]: %02d\n", tirada, numDauInicial);

	// while mentre la casella sigui inferior a 54
	while (casella < 54)
	{
		// incremento tirada en 1
		tirada++;
		// genero el valor aleatori entre 1 i 6
		numDau = (rand() % 6) + 1;
		// assigno el resultat de la tirada a casella per posicionarme
		casella = numDau + numDauInicial;

		//per controlar si cau dos vegades al 6
		if (numDau == 6)
		{
			contador6++;
		}
		else
		{
			contador6 = 0;
		}

		if (contador6 == 2)
		{
			printf("Tirada[%02d]: %02d + %d = %d --> 1\n", tirada, numDauInicial, numDau, casella);
			casella = 1;
		}
		else
		{
			switch (casella)
			{ // switch per controlar les diferentes opcions
			case 7:
				printf("Tirada[%02d]: %02d + %d = %d --> 17\n", tirada, numDauInicial, numDau, casella);
				casella = 17;
				break;
			case 30:
				printf("Tirada[%02d]: %02d + %d = %d --> 36\n", tirada, numDauInicial, numDau, casella);
				casella = 36;
				break;
			case 44:
				printf("Tirada[%02d]: %02d + %d = %d --> 22\n", tirada, numDauInicial, numDau, casella);
				casella = 22;
				break;
			case 49:
				printf("Tirada[%02d]: %02d + %d = %d --> 46\n", tirada, numDauInicial, numDau, casella);
				casella = 46;
				break;
			default:
				printf("Tirada[%02d]: %02d + %d = %d\n", tirada, numDauInicial, numDau, casella);
				break;
			}
		}

		// assigno casella a numDauInicial
		numDauInicial = casella;
		getch();
	}
	// printo el resum de tirades
	printf("S'han produit: %d tirades.", tirada);
	acabament();
	return 0;
}
