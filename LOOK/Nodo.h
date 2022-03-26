#ifndef NODO_H
#define NODO_H
// declaración anticipada de la clase Lista, requerida para anunciar que la clase
// Lista existe y poder utilizarla en la declaración friend de la línea 13
template< typename Tipo > class Lista;
template< typename Tipo >
class Nodo{
    friend class Lista< Tipo >; // hace de Lista una amiga
public:
    Nodo( const Tipo & ); // constructor
    Tipo obtenerDatos() const; // devuelve los datos en el nodo
private:
    Tipo datos; // datos
    Nodo< Tipo > *siguientePtr; // siguiente nodo en la lista
}; // fin de la clase NodoLista

// constructor
template< typename Tipo >
Nodo< Tipo >::Nodo( const Tipo &info )
    : datos( info ), siguientePtr( 0 ){ }

// devuelve una copia de los datos en el nodo
template< typename Tipo >
Tipo Nodo< Tipo >::obtenerDatos() const
{
    return datos;
} // fin de la función obtenerDatos
#endif
