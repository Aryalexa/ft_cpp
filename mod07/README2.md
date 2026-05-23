# Módulo 07 — Plantillas (templates)

## Resumen general

Esta carpeta contiene las soluciones a los ejercicios ex00..ex02 implementadas para C++98 siguiendo las instrucciones del módulo.

**Compilación:** Todos los ejercicios compilan con `c++ -std=c++98 -Wall -Wextra -Werror` sin errores ni warnings.

**Cómo compilar y ejecutar:**
```bash
cd ex00 && make && ./templates
cd ../ex01 && make && ./templates
cd ../ex02 && make && ./templates
```

**Validación de memoria:** Todos los ejercicios pasan `valgrind --leak-check=full` sin fugas (`in use at exit: 0 bytes`).

---

## Conceptos clave aprendidos

### ¿Qué son los templates?

Son plantillas de código que permiten escribir funciones o clases genéricas reutilizables para múltiples tipos sin duplicar código.

**Sintaxis:**
```cpp
template <typename T>
T max(const T &a, const T &b);
```

**Instanciación:** El compilador crea una versión concreta de la plantilla en **tiempo de compilación** cuando la usas con un tipo específico (ej: `max<int>`, `max<std::string>`).

**Ventajas:**
- ✅ Reutilización: un algoritmo para todos los tipos.
- ✅ Seguridad de tipos en compilación (errores detectados pronto).
- ✅ Eficiencia: código especializado sin overhead en tiempo de ejecución.

### Pasar por valor vs. referencia vs. referencia const

| Forma | Uso | Ventaja | Desventaja |
|-------|-----|---------|-----------|
| `T a` | Por valor | Simple, copia el valor | Copia innecesaria (lento para tipos grandes) |
| `T& a` | Referencia no-const | Modifica original, sin copia | Permite modificaciones involuntarias |
| `const T& a` | Referencia const | Sin copia, no se modifica, seguro | Must be constant value |

**En este módulo:**
- Parámetros: `const T&` (eficiente + seguro, no modificamos).
- Retorno en `min`/`max`: `T` por valor (seguro con temporales, es lo que pide el subject).

### Regla de las tres (Rule of Three)

Cuando una clase gestiona recursos externos (memoria dinámica, archivos, etc.), necesita:
1. **Constructor copia** — copia profunda del recurso.
2. **Operador =** — asignación profunda del recurso.
3. **Destructor** — libera el recurso.

**En ex02:** `Array<T>` necesita las tres porque gestiona memoria con `new[]`/`delete[]`.
- Sin ellas: dos objetos compartirían el mismo `arr` → doble `delete` (crash).

### Const-correctness

Funciones y parámetros deben tener `const` donde sea apropiado:
- Si no modificas un parámetro: `const T&` o `const T`
- Si modificas un parámetro: `T&`
- Si un método no modifica el objeto: `void func() const`

Esto evita bugs sutiles y comunica intención clara al lector.

---

## Resumen por ejercicios

### ex00 — swap, min, max

**Descripción:** Implementa tres funciones plantilla básicas.

**Archivos:** `templates.hpp`, `main.cpp`, `Makefile`

**Frase de defensa (20s):**
> "Uso plantillas para implementar `swap`, `min` y `max` una sola vez para cualquier tipo. Los parámetros son referencias const para eficiencia. El retorno es por valor (no referencia) para evitar undefined behavior con temporales."

**Conceptos aprendidos:**
- Sintaxis y semántica de funciones plantilla.
- Paso por referencia y retorno por valor.
- Instanciación automática por el compilador.

**Salida esperada:**
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

---

### ex01 — iter

**Descripción:** Implementa una función plantilla que aplica una función a cada elemento de un array.

**Archivos:** `iter.hpp`, `main.cpp`, `Makefile`

**Frase de defensa (20s):**
> "`iter` acepta un puntero a array, su longitud y una función. Usa dos overloads — uno para `T*` y otro para `const T*` — para soportar arrays const y no-const. Las funciones pasadas pueden ser de lectura (`const T&`) o modificación (`T&`) según el contexto."

**Conceptos aprendidos:**
- Pasar funciones como parámetros.
- Overloading (sobrecarga) de plantillas para const y no-const.
- Const-correctness: respetar si los elementos son const o no.

**Lección clave:**
`iter` necesita **dos overloads** para flexibilidad:
```cpp
template <typename T, typename F>
void iter(T *arr, size_t len, F func)  // Arrays no-const → pasa T

template <typename T, typename F>
void iter(const T *arr, size_t len, F func)  // Arrays const → pasa const T
```

Las funciones pasadas deben estar preparadas:
- **Lectura:** `void my_print(const T&)` — funciona con const y no-const.
- **Modificación:** `void increment(T&)` — solo funciona con no-const (correcto: no puedes modificar const).

**Salida esperada:** Arrays de int, string, char; ejemplos de lectura y modificación.

---

### ex02 — Array<T>

**Descripción:** Implementa una clase plantilla que encapsula un array dinámico.

**Archivos:** `Array.hpp`, `main.cpp`, `Makefile`

**Frase de defensa (20s):**
> "`Array<T>` es una clase plantilla que gestiona memoria dinámica. Implementa la regla de las tres (copia, operador=, destructor) para garantizar copia profunda sin fugas. El `operator[]` comprueba límites y lanza `std::out_of_range` si accedes fuera del rango. Tengo versiones const y no-const de `operator[]`."

**Conceptos aprendidos:**
- Clase plantilla con recursos dinámicos.
- Regla de las tres: constructor copia, operador=, destructor.
- Comprobación de límites y manejo de excepciones.
- Const-correctness en métodos y operadores.

**Requisitos cumplidos:**
- ✅ Constructor sin parámetros (array vacío).
- ✅ Constructor con `unsigned int n` (array de n elementos).
- ✅ Constructor copia y `operator=` (deep copy).
- ✅ Destructor (libera con `delete[]`).
- ✅ `operator[]` con comprobación de límites, lanza `std::out_of_range`.
- ✅ `size()` const que devuelve número de elementos.
- ✅ Versiones const y no-const de `operator[]`.

**Salida esperada:** Arrays vacíos, copias profundas, excepciones en acceso fuera de rango, test 42 con asignaciones aleatorias.

---

## Trampas comunes y puntos clave para la defensa

1. **Las plantillas van en headers**
   - Si la definición queda en .cpp, no se instanciará en otras unidades de traducción.
   - El compilador necesita ver la definición completa en cada punto de uso.

2. **Retorno por valor vs. referencia**
   - Retornar por referencia (`const T&`) a un temporal es undefined behavior.
   - En `min`/`max` retornamos por valor: copia el resultado (seguro).

3. **Const-correctness en iter**
   - Dos overloads: uno para `T*` (pasa `T` a la función), otro para `const T*` (pasa `const T`).
   - Esto permite máxima flexibilidad sin comprometer seguridad.

4. **Regla de las tres en Array<T>**
   - Sin constructor copia: dos objetos comparten `arr` → doble `delete` (crash).
   - Sin `operator=` profundo: asignación crea alias → datos inconsistentes.
   - Sin destructor: memory leak.

5. **Excepciones estándar**
   - Usamos `std::out_of_range` (hereda de `std::exception`).
   - Lanzar excepciones comunica error de forma clara.

6. **C++98 compatibility**
   - No `nullptr`: usar `0` o `NULL`.
   - No `auto`: tipos explícitos.
   - Templates definidos en headers.

---

## Preguntas rápidas para la defensa (flashcards)

**P1: ¿Por qué las plantillas van en headers?**
A: Porque el compilador debe ver la definición para instanciarla con tipos concretos en cada punto de uso. Si queda en .cpp, no se instantiará en otras unidades de traducción.

**P2: ¿Qué es la regla de las tres?**
A: Constructor copia, `operator=` y destructor. Necesarios cuando la clase gestiona recursos externos (memoria dinámica, archivos, etc.). Sin ellos, hay undefined behavior.

**P3: ¿Qué es la instanciación de una plantilla?**
A: Es cuando el compilador crea una versión concreta de la plantilla para un tipo específico. Ej: usar `swap<int>` genera código de `swap` especializado para `int`.

**P4: ¿Cómo manejas un acceso fuera de rango en `operator[]`?**
A: Compruebo si `index < len`. Si no, lanzo `std::out_of_range` con un mensaje descriptivo.

**P5: ¿Por qué evitar `nullptr` en este repo?**
A: Porque el código se ajusta a C++98 (antes de C++11). Usar `0` o `NULL` es la alternativa compatible.

**P6: ¿Por qué `iter` necesita dos overloads?**
A: Porque arrays const deben pasar elementos const a la función, mientras que arrays no-const pueden pasar elementos no-const. Los dos overloads hacen que `iter` sea flexible: funciones que necesitan `const T&` funcionan en ambos casos, pero funciones que necesitan `T&` (para modificar) solo funcionan con arrays no-const (correcto y seguro).

---

## Plan de preparación antes de la defensa (30–60 min)

1. **Lee este README** (5 min) — comprende los conceptos.
2. **Ejecuta cada ejercicio** (10 min) — verifica que compilas y la salida es correcta.
3. **Repite en voz alta las 3 frases de defensa** (3 min) — memoriza los puntos clave.
4. **Repasa las 6 flashcards** (5 min) — responde sin mirar.
5. **Valgrind check** (5 min) — `valgrind --leak-check=full ./templates` en ex02.
6. **Revisar código fuente** (10 min) — entiende qué hace cada línea.

---

## Checklist final antes de la evaluación

- [ ] Compilo: `cd mod07/exNN && make` sin errores en todos los ejercicios.
- [ ] Ejecuto: `./templates` en cada ejercicio y la salida tiene sentido (sin crashes).
- [ ] Leo: secciones "Conceptos clave" y frases de defensa de este README.
- [ ] Practico: repito en voz alta las 3 frases de defensa 2 veces.
- [ ] Flashcards: repaso las 6 preguntas sin mirar las respuestas.
- [ ] Valgrind: `valgrind --leak-check=full ./templates` en ex02 → "in use at exit: 0 bytes".
- [ ] Código: entiendo por qué cada ejercicio necesita templates y qué hace.

---

## Criterios de evaluación

- ✅ **Compilación:** Sin errores ni warnings con `-std=c++98 -Wall -Wextra -Werror`.
- ✅ **Correctitud:** El código hace exactamente lo que pide el subject.
- ✅ **Comprensión:** Explicas por qué usaste templates y qué ventajas dan.
- ✅ **Memoria:** Sin fugas (validado con valgrind).
- ✅ **Const-correctness:** Parámetros y métodos tienen `const` donde corresponde.
- ✅ **Excepciones:** Lanzas excepciones apropiadas (no crashes).

