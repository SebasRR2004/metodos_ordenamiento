#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <random>

using namespace std;

vector<long long int> arr;

// Contadores de iteraciones
long long int bubble_iter = 0;
long long int selection_iter = 0;
long long int insertion_iter = 0;
long long int merge_iter = 0;
long long int quick_iter = 0;
long long int bucket_iter = 0;
long long int shell_iter = 0;
long long int counting_iter = 0;

const int MAX_NUMBERS = 5000;

// Prototipos de funciones
void bubbleSort(vector<long long int>& arr);
void selectionSort(vector<long long int>& arr);
void insertionSort(vector<long long int>& arr);
void mergeSort(vector<long long int>& arr, long long int l, long long int r);
void quickSort(vector<long long int>& arr, long long int low, long long int high);
long long int partition(vector<long long int>& arr, long long int low, long long int high); // Prototipo de partition
void bucketSort(vector<long long int>& arr);
void shellSort(vector<long long int>& arr);
void countingSort(vector<long long int>& arr);
void insertar();
void ordenar();
bool esNumero(const string& str);
void deleteElement(vector<long long int>& arr, long long int element);
void mostrarArray(const vector<long long int>& arr);
vector<long long int> leerArchivoTxt(const string& filename);
vector<long long int> obtener5000Aleatorios(const vector<long long int>& lista);

void insertar() {
    if (arr.size() >= MAX_NUMBERS) {
        cout << "Ya se han insertado " << MAX_NUMBERS << " números. No se pueden insertar más." << endl;
        return;
    }

    cout << "Ingrese el array de numeros separados por espacios, o ingrese 'archivo' para leer desde un archivo: ";
    string input;
    getline(cin, input);

    if (input == "archivo") {
        cout << "Ingrese el nombre del archivo: ";
        string filename;
        cin >> filename;
        arr = leerArchivoTxt(filename);
        if (arr.size() > MAX_NUMBERS) {
            arr = obtener5000Aleatorios(arr);
            cout << "Se han extraído aleatoriamente " << MAX_NUMBERS << " números del archivo." << endl;
        }
    } else {
        stringstream ss(input);
        long long int num;
        string token;
        while (ss >> token) {
            if (!esNumero(token)) {
                cout << "Error: Se han ingresado caracteres no válidos." << endl;
                return;
            }
            num = stoll(token);
            arr.push_back(num);
        }
    }
}

void deleteElement(vector<long long int>& arr, long long int element) {
    auto it = find(arr.begin(), arr.end(), element);
    if (it != arr.end()) {
        arr.erase(it);
        cout << "Elemento eliminado." << endl;
        mostrarArray(arr); // Llama a la función para mostrar el array actualizado
        cout << "Ordenando array..." << endl;
        sort(arr.begin(), arr.end()); // Ordena el array después de eliminar el elemento
        cout << "Array ordenado: ";
        mostrarArray(arr); // Muestra el array ordenado
    } else {
        cout << "Elemento no encontrado." << endl;
    }
}

void mostrarArray(const vector<long long int>& arr) {
    cout << "Array actual: ";
    for (long long int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void ordenar() {
    if (arr.empty()) {
        cout << "Antes de ordenar, debe ingresar un array." << endl;
        return;
    }

    vector<long long int> arr_copy = arr;

    cout << "Seleccione el metodo de ordenamiento:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quicksort" << endl;
    cout << "6. Bucket Sort" << endl;
    cout << "7. Shell Sort" << endl;
    cout << "8. Counting Sort" << endl;

    long long int opcion;
    cin >> opcion;

    auto start = chrono::high_resolution_clock::now();

    switch (opcion) {
        case 1:
            // Bubble Sort
            bubbleSort(arr_copy);
            cout << "Iteraciones: " << bubble_iter << endl;
            break;
        case 2:
            // Selection Sort
            selectionSort(arr_copy);
            cout << "Iteraciones: " << selection_iter << endl;
            break;
        case 3:
            // Insertion Sort
            insertionSort(arr_copy);
            cout << "Iteraciones: " << insertion_iter << endl;
            break;
        case 4:
            // Merge Sort
            mergeSort(arr_copy, 0, arr_copy.size() - 1);
            cout << "Iteraciones: " << merge_iter << endl;
            break;
        case 5:
            // Quicksort
            quickSort(arr_copy, 0, arr_copy.size() - 1);
            cout << "Iteraciones: " << quick_iter << endl;
            break;
        case 6:
            // Bucket Sort
            bucketSort(arr_copy);
            cout << "Iteraciones: " << bucket_iter << endl;
            break;
        case 7:
            // Shell Sort
            shellSort(arr_copy);
            cout << "Iteraciones: " << shell_iter << endl;
            break;
        case 8:
            // Counting Sort
            countingSort(arr_copy);
            cout << "Iteraciones: " << counting_iter << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            return;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo = end - start;

    cout << "Array ordenado exitosamente." << endl;
    cout << "Tiempo total: " << tiempo.count() << " segundos" << endl;

    cout << "Array ordenado: ";
    for (long long int num : arr_copy) {
        cout << num << " ";
    }
    cout << endl;
}

void bubbleSort(vector<long long int>& arr) {
    long long int n = arr.size();
    bubble_iter = 0;
    for (long long int i = 0; i < n - 1; ++i) {
        for (long long int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            bubble_iter++;
        }
    }
}

void selectionSort(vector<long long int>& arr) {
    long long int n = arr.size();
    selection_iter = 0;
    for (long long int i = 0; i < n - 1; ++i) {
        long long int min_idx = i;
        for (long long int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            selection_iter++;
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(vector<long long int>& arr) {
    long long int n = arr.size();
    insertion_iter = 0;
    for (long long int i = 1; i < n; ++i) {
        long long int key = arr[i];
        long long int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            insertion_iter++;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<long long int>& arr, long long int l, long long int m, long long int r) {
    long long int n1 = m - l + 1;
    long long int n2 = r - m;

    vector<long long int> L(n1), R(n2);
    for (long long int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (long long int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    long long int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        merge_iter++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        merge_iter++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        merge_iter++;
    }
}

void mergeSort(vector<long long int>& arr, long long int l, long long int r) {
    if (l >= r) return;
    long long int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

long long int partition(vector<long long int>& arr, long long int low, long long int high) {
    long long int pivot = arr[high];
    long long int i = low - 1;
    for (long long int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        quick_iter++;
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<long long int>& arr, long long int low, long long int high) {
    if (low < high) {
        long long int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bucketSort(vector<long long int>& arr) {
    const long long int max_val = *max_element(arr.begin(), arr.end()) + 1;
    bucket_iter = 0;
    vector<long long int> bucket(max_val, 0);

    for (long long int num : arr) {
        bucket[num]++;
        bucket_iter++;
    }

    arr.clear();
    for (long long int i = 0; i < max_val; ++i) {
        for (long long int j = 0; j < bucket[i]; ++j) {
            arr.push_back(i);
            bucket_iter++;
        }
    }
}

void shellSort(vector<long long int>& arr) {
    long long int n = arr.size();
    shell_iter = 0;
    for (long long int gap = n / 2; gap > 0; gap /= 2) {
        for (long long int i = gap; i < n; ++i) {
            long long int temp = arr[i];
            long long int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                shell_iter++;
            }
            arr[j] = temp;
        }
    }
}

void countingSort(vector<long long int>& arr) {
    const long long int max_val = *max_element(arr.begin(), arr.end()) + 1;
    counting_iter = 0;
    vector<long long int> count(max_val, 0);
    vector<long long int> output(arr.size());

    for (long long int num : arr) {
        count[num]++;
        counting_iter++;
    }

    for (long long int i = 1; i < max_val; ++i) {
        count[i] += count[i - 1];
        counting_iter++;
    }

    for (long long int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        counting_iter++;
    }

    arr = output;
}

bool esNumero(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

vector<long long int> leerArchivoTxt(const string& filename) {
    ifstream file(filename);
    vector<long long int> lista;
    if (!file) {
        cout << "Error al abrir el archivo." << endl;
        return lista;
    }

    long long int num;
    while (file >> num) {
        lista.push_back(num);
    }

    file.close();
    return lista;
}

vector<long long int> obtener5000Aleatorios(const vector<long long int>& lista) {
    vector<long long int> aleatorios;
    vector<long long int> lista_copy = lista;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(lista_copy.begin(), lista_copy.end(), default_random_engine(seed));
    for (int i = 0; i < MAX_NUMBERS; ++i) {
        aleatorios.push_back(lista_copy[i]);
    }
    return aleatorios;
}

int main() {
    long long int opcion;

    do {
        cout << "\nMENU PRINCIPAL" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Ordenar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        cin.ignore(); // Limpiar el buffer del teclado

        switch (opcion) {
            case 1:
                insertar();
                break;
            case 2:
                ordenar();
                break;
            case 3:
                long long int element;
                cout << "Ingrese el elemento a eliminar: ";
                cin >> element;
                deleteElement(arr, element);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
