#include <stdio.h>
#include <stdlib.h>

enum tipoUsuario {ALUMNO, PROFESOR};
enum estadoUsuario {ACTIVO, INACTIVO};
// Definición de una estructura para almacenar los datos de usuario
struct Usuario {
    int id_usuario;
    enum tipoUsuario tipo;
    char nombre[45];
    char apellido[45];
    char email[255];
    char contrasena[32];
    enum estadoUsuario estado;
};

// Definición de una estructura para almacenar los datos de materia
struct Materia {
    int id_materia;
    char nombre[45];
};

// Definición de una estructura para almacenar los datos de curso
struct Curso {
    int id_cursada;
    char anio_division[45];
};

// Definición de una estructura para almacenar las calificaciones
struct Calificacion {
    int id_calificacion;
    int id_alumno;
    int id_materia;
    int nota;
    int num_examen;
};


// funciones para las operaciones de alta
void altaAlumno(){
    struct Usuario nuevoAlumno;
    printf("Ingrese el id del alumno: ");
    scanf("%d", &nuevoAlumno.id_usuario);
    nuevoAlumno.tipo = ALUMNO;
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nuevoAlumno.nombre);
    printf("Ingrese el apellido del alumno: ");
    scanf("%s", nuevoAlumno.apellido);
    printf("Ingrese el email del alumno: ");
    scanf("%s", nuevoAlumno.email);
    printf("Ingrese la contraseña del alumno: ");
    scanf("%s", nuevoAlumno.contrasena);
    nuevoAlumno.estado = ACTIVO;
}
void altaProfesor(){
    struct Usuario nuevoProfesor;
    printf("Ingrese el id del profesor: ");
    scanf("%d", &nuevoProfesor.id_usuario);
    nuevoProfesor.tipo = PROFESOR;
    printf("Ingrese el nombre del profesor: ");
    scanf("%s", nuevoProfesor.nombre);
    printf("Ingrese el apellido del profesor: ");
    scanf("%s", nuevoProfesor.apellido);
    printf("Ingrese el email del profesor: ");
    scanf("%s", nuevoProfesor.email);
    printf("Ingrese la contraseña del profesor: ");
    scanf("%s", nuevoProfesor.contrasena);
    nuevoProfesor.estado = ACTIVO;
}

void altaCurso(){
    struct Curso nuevoCurso;
    printf("Ingrese el id del curso: ");
    scanf("%d", &nuevoCurso.id_cursada);
    printf("Ingrese el año y división del curso: ");
    scanf("%s", nuevoCurso.anio_division);
}


void altaMateria(){
    struct Materia nuevaMateria;
    printf("Ingrese el id de la materia: ");
    scanf("%d", &nuevaMateria.id_materia);
    printf("Ingrese el nombre de la materia: ");
    scanf("%s", nuevaMateria.nombre);
}

void altaCalificacion(){
    struct Calificacion nuevaCalificacion;
    printf("Ingrese el id de la calificacion: ");
    scanf("%d", &nuevaCalificacion.id_calificacion);
    printf("Ingrese el id del alumno: ");
    scanf("%d", &nuevaCalificacion.id_alumno);
    printf("Ingrese el id de la materia: ");
    scanf("%d", &nuevaCalificacion.id_materia);
    printf("Ingrese la nota: ");
    scanf("%d", &nuevaCalificacion.nota);
    printf("Ingrese el numero de examen: ");
    scanf("%d", &nuevaCalificacion.num_examen);
}

// funciones para las operaciones de baja
void bajaAlumno(){
    struct Usuario bajaAlumno;
    printf("Ingrese el id del alumno a dar de baja: ");
    scanf("%d", &bajaAlumno.id_usuario);
}

void bajaProfesor(){
    struct Usuario bajaProfesor;
    printf("Ingrese el id del profesor a dar de baja: ");
    scanf("%d", &bajaProfesor.id_usuario);
}

// funciones para las operaciones de modificación
void modificarAlumno(){
    struct Usuario modificarAlumno;
    printf("Ingrese el id del alumno a modificar: ");
    scanf("%d", &modificarAlumno.id_usuario);
    printf("Ingrese el nombre del alumno a modificar: ");
    scanf("%s", modificarAlumno.nombre);
    printf("Ingrese el apellido del alumno a modificar: ");
    scanf("%s", modificarAlumno.apellido);
    printf("Ingrese el email del alumno a modificar: ");
    scanf("%s", modificarAlumno.email);
    printf("Ingrese la contraseña del alumno a modificar: ");
    scanf("%s", modificarAlumno.contrasena);
    printf("Ingrese el estado del alumno a modificar (activo/inactivo): ");
    scanf("%s", modificarAlumno.estado);
}

void modificarProfesor(){
    struct Usuario modificarProfesor;
    printf("Ingrese el id del profesor a modificar: ");
    scanf("%d", &modificarProfesor.id_usuario);
    printf("Ingrese el nombre del profesor a modificar: ");
    scanf("%s", modificarProfesor.nombre);
    printf("Ingrese el apellido del profesor a modificar: ");
    scanf("%s", modificarProfesor.apellido);
    printf("Ingrese el email del profesor a modificar: ");
    scanf("%s", modificarProfesor.email);
    printf("Ingrese la contraseña del profesor a modificar: ");
    scanf("%s", modificarProfesor.contrasena);
    printf("Ingrese el estado del profesor a modificar (activo/inactivo): ");
    scanf("%s", modificarProfesor.estado);
}

// funciones para las operaciones de consulta
//void consultarUsuarios();
//void consultarCursosMaterias();
//void consultarCalificaciones();

// Función para mostrar el menú principal
void menuPrincipal() {
    int opcion;
    
    do {
        system("cls"); // Limpiar la pantalla
        printf("----- Menu Principal -----\n");
        printf("1. Alumno\n");
        printf("2. Profesor\n");
        printf("3. Materia\n");
        printf("4. Curso\n");
        printf("5. Calificacion\n");
        printf("6. Consulta\n");
        printf("7. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Submenú de alumno
                submenuAlumno();
                break;
            case 2:
                // Submenú de profesor
                submenuProfesor();
                break;
            case 3:
                // Agregar una materia
                altaMateria();
                break;
            case 4:
                // Agregar un curso
                altaCurso();
                break;
            case 5:
                // Agregar una calificación
                altaCalificacion();
                break;
            case 6:
                // Submenú de consulta
                submenuConsulta();
                break;
            case 7:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida.\n");
                TeclaParaContinuar();
                break;
        }
    } while (opcion != 7);
}

void submenuAlumno() {
    int aluOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Menu de Alumno -----\n");
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificacion\n");
        printf("4. Consulta\n");
        printf("5. Volver al Menu Principal\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &aluOpcion);

        switch (aluOpcion) {
            case 1:
                altaAlumno();
                break;
            case 2:
                bajaAlumno();
                break;
            case 3:
                modificarAlumno();
                break;
            case 4:
                // consulta alumnos
                break;
            case 5:
                // Volver al menú principal
                break;
            default:
                printf("Opción no válida.\n");
                TeclaParaContinuar();
                break;
        }
    } while (aluOpcion != 5);
}

void submenuProfesor() {
    int profOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Menu de Profesor -----\n");
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificacion\n");
        printf("4. Consulta\n");
        printf("5. Volver al Menu Principal\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &profOpcion);

        switch (profOpcion) {
            case 1:
                altaProfesor();
                break;
            case 2:
                bajaProfesor();
                break;
            case 3:
                modificarProfesor();
                break;
            case 4:
                // consulta profesores
                break;
            case 5:
                // Volver al menú principal
                break;
            default:
                printf("Opción no válida.\n");
                TeclaParaContinuar();
                break;
        }
    } while (profOpcion != 5);
}

void submenuConsulta() {
    int altaOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Menu de Consulta -----\n");
        printf("1. Consultar Usuarios\n");
        printf("2. Consultar Cursos y Materias\n");
        printf("3. Consultar Calificaciones\n");
        printf("4. Volver al Menu Principal\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &altaOpcion);

        switch (altaOpcion) {
            case 1:
                //consultarUsuarios();
                break;
            case 2:
                //consultarCursosMaterias();
                break;
            case 3:
                //consultarCalificaciones();
                break;
            case 4:
                // Volver al menú principal
                break;
            default:
                printf("Opción no válida.\n");
                TeclaParaContinuar();
                break;
        }
    } while (altaOpcion != 4);
}

void TeclaParaContinuar() {
    printf("\nPresiona una tecla para continuar...");
    getch();
}

// Implementa las funciones de alta, baja, modificación y consulta aquí

int main() {
    menuPrincipal(); // Llama a la función del menú principal
    return 0;
}

