# Tarea 1 - Sistema Hospital

Este programa en C es un sistema básico para gestionar pacientes en un hospital. Permite realizar acciones como registrar pacientes, asignar prioridades, mostrar la lista de espera, atender al siguiente paciente, mostrar pacientes por prioridad, y limpiar la lista de pacientes.

## Estructuras de datos utilizadas

El programa utiliza las siguientes estructuras de datos:

- `Persona`: Estructura que representa a un paciente con campos como nombre, apellido, edad, síntoma y prioridad.
- `Node`: Estructura que representa un nodo en una lista enlazada que contiene datos de tipo `Persona`.
- `List`: Estructura que representa una lista enlazada de nodos.

## Funciones principales

El programa incluye las siguientes funciones principales:

- `list_create()`: Función para crear una lista enlazada.
- `limpiarPantalla()`: Función para limpiar la pantalla.
- `pushFront()`: Función para agregar un nodo al principio de la lista.
- `pushBack()`: Función para agregar un nodo al final de la lista.
- `menu()`: Función para mostrar un menú de opciones.
- `validar()`: Función para validar caracteres alfanuméricos en una cadena.
- `registrarPaciente()`: Función para registrar un nuevo paciente.
- `asignarPrioridad()`: Función para asignar prioridad a un paciente.
- `mostrarLista()`: Función para mostrar la lista de pacientes.
- `atenderPaciente()`: Función para atender al primer paciente con la prioridad mas alta.
- `limpiarLista()`: Función para limpiar la lista de pacientes.

Esta funcion aun no esta disponible, pero lo estara prontamente
- `mostrarPacientes()`: Función para mostrar pacientes por prioridad.
