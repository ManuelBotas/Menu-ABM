#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

// Prototipos de funciones
void menuPrincipal();
void submenuAlumno(FILE *);
void submenuProfesor(FILE *);
void submenuConsulta();
void TeclaParaContinuar();
void altaAlumno(FILE *);
void altaProfesor(FILE *);
void altaMateria(FILE *);
void altaCurso(FILE *);
void altaCalificacion(FILE *);
void bajaAlumno(FILE *);
void bajaProfesor(FILE *);
void modificarAlumno(FILE *);
void modificarProfesor(FILE *);

int main() {
    menuPrincipal(); // Llama a la función del menú principal
    return 0;
}

// funciones para las operaciones de alta
void altaAlumno(FILE *fAlumnos){
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
    printf("Ingrese la contrase%ca del alumno: ", 164);
    scanf("%s", nuevoAlumno.contrasena);
    nuevoAlumno.estado = ACTIVO;
    fwrite(&nuevoAlumno, sizeof(struct Usuario), 1, fAlumnos);
}
void altaProfesor(FILE *fProfesores){
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
    printf("Ingrese la contrase%Ca del profesor: ", 164);
    scanf("%s", nuevoProfesor.contrasena);
    nuevoProfesor.estado = ACTIVO;
    fwrite(&nuevoProfesor, sizeof(struct Usuario), 1, fProfesores);
}

void altaCurso(FILE *fCursos){
    struct Curso nuevoCurso;
    printf("Ingrese el id del curso: ");
    scanf("%d", &nuevoCurso.id_cursada);
    printf("Ingrese el a%co y divisi%cn del curso: ", 164, 162);
    scanf("%s", nuevoCurso.anio_division);
    fwrite(&nuevoCurso, sizeof(struct Curso), 1, fCursos);
}


void altaMateria(FILE *fMaterias){
    struct Materia nuevaMateria;
    printf("Ingrese el id de la materia: ");
    scanf("%d", &nuevaMateria.id_materia);
    printf("Ingrese el nombre de la materia: ");
    scanf("%s", nuevaMateria.nombre);
    fwrite(&nuevaMateria, sizeof(struct Materia), 1, fMaterias);
}

void altaCalificacion(FILE *fCalificaciones){
    struct Calificacion nuevaCalificacion;
    printf("Ingrese el id de la calificaci%cn: ", 162);
    scanf("%d", &nuevaCalificacion.id_calificacion);
    printf("Ingrese el id del alumno: ");
    scanf("%d", &nuevaCalificacion.id_alumno);
    printf("Ingrese el id de la materia: ");
    scanf("%d", &nuevaCalificacion.id_materia);
    printf("Ingrese la nota: ");
    scanf("%d", &nuevaCalificacion.nota);
    printf("Ingrese el n%cmero de examen: ", 163);
    scanf("%d", &nuevaCalificacion.num_examen);
    fwrite(&nuevaCalificacion, sizeof(struct Calificacion), 1, fCalificaciones);
}

// funciones para las operaciones de baja
void bajaAlumno(FILE *fAlumnos){
    struct Usuario bajaAlumno;
    printf("Ingrese el id del alumno a dar de baja: ");
    scanf("%d", &bajaAlumno.id_usuario);
}

void bajaProfesor(FILE *fProfesores){
    struct Usuario bajaProfesor;
    printf("Ingrese el id del profesor a dar de baja: ");
    scanf("%d", &bajaProfesor.id_usuario);
}

// funciones para las operaciones de modificación
void modificarAlumno(FILE *fAlumnos){
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

void modificarProfesor(FILE *fProfesores){
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
    FILE *fAlumnos, *fProfesores, *fMaterias, *fCursos, *fCalificaciones;
    if ((fAlumnos = fopen("alumnos.dat", "rb+")) == NULL)
    {
        fAlumnos = fopen("alumnos.dat", "wb+");
    }
    if ((fProfesores = fopen("profesores.dat", "rb+")) == NULL)
    {
        fProfesores = fopen("profesores.dat", "wb+");
    }
    if ((fMaterias = fopen("materias.dat", "rb+")) == NULL)
    {
        fMaterias = fopen("materias.dat", "wb+");
    }
    if ((fCursos = fopen("cursos.dat", "rb+")) == NULL)
    {
        fCursos = fopen("cursos.dat", "wb+");
    }
    if ((fCalificaciones = fopen("calificaciones.dat", "rb+")) == NULL)
    {
        fCalificaciones = fopen("calificaciones.dat", "wb+");
    }
    do {
        system("cls"); // Limpiar la pantalla
        printf("----- Men%c Principal -----\n", 163);
        printf("1. Alumno\n");
        printf("2. Profesor\n");
        printf("3. Materia\n");
        printf("4. Curso\n");
        printf("5. Calificaci%cn\n", 162);
        printf("6. Consulta\n");
        printf("7. Salir\n");
        printf("Selecciona una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Submenú de alumno
                submenuAlumno(fAlumnos);
                break;
            case 2:
                // Submenú de profesor
                submenuProfesor(fProfesores);
                break;
            case 3:
                // Agregar una materia
                altaMateria(fMaterias);
                break;
            case 4:
                // Agregar un curso
                altaCurso(fCursos);
                break;
            case 5:
                // Agregar una calificación
                altaCalificacion(fCalificaciones);
                break;
            case 6:
                // Submenú de consulta
                submenuConsulta();
                break;
            case 7:
                printf("Saliendo del programa. %cHasta luego!\n", 173);
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                TeclaParaContinuar();
                break;
        }
    } while (opcion != 7);
    fclose(fAlumnos);
    fclose(fProfesores);
    fclose(fMaterias);
    fclose(fCursos);
    fclose(fCalificaciones);
}

void submenuAlumno(FILE *fAlumnos) {
    int aluOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Men%c de Alumno -----\n", 163);
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificaci%cn\n", 162);
        printf("4. Consulta\n");
        printf("5. Volver al Men%c Principal\n", 163);
        printf("Selecciona una opci%cn: ", 162);
        scanf("%d", &aluOpcion);

        switch (aluOpcion) {
            case 1:
                altaAlumno(fAlumnos);
                break;
            case 2:
                bajaAlumno(fAlumnos);
                break;
            case 3:
                modificarAlumno(fAlumnos);
                break;
            case 4:
                // consulta alumnos
                break;
            case 5:
                // Volver al menú principal
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                TeclaParaContinuar();
                break;
        }
    } while (aluOpcion != 5);
}

void submenuProfesor(FILE *fProfesores) {
    int profOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Men%c de Profesor -----\n", 163);
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificaci%cn\n", 162);
        printf("4. Consulta\n");
        printf("5. Volver al Men%c Principal\n", 163);
        printf("Selecciona una opci%cn: ", 162);
        scanf("%d", &profOpcion);

        switch (profOpcion) {
            case 1:
                altaProfesor(fProfesores);
                break;
            case 2:
                bajaProfesor(fProfesores);
                break;
            case 3:
                modificarProfesor(fProfesores);
                break;
            case 4:
                // consulta profesores
                break;
            case 5:
                // Volver al menú principal
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                TeclaParaContinuar();
                break;
        }
    } while (profOpcion != 5);
}

void submenuConsulta() {
    int altaOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Men%c de Consulta -----\n", 163);
        printf("1. Consultar Usuarios\n");
        printf("2. Consultar Cursos y Materias\n");
        printf("3. Consultar Calificaciones\n");
        printf("4. Volver al Men%c Principal\n", 163);
        printf("Selecciona una opci%cn: ", 162);
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
                printf("Opci%cn no v%clida.\n", 162, 160);
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