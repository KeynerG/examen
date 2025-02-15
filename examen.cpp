#include <cstdio>
#include <cstdlib>
#include <list>
#include <string>

// Precios por categoría e impuesto
const int precios[4] = {5000, 7500, 10000, 15000};
const int impuesto = 15; // 15% de impuesto

// Estadísticas de ventas
int totalVendidos[4] = {0};
int totalRecaudado[4] = {0};

// Listas para registrar ventas por indice
std::list<int> categorias;
std::list<int> cantidades;
std::list<int> totales;
std::list<std::string> compradores;

// Funcion para registrar ventas
void registrarVenta() {
    std::string comprador;
    int categoria, cantidad, total;
    
    printf("Ingrese el nombre del comprador: ");
    char buffer[50];
    scanf("%s", buffer);
    comprador = buffer;
    
    do {
        printf("Categorías de entradas:\n");
        printf("1- Sol: $5000\n");
        printf("2- Sombra: $7500\n");
        printf("3- Platea: $10000\n");
        printf("4- VIP: $15000\n");
        printf("Seleccione categoría (1-4): ");
        scanf("%d", &categoria);
    } while (categoria < 1 || categoria > 4);
    
    do {
        printf("Ingrese cantidad de entradas (1-5): ");
        scanf("%d", &cantidad);
    } while (cantidad < 1 || cantidad > 5);
    
    // Calcular total a pagar
    int subtotal = cantidad * precios[categoria - 1];
    int totalImpuesto = (subtotal * impuesto) / 100;
    total = subtotal + totalImpuesto;
    
    // Agregar venta a las listas
    categorias.push_back(categoria);
    cantidades.push_back(cantidad);
    totales.push_back(total);
    compradores.push_back(comprador);
    
    // Actualizar estadísticas de ventas totales
    totalVendidos[categoria - 1] += cantidad;
    totalRecaudado[categoria - 1] += total;
    
    // Mostrar resumen de la venta
    printf("\n--- Resumen de la Venta ---\n");
    printf("Comprador: %s\n", comprador.c_str());
    printf("Categoría: %d\n", categoria);
    printf("Cantidad: %d\n", cantidad);
    printf("Subtotal: $%d\n", subtotal / 100);
    printf("Impuesto (15%%): $%d\n", totalImpuesto / 100);
    printf("Total a pagar: $%d\n", total / 100);
    printf("--------------------------\n\n");
}

// Funcion para mostrar estadisticas
void mostrarEstadisticas() {
    printf("\n--- Estadísticas de Ventas ---\n");
    for (int i = 0; i < 4; i++) {
        printf("Categoría %d: %d entradas vendidas, Total recaudado: $%d\n", i + 1, totalVendidos[i], totalRecaudado[i] / 100);
    }
    printf("------------------------------\n");
}

int main() {
    int opcion;
    do {
        printf("\nMenú de Ventas\n");
        printf("1. Registrar nueva venta\n");
        printf("2. Mostrar estadísticas\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarVenta();
                break;
            case 2:
                mostrarEstadisticas();
                break;
            case 3:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida, intente de nuevo.\n");
        }
    } while (opcion != 3);
    
    return 0;
}
