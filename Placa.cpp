#include "Placa.h"

Placa::Placa(string placa, string nombre, string telefono, string correo)
    : placa(placa), nombre(nombre), telefono(telefono), correo(correo)
{
    for (int i = 0; i < 7; i++)
    {
        restricciones[i] = 0;
    }
}

string Placa::getPlaca() const { return placa; }
string Placa::getNombre() const { return nombre; }
string Placa::getTelefono() const { return telefono; }
string Placa::getCorreo() const { return correo; }
int Placa::getRestriccion(int dia) const
{
    if (dia >= 0 && dia < 7)
        return restricciones[dia];
    return -1;
}

void Placa::setPlaca(const string &nuevaPlaca) { placa = nuevaPlaca; }
void Placa::setNombre(const string &nuevoNombre) { nombre = nuevoNombre; }
void Placa::setTelefono(const string &nuevoTelefono) { telefono = nuevoTelefono; }
void Placa::setCorreo(const string &nuevoCorreo) { correo = nuevoCorreo; }
void Placa::setRestricciones(int l, int m, int mi, int j, int v, int s, int d)
{
    restricciones[0] = l;
    restricciones[1] = m;
    restricciones[2] = mi;
    restricciones[3] = j;
    restricciones[4] = v;
    restricciones[5] = s;
    restricciones[6] = d;
}