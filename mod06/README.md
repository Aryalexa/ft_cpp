# Module 06 — Scalar conversions / Serialization / RTTI

This folder contains exercises ex00..ex02 implemented for C++98.

Requirements
- Compile with: `c++ -std=c++98 -Wall -Wextra -Werror` (Makefiles already set this).
- No STL containers used in these exercises.
- No `using namespace` or `friend` keywords.

Short summary of implementations

ex00 — ScalarConverter
- Files: `ScalarConverter.hpp`, `ScalarConverter.cpp`, `main.cpp`, `Makefile`.
- `ScalarConverter::convert(const std::string &)` detects literal type (char/int/float/double)
  and prints conversions to `char`, `int`, `float`, `double`.
- Pseudo-literals handled: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`.
- Casting choice: `static_cast` used for numeric/char conversions.
- Notes: precision for float/double output is derived from input; non-displayable char shows `Non displayable` and impossible conversions print `impossible`.

ex01 — Serializer
- Files: `Serializer.hpp`, `Serializer.cpp`, `Data.hpp`, `main.cpp`, `Makefile`.
- `serialize(Data* ptr)` / `deserialize(uintptr_t raw)` implemented with `reinterpret_cast`.
- Casting choice: `reinterpret_cast` to convert between pointer and `uintptr_t`.
- `main.cpp` includes an `assert(ptr == &data)` sanity check.

ex02 — Identify real type
- Files: `Base.hpp`, `Base.cpp`, `main.cpp`, `Makefile`.
- `Base` has a virtual destructor. `A`, `B`, `C` inherit from `Base`.
- `generate()` creates random instance of A/B/C (seeded in `main()`).
- `identify(Base*)` uses `dynamic_cast<T*>(p)` to check types.
- `identify(Base&)` uses `dynamic_cast<T&>(p)` in try/catch and catches `std::bad_cast`.
- Casting choice: `dynamic_cast` for RTTI detection.

Valgrind / Memory
- I ran valgrind on the produced binaries (Ubuntu, valgrind 3.18.1) with `--leak-check=full`.
- Results: no leaks detected for ex00, ex01, ex02 (all heap blocks freed at exit).

```sh
valgrind --leak-check=full ./executable args
```

How to build and run
- Each exercise has a Makefile. From the exercise folder (ex00/ex01/ex02):

```bash
make
./<binary>
```

Example outputs
- See the exercise `main.cpp` files; they include example runs and tests.

Notes for defense
- Casting types used per exercise:
  - ex00: `static_cast<T>` for numeric/char conversions.
  - ex01: `reinterpret_cast<uintptr_t>` / `reinterpret_cast<Data*>`.
  - ex02: `dynamic_cast` for runtime identification.
- Precision differences for floats are due to IEEE-754 rounding when converting to `float`.

If you want, I can:
- Provide a "clean" version of each `main.cpp` for submission (minimal I/O),
- Add small unit-tests or scripts to automate the runs,
- Push the README and commit changes (I can do that if you want).

## Teoría y objetivos de aprendizaje (breve)

A continuación se resume qué se espera aprender con cada ejercicio y los conceptos clave que conviene dominar para la defensa.

ex00 — ScalarConverter
- Objetivo: aprender a parsear literales escalares y controlar conversiones entre tipos básicos.
- Conceptos clave: parsing de cadenas (C: `strtod`/`strtol` o C++ streams), comprobación de errores en parseo, límites numéricos (`std::numeric_limits`), representación en punto flotante (IEEE-754), pseudoliterales (`nan`, `inf`), y detección de caracteres imprimibles (`std::isprint`).
- Casting: se usa `static_cast<T>` para conversiones numéricas/char; en la defensa debes poder justificar por qué `static_cast` es apropiado aquí (conversión explícita pero sin reinterpretación de bits).

ex01 — Serializer
- Objetivo: entender cómo convertir punteros a un entero que pueda almacenar una dirección y volver a convertirlo a puntero (serialización simple de dirección).
- Conceptos clave: tipos enteros de puntero (`uintptr_t`), punteros y su representación, portabilidad y límites, y el uso seguro de `reinterpret_cast` para este propósito.
- Casting: `reinterpret_cast` documentado y utilizado porque la intención es reinterpretar la representación de la dirección como entero sin alterar los bits.

ex02 — Identify real type
- Objetivo: practicar polimorfismo en tiempo de ejecución (RTTI) y el uso de `dynamic_cast`.
- Conceptos clave: clases base con destructor virtual, herencia pública, `dynamic_cast` para punteros y referencias, manejo de `std::bad_cast`, y diferencias entre comprobación por puntero (nullptr) y por referencia (excepción). También semillas y generación aleatoria controlada para pruebas.

Recomendaciones de estudio
- Repasar el uso y semántica de los distintos `cast` en C++ (`static_cast`, `reinterpret_cast`, `const_cast`, `dynamic_cast`) y cuándo cada uno es seguro/adecuado.
- Entender las limitaciones y la precisión de `float` vs `double` y por qué aparecen resultados inesperados por redondeo.
- Practicar técnicas de parseo robusto (comprobar errores de parseo, validar rangos, entradas malformadas).
- Usar herramientas como `valgrind` para detectar fugas y asegurar liberación de memoria.
- Preparar la defensa: explica por qué elegiste cada cast, cómo detectas errores/overflows, y cómo garantizas que no haya fugas.

Si quieres que traduzca esta sección al inglés o la resuma en una diapositiva para la defensa, lo hago a continuación.

## Explicación para principiantes (rápida)

Lo más corto y claro que puedes decir en la defensa.

- ¿Qué hace `static_cast` (ejemplo en ex00)?
  - Convierte el valor. Ejemplo: `int i = static_cast<int>(3.14); // i == 3`.
  - Úsalo cuando quieres el nuevo número resultante (truncar, redondear, cambiar tipo), no tocar los bytes.

- ¿Qué hace `reinterpret_cast` (ejemplo en ex01)?
  - Reinterpreta los bytes existentes: toma la misma secuencia de bits y la lee como otro tipo.
  - Ejemplo: `uintptr_t r = reinterpret_cast<uintptr_t>(ptr);` (la dirección del puntero se guarda como entero) y `Data* p2 = reinterpret_cast<Data*>(r);` (se vuelve a leer la misma dirección como puntero).

- Diferencia clave en una frase:
  - `static_cast` = "convertir el valor". `reinterpret_cast` = "leer los mismos bytes como otro tipo".

- Frase de 10 segundos lista para la defensa:
  - "En ex00 uso `static_cast` porque convierto valores (double→int) y espero pérdida controlada; en ex01 uso `reinterpret_cast` porque necesito reinterpretar la dirección del puntero como un entero para serializarla."

Si quieres la versión en inglés o una versión aún más corta (una línea), la pongo también.

## Conceptos importantes y criterio para la defensa (resumen y respuestas)

He unido los conceptos y el criterio en una sola sección práctica. Aquí tienes lo que debes saber, qué mostrar y frases listas para la defensa; copia y repite.

ex00 — ScalarConverter
- Qué saber (rápido): parseo de cadenas (por ejemplo `strtod`/`strtol` o C++ streams), comprobación de errores de parseo y validación de límites con `numeric_limits`, `std::isprint` para chars, y que `float` vs `double` tiene distinta precisión (IEEE‑754).
- Qué mostrar (reglas exactas):
  - char: `impossible` si `nan`/`inf` o fuera de 0..127; `Non displayable` si no imprimible; o `char: 'X'` si imprimible.
  - int: `impossible` si `nan`/`inf` o fuera de `INT_MIN..INT_MAX`; o `int: <n>`.
  - float: `nanf`/`+inff`/`-inff` para pseudo-literals; para finitos `float: <valor>f` (decimales derivados de la entrada, mínimo 1).
  - double: `nan`/`+inf`/`-inf` para pseudo-literals; para finitos `double: <valor>` (decimales derivados de la entrada, mínimo 1).
- Qué decir en la defensa (1 frase):
  - "Uso `static_cast` para convertir valores (double→int, int→char). Para parsing hago comprobaciones de parseo y validación de rango para detectar entradas malformadas o fuera de rango."

ex01 — Serializer
- Qué saber (rápido): `uintptr_t` almacena direcciones como enteros; `reinterpret_cast` reinterpreta los bits de la dirección; esto es válido para round-trip en el mismo proceso, no para serializar datos entre procesos.
- Qué mostrar: mostrar el round-trip y el `assert(ptr == deserialize(serialize(ptr)))` en pruebas.
- Qué decir en la defensa (1 frase):
  - "Uso `reinterpret_cast<uintptr_t>` porque la intención es reinterpretar la dirección de memoria como entero y volverla a convertir sin cambiar los bits."

ex02 — Identify real type
- Qué saber (rápido): `Base` necesita destructor virtual; `dynamic_cast<T*>(p)` devuelve `0` (null) si falla; `dynamic_cast<T&>(p)` lanza `std::bad_cast` si falla.
- Qué mostrar: ejemplo detectando A/B/C por puntero y por referencia; pruebas repetidas para mostrar aleatoriedad controlada.
- Qué decir en la defensa (1 frase):
  - "Uso `dynamic_cast` porque necesito información de tiempo de ejecución (RTTI) para identificar el tipo real de un objeto apuntado por la base."

Buenas prácticas y pruebas
- Valgrind: ejecutar `valgrind --leak-check=full ./binary` y mostrar que `in use at exit: 0 bytes`.
- Tests: asserts (ex01) y bucles de prueba (ex02) incluidos; muestra ejemplos usados (0, nan, 42.0f, etc.).

Cómo usar esto antes de la defensa
- Lee las 3 frases (una por ejercicio) para explicar rápidamente tu elección de cast y la estrategia de comprobación.
- Si te preguntan por límites, responde: "usé numeric_limits para detectar int overflow y comprobaciones de parseo/validación de rango para detectar entradas fuera de rango".

Si quieres, muevo estas frases a la cabecera del README como "Guion de 30s" para repasarlas justo antes de hablar. ¿Lo hago?

