# 📚 BiblioGest 📚
Sistema de gestion para una biblioteca. Proyecto colaborativo para Trabajo Practico Integrador de Programación II de la Tecnicatura Universitaria en Programación en UTN FRGP.

## Descripcion ✍
Este sistema permitirá administrar operaciones relacionadas con la gestión de una biblioteca física, donde se efectuarán préstamos de libros, pagos de cuotas mensuales y gestión de operaciones relacionadas con los socios, todo ello a través de una interfaz intuitiva para el usuario.

## Funcionalidades Principales ⚙ 
* Gestión de Socios: Registro, modificación y eliminación de socios, incluyendo sus datos personales y estado de membresía.
* Gestión de Libros: Administración del catálogo de libros, incluyendo alta, baja y modificación de ejemplares.
* Préstamos y Devoluciones: Registro de préstamos de libros a socios, control de fechas de inicio y fin, y gestión de devoluciones.
* Pagos de Cuotas: Registro de pagos mensuales realizados por los socios, incluyendo importe, fecha y período correspondiente.
* Consultas y Reportes: Generación de informes sobre préstamos activos, pagos realizados, pagos fuera de tiempo y/o falta de pagos.

## Archivos 🗂
* archivoSocios.dat: Almacenará todos los datos de cada socio especificados dentro dé la clase del mismo. 
* archivoPagosMes.dat: Refleja los pagos de cada mes efectuados por cada socio, junto con su fecha de pago, el importe, el mes dé la cuota y el año.
* archivoLibros.dat: Almacenará la información de cada libro: su ISBN, el título, autor, la fecha dé publicación y la cantidad dé ejemplares con los que cuenta la biblioteca. 
* archivoPrestamos.dat: Guardará los préstamos de cada libro con su ISBN correspondiente, el número del socio que lo solicito, la fecha del préstamo y la fecha dé devolucion.

## Reportes🚨
Además de las consultas especificadas anteriormente, se efectuarán una serie de reportes que brindarán información valiosa al usuario para la organización de la biblioteca:
* Alerta de socios con más atrasos en los pagos: A fin de mes se cerrará el pago de la cuota y por lo tanto se comenzará a colocar los usuarios cuyos pagos no fueron efectuados en esta lista. Se les agregará un porcentaje extra por mes hasta que vuelvan a pagar, el cual se incrementará a medida que pase el tiempo.  
* Ranking de libros con mayores préstamos: Un top de los 10 libros más solicitados, independientemente del género. 
* Ranking de libros con menores préstamos: para revisar qué libros tienen poco movimiento.
* Socios con membresía inactiva, pero préstamos activos: para controlar que no se prestan libros a usuarios que no están al día.

## Clases 📂
### Principales 📌
![ClasesBibliotecaBorrador-Clases2](https://github.com/user-attachments/assets/b9370354-4e79-41fe-984d-46d1b2b87904)

### Archivos 🗒

## Construido con 🛠️

* C++ 
* [rlutil.h](https://tapiov.net/rlutil/docs/HTML/files/rlutil-h.html) - Librería para diseño gráfico

## Autoras📝
* **Florencia Susana Olivera** - *Desarrollo BackEnd y Frontend* - 
*  **Guadalupe Franchi Leiva** - *Desarrollo BackEnd y FrontEnd* - [GuadalupeUTN](https://github.com/GuadalupeUTN)
