#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef enum {ALUMNO, PROFESOR}tipoUsuario;
typedef enum {ACTIVO, INACTIVO}estadoUsuario;
// Definición de una estructura para almacenar los datos de usuario
typedef struct {
    int id_usuario;
    tipoUsuario tipo;
    char nombre[45];
    char apellido[45];
    char email[255];
    char contrasena[32];
    estadoUsuario estado;
}Usuario;

// Definición de una estructura para almacenar los datos de materia
typedef struct {
    int id_materia;
    char nombre[45];
}Materia;

// Definición de una estructura para almacenar los datos de curso
typedef struct {
    int id_cursada;
    char anio_division[45];
}Curso;

// Definición de una estructura para almacenar las calificaciones
typedef struct {
    int id_calificacion;
    int id_alumno;
    int id_materia;
    int nota;
    int num_examen;
}Calificacion;

// Prototipos de funciones
void altaAlumno(FILE *);
void altaProfesor(FILE *);
void altaCurso(FILE *);
void altaMateria(FILE *);
void altaCalificacion(FILE *);
void bajaAlumno(FILE *);
void bajaProfesor(FILE *);
void modificarAlumno(FILE *);
void modificarProfesor(FILE *);
void modificarCurso(FILE *);
void menuPrincipal();
void submenuAlumno(FILE *);
void submenuProfesor(FILE *);
void submenuCurso(FILE *);
void submenuMateria(FILE *);
void submenuCalificacion(FILE *);
void submenuConsulta();
void TeclaParaContinuar();
const char* getTipoUsuario(tipoUsuario);
const char* getEstadoUsuario(estadoUsuario);
Usuario buscarAlumno(FILE *, int);
Usuario buscarProfesor(FILE *, int);
Curso buscarCurso(FILE *, int);
void consultarAlumnos(FILE *);
void consultarProfesores(FILE *);
void consultarMaterias(FILE *);
void consultarCursos(FILE *);
void consultarCalificaciones(FILE *);

int main() {
    menuPrincipal(); // Llama a la función del menú principal
    return 0;
}

// funciones para las operaciones de alta
void altaAlumno(FILE *fAlumnos){
    Usuario nuevoAlumno;
    Usuario alumno;
    printf("Ingrese el id del alumno: ");
    scanf("%d", &nuevoAlumno.id_usuario);
    alumno = buscarAlumno(fAlumnos, nuevoAlumno.id_usuario);
    if (alumno.id_usuario == nuevoAlumno.id_usuario){
        if (alumno.estado == ACTIVO){
            printf("Ya existe un alumno con ese id.\n");
        } else {
            printf("Ya existe un alumno con ese id, pero se encuentra inactivo.\n");
            printf("Desea darlo de alta? (s/n): ");
            char opcion;
            fflush(stdin);
            scanf("%c", &opcion);
            if (opcion == 's'){
                alumno.estado = ACTIVO;
                fseek(fAlumnos, -sizeof(Usuario), SEEK_CUR);
                fwrite(&alumno, sizeof(Usuario), 1, fAlumnos);
            }
        }
        TeclaParaContinuar();
    } else {
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
        fseek(fAlumnos, 0L, SEEK_END);
        fwrite(&nuevoAlumno, sizeof(Usuario), 1, fAlumnos);
    }
}

void altaProfesor(FILE *fProfesores){
    Usuario nuevoProfesor;
    Usuario profesor;
    printf("Ingrese el id del profesor: ");
    scanf("%d", &nuevoProfesor.id_usuario);
    profesor = buscarProfesor(fProfesores, nuevoProfesor.id_usuario);
    if (profesor.id_usuario == nuevoProfesor.id_usuario){
        if (profesor.estado == ACTIVO){
            printf("Ya existe un profesor con ese id.\n");
        } else {
            printf("Ya existe un profesor con ese id, pero se encuentra inactivo.\n");
            printf("Desea darlo de alta? (s/n): ");
            char opcion;
            fflush(stdin);
            scanf("%c", &opcion);
            if (opcion == 's'){
                profesor.estado = ACTIVO;
                fseek(fProfesores, -sizeof(Usuario), SEEK_CUR);
                fwrite(&profesor, sizeof(Usuario), 1, fProfesores);
            }
        }
        TeclaParaContinuar();
    } else {
        nuevoProfesor.tipo = PROFESOR;
        printf("Ingrese el nombre del profesor: ");
        scanf("%s", nuevoProfesor.nombre);
        printf("Ingrese el apellido del profesor: ");
        scanf("%s", nuevoProfesor.apellido);
        printf("Ingrese el email del profesor: ");
        scanf("%s", nuevoProfesor.email);
        printf("Ingrese la contrase%ca del profesor: ", 164);
        scanf("%s", nuevoProfesor.contrasena);
        nuevoProfesor.estado = ACTIVO;
        fseek(fProfesores, 0L, SEEK_END);
        fwrite(&nuevoProfesor, sizeof(Usuario), 1, fProfesores);
    }
}

void altaCurso(FILE *fCursos){
    Curso nuevoCurso;
    Curso curso;
    printf("Ingrese el id del curso: ");
    scanf("%d", &nuevoCurso.id_cursada);
    curso = buscarCurso(fCursos, nuevoCurso.id_cursada);
    if (curso.id_cursada == nuevoCurso.id_cursada){
        printf("Ya existe un curso con ese id.\n");
        TeclaParaContinuar();
    } else {
        printf("Ingrese el a%co y divisi%cn del curso: ", 164, 162);
        scanf("%s", nuevoCurso.anio_division);
        fseek(fCursos, 0L, SEEK_END);
        fwrite(&nuevoCurso, sizeof(Curso), 1, fCursos);
    }
}


void altaMateria(FILE *fMaterias){
    Materia nuevaMateria;
    printf("Ingrese el id de la materia: ");
    scanf("%d", &nuevaMateria.id_materia);
    printf("Ingrese el nombre de la materia: ");
    scanf("%s", nuevaMateria.nombre);
    fseek(fMaterias, 0L, SEEK_END);
    fwrite(&nuevaMateria, sizeof(Materia), 1, fMaterias);
}

void altaCalificacion(FILE *fCalificaciones){
    Calificacion nuevaCalificacion;
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
    fseek(fCalificaciones, 0L, SEEK_END);
    fwrite(&nuevaCalificacion, sizeof(Calificacion), 1, fCalificaciones);
}

// funciones para las operaciones de baja
void bajaAlumno(FILE *fAlumnos) {
    Usuario alumno;
    int id;
    printf("Ingrese el ID del alumno a dar de baja: ");
    scanf("%d", &id);
    alumno = buscarAlumno(fAlumnos, id);
    if (alumno.id_usuario == id){
        if (alumno.estado == INACTIVO){
            printf("El alumno ya se encuentra inactivo.\n");
        } else {
            printf("Desea dar de baja al alumno? (s/n): ");
            char opcion;
            fflush(stdin);
            scanf("%c", &opcion);
            if (opcion == 's'){
                alumno.estado = INACTIVO;
                fseek(fAlumnos, -sizeof(Usuario), SEEK_CUR);
                fwrite(&alumno, sizeof(Usuario), 1, fAlumnos);
            }
        }
        TeclaParaContinuar();
    } else {
        printf("No existe un alumno con ese id.\n");
        TeclaParaContinuar();
    }
}

void bajaProfesor(FILE *fProfesores) {
    Usuario profesor;
    int id;
    printf("Ingrese el ID del profesor a dar de baja: ");
    scanf("%d", &id);
    profesor = buscarAlumno(fProfesores, id);
    if (profesor.id_usuario == id){
        if (profesor.estado == INACTIVO){
            printf("El profesor ya se encuentra inactivo.\n");
        } else {
            printf("Desea dar de baja al profesor? (s/n): ");
            char opcion;
            fflush(stdin);
            scanf("%c", &opcion);
            if (opcion == 's'){
                profesor.estado = INACTIVO;
                fseek(fProfesores, -sizeof(Usuario), SEEK_CUR);
                fwrite(&profesor, sizeof(Usuario), 1, fProfesores);
            }
        }
        TeclaParaContinuar();
    } else {
        printf("No existe un profesor con ese id.\n");
        TeclaParaContinuar();
    }
}

// funciones para las operaciones de modificación
void modificarAlumno(FILE *fAlumnos){
    Usuario alumno;
    int id;
    printf("Ingrese el id del alumno a modificar: ");
    scanf("%d", &id);
    alumno = buscarAlumno(fAlumnos, id);
    if (alumno.id_usuario == id){
        printf("Ingrese el nombre del alumno a modificar: ");
        scanf("%s", alumno.nombre);
        printf("Ingrese el apellido del alumno a modificar: ");
        scanf("%s", alumno.apellido);
        printf("Ingrese el email del alumno a modificar: ");
        scanf("%s", alumno.email);
        printf("Ingrese la contrase%ca del alumno a modificar: ", 164);
        scanf("%s", alumno.contrasena);
        printf("Desea activar o desactivar al alumno? (a/d): ");
        char opcion;
        fflush(stdin);
        scanf("%c", &opcion);
        if (opcion == 'a'){
            alumno.estado = ACTIVO;
        } else if (opcion == 'd'){
            alumno.estado = INACTIVO;
        }
        // Guardar los cambios en el archivo
        fseek(fAlumnos, -sizeof(Usuario), SEEK_CUR);
        fwrite(&alumno, sizeof(Usuario), 1, fAlumnos);
        printf("Alumno modificado correctamente.\n");
    } else {
        printf("No existe un alumno con ese id.\n");
        TeclaParaContinuar();
    }
}

void modificarProfesor(FILE *fProfesores){
    Usuario profesor;
    int id;
    printf("Ingrese el id del profesor a modificar: ");
    scanf("%d", &id);
    profesor = buscarProfesor(fProfesores, id);
    if (profesor.id_usuario == id){
        printf("Ingrese el nombre del profesor a modificar: ");
        scanf("%s", profesor.nombre);
        printf("Ingrese el apellido del profesor a modificar: ");
        scanf("%s", profesor.apellido);
        printf("Ingrese el email del profesor a modificar: ");
        scanf("%s", profesor.email);
        printf("Ingrese la contrase%ca del profesor a modificar: ", 164);
        scanf("%s", profesor.contrasena);
        printf("Desea activar o desactivar al profesor? (a/d): ");
        char opcion;
        fflush(stdin);
        scanf("%c", &opcion);
        if (opcion == 'a'){
            profesor.estado = ACTIVO;
        } else if (opcion == 'd'){
            profesor.estado = INACTIVO;
        }
        // Guardar los cambios en el archivo
        fseek(fProfesores, -sizeof(Usuario), SEEK_CUR);
        fwrite(&profesor, sizeof(Usuario), 1, fProfesores);
        printf("Profesor modificado correctamente.\n");
    } else {
        printf("No existe un profesor con ese id.\n");
        TeclaParaContinuar();
    }
}

void modificarCurso(FILE *fCursos){ 
    Curso curso;
    int id;
    printf("Ingrese el id del curso a modificar: ");
    scanf("%d", &id);
    curso = buscarCurso(fCursos, id);
    if (curso.id_cursada == id){
        printf("Ingrese el a%co y divisi%cn del curso a modificar: ", 164, 162);
        scanf("%s", curso.anio_division); //no acepta espacios
        // Guardar los cambios en el archivo
        fseek(fCursos, -sizeof(Curso), SEEK_CUR);
        fwrite(&curso, sizeof(Curso), 1, fCursos);
        printf("Curso modificado correctamente.\n");
    } else {
        printf("No existe un curso con ese id.\n");
        TeclaParaContinuar();
    }
}

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
                // Submenú de materia
                submenuMateria(fMaterias);
                break;
            case 4:
                // Submenú de curso
                submenuCurso(fCursos);
                break;
            case 5:
                // Submenú de calificación
                submenuCalificacion(fCalificaciones);
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
                consultarAlumnos(fAlumnos);
                break;
            case 5:
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
                consultarProfesores(fProfesores);
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

void submenuCurso(FILE *fCursos) {
    int curOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Men%c de Curso -----\n", 163);
        printf("1. Alta\n");
        printf("2. Consulta\n");
        printf("3. Modificaci%cn\n", 162);
        printf("4. Volver al Men%c Principal\n", 163);
        printf("Selecciona una opci%cn: ", 162);
        scanf("%d", &curOpcion);

        switch (curOpcion) {
            case 1:
                altaCurso(fCursos);
                break;
            case 2:
                consultarCursos(fCursos);
                break;
            case 3:
                modificarCurso(fCursos);
                break;
            case 4:
                // Volver al menú principal
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                TeclaParaContinuar();
                break;
        }
    } while (curOpcion != 4);
}

void submenuMateria(FILE *fMaterias) {
    int matOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Men%c de Materia -----\n", 163);
        printf("1. Alta\n");
        printf("2. Consulta\n");
        printf("3. Volver al Men%c Principal\n", 163);
        printf("Selecciona una opci%cn: ", 162);
        scanf("%d", &matOpcion);

        switch (matOpcion) {
            case 1:
                altaMateria(fMaterias);
                break;
            case 2:
                consultarMaterias(fMaterias);
                break;
            case 3:
                // Volver al menú principal
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                TeclaParaContinuar();
                break;
        }
    } while (matOpcion != 3);
}

void submenuCalificacion(FILE *fCalificaciones) {
    int calOpcion;
    do {
        system("cls"); // Limpiar la pantalla
        printf("\n----- Men%c de Calificaci%cn -----\n", 163, 162);
        printf("1. Alta\n");
        printf("2. Consulta\n");
        printf("3. Volver al Men%c Principal\n", 163);
        printf("Selecciona una opci%cn: ", 162);
        scanf("%d", &calOpcion);

        switch (calOpcion) {
            case 1:
                altaCalificacion(fCalificaciones);
                break;
            case 2:
                consultarCalificaciones(fCalificaciones);
                break;
            case 3:
                // Volver al menú principal
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                TeclaParaContinuar();
                break;
        }
    } while (calOpcion != 3);
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

const char* getTipoUsuario(tipoUsuario tipo) {
    switch (tipo) {
        case ALUMNO:
            return "Alumno";
        case PROFESOR:
            return "Profesor";
        default:
            return "Desconocido";
    }
}

const char* getEstadoUsuario(estadoUsuario estado) {
    switch (estado) {
        case ACTIVO:
            return "Activo";
        case INACTIVO:
            return "Inactivo";
        default:
            return "Desconocido";
    }
}


Usuario buscarProfesor(FILE *fProfesores, int id) {
    Usuario profesor;
    rewind(fProfesores);
    fread(&profesor, sizeof(Usuario), 1, fProfesores);
    while (!feof(fProfesores) && profesor.id_usuario != id) {
        fread(&profesor, sizeof(Usuario), 1, fProfesores);
    }
    return profesor;
}

Usuario buscarAlumno(FILE *fAlumnos, int id) {
    Usuario alumno;
    rewind(fAlumnos);
    fread(&alumno, sizeof(Usuario), 1, fAlumnos);
    while (!feof(fAlumnos) && alumno.id_usuario != id) {
        fread(&alumno, sizeof(Usuario), 1, fAlumnos);
    }
    return alumno;
}

Materia buscarMateria(FILE *fMaterias, int id) {
    Materia materia;
    rewind(fMaterias);
    fread(&materia, sizeof(Materia), 1, fMaterias);
    while (!feof(fMaterias) && materia.id_materia != id) {
        fread(&materia, sizeof(Materia), 1, fMaterias);
    }
    return materia;
}

Curso buscarCurso(FILE *fCursos, int id) {
    Curso curso;
    rewind(fCursos);
    fread(&curso, sizeof(Curso), 1, fCursos);
    while (!feof(fCursos) && curso.id_cursada != id) {
        fread(&curso, sizeof(Curso), 1, fCursos);
    }
    return curso;
}

void consultarAlumnos(FILE *fAlumnos){
    Usuario alumno;
    rewind(fAlumnos);
    int hayAlumnos = 0;
    while (fread(&alumno, sizeof(Usuario), 1, fAlumnos) == 1){
        if (alumno.tipo == ALUMNO){
            printf("\nId: %d\n", alumno.id_usuario);
            printf("Nombre: %s\n", alumno.nombre);
            printf("Apellido: %s\n", alumno.apellido);
            printf("Email: %s\n", alumno.email);
            printf("Contrase%ca: %s\n", 164, alumno.contrasena);
            printf("Estado: %s\n", getEstadoUsuario(alumno.estado));
            hayAlumnos = 1;
        } 
    }
    if (!hayAlumnos){
        printf("\nNo hay alumnos cargados.\n");
    }
    TeclaParaContinuar();
}

void consultarProfesores(FILE *fProfesores){
    Usuario profesor;
    rewind(fProfesores);
    int hayProfesores = 0;
    while (fread(&profesor, sizeof(Usuario), 1, fProfesores) == 1){
        if (profesor.tipo == PROFESOR){
            printf("\nId: %d\n", profesor.id_usuario);
            printf("Nombre: %s\n", profesor.nombre);
            printf("Apellido: %s\n", profesor.apellido);
            printf("Email: %s\n", profesor.email);
            printf("Contrase%ca: %s\n", 164, profesor.contrasena);
            printf("Estado: %s\n", getEstadoUsuario(profesor.estado));
            hayProfesores = 1;
        } 
    }
    if (!hayProfesores){
        printf("\nNo hay profesores cargados.\n");
    }
    TeclaParaContinuar();
}

void consultarMaterias(FILE *fMaterias){
    Materia materia;
    rewind(fMaterias);
    int hayMaterias = 0;
    while (fread(&materia, sizeof(Materia), 1, fMaterias) == 1){
        printf("\nId: %d\n", materia.id_materia);
        printf("Nombre: %s\n", materia.nombre);
        hayMaterias = 1;
    }
    if (!hayMaterias){
        printf("\nNo hay materias cargadas.\n");
    }
    TeclaParaContinuar();
}

void consultarCursos(FILE *fMaterias){
    Curso curso;
    rewind(fMaterias);
    int hayCursos = 0;
    while (fread(&curso, sizeof(Curso), 1, fMaterias) == 1){
        printf("\nId: %d\n", curso.id_cursada);
        printf("A%co y divisi%cn: %s\n", 164, 162, curso.anio_division);
        hayCursos = 1;
    }
    if (!hayCursos){
        printf("\nNo hay cursos cargados.\n");
    }
    TeclaParaContinuar();
}

void consultarCalificaciones(FILE *fCalificaciones){
    Calificacion calificacion;
    rewind(fCalificaciones);
    int hayCalificaciones = 0;
    while (fread(&calificacion, sizeof(Calificacion), 1, fCalificaciones) == 1){
        printf("\nId: %d\n", calificacion.id_calificacion);
        printf("Id alumno: %d\n", calificacion.id_alumno);
        printf("Id materia: %d\n", calificacion.id_materia);
        printf("Nota: %d\n", calificacion.nota);
        printf("N%cmero de examen: %d\n", 163, calificacion.num_examen);
        hayCalificaciones = 1;
    }
    if (!hayCalificaciones){
        printf("\nNo hay calificaciones cargadas.\n");
    }
    TeclaParaContinuar();
}