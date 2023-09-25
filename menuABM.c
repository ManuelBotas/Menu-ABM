#include <stdio.h>
#include <stdlib.h>

// Definición de una estructura para almacenar los datos de usuario
struct Usuario {
    int id_usuario;
    char nombre[45];
    char apellido[45];
    char email[255];
    char contrasena[32];
    char estado[10];
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
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nuevoAlumno.nombre);
    printf("Ingrese el apellido del alumno: ");
    scanf("%s", nuevoAlumno.apellido);
    printf("Ingrese el email del alumno: ");
    scanf("%s", nuevoAlumno.email);
    printf("Ingrese la contraseña del alumno: ");
    scanf("%s", nuevoAlumno.contrasena);
    printf("Ingrese el estado del alumno (activo/inactivo): ");
    scanf("%s", nuevoAlumno.estado);
}
void altaProfesor(){
    struct Usuario nuevoProfesor;
    printf("Ingrese el nombre del profesor: ");
    scanf("%s", nuevoProfesor.nombre);
    printf("Ingrese el apellido del profesor: ");
    scanf("%s", nuevoProfesor.apellido);
    printf("Ingrese el email del profesor: ");
    scanf("%s", nuevoProfesor.email);
    printf("Ingrese la contraseña del profesor: ");
    scanf("%s", nuevoProfesor.contrasena);
    printf("Ingrese el estado del profesor (activo/inactivo): ");
    scanf("%s", nuevoProfesor.estado);
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
    printf("Ingrese el nombre del alumno a dar de baja: ");
    scanf("%s", bajaAlumno.nombre);
    printf("Ingrese el apellido del alumno a dar de baja: ");
    scanf("%s", bajaAlumno.apellido);
    printf("Ingrese el email del alumno a dar de baja: ");
    scanf("%s", bajaAlumno.email);
    printf("Ingrese la contraseña del alumno a dar de baja: ");
    scanf("%s", bajaAlumno.contrasena);
    printf("Ingrese el estado del alumno a dar de baja (activo/inactivo): ");
    scanf("%s", bajaAlumno.estado);
}

void bajaProfesor(){
    struct Usuario bajaProfesor;
    printf("Ingrese el nombre del profesor a dar de baja: ");
    scanf("%s", bajaProfesor.nombre);
    printf("Ingrese el apellido del profesor a dar de baja: ");
    scanf("%s", bajaProfesor.apellido);
    printf("Ingrese el email del profesor a dar de baja: ");
    scanf("%s", bajaProfesor.email);
    printf("Ingrese la contraseña del profesor a dar de baja: ");
    scanf("%s", bajaProfesor.contrasena);
    printf("Ingrese el estado del profesor a dar de baja (activo/inactivo): ");
    scanf("%s", bajaProfesor.estado);
}

void bajaMateria(){
    struct Materia bajaMateria; 
    printf("Ingrese el id de la materia a dar de baja: ");
    scanf("%d", &bajaMateria.id_materia);
    printf("Ingrese el nombre de la materia a dar de baja: ");
    scanf("%s", bajaMateria.nombre);
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

void modificarMateria(){
    struct Materia modificarMateria;
    printf("Ingrese el id de la materia a modificar: ");
    scanf("%d", &modificarMateria.id_materia);
    printf("Ingrese el nombre de la materia a modificar: ");
    scanf("%s", modificarMateria.nombre);
}

// funciones para las operaciones de consulta
//void consultarUsuarios();
//void consultarCursosMaterias();
//void consultarCalificaciones();

// Función para mostrar el menú principal
void menuPrincipal() {
    int opcion;

    int altaOpcion; // Declarar aquí las variables de los submenús
    int bajaOpcion;
    int modificacionOpcion;
    int consultaOpcion;

    while (1) {
        system("cls"); // Limpiar la pantalla
        printf("----- Menu Principal -----\n");
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificacion\n");
        printf("4. Consulta\n");
        printf("5. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Submenú de alta
                while (1) {
                    system("cls"); // Limpiar la pantalla
                    printf("\n----- Menu de Alta -----\n");
                    printf("1. Alumno\n");
                    printf("2. Profesor\n");
                    printf("3. Materia\n");
                    printf("4. Volver al Menu Principal\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &altaOpcion);

                    switch (altaOpcion) {
                        case 1:
                            altaAlumno();
                            break;
                        case 2:
                            //altaProfesor();
                            break;
                        case 3:
                            //altaMateria();
                            break;
                        case 4:
                            // Volver al menú principal
                            break;
                        default:
                            printf("Opción no válida. Inténtalo de nuevo.\n");
                            break;
                    }

                    if (altaOpcion == 4) {
                        break; // Salir del submenú de alta
                    }
                }
                break;
            case 2:
                // Submenú de baja
                while (1) {
                    system("cls"); // Limpiar la pantalla
                    printf("\n----- Menu de Baja -----\n");
                    printf("1. Alumno\n");
                    printf("2. Profesor\n");
                    printf("3. Materia\n");
                    printf("4. Volver al Menu Principal\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &bajaOpcion);

                    switch (bajaOpcion) {
                        case 1:
                            //bajaAlumno();
                            break;
                        case 2:
                            //bajaProfesor();
                            break;
                        case 3:
                            //bajaMateria();
                            break;
                        case 4:
                            // Volver al menú principal
                            break;
                        default:
                            printf("Opción no válida. Inténtalo de nuevo.\n");
                            break;
                    }

                    if (bajaOpcion == 4) {
                        break; // Salir del submenú de baja
                    }
                }
                break;
            case 3:
                // Submenú de modificación
                while (1) {
                    system("cls"); // Limpiar la pantalla
                    printf("\n----- Menu de Modificacion -----\n");
                    printf("1. Alumno\n");
                    printf("2. Profesor\n");
                    printf("3. Materia\n");
                    printf("4. Volver al Menu Principal\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &modificacionOpcion);

                    switch (modificacionOpcion) {
                        case 1:
                            //modificarAlumno();
                            break;
                        case 2:
                            //modificarProfesor();
                            break;
                        case 3:
                            //modificarMateria();
                            break;
                        case 4:
                            // Volver al menú principal
                            break;
                        default:
                            printf("Opción no válida. Inténtalo de nuevo.\n");
                            break;
                    }

                    if (modificacionOpcion == 4) {
                        break; // Salir del submenú de modificación
                    }
                }
                break;
            case 4:
                // Submenú de consulta
                while (1) {
                    printf("\n----- Menú de Consulta -----\n");
                    printf("1. Consultar Usuarios\n");
                    printf("2. Consultar Cursos y Materias\n");
                    printf("3. Consultar Calificaciones\n");
                    printf("4. Volver al Menú Principal\n");
                    printf("Selecciona una opción: ");
                    scanf("%d", &consultaOpcion);

                    switch (consultaOpcion) {
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
                            printf("Opción no válida. Inténtalo de nuevo.\n");
                            break;
                    }

                    if (consultaOpcion == 4) {
                        break; // Salir del submenú de consulta
                    }
                }
                break;
            case 5:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                exit(0);
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
                break;
        }
    }
}

// Implementa las funciones de alta, baja, modificación y consulta aquí

int main() {
    menuPrincipal(); // Llama a la función del menú principal
    return 0;
}

