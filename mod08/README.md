# Módulo 08 — Contenedores y Algoritmos STL

## Resumen general

Esta carpeta contiene las soluciones a los ejercicios ex00..ex02 implementadas para C++98 siguiendo las instrucciones del módulo.

**Compilación:** Todos los ejercicios compilan con `c++ -std=c++98 -Wall -Wextra -Werror` sin errores ni warnings.

**Cómo compilar y ejecutar:**
```bash
cd ex00 && make && ./containers
cd ../ex01 && make && ./containers
cd ../ex02 && make && ./containers
```

**Validación de memoria:** Todos los ejercicios pasan `valgrind --leak-check=full` sin fugas (`in use at exit: 0 bytes`).

---

## Conceptos clave aprendidos

### ¿Qué son los Contenedores STL (Standard Template Library)?

Los contenedores STL son estructuras de datos genéricas que permiten almacenar y manipular colecciones de elementos de cualquier tipo. Son la base del módulo 08 y representan un cambio fundamental en cómo escribimos código C++.

**Categorías principales de contenedores:**

| Categoría | Ejemplos | Características | Caso de uso |
|-----------|----------|-----------------|------------|
| **Secuenciales** | `vector`, `deque`, `list` | Mantienen orden de inserción | Cuando necesitas acceso ordenado |
| **Asociativos** | `set`, `map`, `multiset`, `multimap` | Organizados por claves | Búsquedas rápidas (O(log n)) |
| **Adaptadores** | `stack`, `queue`, `priority_queue` | Restringen acceso a elementos | Cuando necesitas LIFO/FIFO |

**Ventajas de los contenedores STL:**
- ✅ Seguridad de tipos en compilación.
- ✅ Gestión automática de memoria (sin `new`/`delete` manual).
- ✅ Iteradores para recorrer elementos de forma genérica.
- ✅ Algoritmos optimizados y eficientes.
- ✅ Código más limpio y expresivo.

### Algoritmos STL (header `<algorithm>`)

Los algoritmos STL son funciones genéricas que operan sobre contenedores a través de iteradores. **El módulo 08 requiere su uso**: no usar STL Algorithms cuando es apropiado resulta en calificación muy baja.

**Algoritmos utilizados en este módulo:**

| Algoritmo | Descripción | Complejidad | Uso |
|-----------|-----------|-----------|-----|
| `std::find(first, last, value)` | Busca el primer elemento igual a `value` | O(n) | Búsquedas lineales |
| `std::sort(first, last)` | Ordena elementos (QuickSort/MergeSort) | O(n log n) | Preparar datos para análisis |
| `std::min_element()` / `std::max_element()` | Encuentra mín/máx | O(n) | Obtener extremos |

**Por qué usar algoritmos STL:**
- Reutilización: no reinventas la rueda.
- Optimización: están escritos por expertos.
- Mantenibilidad: código más legible y menos propenso a bugs.
- Performance: ofrecen las mejores complejidades conocidas.

### Iteradores: La puerta a la generalidad

Un iterador es un objeto que actúa como un "puntero genérico" a elementos dentro de un contenedor. Permiten recorrer cualquier contenedor de forma uniforme sin saber su estructura interna.

**Categorías de iteradores (del más débil al más fuerte):**

1. **Input Iterator** — Solo lectura, avance solo hacia delante (ej: entrada de stream)
2. **Output Iterator** — Solo escritura, avance solo hacia delante (ej: salida a stream)
3. **Forward Iterator** — Lectura/escritura, avance solo hacia delante (ej: `std::forward_list`)
4. **Bidirectional Iterator** — Lectura/escritura, avance adelante y atrás (ej: `std::list`, `std::set`)
5. **Random Access Iterator** — Acceso completo, como punteros (ej: `std::vector`, `std::deque`)

**Ejemplo de uso genérico:**
```cpp
template <typename Container>
void print(const Container &c) {
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
}
```

Esta función trabaja con **cualquier contenedor**: `std::vector`, `std::list`, `std::set`, etc.

### Diferencias clave entre contenedores

| Contenedor | Acceso | Insert/Delete | Memoria | Iterador |
|-----------|--------|---------------|---------|----------|
| `vector<T>` | O(1) random | O(n) medio | Contigua | Random Access |
| `deque<T>` | O(1) random | O(n) medio | Bloques | Random Access |
| `list<T>` | O(n) lineal | O(1) si tienes iterador | Dispersa | Bidirectional |
| `set<T>` | O(log n) búsqueda | O(log n) | Árbol | Bidirectional |
| `map<K,V>` | O(log n) búsqueda | O(log n) | Árbol | Bidirectional |

**Regla de oro:** Usa `vector` si no tienes razón específica para otro contenedor (excelente rendimiento en la mayoría de casos).

---

## Resumen por ejercicios

### ex00 — easyfind

**Descripción:** Implementa una función plantilla que busca un valor en un contenedor.

**Archivos:** `easyfind.hpp`, `main.cpp`, `Makefile`

**Frase de defensa (20s):**
> "`easyfind` es una función plantilla que busca un valor entero dentro de cualquier contenedor usando `std::find()`. Devuelve el índice de la primera ocurrencia o lanza `std::out_of_range` si no la encuentra. Funciona con contenedores secuenciales (`vector`, `list`, `deque`) y asociativos (`set`)."

**Conceptos aprendidos:**
- Uso de `std::find()` del header `<algorithm>`.
- Cálculo de índice desde un iterador.
- Generalidad: una única función trabaja con múltiples contenedores.
- Excepciones para comunicar errores.

**Lección clave:**

El código original usaba un bucle manual:
```cpp
for (it = c.begin(); it != c.end(); ++it) {
    if ((*it) == x) return i;
    ++i;
}
```

Con STL optimizado:
```cpp
typename T::iterator it = std::find(c.begin(), c.end(), x);
if (it == c.end())
    throw std::runtime_error("not found");
```

Beneficios:
- **Claridad:** `std::find` expresa la intención directamente.
- **Optimización:** El compilador puede especializarla para cada tipo.
- **Robustez:** Implementación testeada por miles de desarrolladores.

**Salida esperada:**
```
list ---
exception caught: not found
container at 1 = 25
deque ---
exception caught: not found
container at 2 = 3
vector ---
exception caught: not found
container at 3 = 99
set ---
exception caught: not found
container at 0 = 5
```

---

### ex01 — Span

**Descripción:** Implementa una clase que almacena hasta N enteros y calcula los "spans" (distancias) más corto y más largo entre elementos.

**Archivos:** `Span.hpp`, `Span.cpp`, `main.cpp`, `Makefile`

**Frase de defensa (30s):**
> "La clase `Span` gestiona un vector de hasta N enteros. Implementa la Regla de las Tres (constructor copia, operador=, destructor) para gestión correcta. El método `shortestSpan()` encuentra la distancia mínima entre dos elementos; `longestSpan()` la máxima. Ambos usan `std::sort()` para O(n log n) en lugar de O(n²) con búsqueda bruta. También implemento `addNumbers()` para llenar el Span desde un rango de iteradores, algo mucho más eficiente que llamadas repetidas a `addNumber()`."

**Conceptos aprendidos:**
- Contenedores como miembros de clase (`std::vector<int> nums`).
- Iteradores como parámetros: `template <class InputIterator> void addNumbers(InputIterator first, InputIterator last)`.
- Regla de las Tres: necesaria cuando gestiono memoria (en este caso, `vector` la gestiona automáticamente pero sigue siendo buena práctica).
- Optimización con algoritmos: `std::sort()` + análisis es mejor que búsqueda O(n²).

**Lección clave - Optimización con STL:**

**Código original (O(n²)):**
```cpp
unsigned int Span::shortestSpan() {
    unsigned int shortest = std::abs(nums[0] - nums[1]);
    for (unsigned int i = 0; i < nums.size(); ++i) 
        for (unsigned int j = i + 1; j < nums.size(); ++j) {
            unsigned int span = abs(nums[i] - nums[j]);
            if (span < shortest)
                shortest = span;
        }
    return shortest;
}
```

Con 10,000 elementos = ~100 millones de comparaciones. ¡Muy lento!

**Código optimizado (O(n log n)):**
```cpp
unsigned int Span::shortestSpan() {
    std::vector<int> sorted_nums(nums.begin(), nums.end());
    std::sort(sorted_nums.begin(), sorted_nums.end());
    
    // Después de ordenar, el span más corto es entre adyacentes
    unsigned int shortest = sorted_nums[1] - sorted_nums[0];
    for (unsigned int i = 1; i < sorted_nums.size(); ++i) {
        unsigned int span = sorted_nums[i] - sorted_nums[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}
```

**Por qué funciona:**
- Si ordenas números, la distancia **mínima** siempre está entre elementos **adyacentes**.
- La distancia **máxima** es simplemente `max - min`.

**Comparación de rendimiento:**
- 10,000 elementos: O(n²) ≈ 100M ops vs O(n log n) ≈ 130K ops → **~700x más rápido**
- Diferencia notable: O(n²) puede tardar segundos, O(n log n) es instantáneo.

**Iteradores como parámetros:**

```cpp
template <typename InputIterator>
void Span::addNumbers(InputIterator first, InputIterator last) {
    std::vector<int> tmp(first, last);
    if (nums.size() + tmp.size() >= N)
        throw std::runtime_error("too many numbers");
    nums.insert(nums.end(), first, last);
}
```

Beneficios:
- **Generalidad:** Funciona con cualquier contenedor (`vector`, `list`, `array`, etc.)
- **Eficiencia:** Una sola llamada vs. miles de `addNumber()`.
- **Legibilidad:** `sp.addNumbers(arr.begin(), arr.end())` es clara y expresiva.

**Salida esperada:**
```
2
14
0
14
0
9997
The contents of span are: 3 1 2 3 
The contents of span are: 3 1 2 3 11 22 33 44
```

---

### ex02 — MutantStack

**Descripción:** Crea una clase que extiende `std::stack` para hacerlo iterable.

**Archivos:** `MutantStack.hpp`, `main.cpp`, `Makefile`

**Frase de defensa (25s):**
> "`MutantStack<T>` es una clase plantilla que hereda de `std::stack<T>`. A diferencia de `std::stack` que no es iterable, expongo el contenedor interno (miembro `c`) y proporciono métodos `begin()` y `end()` que retornan iteradores al contenedor subyacente (por defecto, `std::deque`). Implemento versiones const y no-const de `begin()`/`end()`. La clase soporta todos los métodos de `stack` (push, pop, top, size) más iteradores, lo que la hace tan flexible como contenedores normales pero manteniendo semántica LIFO."

**Conceptos aprendidos:**
- Herencia de plantillas: `class MutantStack : public std::stack<T>`.
- Acceso a miembros protegidos de la clase base: el miembro `c` de `std::stack`.
- Typedefs para exponer tipos internos: `typedef typename container_type::iterator iterator`.
- Diferencia entre `std::stack` (adaptador no-iterable) y contenedores normales.

**Lección clave - Adaptadores vs Contenedores:**

`std::stack` es un **adaptador de contenedor**: envuelve un contenedor secuencial (`std::deque` por defecto) y expone solo operaciones LIFO (Last-In-First-Out).

```cpp
std::stack<int> s;
s.push(1);
s.push(2);
s.top();     // ✅ OK: acceso al tope
s.begin();   // ❌ ERROR: no tiene begin()!
```

¿Por qué `std::stack` no tiene iteradores?
- Porque si pudieras iterar, podrías acceder y modificar elementos en orden arbitrario → violarías la semántica LIFO.
- STL mantiene restricciones de acceso como **garantías de contrato**.

**Solución: Heredar y exponer iteradores:**

```cpp
template<typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
};
```

Ahora:
- Usas `MutantStack` como `std::stack` (push, pop, top, size).
- Pero también tienes iteradores para análisis/depuración.

**¿Por qué acceso a `c`?**

El miembro `c` en `std::stack` es **protegido**, no público. Al heredar, puedes acceder a miembros protegidos. Si intentaras en código externo:

```cpp
std::stack<int> s;
s.c.begin();  // ❌ ERROR: 'c' es protegido
```

Pero dentro de `MutantStack`:

```cpp
iterator begin() { return this->c.begin(); }  // ✅ OK
```

**Diseño de adaptadores vs contenedores:**

| Aspecto | Contenedor (`vector`, `list`) | Adaptador (`stack`, `queue`) |
|--------|------|--------|
| Acceso | Cualquiera (random access o FIFO) | Restringido (LIFO, FIFO) |
| Iteradores | Siempre presentes | A menudo ausentes |
| Uso típico | Almacenamiento general | Casos específicos (parsing, BFS) |
| `MutantStack` | Híbrido: stack + iteradores | ✅ Mejor de ambos mundos |

**Salida esperada:**
```
top: 17
size: 1
5
3
5
737
0
top: 17
size: 1
5
3
5
737
0
```

(La salida se repite porque testeas MutantStack y luego `std::vector` con la misma lógica.)

---

## Trampas comunes y puntos clave para la defensa

1. **DEBES usar STL Algorithms**
   - El módulo exige explícitamente `<algorithm>`.
   - No usarlos resulta en calificación muy baja ("even if your code works").
   - Usa `std::find()`, `std::sort()`, `std::min_element()`, etc. siempre que sea apropiado.

2. **Contenedores vs Adaptadores**
   - `vector`, `list`, `deque`, `set`, `map` son contenedores → tienen iteradores.
   - `stack`, `queue`, `priority_queue` son adaptadores → NO tienen iteradores (a menos que heredes).

3. **Iteradores como parámetros (Range constructor)**
   - Los contenedores aceptan iteradores en constructores: `std::vector<int> v(arr.begin(), arr.end())`.
   - Esto es **mucho más eficiente** que loops manuales.

4. **Tipografía de iteradores**
   - `typename T::iterator` — iterador mutable.
   - `typename T::const_iterator` — iterador const.
   - Para obtener const_iterator manualmente: `c.begin()` retorna `const_iterator` si `c` es const.

5. **std::sort requiere Random Access Iterators**
   - `std::sort` funciona con `vector`, `deque`, `array`.
   - **NO funciona** con `list` o `set` (solo Bidirectional Iterators).
   - Para `list`: usa `list::sort()` (miembro de la clase) o `std::stable_sort`.

6. **Regla de las Tres en Span**
   - Aunque `std::vector` gestiona memoria automáticamente, escribir constructor copia y `operator=` explícitos es buena práctica.
   - Cuando borres esta clase, el vector se destruye automáticamente.

7. **Acceso a miembros protegidos en herencia**
   - Solo dentro de métodos de la clase derivada puedes acceder a `protected`.
   - Es por eso que `MutantStack` puede hacer `this->c.begin()`.

8. **Complejidad algorítmica**
   - O(n²) vs O(n log n) es enorme: diferencia entre segundos y microsegundos.
   - Siempre elige el algoritmo de mejor complejidad si está disponible.

---

## Cambios y optimizaciones realizados

### ex00 - easyfind
**Antes:** Loop manual `for (it = c.begin(); it != c.end(); ++it)`
**Después:** `std::find(c.begin(), c.end(), x)`
**Beneficio:** Código más claro, optimizable por compilador.

### ex01 - Span
**Antes:** `shortestSpan()` y `longestSpan()` usaban O(n²) nested loops.
**Después:** `std::sort()` + iteración única = O(n log n).
**Beneficio:** 10,000 elementos: ~700x más rápido.

**Headers añadidos:** `#include <algorithm>` para `std::sort()` y `std::find()`.

**ex01/main.cpp:** Agregados `#include <cstdlib>` y `#include <ctime>` para `rand()` y `srand()`.

**ex01/Span.cpp:** Agregado `#include <cstdlib>` para `std::abs()`.

---

## Preguntas rápidas para la defensa (flashcards)

**P1: ¿Por qué STL Algorithms son obligatorios en módulo 08?**
A: Porque el objetivo del módulo es enseñar a usar STL correctamente. El subject dice explícitamente: "You will get a very bad grade if you don't". Algoritmos como `std::sort()`, `std::find()` son más seguros, rápidos y expresivos que loops manuales.

**P2: ¿Cuál es la diferencia entre `std::vector` y `std::list`?**
A: `vector` tiene acceso O(1) random pero O(n) inserción/borrado. `list` tiene O(n) acceso pero O(1) inserción/borrado en posiciones conocidas. Usa `vector` por defecto a menos que hagas muchas inserciones/borrados en el medio.

**P3: ¿Por qué `std::stack` no tiene iteradores?**
A: Porque es un adaptador diseñado para LIFO. Si tuviera iteradores, podrías violar la semántica LIFO accediendo elementos arbitrariamente. `MutantStack` hereda y expone el contenedor subyacente para romper esta restricción.

**P4: ¿Cómo optimizaste `shortestSpan()`?**
A: Originalmente era O(n²) con nested loops comparando cada par. Ahora ordeno con `std::sort()` (O(n log n)) y luego sé que la distancia mínima está entre elementos adyacentes (O(n)). Total: O(n log n) vs O(n²).

**P5: ¿Qué es un iterador?**
A: Un objeto que actúa como puntero genérico a elementos dentro de un contenedor. Permite recorrer elementos sin saber la estructura interna del contenedor. Hay 5 categorías: Input, Output, Forward, Bidirectional, Random Access.

**P6: ¿Cómo usas iteradores en parámetros de función?**
A: Con plantillas: `template <typename InputIterator> void func(InputIterator first, InputIterator last)`. Funciona con cualquier contenedor. Ejemplo: `sp.addNumbers(arr.begin(), arr.end())`.

**P7: ¿Por qué `std::sort` no funciona con `std::list`?**
A: Porque `std::sort` requiere Random Access Iterators (acceso O(1) a cualquier elemento). `list` solo tiene Bidirectional Iterators. Para `list`, usa `list::sort()` (miembro) en lugar de `std::sort()`.

**P8: ¿Qué es la Regla de las Tres?**
A: Constructor copia, operador= y destructor. Si tu clase gestiona recursos (memoria, archivos), necesitas las tres para evitar undefined behavior. En Span, `std::vector` los gestiona, pero es buena práctica escribirlos explícitamente.

---

## Plan de preparación antes de la defensa (30–60 min)

1. **Lee este README** (5 min) — comprende los conceptos.
2. **Ejecuta cada ejercicio** (10 min) — verifica compilación y salida.
3. **Repite en voz alta las 8 frases de defensa** (3 min) — memoriza puntos clave.
4. **Repasa las 8 flashcards** (5 min) — responde sin mirar.
5. **Analiza la optimización O(n²) → O(n log n)** (5 min) — entiende por qué sort + linear pass es más rápido.
6. **Prueba MutantStack con diferentes contenedores** (5 min) — cambia `typedef` en main para ver que funciona con `vector`, `list`, `deque`.
7. **Valgrind check** (5 min) — `valgrind --leak-check=full ./containers` en cada ejercicio.
8. **Revisar código fuente** (10 min) — entiende cada línea.

---

## Checklist final antes de la evaluación

- [ ] Compilo: `cd mod08/exNN && make` sin errores en todos los ejercicios.
- [ ] Ejecuto: `./containers` en cada ejercicio y la salida es correcta.
- [ ] Leo: secciones "Conceptos clave" y frases de defensa de este README.
- [ ] Practico: repito en voz alta las 8 frases de defensa 2 veces.
- [ ] Flashcards: repaso las 8 preguntas sin mirar las respuestas.
- [ ] STL: verifico que `<algorithm>` está usado en ex00 y ex01.
- [ ] Valgrind: `valgrind --leak-check=full ./containers` en todos los ejercicios → "in use at exit: 0 bytes".
- [ ] Código: entiendo por qué cada ejercicio necesita STL y qué ventajas proporciona.
- [ ] Optimización: puedo explicar claramente O(n²) → O(n log n) en Span.

---

## Criterios de evaluación

- ✅ **Compilación:** Sin errores ni warnings con `-std=c++98 -Wall -Wextra -Werror`.
- ✅ **Corrección:** El código hace exactamente lo que pide el subject.
- ✅ **Uso de STL:** Algoritmos (`std::find`, `std::sort`) y contenedores (`vector`, `deque`, `list`, `set`) usados apropiadamente.
- ✅ **Comprensión:** Explicas por qué usaste STL y qué ventajas proporciona.
- ✅ **Memoria:** Sin fugas (validado con valgrind).
- ✅ **Iteradores:** Usados correctamente en parámetros y loops.
- ✅ **Const-correctness:** `begin() const` y `end() const` donde corresponde.
- ✅ **Excepciones:** Lanzas excepciones apropiadas, código robusto.

---

## Recursos útiles

- [cppreference.com - Containers](https://en.cppreference.com/w/cpp/container)
- [cppreference.com - Algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [cppreference.com - Iterators](https://en.cppreference.com/w/cpp/iterator)
- Regla: Si necesitas buscar/ordenar/transformar, hay un `std::` algorithm para eso.
