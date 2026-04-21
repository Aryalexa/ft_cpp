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



Resumen de ejercicios

ex00 — `swap`, `min`, `max`
- Archivos: `templates.hpp`, `main.cpp`, `Makefile`.
- Implementa funciones plantilla `swap(T&,T&)`, `min(const T&,const T&)` y `max(const T&,const T&)` en el header.
- Pruebas incluidas en `main.cpp` con `int` y `std::string`.

ex01 — `iter`
- Archivos: `iter.hpp`, `main.cpp`, `Makefile`.
- Implementa `iter(T* arr, size_t len, F func)` que aplica `func` a cada elemento del array.
- Soporta funciones plantilla como parámetro y trabaja con arrays de tipos const y no-const si la función pasada lo admite.

ex02 — `Array<T>`
- Archivos: `Array.hpp`, `main.cpp`, `Makefile`.
- Implementa una clase plantilla `Array<T>` con:
  - constructor por defecto (array vacío),
  - constructor con tamaño `Array(unsigned int n)`,
  - copia, operador= (deep copy), destructor, operadores `operator[]` con comprobación de límites (lanza `std::out_of_range`),
  - `size()` const.
- Notas de implementación relevantes:
  - La implementación está en `Array.hpp` (plantilla) y por eso el header incluye las cabeceras necesarias (`<iostream>`, `<stdexcept>`, etc.).
  - Para mantener compatibilidad con C++98 se reemplazaron usos de `nullptr` por `0`.
  - El `operator[]` tiene versión const y no-const.

Estado y verificación rápida
- He compilado los ejercicios con los Makefiles del repo. `make` en `ex02` fue arreglado y ya compila (se añadieron `<cstdlib>` y `<ctime>` en `main.cpp` para `rand`/`srand`). También se ejecutaron `make` en `ex00` y `ex01` (no reportaron errores en la sesión de compilación automatizada).

Cobertura de requisitos
- ex00: Hecho — plantillas definidas en header y tests en `main.cpp`.
- ex01: Hecho — `iter` implementado en `iter.hpp` y `main.cpp` contiene pruebas.
- ex02: Hecho — `Array<T>` en `Array.hpp`, manejo de copias, excepciones en accesos fuera de rango, `size()` y compatibilidad C++98 (sin `nullptr`).

Cómo probar rápido

Desde el folder raíz del módulo:

```bash
cd mod07/ex00 && make && ./main
cd ../ex01 && make && ./main
cd ../ex02 && make && ./main
```

Notas finales / recomendaciones
- Mantén la regla: implementación de plantillas en headers; para código no-template, evita incluir cabeceras innecesarias en `.hpp`.
- Ejecuta `valgrind --leak-check=full ./binary` si quieres comprobar fugas de memoria antes de la entrega.

---

¿Basta leer este README para la evaluación?

- Es un buen punto de partida: te da estructura, archivos relevantes y preguntas clave. Pero para la defensa necesitas además ejecutar los programas, entender las decisiones de diseño y ser capaz de responder preguntas sobre memoria, copias y const-correctness.

Qué son los templates (resumen rápido)

- Son plantillas de código que permiten escribir funciones o clases genéricas que funcionan con distintos tipos sin duplicar código.
- Sintaxis mínima:

  `template<typename T>`
  `T max(const T &a, const T &b);`

- El compilador crea una versión concreta (instanciación) cuando usas la plantilla con un tipo específico (por ejemplo `max<int>`). Hay function-templates y class-templates.

¿Para qué sirven? (ventajas)

- Reutilización: un mismo algoritmo para muchos tipos.
- Seguridad de tipos en tiempo de compilación.
- Eficiencia: el compilador genera código concreto por tipo evitando sobrecarga en tiempo de ejecución.

Qué aprendes exactamente con este módulo

- ex00 (swap, min, max)
  - Sintaxis y semántica de funciones plantilla.
  - Paso por referencia y retorno por referencia (eficiencia y riesgos si se devuelve referencia a objeto temporal).

- ex01 (iter)
  - Pasar una función (o función-template) como parámetro.
  - Compatibilidad con arrays const y no-const: la función pasada puede requerir `const T&` o `T&`.
  - Manejo de arrays crudos y funciones genéricas aplicadas a cada elemento.

- ex02 (Array<T>)
  - Clase plantilla con gestión de memoria dinámica (`new[]`/`delete[]`).
  - Regla de las tres: constructor copia, operador= y destructor (deep copy para evitar aliasing de punteros).
  - `operator[]` con comprobación de límites y versión const/no-const.
  - Por qué la implementación de plantillas debe estar en el header.

Trampas comunes y puntos de defensa

- Las plantillas deben definirse en headers: si la implementación queda en un .cpp no se instanciará en otras unidades de traducción.
- Cuidado con la gestión de memoria en templates: asegura copias profundas y libera memoria en el destructor.
- Const-correctness en `iter`: tu función debería poder aceptar `const T&` o `T&` según corresponda.
- Mensajes de error de templates pueden ser largos; aprende a identificar la causa raíz en el primer bloque del error.

Lista corta de estudio (prioridad alta)

1. Sintaxis de `template<typename T>` y cuándo se instancian.
2. Diferencia entre pasar por valor, referencia y referencia const.
3. Regla de las tres (copy ctor, operator=, destructor) y por qué es necesaria aquí.
4. Cómo pasar funciones a `iter` (funciones normales, funciones plantilla instanciadas).
5. Manejo de excepciones estándar (`std::out_of_range`) y comprobaciones de límites.

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

Frases listas para la defensa (3 × 20s)

- ex00: "Uso plantillas para implementar `swap`, `min` y `max` una sola vez para cualquier tipo; devuelvo por referencia const en `min`/`max` por eficiencia y seguridad cuando los objetos existen fuera de la función."

- ex01: "`iter` acepta un puntero a array, su longitud y una función; permite aplicar la misma operación a arrays de cualquier tipo sin duplicar código y respeta const-correctness según la función pasada."

- ex02: "`Array<T>` es una clase plantilla que gestiona memoria dinámica y hace copia profunda en copia/operador=; `operator[]` comprueba límites y lanza `std::out_of_range` para evitar lecturas/escrituras fuera del array."

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

---

Salida esperada (referencia rápida)

ex00 — swap/min/max
Ejecuta: `cd ex00 && make && ./templates`
Salida esperada:
```
a = 2, b = 3
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine1, d = chaine2
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

ex01 — iter
Ejecuta: `cd ex01 && make && ./templates`
Salida esperada: arrays de int (1, 5, 10 y 4, 8, 16), evaluaciones booleanas (0, 0, 1 y 0, 1, 1), array de strings (oso1, oso2, oso3), y caracteres individuales (h, o, l, a).

ex02 — Array<T>
Ejecuta: `cd ex02 && make && ./templates`
Salida esperada: pruebas de arrays vacíos, arrays con tamaño, copias profundas, excepciones en acceso fuera de rango, y test 42 con asignaciones aleatorias.
- Verás "Exception: index out of bounds" cuando intentes acceder fuera del rango; esto es correcto (significa que tu código lanza la excepción).
- Verás arrays con valores inicializados por defecto (0 para int, vacío para strings) cuando uses constructores sin parámetros.

Checklist final — Listo para la evaluación

Antes de entrar a la defensa, verifica:

- [ ] Compilo: `cd mod07/exNN && make` en cada ejercicio sin errores.
- [ ] Ejecuto: `./main` en cada ejercicio y reviso que la salida tenga sentido (sin crashes).
- [ ] Leo: secciones "Qué son los templates" y "Frases listas para la defensa" de este README.
- [ ] Practico: repito en voz alta las 3 frases de defensa (ex00, ex01, ex02) 2 veces.
- [ ] Flashcards: repaso las 6 preguntas clave sin mirar las respuestas.
- [ ] Valgrind (opcional pero recomendado): `valgrind --leak-check=full ./main` en ex02 y verifico "in use at exit: 0 bytes".
- [ ] Conceptos: puedo explicar en 1-2 frases por qué cada ejercicio necesita plantillas.

Eres evaluado en:
- Compilación limpia (sin warnings si es posible).
- Correctitud: el código hace lo que promete (sin crashes, manejo de límites correcto).
- Comprensión: entiendes por qué usaste templates aquí y qué alternativas había.
- Memoria: sin fugas (si se verifica con valgrind).
- Const-correctness: las funciones tienen los parámetros `const` donde corresponde.

¿Quieres que añada esto exactamente al README y haga commit+push automáticamente ahora? Puedo hacerlo y luego ejecutar los binarios y adjuntar sus salidas si quieres.