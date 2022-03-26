#ifndef LISTA_H
#define LISTA_H

template< typename Tipo >
class Lista{
public:
    Lista(); // constructor
    ~Lista(); // destructor
    void insertarAlFrente( const Tipo & );
    void insertarAlFinal( const Tipo & );
    bool eliminarDelFrente( Tipo & );
    bool eliminarDelFinal( Tipo & );
    bool estaVacia() const;
    void imprimir() const;
private:
    Nodo< Tipo > *primeroPtr; // apuntador al primer nodo
    Nodo< Tipo > *ultimoPtr; // apuntador al último nodo
    // función utilitaria para asignar un nuevo nodo
    Nodo< Tipo > *obtenerNuevoNodo( const Tipo & );
}; // fin de la clase Lista

// constructor predeterminado
template< typename Tipo >
Lista< Tipo >::Lista()
    : primeroPtr( 0 ), ultimoPtr( 0 ){ }

// destructor
template< typename Tipo >
Lista< Tipo >::~Lista(){
    if ( !estaVacia() ) // la Lista no está vacía
    {
        cout << "Destruyendo nodos ...\n";
        Nodo< Tipo > *actualPtr = primeroPtr;
        Nodo< Tipo > *tempPtr;
        while ( actualPtr != 0 ){ // elimina los nodos restantes
            tempPtr = actualPtr;
            cout << tempPtr->datos << "\t";
            actualPtr = actualPtr->siguientePtr;
            delete tempPtr;
        } // fin de while
    } // fin de if
    cout << "Se destruyeron todos los nodos\n\n";
} // fin del destructor de Lista

// inserta un nodo al frente de la lista
template< typename Tipo >
void Lista< Tipo >::insertarAlFrente( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo
    if ( estaVacia() ) // la Lista está vacía
        primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
    else{ // la Lista no está vacía
        nuevoPtr->siguientePtr = primeroPtr; // apunta el nuevo nodo al nodo que antes era el primero
        primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
    } // fin de else
} // fin de la función insertarAlFrente

// inserta un nodo al final de la lista
template< typename Tipo >
void Lista< Tipo >::insertarAlFinal( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo
    if ( estaVacia() ) // la Lista está vacía
        primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
    else{ // la Lista no está vacía
        ultimoPtr->siguientePtr = nuevoPtr; // actualiza el nodo que antes era el último
        ultimoPtr = nuevoPtr; // nuevo último nodo
    } // fin de else
} // fin de la función insertarAlFinal

// elimina un nodo de la parte frontal de la lista
template< typename Tipo >
bool Lista< Tipo >::eliminarDelFrente( Tipo &valor ){
    if ( estaVacia() ) // la Lista está vacía
        return false; // la eliminación no tuvo éxito
    else{
        Nodo< Tipo > *tempPtr = primeroPtr; // contiene tempPtr a eliminar
        if ( primeroPtr == ultimoPtr )
            primeroPtr = ultimoPtr = 0; // no hay nodos después de la eliminación
        else
            primeroPtr = primeroPtr->siguientePtr; // apunta al nodo que antes era el segundo
        valor = tempPtr->datos; // devuelve los datos que se van a eliminar
        delete tempPtr; // reclama el nodo que antes era el primero
        return true; // la eliminación tuvo éxito
    } // fin de else
} // fin de la función eliminarDelFrente

// elimina un nodo de la parte final de la lista
template< typename Tipo >
bool Lista< Tipo >::eliminarDelFinal( Tipo &valor ){
    if ( estaVacia() ) // la Lista está vacía
        return false; // la eliminación no tuvo éxito
    else{
        Nodo< Tipo > *tempPtr = ultimoPtr; // contiene tempPtr a eliminar
        if ( primeroPtr == ultimoPtr ) // la Lista tiene un elemento
            primeroPtr = ultimoPtr = 0; // no hay nodos después de la eliminación
        else{
            Nodo< Tipo > *actualPtr = primeroPtr;
            // localiza el penúltimo elemento
            while ( actualPtr->siguientePtr != ultimoPtr )
                actualPtr = actualPtr->siguientePtr; // se desplaza al siguiente nodo
            ultimoPtr = actualPtr; // elimina el último nodo
            actualPtr->siguientePtr = 0; // ahora éste es el último nodo
        } // fin de else
        valor = tempPtr->datos; // devuelve el valor del nodo que antes era el último
        delete tempPtr; // reclama el nodo que antes era el último
        return true; // la eliminación tuvo éxito
    } // fin de else
} // fin de la función eliminarDelFinal

// ¿está la Lista vacía?
template< typename Tipo >
bool Lista< Tipo >::estaVacia() const{
    return primeroPtr == 0;
} // fin de la función estaVacia

// devuelve el apuntador al nodo recién asignado
template< typename Tipo >
Nodo< Tipo > *Lista< Tipo >::obtenerNuevoNodo(const Tipo &valor ){
    return new Nodo< Tipo >( valor );
} // fin de la función obtenerNuevoNodo

// muestra el contenido de la Lista
template< typename Tipo >
void Lista< Tipo >::imprimir() const{
    if ( estaVacia() ) {// la Lista está vacía
        cout << "La lista esta vacia\n\n";
        return;
    } // fin de if
    Nodo< Tipo > *actualPtr = primeroPtr;
    cout << "La lista es: ";
    while ( actualPtr != 0 ) {// obtiene los datos del elemento
        cout << actualPtr->datos << "\t";
        actualPtr = actualPtr->siguientePtr;
        //sleep(1);
    } // fin de while
    cout << "\n\n";
} // fin de la función imprimir
#endif
