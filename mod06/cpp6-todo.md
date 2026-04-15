Collecting workspace informationFiltering to most relevant informationSí. El módulo exige compatibilidad con C++98. Reglas clave extraídas de cpp6-context.md:

- Compilación: usar c++ con flags `-Wall -Wextra -Werror` y debe compilar también con `-std=c++98`.
- STL (contenedores/algoritmos) está prohibida hasta los módulos 08/09.
- Prohibidos: `using namespace <...>`, `friend`, printf/malloc/free, librerías externas (incl. C++11/Boost).
- Diseño: evitar fugas de memoria; clases en Forma Canónica Ortodoxa (Mód.02–09 salvo indicación); implementaciones no deben ir en headers (salvo plantillas); añadir include guards.
- Regla adicional (obligatoria): cada ejercicio debe usar un tipo específico de casting para manejar conversiones — esa elección se revisará en la defensa. (Ver mod06/cpp6-context.md.)

Sugerencias por ejercicio (cumpliendo C++98 y la regla de casting):

- ex00 (ScalarConverter — mod06/ex00)
  - Parseo: usar funciones de C como `strtod`, `strtol` desde <cstdlib> o streams de <sstream>.
  - Para conversiones entre tipos numéricos, usar `static_cast<...>` y comprobar overflow/rangos con <limits>.
  - Para char: comprobar `std::isprint` antes de mostrar; si no imprimible, mostrar mensaje adecuado.
  - Manejar pseudoliterals (`nan`, `inf`, `nanf`, `inff`) explícitamente.

- ex01 (Serializer — mod06/ex01)
  - Implementar `serialize`/`deserialize` con `reinterpret_cast<uintptr_t>(ptr)` y `reinterpret_cast<Data*>(raw)` respectivamente (esto es lo esperado y portable para este ejercicio).

- ex02 (Identify real type — mod06/ex02)
  - Hacer que `Base` tenga un destructor virtual.
  - Para `identify(Base* p)`: usar `dynamic_cast<A*>(p)` / `dynamic_cast<B*>(p)` / `dynamic_cast<C*>(p)` y detectar `nullptr`.
  - Para `identify(Base& p)`: usar `dynamic_cast<A&>(p)` en un bloque try/catch y capturar `std::bad_cast` para probar las alternativas (el enunciado prohíbe usar un puntero dentro de esta función).
  - No usar <typeinfo>.

Checklist rápido antes de entregar:
- Compila con `c++ -std=c++98 -Wall -Wextra -Werror`.
- No usar contenedores STL en estos ejercicios.
- No poner implementaciones no-template en headers.
- Todas las conversiones usan el tipo de cast elegido (documentarlo en comentarios si lo deseas).

Archivos/dirs referenciados:
- cpp6-context.md
- mod06/ex00
- mod06/ex01
- mod06/ex02
