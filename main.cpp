#include <iostream>
#include <time.h>
using namespace std;
template <typename T>
class quicksort {
    T *array;
    int inicio;
    int fin;

public:
    quicksort(T *array, int inicio, int fin) : array{array}, inicio{inicio}, fin{fin} {}

    int dividir(T *array, int inicio, int fin) {
        int izq;
        int der;
        T pibote;
        T temp;

        pibote = array[inicio];
        izq = inicio;
        der = fin;

        //Mientras no se cruzen los índices
        while (izq < der) {
            while (array[der] > pibote) {
                der--;
            }

            while ((izq < der) && (array[izq] <= pibote)) {
                izq++;
            }

            // Si todavia no se cruzan los indices seguimos intercambiando
            if (izq < der) {
                temp = array[izq];
                array[izq] = array[der];
                array[der] = temp;
            }
        }

        //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
        temp = array[der];
        array[der] = array[inicio];
        array[inicio] = temp;

        //La nueva posición del pivote
        return der;
    }
    void arreglar(T *array, int inicio, int fin){
        int pivote;
        if(inicio < fin)
        {
            pivote = dividir(array, inicio, fin );
            arreglar( array, inicio, pivote - 1 );//ordeno la lista de los menores
            arreglar( array, pivote + 1, fin );//ordeno la lista de los mayores
        }
    }
    void imprimir(){
        for(int i = 0 ; i < fin; i++)
            cout << array[i] << " ";
    }
};

int main() {
    srand(time(nullptr));
    int n;
    cout << "Ingrese tamano del array" << endl;
    cin >> n;
    auto* a = new float[n];
    for( int i = 0;  i < n ; i++)
        a[i]= rand()%100;
    cout << "Los valores del array son: " << endl;
    for( int i = 0 ;i < n ; i++)
        cout << a[i] << " ";
    cout << endl;
    quicksort <float> ordenar1(a,0,n);
    ordenar1.arreglar(a,0,n-1);
    cout << "Ahora los valores ordenados son: ";
    cout << endl;
    ordenar1.imprimir();
}