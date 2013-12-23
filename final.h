#ifndef _FINAL_H_
	#define _FINAL_H_
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <assert.h>
	#include <mysql/mysql.h>
	typedef struct{
		int anio;
		int mes;
		int dia;
	} Fecha;
	typedef struct{
		int id;
		char * titulo;
		Fecha estreno; 
		char * origen;
		char * idioma;
	} Pelicula;
	typedef struct{
		int id;
		char * nombre;
		Fecha nacimiento;
		char * origen;
	} Persona;
	typedef struct{
		int id;
		char* username;
		int admin;
	} User;
	typedef struct{
		int pelicula;
		int persona;
		int tipo;
		int personajeId;
		char * personajeDesc;
		int importancia;
	} Relacion;
	typedef struct P{
		Relacion * valor;
		struct P * sig;
	} NodoRelacion;
	typedef struct N{
		struct N * ant;
		struct N  *sig;
		int categoria;
		int idPelicula;
		char *titulo;
		int anio;
		int voto;
		
	} NodoListaDoble;



	void menuPrincipal(User *);
	Fecha atofec (char *);
	MYSQL_RES * mandarQuery(char *);
	User * registrar();
	User * login();
	User * realLogin(char *, char *);
	void logout(User **);
	int buscar(User *, int);
	void generos(User *);
	void top10();
	void bottom5();
	void ranking(int, int, int);
	MYSQL_RES * createRanking(int, int,int);
	void agregarPelicula();
	void agregarPersona();
	void agregarRelacion(int);
	void agregarRelacionGenero(int);
	int checkearFecha(Fecha);
	int crearPersonaje(char *);
	void qStore (Relacion *, NodoRelacion **, NodoRelacion **);
	char * qRetrieve (NodoRelacion **, NodoRelacion **);
	void insertarRelaciones(NodoRelacion **,NodoRelacion **);
	void mostrarPelicula(User *, int);
	void mostrarPersona(User *, int);
	void mostrarPersonaje(User *, int);
	void menuMostrar(User *);
	void mostrarTodos(int, User *);
	Pelicula * traerPelicula(int);
	Persona * traerPersona(int);
	void mostrarGeneros();
	void displayCast(int, int);
	void displayGenero(int);
	void displayActors(int);
	void displayParts(int);
	void displayDEP(int, int);
	char * displayNombrePersona(int);
	void displayVoting(User *,int);
	char * displayFecha(Fecha);
	void votar(User *,int);
	void mostrarTrabajo(int);
	int mostrarBusqueda(char *, int);
	char * cadenaBuscadora (char *, int);
	Relacion * relacionActores(Relacion *);
	Relacion * setImportancia(Relacion *, NodoRelacion *);
	int menuPerfil(User *);
	void menuAdministrador(User *);
	void menuModificar(void);
	void menuEliminar(void);
	void misPeliculas(User *);
	void historial(User *);
	void cambiarPass(User *);
	char * longerString (char *, int);
	void agregarAdmin (User *);
	void eliminarAdmin (User *);
	void eliminar (int);
	void eliminarRelacion (void);
	void eliminarGenero(void);
	void agregar(User *,int);
	void modificarPelicula(int);
	void modificarPersona(int);
	void modificarPersonaje(int);
	void modificarRelacion(void);
	void eliminarRelacionesPelicula(void);
	void eliminarGenerosPelicula(void);
	void cambiarImportancia(int, int, int);
	void acomodarRelaciones(int);
	void acomodarGeneros(int);
	int MPtraer(NodoListaDoble **,NodoListaDoble **,int);
	void MPmostrarLista(NodoListaDoble *,NodoListaDoble *);
	char * MPmostrarTituloNodo(NodoListaDoble);
	void MPagregar(NodoListaDoble **,NodoListaDoble **, NodoListaDoble);
	void MPordenar(NodoListaDoble **, NodoListaDoble **, int);
	void MPswap (NodoListaDoble *, NodoListaDoble *, NodoListaDoble **, NodoListaDoble **, int);
	int MPeliminar (NodoListaDoble **, NodoListaDoble **, int, int);
	void MPrealOrdenar (NodoListaDoble **, NodoListaDoble **, int, int);
	int MPmostrarCategoria(NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, int);
	int MPmostrarGenero(NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, int);
	NodoListaDoble* MPmoverALista(NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, NodoListaDoble **);
	int MPmostrarTodos(NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, NodoListaDoble **, int);
	void MPvaciar(NodoListaDoble **, NodoListaDoble **);



	#endif
