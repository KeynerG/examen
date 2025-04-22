#ifndef PLACA_H
#define PLACA_H

#include <string>
using namespace std;

class Placa
{
private:
    string placa;
    string nombre;
    string telefono;
    string correo;
    int restricciones[7];

public:
    Placa(string placa, string nombre, string telefono, string correo);

    // Getters
    string getPlaca() const;
    string getNombre() const;
    string getTelefono() const;
    string getCorreo() const;
    int getRestriccion(int dia) const;

    // Setters
    void setPlaca(const string &nuevaPlaca);
    void setNombre(const string &nuevoNombre);
    void setTelefono(const string &nuevoTelefono);
    void setCorreo(const string &nuevoCorreo);
    void setRestricciones(int l, int m, int mi, int j, int v, int s, int d);
};

#endif // PLACA_H