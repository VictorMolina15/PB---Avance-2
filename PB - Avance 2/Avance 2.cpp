#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int opcion;
	int salir = 1;
	int j,i = 0;
	struct{
		int id, edad;
		string nombre, correo,clinica, desc, doccons;
	} paciente[99];
	do {
		cout << "---[CITAS DENTALES]---" << endl;
		cout << "1.-AGENDAR CITA\n2.-MODIFICAR CITA\n3.-ELIMINAR CITA\n4.-LISTA DE CITAS VIGENTES\n5.-LIMPIAR PANTALLA\n6.-SALIR\n";
		cout << "\nIngrese su opción: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			do {
				paciente[i].id = 20220000 +i+1;
				cout << "\n-PACIENTE " << paciente[i].id << "-\n";
				cout << "Nombre del Paciente: ";
				cin.get();
				getline(cin,paciente[i].nombre);
				cout << "Edad: ";
				cin >> paciente[i].edad;
				cin.ignore();
				cout << "Correo del paciente: ";
				getline(cin, paciente[i].correo);
				cout << "Clinica: ";
				getline(cin, paciente[i].clinica);
				cout << "Doctor consultado: ";
				getline(cin, paciente[i].doccons);
				cout << "Descripcíon de la consulta: ";
				getline(cin, paciente[i].desc);
				cout << "\n--[SU CITA HA SIDO AGENDADA]--\n";
				cout << "\n\n¿Desea agregar otro paciente?(Sí=1, No=2)\n";
				cin >> opcion;
				i++;
			} while (opcion == 1);
			break;
		case 2:
			do {

				cout << "\ningrese el útlimo digito de la cita a modificar \n";
				cin >> j;
				j = j - 1;

				for (i = j; i <= j; i++) {
					cout << "\n-PACIENTE " << paciente[i].id << "-\n";
					cout << "Nombre del Paciente: ";
					cin.ignore();
					getline(cin, paciente[i].nombre);
					cout << "Edad: ";
					cin >> paciente[i].edad;
					cin.ignore();
					cout << "Correo del paciente: ";
					getline(cin, paciente[i].correo);
					cout << "Clinica: ";
					getline(cin, paciente[i].clinica);
					cout << "Doctor consultado: ";
					getline(cin, paciente[i].doccons);
					cout << "Descripcíon de la consulta: ";
					getline(cin, paciente[i].desc);
					cout << "\n--[SU CITA HA SIDO MODIFICADA]--\n";
				}
				cout << "Desea modificar otra cita?(Sí=1,No=2)\n";
				cin >> opcion;
			} while (opcion == 1);
			break;
		case 3:

			break;
		case 4:
			cout << "\n-----[LISTA DE PACIENTES VIGENTES]----";
			for (int k = 0; k < i; k++) {
				cout << "\n-Id del Paciente " << paciente[k].id << "-\n";
				cout << "\nNombre del Paciente: " << paciente[k].nombre;
				cout << "\nEdad: " << paciente[k].edad;
				cout << "\nCorreo del paciente: " << paciente[k].correo;
				cout << "\nClinica: " << paciente[k].clinica;
				cout << "\nDoctor consultado: " << paciente[k].doccons;
				cout << "\nDescripcíon de la consulta: " << paciente[k].desc<<endl;
			}
			cout << "\n======================================\n";
			system("pause>null");
			break;
		case 5:
			system("cls");
			opcion = 0;
			break;
		case 6:
			salir = 2;
			break;
		default:
			cout << "\n**ERROR, Ingrese una opción válida**\n";
		}
	} while (salir == 1);
}