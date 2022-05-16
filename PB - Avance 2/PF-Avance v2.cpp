#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
#include <conio.h>
#include<stdlib.h>
#include <Windows.h>
using namespace std;

//definir funciones
void Agendar();
void Modificar();
void Eliminar();
void Lista();
void Archivo();

struct {
	int id, edad, cant,hora;
	float precio, stotal, total, iva;
	string nombre, trat, desc, desctra;
} paciente[99];

bool validar = false;
int opcion;
int salir = 1;
int j,z, i = 0;

int main()
{
	setlocale(LC_ALL, "");
	do {
		cout << "---[CITAS DENTALES]---" << endl;
		cout << "1.-AGENDAR CITA\n2.-MODIFICAR CITA\n3.-ELIMINAR CITA\n4.-LISTA DE CITAS VIGENTES\n5.-LIMPIAR PANTALLA\n6.-SALIR\n";
		cin.clear();
		cout << "\nIngrese su opción: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			Agendar();
			break;
		case 2:
			Modificar();
			break;
		case 3:
			Eliminar();
			break;
		case 4:
			Lista();
			break;
		case 5:
			system("cls");
			opcion = 0;
			break;
		case 6:
			Archivo();
			salir = 2;
			break;
		default:
			cout << "\n**ERROR, Ingrese una opción válida**\n\n";
			break;
		}
	} while (salir == 1);
}
void Agendar() {
	system("cls");
	do {
		paciente[i].id = i + 1;
		cout << "\n-ID PACIENTE " << paciente[i].id << "-\n";//ID automatico
		do {
			validar = false;
			cout << "Nombre del Paciente: ";
			cin.ignore();
			getline(cin, paciente[i].nombre);
			for (z = 0; z < paciente[i].nombre.length(); z++) {
				if (!isalpha(paciente[i].nombre.at(z))&&!isspace(paciente[i].nombre.at(z)))
				{
					z = paciente[i].nombre.length() + 1;
					validar = true;
				}

			}
			if (validar == true) {
				cout << "*Error, Ingrese correctamente el nombre del paciente*\n";
			}
		} while (validar == true);
		cout << "Edad: ";
		cin >> paciente[i].edad;
		cout << "Hora (formato 24hrs): ";
		do {
			cin >> paciente[i].hora;
			if (paciente[i].hora < 0 || paciente[i].hora>23)
				cout << "\nError, Ingrese una hora válida: ";
		} while (paciente[i].hora < 0 || paciente[i].hora>23);
		do {
			validar = false;
			cout << "Tratamiento: ";
			cin.get();
			getline(cin, paciente[i].trat);
			for (z = 0; z < paciente[i].trat.length(); z++) {
				if (!isalpha(paciente[i].trat.at(z)) && !isspace(paciente[i].trat.at(z))) 
				{
					z = paciente[i].trat.length() + 1;
					validar = true;
				}
			}
			if (validar == true) {
				cout << "*Error, Ingrese correctamente el Tratamiento*\n";
			}
		} while (validar ==true);
		do
		{
			validar = false;
			cout << "Descripción del tratamiento: ";
			//cin.get();
			getline(cin, paciente[i].desctra);
			for (z = 0; z < paciente[i].desctra.length(); z++) {
				if (!isalpha(paciente[i].desctra.at(z)) && !isspace(paciente[i].desctra.at(z)))
				{
					z = paciente[i].desctra.length() + 1;
					validar = true;
				}
			}
			if (validar == true) {
				cout << "\n*Error, Evite usar carecteres especiales*\n";
			}
		} while (validar == true);
		do
		{
			cout << "Cantidad del tratamiento: ";
			cin >> paciente[i].cant;
			if (paciente[i].cant <= 0) 
				cout << "\n*Error, Ingrese cantidad válida*\n";	
		} while (paciente[i].cant <= 0);
		do {
			cout << "Precio Unitario: $";
			cin >> paciente[i].precio;
			if (paciente[i].precio <= 0) {
				cout << "\n*Error,Ingrese cantidad válida*\n";
			}
		} while (paciente[i].precio<= 0);

		paciente[i].stotal = paciente[i].cant*paciente[i].precio;
		paciente[i].iva = paciente[i].stotal * .16;
		paciente[i].total = paciente[i].stotal + paciente[i].iva;

		cout << "\n--[SU CITA HA SIDO AGENDADA]--\n";
		cout << "\n\n¿Desea agregar otro paciente?(Sí=1, No=2)\n";
		cin >> opcion;
		i++;
	} while (opcion == 1);
}
void Modificar() {
	system("cls");
	do {
		cout << "\nIngrese el ID del paciente a modificar \n";
		cin >> j;
		if (j > i||j<=0||paciente[i].id == 0) {
			cout << "\n--*ID inexistente*-\n\n";
			break;
		}
		j = j - 1;
		for (i = j; i == j; i++) {
			cout << "\n-ID PACIENTE " << paciente[i].id << "-\n";//ID automatico
			do {
				validar = false;
				cout << "Nombre del Paciente: ";
				cin.get();
				getline(cin, paciente[i].nombre);
				for (z = 0; z < paciente[i].nombre.length(); z++) {
					if (!isalpha(paciente[i].nombre.at(z)) && !isspace(paciente[i].nombre.at(z)))
					{
						z = paciente[i].nombre.length() + 1;
						validar = true;
					}
				}
				if (validar == true) {
					cout << "*Error, Ingrese correctamente el nombre del paciente*\n"; 
				}
			} while (validar == true);
			cout << "Edad: ";
			cin >> paciente[i].edad;
			cout << "Hora (formato 24hrs): ";
			do {
				cin >> paciente[i].hora;
				if (paciente[i].hora < 0 || paciente[i].hora>23)
					cout << "\nError, Ingrese una hora válida:";
			} while (paciente[i].hora < 0 || paciente[i].hora>23);
			do {
				validar = false;
				cout << "Tratamiento: ";
				cin.get();
				getline(cin, paciente[i].trat);
				for (z = 0; z < paciente[i].trat.length(); z++) {
					if (!isalpha(paciente[i].trat.at(z)) && !isspace(paciente[i].trat.at(z)))
					{
						z = paciente[i].trat.length() + 1;
						validar = true;
					}
				}
				if (validar == true) {
					cout << "*Error, Ingrese correctamente el Tratamiento*\n";
					while (getchar() != '\n');
				}
			} while (validar == true);
			do
			{
				validar = false;
				cout << "Descripción del tratamiento: ";
				//cin.get();
				getline(cin, paciente[i].desctra);
				for (z = 0; z < paciente[i].desctra.length(); z++) {
					if (!isalpha(paciente[i].desctra.at(z)) && !isspace(paciente[i].desctra.at(z)))
					{
						z = paciente[i].desctra.length() + 1;
						validar = true;
					}
				}
				if (validar == true) {
					cout << "\n*Error, Evite usar carecteres especiales*\n";
				}
			} while (validar == true);
			do
			{
				cout << "Cantidad del tratamiento: ";
				cin >> paciente[i].cant;
				if (paciente[i].cant <= 0) {
					while (getchar() != '\n')
					cout << "\n*Error, Ingrese cantidad válida*\n";
				}
			} while (paciente[i].cant <= 0);
			do {
				cout << "Precio Unitario: $";
				cin >> paciente[i].precio;
				if (paciente[i].precio <= 0) {
					cout << "\n*Error,Ingrese cantidad válida*\n";
				}
			} while (paciente[i].precio <= 0);

			paciente[i].stotal = paciente[i].cant * paciente[i].precio;
			paciente[i].iva = paciente[i].stotal * .16;
			paciente[i].total = paciente[i].stotal + paciente[i].iva;

			cout << "\n--[SU CITA HA SIDO MODIFICADA]--\n\n";
		}
		cout << "Desea modificar otra cita?(Sí=1,No=2)\n";
		cin >> opcion;
		i++;
	} while (opcion == 1);
}
void Lista() {
	system("cls");
	cout << "\n-----[LISTA DE PACIENTES VIGENTES]----\n";
	for (int k = 0; k < i; k++) {
		if (paciente[k].id == 0) {
			cout << "\n==REGISTRO "<<k +1<<" ELIMINADO==\n";
		}
		else {
			cout << "\n-ID PACIENTE " << paciente[k].id << "-\n";
			cout << "\nNombre del Paciente: " << paciente[k].nombre;
			cout << "\nEdad: " << paciente[k].edad;
			cout << "\nHora: " << paciente[k].hora;
			cout << "\nTratamiento: " << paciente[k].trat;
			cout << "\nDescripción del tratamiento: " << paciente[k].desctra;
			cout << "\nCantidad del tratamiento: " << paciente[k].cant;
			cout << "\nPrecio Unitario: " << paciente[k].precio << endl;
			cout << "\nSubtotal: " << paciente[k].stotal;
			cout << "\nIVA: " << paciente[k].iva;
			cout << "\nTotal: " << paciente[k].total<<endl;
		}
	}
	cout << "\n======================================\n\n";
	system("pause>null");
}
void Eliminar() {
	system("cls");
	do {
		cout << "\nIngrese el número de paciente a eliminar\n";
		cin >> j;
		j = j - 1;
		for (int l = j; l == j; l++) {
			paciente[l].id = 0;
			paciente[l].nombre = " ";
			paciente[l].edad = 0;
			paciente[l].trat = " ";
			paciente[l].hora = 0;
			paciente[l].desctra = " ";
			paciente[l].cant = 0;
			paciente[l].precio = 0;
			cout << "\n--[SU CITA HA SIDO ELIMINADA]--\n\n";
		}
		cout << "Desea eliminar otra cita?(Sí=1,No=2)\n";
		cin >> opcion;
	} while (opcion == 1);
}
void Archivo() {
	//CREAR ARCHIVO
	ofstream archivo("Lista de Pacientes.txt", ios::out);
	if (archivo.is_open()) {

		for (int k = 0; k < i; k++) {
			if (paciente[k].id == 0) {
				cout << "\n==REGISTRO " << k + 1 << " ELIMINADO==\n";
			}
			else {
				archivo << "\n-ID PACIENTE " << paciente[k].id << "-\n";
				archivo << "\nNombre del Paciente: " << paciente[k].nombre;
				archivo << "\nEdad: " << paciente[k].edad;
				archivo << "\nHora: " << paciente[k].hora;
				archivo << "\nTratamiento: " << paciente[k].trat;
				archivo << "\nDescripción del tratamiento: " << paciente[k].desctra;
				archivo << "\nCantidad del tratamiento: " << paciente[k].cant;
				archivo << "\nPrecio Unitario: " << paciente[k].precio << endl;
				archivo << "\nSubtotal: " << paciente[k].stotal;
				archivo << "\nIVA: " << paciente[k].iva;
				archivo << "\nTotal: " << paciente[k].total<<endl;

			}
		}
		system("cls");
		// ciclo estetético para guardar
		for (int c = 0; c <= 1; c++) {
			printf("\nGuardando... %c ", 92); Sleep(200); system("cls");
			cout << "\nGuardando... | "; Sleep(200); system("cls");
			cout << "\nGuardando... / "; Sleep(200); system("cls");
			cout << "\nGuardando... - "; Sleep(200); system("cls");
		}
		cout << "\n--[ARCHIVO CREADO EXITOSAMENTE]--\n\n";
		archivo.close();
	}
	else {
		cout << "\n--*Imposible crear archivo*--\n";
	}
}