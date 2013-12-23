TARGETS=final
CC=gcc 
CFLAGS= -Wall -lmysqlclient

all: $(TARGETS)

final: agregarAdmin.c acomodarGeneros.c acomodarRelaciones.c agregar.c agregarPelicula.c agregarPersona.c agregarRelacion.c agregarRelacionGenero.c atofec.c buscar.c cadenaBuscadora.c cambiarImportancia.c cambiarPass.c checkearFecha.c crearPersonaje.c createRanking.c displayActors.c displayCast.c displayDEP.c displayFecha.c displayGenero.c displayNombrePersona.c displayParts.c displayVoting.c eliminarAdmin.c eliminar.c eliminarGenero.c eliminarGenerosPelicula.c eliminarRelacion.c eliminarRelacionesPelicula.c generos.c historial.c insertarRelaciones.c login.c logout.c longerString.c main.c mandarQuery.c menuAdministrador.c menuEliminar.c menuModificar.c menuMostrar.c menuPerfil.c menuPrincipal.c misPeliculas.c modificarPelicula.c modificarPersona.c modificarPersonaje.c modificarRelacion.c mostrarBusqueda.c  mostrarGeneros.c mostrarPelicula.c mostrarPersona.c mostrarPersonaje.c mostrarTodos.c mostrarTrabajo.c MPagregar.c MPeliminar.c MPmostrarCategoria.c MPmostrarGenero.c MPmostrarLista.c MPmostrarTituloNodo.c MPmostrarTodos.c MPmoverALista.c MPordenar.c MPrealOrdenar.c MPswap.c MPtraer.c MPvaciar.c qRetrieve.c qStore.c ranking.c realLogin.c registrar.c relacionActores.c setImportancia.c traerPelicula.c traerPersona.c votar.c 
	clear
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS)

test: final
	clear
	./final
