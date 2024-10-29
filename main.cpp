#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <cmath>
#include <vector>
#include <array>
using namespace std;

//Declaracion funciones
void pause();
bool secuencia_Valida(string secuencia);
int invertir_entero(int numero);
int NumeroInvertido(int numero, int invertido);
int numeroDigitos(int cont);
void construirArreglo();
float wallisRecursivo(unsigned int n);
double wallisCola(unsigned int n, float auxiliar);
void wallis_product(int terms);

int main() 
{
  string secuencia;
  int numero;
  int op;
  
  //Do While
  do
  {

    //Menu del prograna
    cout<<("\033[H\033[J"); //Limpiar pantalla   
    cout<<"****************************************************************************************"<<endl;
    cout<<"\n-----Trabajo computacional-----\n"<<endl;
    cout<<"\n------------- MENU -------------"<<endl<<endl;
    cout<<"\n\u27a4 [1] Una función destinada a reconocer secuencias descritas mediante las siguientes reglas BNF. "<<endl;
    cout<<"\n\u27a4 [2] Invertir un entero no negativo n de, a lo más 9 dígitos. "<<endl;
    cout<<"\n\u27a4 [3] creador de un conjunto potencia de un conjunto base T "<<endl;
    cout<<"\n\u27a4 [4] Obtener el producto de Wallis. "<<endl;
    cout<<"\n\u27a4 [5] Terminar"<<endl; 
    cout<<"\n****************************************************************************************"<<endl;   
    
    cout<<"\nIngrese una opcion: ";
    cin>>op;
    if(op > 5)
    fflush(stdin);
    switch(op)
    {

      case 1: //Una función destinada a reconocer secuencias descritas mediante las siguientes reglas BNF.
        cout<<("\033[H\033[J");
        cout<<"------------------------------------------------------------------------------------ "<<endl<<endl;
        cout<<"Una función destinada a reconocer secuencias descritas mediante las siguientes reglas BNF. "<<endl<<endl;
        cout<<"\n\u27a4Ingrese la secuencia: ";
        cin>>secuencia;
        secuencia_Valida(secuencia);
        pause();
        cout<<"------------------------------------------------------------------------------------ "<<endl;
        
      break;

      case 2: //Invertir un entero no negativo n de, a lo más 9 dígitos.
        cout<<("\033[H\033[J");
        cout<<"------------------------------------------------------------------------------------ "<<endl;
        cout << "Ingrese un numero de hasta 9 digitos y que no empiece ni termine con un '0': ";
        cin >> numero;

        if(numeroDigitos(numero) <= 9)
        {
          int invertido = NumeroInvertido(numero, 0);
          cout << "El numero invertido es: " << invertido << endl;
        }
        else
        {
          cout << "El numero tiene mas de 9 digitos, por favor ingrese un numero valido." << endl;
        }
        pause();
        cout<<"------------------------------------------------------------------------------------ "<<endl;
      break;

      case 3: //Una función que invoque a otras dos funciones.
        cout<<("\033[H\033[J");
        cout<<"------------------------------------------------------------------------------------ "<<endl;
        construirArreglo();
        pause();
        cout<<"------------------------------------------------------------------------------------ "<<endl;
      break;

      case 4: //Obtener el producto de Wallis.
        cout<<("\033[H\033[J");
        cout<<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"Obtener el producto de Wallis. "<<endl;
        wallisRecursivo(60);
        cout<<"----------------COLA--------------"<<endl;
        wallis_product(60);
        pause();
        cout<<"------------------------------------------------------------------------------------ "<<endl;
      break;

      case 5: //Terminar el programa
        cout<<("\033[H\033[J");
        cout<<"\n****Gracias por utilizar****"<<endl;
      break;
    }
    
  }while(op!=5);
}

//Función para validar la secuencia según las reglas BNF dadas
bool secuencia_Valida(string secuencia) 
{
  int cont = 0; //Contador
  while(cont < secuencia.size()) //Recorrer la secuencia
  {
    if(isdigit(secuencia[cont])) //Si es un dígito <D>
    {
      cont++; //Avanzar al siguiente
      
      if(cont == secuencia.size()) //Si termina en digito la secuencia es valida
      {
        break;
      }
      if(!isalpha(secuencia[cont])) //Si hay 2 digitos seguidos es invalida
      {
        cout<<"\nLa secuencia no es valida"<<endl<<endl;
        return false;
      }
    }    
    while(cont < secuencia.size() && isalpha(secuencia[cont])) //Avanzar mientras haya letras <L> <S>
    {
      cont++;
    }
  }
  cout<<"\nLa secuencia es valida"<<endl<<endl;
  return true; //La secuencia es válida
}

//Funcion invertir un entero no negativo n de, a lo más 9 dígitos
int numeroDigitos(int cont)
{
  int cont1 = 0; 
  if (cont == 0) return 1;

  while(cont > 0)
  {
    cont = cont / 10;
    cont1++;
  }
  return cont1;
}

int NumeroInvertido(int numero, int invertido) 
{
  if (numero == 0)
  {
    return invertido;
  }
  else
  {
    int ultimo_digito = numero % 10;
    numero = numero / 10;
    invertido = (invertido * 10) + ultimo_digito;
    return NumeroInvertido(numero, invertido);
  }
}

//Funcion que pausa la pantalla del usuario
void pause() 
{
  cout<<endl<<"\u27a4 Presione enter para continuar...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string dummy;
  getline( cin, dummy );
}

//Funcion que imprime un vectores de vectores segun la cantidad de elementos que contenga
void imprimirArreglo(vector<vector<int>> const &input)
{
  //se imprime el Vacio
  cout<<"[ ]"<<endl;
  //Recorre los vectores
  for (int i = 1; i<input.size(); i++)
  {
    cout<<"[";
    for (int j = 0; j<input[i].size(); j++)
    {
      cout << input[i][j];
      if(j != input[i].size()-1)
      {
        cout<<",";
      }
    }
    cout<<"]"<<endl;
  }
}

//Función que ordena los elementos de un vector de vectores según su tamaño
void ordenarElementos(vector<vector<int>> const &input)
{
  vector<vector<int>> arregloOrdenado;
  int aux=1;
  arregloOrdenado.push_back(input[0]); //Agrega el primer elemento del input al arreglo ordenado
  while(aux<input.size())
  {
    for (int i = 1; i < input.size(); i++)
    {
      if (input[i].size() == aux)
      {
        //Si el tamaño del vector en la posición i es igual a aux, se agrega al arreglo ordenado
        arregloOrdenado.push_back(input[i]);
      }
    }
    aux++;
  }
  //Llama a la función para imprimir el arreglo ordenado
  imprimirArreglo(arregloOrdenado);
}

//Función que construye los subconjuntos de un vector dado
void construirSubconjuntos(vector<int> const &a)
{
  int n = a.size();
  //`N` almacena el número total de subconjuntos
  int N = pow(2, n);
  vector<vector<int>> arregloSubconjuntos;
  //Generar cada subconjunto uno por uno
  for (int i = 0; i < N; i++)
  {
    vector<int> input;
    //Revisa cada bit de `i`
    for (int j = 0; j < n; j++)
    {
      //Si se establece el j-ésimo bit de `i`, imprime `S[j]`
      if (i & (1 << j)) 
      {
        input.push_back(a[j]);
      }
    }
    arregloSubconjuntos.push_back(input); //Primero a funcion que ordene los elementos
  }
  ordenarElementos(arregloSubconjuntos);
}

//Función que divide una cadena en un vector de enteros usando un delimitador
vector<int> split(string str, char coma)
{

  int posInicial = 0;
  int posFound = 0;
  string splitted;
  int splittedToInt;
  vector<int> results;

  while(posFound >= 0)
  {
    posFound = str.find(coma, posInicial);
    splitted = str.substr(posInicial, posFound - posInicial);
    splittedToInt = stoi(splitted);//Convierte el string a int
    posInicial = posFound + 1;
    results.push_back(splittedToInt);//Agrega el entero al vector de resultados
  }
  return results;
}

//Función que valida un vector de enteros
bool validacion(vector<int> arreglo)
{
  //Se valida el largo del arreglo
  if(arreglo.size()<=9 && arreglo.size()>=0)
  {
    //Se valida que cada elemento esté en el rango 0 <= x <= 9
    for(int i=0; i<arreglo.size(); i++)
    {
      if(arreglo[i]>9 || arreglo[i]<=0)
      {
        cout<<"error"<<endl;
        return true;
      }
    }
    return false; 
  }
  else
  {    
    cout<<"error"<<endl;
    return true;
  }
}

// Función que construye un arreglo a partir de una entrada del usuario
void construirArreglo()
{
  string conjunto;
  vector<int> arreglo;
  bool validar = true;
  do
  {
    cout << "Ingrese un conjunto separados por una ',' de 1 hasta el 9" << endl;
    cin >> conjunto;  
    arreglo = split(conjunto, ',');// Divide la entrada del usuario en un vector de enteros
    validar = validacion(arreglo); //Valida el vector generado
  }
  while(validar == true);
  construirSubconjuntos(arreglo);// Construye los subconjuntos del vector validado    
}

//Funcion recursiva que calcula el producto de Wallis
float wallisRecursivo(unsigned int n)
{
  float aux;
  if(n == 0)
  {
    //Caso cuando n es igual a 0, entonces el producto es igual a 1
    cout << " W = " << 1 << " cuando n = "<< 0 <<  endl;
    return 1;
  }
  else if(n % 2 == 0)
  {
     //Caso cuando n es par, se multiplica n/(n + 1) por el resultado de la llamada recursiva con n-1
     aux = (float)n / ((float)n + 1) * wallisRecursivo(n - 1);
     cout << " W = " << aux <<" cuando n = "<<n<< endl;
     return  aux;
  }
  else
  { 
     //Caso cuando es impar, se multiplica (n + 1)/n por el resultado de la llamada recursiva con n-1
     aux = ((float)n + 1) / (float)n * wallisRecursivo(n - 1);
     cout << " W = " << aux <<" cuando n = "<<n<< endl;
     return  aux;
  }
}

//Función de cola recursiva que calcula el producto de Wallis
double wallis_cola(unsigned int n, int max_n, double accumulator)
{
  if (n > max_n)
  {
    //Caso base: si n es mayor que max_n, se retorna el acumulador
    return accumulator;
  }
  if(n == 0)
  {
    //Si n es 0, se suma 1 al acumulador
    accumulator += 1;
  }
  else if(n % 2 == 0) 
  {
    //Si n es par, se multiplica el acumulador por n/(n + 1)
    accumulator *= ((double)n/((double)n+1));
  }
  else if(n % 2 == 1)
  {
    //Si n es impar, se multiplica el acumulador por (n + 1)/n
    accumulator *= (((double)n+1)/(double)n);
  }
  //Imprime el valor actual del acumulador
  cout << "W = " << accumulator << " cuando n = " << n << endl;
  //Llamada recursiva con n + 1
  return wallis_cola(n + 1, max_n, accumulator);
}

//Función que calcula el valor de π usando el producto de Wallis
void wallis_product(int terms) 
{
  double valor = wallis_cola(0, terms, 0)*2;
  // Imprime el valor de pi calculado
  cout << "el valor de pi es: " << valor << " con " << terms << " iteraciones" << endl;
}

//Python

import numpy as np
import os

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def encontrarPosición(multiListaDinamica, nivel):
    auxiliar = 0
    for i in multiListaDinamica:
        if isinstance(i, list):
            auxiliar += 1

        if nivel == auxiliar:
            return multiListaDinamica.index(i)

def menuDinamico(multiListaDinamica):
    while True:
        clear_screen()
        print("Nivel actual:", multiListaDinamica)
        elementos = elementosDentroDeMultiLista(multiListaDinamica)
        print("Actualmente existen", elementos, "listas en este nivel de multiLista")

        print("¿Qué deseas hacer?")
        print("1.- Ingresar valor en este nivel")
        print("2.- Crear lista / nivel nuevo (Se añade el nivel al final del nivel actual)")

        if elementos != 0:
            print("3.- Ingresar a un nivel de los", elementos, "disponibles:")

        print("4.- Salir / Volver al nivel inferior")

        try:
            eleccion = int(input("Elección: "))
        except ValueError:
            print("Por favor, ingrese un número válido.")
            continue

        if eleccion == 1:
            while True:
                valor = input("Ingrese el valor que desea ingresar (solo un carácter): ")
                if len(valor) == 1:
                    multiListaDinamica.append(valor)
                    print("Valor ingresado")
                    break
                else:
                    print("Por favor, ingrese solo un carácter.")
        elif eleccion == 2:
            multiListaDinamica.append([])
            print("Has entrado en el nivel creado")
            menuDinamico(multiListaDinamica[-1])
        elif eleccion == 3:
            if elementos == 0:
                print("No hay niveles disponibles para ingresar.")
            else:
                print("Nivel(es) disponibles:", elementos)
                try:
                    nivel = int(input("¿A qué nivel deseas entrar?: "))
                    if nivel <= 0 or nivel > elementos:
                        print("Ingrese un nivel válido.")
                    else:
                        posicion = encontrarPosición(multiListaDinamica, nivel)
                        menuDinamico(multiListaDinamica[posicion])
                except ValueError:
                    print("Por favor, ingrese un número válido.")
        elif eleccion == 4:
            break
        else:
            print("Ingrese un valor válido.")

def elementosDentroDeMultiLista(lista):
    numeroDeListas = 0
    for i in lista:
        if isinstance(i, list):
            numeroDeListas += 1
    return numeroDeListas

def main():
    print("Bienvenido al programa de creación de multiLista")
    multiLista = []
    menuDinamico(multiLista)

if __name__ == "__main__":
    main()
