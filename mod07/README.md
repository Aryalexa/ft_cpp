# Módulo 07 — Plantillas (templates)

Resumen

Esta carpeta contiene las soluciones a los ejercicios ex00..ex02 implementadas para C++98 siguiendo las instrucciones del enunciado del módulo.

Compilación
- Compilar con: `c++ -std=c++98 -Wall -Wextra -Werror` (los Makefiles ya lo hacen).
- Cada ejercicio tiene su `Makefile`; desde la carpeta del ejercicio:

```bash
make
./<binary>
```



## Defensa - prep general

Qué son los templates (resumen rápido)

- Son plantillas de código que permiten escribir funciones o clases genéricas que funcionan con distintos tipos sin duplicar código.
- Sintaxis mínima:

  `template<typename T>`
  `T max(const T &a, const T &b);`

- El compilador crea una versión concreta (instanciación) cuando usas la plantilla con un tipo específico (por ejemplo `max<int>`). Hay function-templates y class-templates.

- ¿Para qué sirven? (ventajas)
  - Reutilización: un mismo algoritmo para muchos tipos.
  - Seguridad de tipos en tiempo de compilación.
  - Eficiencia: el compilador genera código concreto por tipo evitando sobrecarga en tiempo de ejecución.

- cuándo se instancian: en compilacion

Diferencia entre pasar por valor, referencia y referencia const.
- la funcion no debe modificar los parametros: const y ref (ref te evita hacer copia)
- si el valor de retorno es const debe ser asignado a una variable const que no permite modificacion
- sie el valor de retorno no es referencia se devuelve una variable nueva.

Regla de las tres (copy ctor, operator=, destructor) y por qué es necesaria aquí.
- 
Cómo pasar funciones a `iter` (funciones normales, funciones plantilla instanciadas).
- 
Manejo de excepciones estándar (`std::out_of_range`) y comprobaciones de límites.
- 
## Defensa - por ejeccicios

- ex00 (swap, min, max)
  - resumen: "Uso plantillas para implementar `swap`, `min` y `max` una sola vez para cualquier tipo; devuelvo por referencia const en `min`/`max` por eficiencia y seguridad cuando los objetos existen fuera de la función."
  - Sintaxis y semántica de funciones plantilla.
  - Paso por referencia y retorno por referencia (eficiencia y riesgos si se devuelve referencia a objeto temporal).

- ex01 (iter)
  - resumen: "`iter` acepta un puntero a array, su longitud y una función; usa dos overloads para soportar arrays const y no-const. Las funciones pasadas pueden requerir `const T&` (solo lectura) o `T&` (modificación) según el contexto — esto permite máxima flexibilidad sin duplicar código."
  - Pasar una función (o función-template) como parámetro.
  - Compatibilidad con arrays const y no-const: la función pasada puede requerir `const T&` o `T&`.
  - Manejo de arrays crudos y funciones genéricas aplicadas a cada elemento.
  - **Lección clave:** `iter` necesita **dos overloads** (sobrecarga) — uno para `T*` y otro para `const T*` — para soportar correctamente arrays const y no-const:
    - `iter(T *arr, size_t len, F func)` — pasa elementos no-const a `func`.
    - `iter(const T *arr, size_t len, F func)` — pasa elementos const a `func`.
  - Las funciones pasadas también deben estar preparadas para ambos contextos:
    - Funciones de lectura: `void my_print(const T&)` — funcionan con arrays const y no-const.
    - Funciones de modificación: `void increment(T&)` — **solo** funcionan con arrays no-const (lo cual es correcto: no puedes modificar arrays const).

- ex02 (Array<T>)
  - resumen: "`Array<T>` es una clase plantilla que gestiona memoria dinámica y hace copia profunda en copia/operador=; `operator[]` comprueba límites y lanza `std::out_of_range` para evitar lecturas/escrituras fuera del array."
  - Clase plantilla con gestión de memoria dinámica (`new[]`/`delete[]`).
  - Regla de las tres: constructor copia, operador= y destructor (deep copy para evitar aliasing de punteros).
  - `operator[]` con comprobación de límites y versión const/no-const.
  - Por qué la implementación de plantillas debe estar en el header.

## Defena - detales

Trampas comunes y puntos de defensa

- Las plantillas deben definirse en headers: si la implementación queda en un .cpp no se instanciará en otras unidades de traducción.
- Cuidado con la gestión de memoria en templates: asegura copias profundas y libera memoria en el destructor.
- Const-correctness en `iter`: tu función debería poder aceptar `const T&` o `T&` según corresponda.
- Mensajes de error de templates pueden ser largos; aprende a identificar la causa raíz en el primer bloque del error.

Plan práctico de 30–60 minutos para la defensa

1. Leer este README (5 min).
2. Ejecutar cada ejercicio y comprobar su salida (10–15 min):

```bash
cd mod07/ex00 && make && ./main
cd ../ex01 && make && ./main
cd ../ex02 && make && ./main
```

3. Para cada ejercicio, prepara una explicación de 1 minuto:
   - Qué hace el programa.
   - Por qué usar plantillas aquí (qué problema evita).
   - Un posible fallo y cómo lo solucionaste (p. ej. `operator[]` fuera de rango).

4. Ejecuta `valgrind --leak-check=full ./main` en los binarios para verificar fugas (si valgrind está disponible).



Tarjetas rápidas (flashcards) — 6 preguntas clave

1) ¿Por qué las plantillas van en headers?
  - Porque el compilador debe ver la definición para instanciarla con tipos concretos en cada unidad de traducción.

2) ¿Qué es la regla de las tres?
  - Constructor copia, operador= y destructor; necesarios cuando la clase gestiona recursos externos (p. ej. memoria dinámica).

3) ¿Qué es la "instanciación" de una plantilla?
  - Es cuando el compilador crea una versión concreta de la plantilla para un tipo específico. Por ejemplo, al usar `swap<int>` el compilador genera código de `swap` especializado para `int`.

4) ¿Cómo manejarías un acceso fuera de rango en `operator[]`?
  - Lanzar `std::out_of_range` o `std::exception` y documentarlo.

5) ¿Por qué evitar `nullptr` en este repo?
  - Porque el código se ajusta a C++98 (antes de C++11); usar `0` o `NULL` es la alternativa compatible.

6) ¿Cómo pasarías una función que imprime cada elemento a `iter`?
  - Pasa la función (o su instancia de plantilla) como tercer parámetro: `::iter(arr, n, ::my_print<T>)` o `iter(arr, n, my_print<T>)`.

7) ¿Por qué necesita `iter` dos overloads (uno para `T*` y otro para `const T*`)?
  - Porque arrays const deben pasar elementos const a la función, mientras que arrays no-const pueden pasar elementos no-const. Los dos overloads hacen que `iter` sea flexible: funciones que necesitan `const T&` funcionan en ambos casos, pero funciones que necesitan `T&` (para modificar) solo funcionan con arrays no-const (lo que es correcto y seguro).