#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Placa.h"
#include <string>
#include <list>

using namespace std;

list<Placa> listaPlacas;

void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void agregarPlaca()
{
    system("cls");
    string placa, nombrePlaca, telefonoPlaca, correoPlaca;
    int restricciones[7] = {0, 0, 0, 0, 0, 0, 0};

    gotoXY(0, 0);
    cout << "AGREGAR PLACA" << endl;
    gotoXY(0, 1);
    cout << "Ingrese el numero de placa: ";
    cin >> placa;

    gotoXY(0, 2);
    cout << "Ingrese el nombre del dueno: ";
    cin >> nombrePlaca;

    gotoXY(0, 3);
    cout << "Ingrese el telefono del dueno: ";
    cin >> telefonoPlaca;

    gotoXY(0, 4);
    cout << "Ingrese el correo del dueno: ";
    cin >> correoPlaca;

    Placa nuevaPlaca(placa, nombrePlaca, telefonoPlaca, correoPlaca);

    gotoXY(0, 5);
    cout << "Por favor, indique si la placa cuenta con restricciones los siguenes dias:" << endl;
    do
    {
        gotoXY(0, 6);
        cout << "Lunes (0 = No, 1 = Si): ";
        cin >> restricciones[0];
    } while (restricciones[0] != 0 && restricciones[0] != 1);

    do
    {
        gotoXY(0, 7);
        cout << "Martes (0 = No, 1 = Si): ";
        cin >> restricciones[1];
    } while (restricciones[1] != 0 && restricciones[1] != 1);

    do
    {
        gotoXY(0, 8);
        cout << "Miercoles (0 = No, 1 = Si): ";
        cin >> restricciones[2];
    } while (restricciones[2] != 0 && restricciones[2] != 1);

    do
    {
        gotoXY(0, 9);
        cout << "Jueves (0 = No, 1 = Si): ";
        cin >> restricciones[3];
    } while (restricciones[3] != 0 && restricciones[3] != 1);

    do
    {
        gotoXY(0, 10);
        cout << "Viernes (0 = No, 1 = Si): ";
        cin >> restricciones[4];
    } while (restricciones[4] != 0 && restricciones[4] != 1);

    do
    {
        gotoXY(0, 11);
        cout << "Sabado (0 = No, 1 = Si): ";
        cin >> restricciones[5];
    } while (restricciones[5] != 0 && restricciones[5] != 1);

    do
    {
        gotoXY(0, 12);
        cout << "Domingo (0 = No, 1 = Si): ";
        cin >> restricciones[6];
    } while (restricciones[6] != 0 && restricciones[6] != 1);

    nuevaPlaca.setRestricciones(
        restricciones[0], restricciones[1], restricciones[2],
        restricciones[3], restricciones[4], restricciones[5],
        restricciones[6]);

    listaPlacas.push_back(nuevaPlaca);

    gotoXY(0, 13);
    cout << "Placa agregada exitosamente." << endl;
    getch();
}

void modificarPlaca()
{
    system("cls");
    string placa;
    gotoXY(0, 0);
    cout << "MODIFICAR PLACA";
    gotoXY(0, 1);
    cout << "Ingrese la placa a modificar: ";
    cin >> placa;

    for (auto &p : listaPlacas)
    {
        if (p.getPlaca() == placa)
        {
            string nuevoNombre, nuevoTelefono, nuevoCorreo;
            int restricciones[7];
            gotoXY(0, 2);
            cout << "Ingrese el nuevo nombre del dueno: ";
            cin >> nuevoNombre;
            p.setNombre(nuevoNombre);

            gotoXY(0, 3);
            cout << "Ingrese el nuevo telefono del dueno: ";
            cin >> nuevoTelefono;
            p.setTelefono(nuevoTelefono);

            gotoXY(0, 4);
            cout << "Ingrese el nuevo correo del dueno: ";
            cin >> nuevoCorreo;
            p.setCorreo(nuevoCorreo);

            gotoXY(0, 5);
            cout << "Por favor, indique si la placa cuenta con restricciones los siguenes dias:" << endl;
            do
            {
                gotoXY(0, 6);
                cout << "Lunes (0 = No, 1 = Si): ";
                cin >> restricciones[0];
            } while (restricciones[0] != 0 && restricciones[0] != 1);

            do
            {
                gotoXY(0, 7);
                cout << "Martes (0 = No, 1 = Si): ";
                cin >> restricciones[1];
            } while (restricciones[1] != 0 && restricciones[1] != 1);

            do
            {
                gotoXY(0, 8);
                cout << "Miercoles (0 = No, 1 = Si): ";
                cin >> restricciones[2];
            } while (restricciones[2] != 0 && restricciones[2] != 1);

            do
            {
                gotoXY(0, 9);
                cout << "Jueves (0 = No, 1 = Si): ";
                cin >> restricciones[3];
            } while (restricciones[3] != 0 && restricciones[3] != 1);

            do
            {
                gotoXY(0, 10);
                cout << "Viernes (0 = No, 1 = Si): ";
                cin >> restricciones[4];
            } while (restricciones[4] != 0 && restricciones[4] != 1);

            do
            {
                gotoXY(0, 11);
                cout << "Sabado (0 = No, 1 = Si): ";
                cin >> restricciones[5];
            } while (restricciones[5] != 0 && restricciones[5] != 1);

            do
            {
                gotoXY(0, 12);
                cout << "Domingo (0 = No, 1 = Si): ";
                cin >> restricciones[6];
            } while (restricciones[6] != 0 && restricciones[6] != 1);

            p.setRestricciones(
                restricciones[0], restricciones[1], restricciones[2],
                restricciones[3], restricciones[4], restricciones[5],
                restricciones[6]);
            gotoXY(0, 13);
            cout << "Placa modificada exitosamente." << endl;
            getch();
            return;
        }
    }
    cout << "Placa no encontrada." << endl;
    getch();
    modificarPlaca();
}

void eliminarPlaca()
{
    system("cls");
    string placa;
    gotoXY(0, 0);
    cout << "ELIMINAR PLACA" << endl;
    gotoXY(0, 1);
    cout << "Ingrese la placa a eliminar: ";
    cin >> placa;

    for (auto it = listaPlacas.begin(); it != listaPlacas.end(); ++it)
    {
        if (it->getPlaca() == placa)
        {
            listaPlacas.erase(it);
            gotoXY(0, 2);
            cout << "Placa eliminada exitosamente." << endl;
            getch();
            return;
        }
    }
    cout << "Placa no encontrada." << endl;
    getch();
    eliminarPlaca();
}

void consultarRestricciones()
{
    system("cls");
    string placa;
    gotoXY(0, 0);
    cout << "CONSULTAR RESTRICCIONES:" << endl;
    gotoXY(0, 1);
    cout << "Ingrese la placa a consultar: ";
    cin >> placa;

    for (const auto &p : listaPlacas)
    {
        if (p.getPlaca() == placa)
        {
            gotoXY(0, 2);
            cout << "Restricciones los dias:" << endl;
            if (p.getRestriccion(0) == 1)
                cout << "Lunes" << endl;
            if (p.getRestriccion(1) == 1)
                cout << "Martes" << endl;
            if (p.getRestriccion(2) == 1)
                cout << "Miercoles" << endl;
            if (p.getRestriccion(3) == 1)
                cout << "Jueves" << endl;
            if (p.getRestriccion(4) == 1)
                cout << "Viernes" << endl;
            if (p.getRestriccion(5) == 1)
                cout << "Sabado" << endl;
            if (p.getRestriccion(6) == 1)
                cout << "Domingo" << endl;
            getch();
            return;
        }
    }
    cout << "Placa no encontrada." << endl;
    getch();
    consultarRestricciones();
}

void consultarPlaca()
{
    system("cls");
    string placa;
    gotoXY(0, 0);
    cout << "CONSULTAR INFORMACION PLACA ";
    gotoXY(0, 1);
    cout << "Ingrese la placa a consultar: ";
    cin >> placa;

    for (const auto &p : listaPlacas)
    {
        if (p.getPlaca() == placa)
        {
            gotoXY(0, 2);
            cout << "Informacion del dueno:" << endl;
            cout << "Nombre: " << p.getNombre() << endl;
            cout << "Telefono: " << p.getTelefono() << endl;
            cout << "Correo: " << p.getCorreo() << endl;
            getch();
            return;
        }
    }
    cout << "Placa no encontrada." << endl;
    getch();
    consultarPlaca();
}

int main()
{
    int option;
    do
    {
        system("cls");
        gotoXY(0, 0);
        cout << "Consulta de restricciones:" << endl;
        cout << "==========================" << endl;
        gotoXY(0, 2);
        cout << "1. Agregar placas" << endl;
        gotoXY(0, 3);
        cout << "2. Modificar placas" << endl;
        gotoXY(0, 4);
        cout << "3. Eliminar placa" << endl;
        gotoXY(0, 5);
        cout << "4. Consultar restricciones" << endl;
        gotoXY(0, 6);
        cout << "5. Consultar INFO placa" << endl;
        gotoXY(0, 7);
        cout << "6. Salir" << endl;
        gotoXY(0, 9);
        cout << "==========================" << endl;
        gotoXY(0, 10);
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            agregarPlaca();
            break;
        case 2:
            modificarPlaca();
            break;
        case 3:
            eliminarPlaca();
            break;
        case 4:
            consultarRestricciones();
            break;
        case 5:
            consultarPlaca();
            break;
        case 6:
            system("cls");
            cout << "Saliendo del programa..." << endl;
            getch();
            break;
        default:
            gotoXY(0, 11);
            cout << "Opcion invalida. Intente de nuevo." << endl;
            getch();
        }
    } while (option != 6);

    return 0;
}