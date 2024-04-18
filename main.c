#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
  char *nombre;
  char *apellido;
  int edad;
  char *sintoma;
  int prioridad;
} Persona;

typedef struct Node 
{
  Persona *data;
  struct Node *next;
} Node;

struct List 
{
  int size;
  Node *head;
  Node *tail;
  Node *current;
};

typedef struct List List;

List *list_create()
{
  List *list = (List *)malloc(sizeof(List));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  return list;
}

void limpiarPantalla()
{
  system("clear");
}

void pushFront(List *list, Persona *data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = list->head;
  list->head = node;
  if (list->tail == NULL)
  {
    list->tail = node;
  }
  list->size++;
}

void pushBack(List *list, Persona *data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  if (list->tail == NULL)
  {
    list->head = node;
    list->tail = node;
  }
  else
  {
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

void menu()
{
  puts("========================================");
  puts("=         MENU DE OPCIONES             =");
  puts("========================================");
  puts("1. Registrar paciente");
  puts("2. Asignar prioridad al paciente");
  puts("3. Mostrar lista de espera");
  puts("4. Atender al siguiente paciente");
  puts("5. Mostrar pacientes por prioridad");
  puts("6. Salir");
  printf("Ingrese una opcion: ");
}

int validar(const char *variable) {
  for (int i = 0; variable[i] != '\0'; i++) {
    if (!isalpha(variable[i]) && variable[i] != ' ') {
      return 0;
    }
  }
  return 1;
}

void registrarPaciente(List *list)
{
  limpiarPantalla();
  Persona *persona = (Persona *)malloc(sizeof(Persona));
  persona->prioridad = 1;
  persona->nombre = (char *)malloc(sizeof(char) * 50);
  persona->apellido = (char *)malloc(sizeof(char) * 50);
  persona->sintoma = (char *)malloc(sizeof(char) * 100);

  printf("Ingrese el nombre del paciente: ");
  scanf("%s", persona->nombre);
  if (!validar(persona->nombre)) {
    printf("Caracteres no válidos en el nombre. El paciente no se registrará.\n");
    free(persona->nombre);
    free(persona->apellido);
    free(persona->sintoma);
    free(persona);
    printf("Espere unos segundos para volver al menú principal\n");
    sleep(3);
    return;
  }

  printf("Ingrese el apellido del paciente: ");
  scanf("%s", persona->apellido);
  if (!validar(persona->apellido)) {
    printf("Caracteres no válidos en el apellido. El paciente no se registrará.\n");
    free(persona->nombre);
    free(persona->apellido);
    free(persona->sintoma);
    free(persona);
    printf("Espere unos segundos para volver al menú principal\n");
    sleep(3);
    return;
  }

  printf("Ingrese la edad del paciente: ");
  scanf("%d", &persona->edad);
  printf("Ingrese el síntoma del paciente: ");
  getchar();
  fgets(persona->sintoma, 100, stdin); 
  if (persona->sintoma[strlen(persona->sintoma) - 1] == '\n')
  {
    persona->sintoma[strlen(persona->sintoma) - 1] = '\0';
  }

  if (list->size == 0)
  {
    pushFront(list, persona);
  }
  else
  {
    pushBack(list, persona); 
  }
  printf("\n");
  printf("Paciente registrado con éxito.\n");
  printf("Espere unos segundos para volver al menu principal\n");
  sleep(3);
}

void asignarPrioridad(List *list)
{
  limpiarPantalla();
  if (list->head == NULL)
  {
    printf("No hay pacientes en la lista.\n");
  }
  else
  {
    char *nombreBusca = (char *)malloc(sizeof(char) * 50);
    char *apellidoBusca = (char *)malloc(sizeof(char) * 50);
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombreBusca);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellidoBusca);
    Node *current = list->head;
    while (current != NULL)
      {
        if (strcmp(current->data->nombre, nombreBusca) == 0 && 
            strcmp(current->data->apellido, apellidoBusca) == 0)
        {
          int prioridad;
          puts("========================================");
          puts("=             PRIORIDADES              =");
          puts("========================================");
          puts("1. Bajo");
          puts("2. Medio");
          puts("3. Alto");
          printf("Ingrese la prioridad del paciente: ");
          scanf("%d", &prioridad);
          current->data->prioridad = prioridad;
          printf("Prioridad asignada con éxito.\n");
          break;
        }
        else
        {
          current = current->next;
          if (current == NULL)
          {
            printf("No se encontró el paciente.\n");
          }
        }
      }
    printf("Espere unos segundos para volver al menu principal\n");
    sleep(3);
    return;
  }
}

void mostrarLista(List *list)
{
  if (list->head == NULL)
  {
    printf("No hay pacientes en la lista.\n\n");
  }
  else
  {
    int contador = 0;
    Node *current = list->head;
    while (current != NULL)
      {
        if (contador == 0)
        {
          printf("%-15s | %-15s | %-6s | %-25s | %-9s\n", "NOMBRE", "APELLIDO", "EDAD", "SINTOMA", "PRIORIDAD");
          contador++;
        }
        printf("%-15s | %-15s | %-6d | %-25s | ", current->data->nombre, current->data->apellido, current->data->edad, current->data->sintoma);
        char *prioridad;
        switch (current->data->prioridad)
          {
            case 1:
              prioridad = "Bajo";
              printf("%-9s\n", prioridad);
              break;
            case 2:
              prioridad = "Medio";
              printf("%-9s\n", prioridad);
              break;
            case 3:
              prioridad = "Alto";
              printf("%-9s\n", prioridad);
              break;
          }
        current = current->next;
      }
  }
  int opcion;
  while (1)
    {
      printf("\n");
      printf("Presione 1 para volver al menu principal: ");
      scanf("%d", &opcion);
      if (opcion == 1)
      {
        printf("Espere unos segundos para volver al menu principal\n");
        sleep(3);
        limpiarPantalla();
        break;
      }
      else
      {
        printf("Opción inválida. Pruebe otra vez\n");
      }  
    } 
}

void atenderPaciente(List *list)
{
  limpiarPantalla();
  if (list->head == NULL)
  {
    printf("No hay pacientes en la lista.\n");
  }
  else
  {
    Node *current = list->head;
    Node *prev = NULL;
    Node *pacienteAtendido = NULL;
    int prioridades[3] = {3, 2, 1};

    for (int i = 0; i < 3; i++)
    {
      current = list->head;
      prev = NULL;
      while (current != NULL)
      {
        if (current->data->prioridad == prioridades[i])
        {
          pacienteAtendido = current;
          break;
        }
        prev = current;
        current = current->next;
      }

      if (pacienteAtendido != NULL)
      {
        printf("Paciente atendido:\n");
        printf("Nombre: %s\n", pacienteAtendido->data->nombre);
        printf("Apellido: %s\n", pacienteAtendido->data->apellido);
        printf("Edad: %d\n", pacienteAtendido->data->edad);
        printf("Síntoma: %s\n", pacienteAtendido->data->sintoma);
        printf("Prioridad: %d\n", pacienteAtendido->data->prioridad);

        if (prev != NULL)
        {
          prev->next = pacienteAtendido->next;
        }
        else
        {
          list->head = pacienteAtendido->next;
        }

        free(pacienteAtendido->data->nombre);
        free(pacienteAtendido->data->apellido);
        free(pacienteAtendido->data->sintoma);
        free(pacienteAtendido->data);
        free(pacienteAtendido);

        printf("Paciente atendido con éxito.\n");
        break;
      }
    }
  }

  printf("Espere unos segundos para volver al menú principal\n");
  sleep(3);
}

void mostrarPacientes(List *list)
{
  
}

void limpiarLista(List *list)
{
  
}

int main(void) 
{
  char opcion;
  List *pacientes = list_create();
  do
    {
      limpiarPantalla();
      menu();
      scanf(" %c", &opcion);
      limpiarPantalla();

      switch(opcion)
        {
          case '1':
          registrarPaciente(pacientes);
          break;

          case '2':
          asignarPrioridad(pacientes);
          break;

          case '3':
          mostrarLista(pacientes);
          break;

          case '4':
          atenderPaciente(pacientes);
          break;

          case '5':
          mostrarPacientes(pacientes);
          break;

          case '6':
          break;
        }
    } while(opcion != '6');

  limpiarLista(pacientes);
}
