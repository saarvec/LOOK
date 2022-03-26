
void instrucciones(){
    cout<< "Escriba una de las siguentes opciones:\n"
        << "1.-> para CSCAN\n"
        << "0.-> para terminar el procesamiento de la lista\n";
} // fin de la función instrucciones

template< typename T >
void probarLista( Lista< T > &objetoLista, const string &nombreTipo ){
    cout << "Prueba de una Lista de valores tipo " << nombreTipo << "\n";
    instrucciones(); // muestra las instrucciones
    int opcion; // almacena la opción del usuario
    T valor; // almacena el valor de entrada
    vector<T> V;
    V.push_back(160);//deben agregar la opción de que esto sea ingresado por el usuario
    V.push_back(30);
    V.push_back(50);
    V.push_back(25);
    V.push_back(45);
    V.push_back(65);
    V.push_back(100);
    V.push_back(120);
    V.push_back(75);
    V.push_back(180);
    do{ // realiza las acciones seleccionadas por el usuario
        cout << "? ";
        cin >> opcion;
        switch ( opcion ){
        case 1:{ // LOOK
            //Hacia Arriba (Subiendo)
            objetoLista.insertarAlFinal( 40 );
            int  P=40, tmp, Pos;
            bool Hay = true;
            for( ; Hay; ){
                Hay = false;
                tmp = 199;
                for(int j=0; j<V.size(); j++){
                    if( V[j] > P ){
                        if( V[j]-P < tmp){
                            tmp = V[j]-P;
                            Pos = j;
                            Hay = true;
                        }
                    }
                }
                if( Hay ){
                    objetoLista.insertarAlFinal( V[Pos] );
                    objetoLista.imprimir();
                    sleep(1);
                    V.erase(V.begin()+Pos);
                }
            }

            //Estudiantes Harán hacia Abajo (Bajada) del LOOK
            break;}
         } // fin de switch
    } while ( opcion != 0 ); // fin de do...while
    cout << "Fin de la prueba de la lista\n\n";
} // fin de la función probarLista
// muestra las instrucciones del programa al usuario



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // prueba Lista de valores int
    Lista< int > Procesos;
    probarLista( Procesos, "entero" );
    return 0;
}
