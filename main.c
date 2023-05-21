#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inicio del programa

int main()
{
	// declaracion de variables
	int pregunta, muz, nap, mor, fug, roq, tot, pizzas, maxPizzas = 0, contMuz = 0, contNap = 0, contMor = 0, contFug = 0, contRoq = 0, minDiaPlata = 99999999999, diaPlata = 0, minDia, totalSem = 0;
	char nom[20], apellido[20], maxNom[20];
	printf("Bienvenido a la Pizzeria Juan");
	// inicio de la estructura "for"
	for (int i = 1; i <= 6; i++)
	{
		printf("\nHoy es el dia %d", i);
		printf("\nHay algun pedido? : \n1_Si \n2_No\n"); // men� de seleccion multiple
		scanf("%d", &pregunta);
		// inicio de la estructura "while" dentro del "for"
		while (pregunta == 1)
		{
			// ingreso de datos
			printf("Ingrese nombre cliente\n");
			fflush(stdin);
			scanf("%s", &nom);
			printf("Ingrese apellido cliente\n");
			fflush(stdin);
			scanf("%s", &apellido);
			system("cls");
			// comparacion de strings
			if (strcmp(nom, "juan") == 0 && strcmp(apellido, "carlos") == 0)
			{
				printf("\nHola Juan CArLOS!\nComo estas chupa pija?");
			}
			else if (strcmp(nom, "juan") == 0)
			{
				printf("\nGrande juan un capo");
			}
			else
			{
				printf("Hola %s", nom);
			}
			printf("\nsabores disponibles: Muzzarela, Napolitana, Morrones, Fugazeta, Roquefort");
			printf("\nCuantas pizzas desea ordenar por sabor?");
			// combinaci�n entre "for" y "switch" para seleccionar la cantidad de pizzas que se compran y a la vez poder contarlas
			for (int x = 1; x <= 5; x++)
			{
				switch (x)
				{
				case 1:
					printf("\n1_Muzzarella: $900: ");
					fflush(stdin);
					scanf("%d", &muz);
					contMuz += muz;
					break;
				case 2:
					printf("\n2_Napolitana: $1100: ");
					fflush(stdin);
					scanf("%d", &nap);
					contNap += nap;
					break;
				case 3:
					printf("\n3_Morrones: $1150: ");
					fflush(stdin);
					scanf("%d", &mor);
					contMor += mor;
					break;
				case 4:
					printf("\n4_Fugazeta: $1000: ");
					fflush(stdin);
					scanf("%d", &fug);
					contFug += fug;
					break;
				case 5:
					printf("\n5_Roquefort: $1200: ");
					fflush(stdin);
					scanf("%d", &roq);
					contRoq += roq;
					break;
				default:
					printf("Nunca va a llegar aqui");
				}
			}
			tot = muz * 900 + nap * 1100 + mor * 1150 + fug * 1000 + roq * 1200;
			pizzas = muz + nap + mor + fug + roq;
			printf("\nEl total a pagar es de: $%d\n", tot);
			system("pause");
			system("cls");
			//"if" para definir la mayor cantidad de pizzas vendidas en un solo pedido
			if (maxPizzas < pizzas)
			{
				maxPizzas = pizzas;
				// concatenacion entre nombre y apellido
				strcpy(maxNom, nom);
				strcat(maxNom, " ");
				strcat(maxNom, apellido);
			}
			diaPlata += tot;

			// reinicio del "while"
			printf("\nHay algun pedido? : \n1_Si \n2_No\n");
			fflush(stdin);
			scanf("%d", &pregunta);
		}
		//"if" para definir la menor cantidad de dinero recolectado en un dia completo
		if (diaPlata < minDiaPlata)
		{
			minDiaPlata = diaPlata;
			minDia = i;
		}
		// monto total de dinero conseguido en la semana
		totalSem += diaPlata;
		diaPlata = 0;
		system("pause");
		system("cls");
	}
	// salida de datos
	printf("El que mas pizzas compro fue: %s con un total de %d pizzas. Por eso le regalamos una pizza a su eleccion y una cOcA-cOlA.", maxNom, maxPizzas);
	printf("\nEl dia que menos dinero se recaudo fue el dia %d con un total de: $%d", minDia, minDiaPlata);
	printf("\nSe recaudo un total de $%d en la semana", totalSem);
	// comparacion entre contadores para definir el tipo de pizza menos vendido en la semana
	if (contMuz < contNap && contMuz < contMor && contMuz < contFug && contMuz < contRoq)
	{
		printf("\nLa pizza que menos se vendio es la pizza de Muzzarela con %d pizza/s vendidas", contMuz);
	}
	else if (contNap < contMuz && contNap < contMor && contNap < contFug && contNap < contRoq)
	{
		printf("\nLa pizza que menos se vendio es la pizza de Napolitana con %d pizza/s vendidas", contNap);
	}
	else if (contMor < contMuz && contMor < contNap && contMor < contFug && contMor < contRoq)
	{
		printf("\nLa pizza que menos se vendio es la pizza de Morrones con %d pizza/s vendidas", contMor);
	}
	else if (contFug < contMuz && contFug < contNap && contFug < contMor && contFug < contRoq)
	{
		printf("\nLa pizza que menos se vendio es la pizza de Fugazeta con %d pizza/s vendidas", contFug);
	}
	else
	{
		printf("\nLa pizza que menos se vendio es la pizza de Roquefort con %d pizza/s vendidas", contRoq);
	}
	return 0;
}

/*printf("\n1_muzzarella: $900: ");
		fflush(stdin);
		scanf("%d", &muz);
		printf("\n2_napolitana: $1100: ");
		fflush(stdin);
		scanf("%d", &nap);
		printf("\n3_morrones: $1150: ");
		fflush(stdin);
		scanf("%d", &mor);
		printf("\n4_fugazeta: $1000: ");
		fflush(stdin);
		scanf("%d", &fug);
		printf("\n5_roquefort: $1200: ");
		fflush(stdin);
		scanf("%d", &roq);*/
