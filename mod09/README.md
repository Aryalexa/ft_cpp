# Módulo 09 — Contenedores STL Avanzados

## Resumen general

Esta carpeta contiene las soluciones a los ejercicios ex00..ex02 implementadas para C++98 siguiendo las instrucciones del módulo.

**Compilación:** Todos los ejercicios compilan con `c++ -std=c++98 -Wall -Wextra -Werror` sin errores ni warnings.

**Cómo compilar y ejecutar:**
```bash
cd ex00 && make && ./btc input.txt
cd ../ex01 && make && ./RPN "1 2 +"
cd ../ex02 && make && ./PmergeMe 3 5 9 7 4
```

**Validación de memoria:** Todos los ejercicios pasan `valgrind --leak-check=full` sin fugas (`in use at exit: 0 bytes`).

---

## Regla especial del módulo 09

⚠️ **Restricción crítica:** Una vez utilizas un contenedor STL, **NO puedes usarlo en el resto del módulo**.

Por ejemplo:
- ex00 usa `std::map` → no puedes usar `std::map` en ex01 o ex02
- ex01 usa `std::stack` y `std::set` → no puedes usarlos en ex02
- ex02 usa `std::vector` y `std::deque` → son los últimos permitidos

Esta regla obliga a conocer múltiples contenedores y sus tradeoffs.

---

## Conceptos clave aprendidos

### STL Containers: Selección estratégica

Módulo 09 requiere usar **múltiples contenedores correctamente**, eligiendo el mejor para cada caso de uso.

**Contenedores disponibles (STL C++98):**

| Contenedor | Complejidad | Caso de uso | Caract. |
|-----------|------------|-----------|---------|
| `std::map<K,V>` | O(log n) búsqueda | Búsquedas rápidas por clave | Árbol rojo-negro |
| `std::vector<T>` | O(1) acceso random | Acceso frecuente, insert al final | Memoria contigua |
| `std::deque<T>` | O(1) ambos extremos | Insert/erase en ambos extremos | Bloques ligados |
| `std::stack<T>` | O(1) push/pop | Evaluación postfija (RPN) | LIFO |
| `std::set<T>` | O(log n) búsqueda | Validación de pertenencia | Árbol único |
| `std::list<T>` | O(1) insert/erase | Insert/erase frecuentes en medio | Lista ligada (❌ NO USAR aquí) |

**Regla de oro:** 
- **Búsqueda rápida + datos ordenados?** → `std::map` o `std::set`
- **Acceso random frecuente?** → `std::vector` (con `lower_bound` para búsqueda binaria)
- **Stack/Queue operations?** → `std::stack` (LIFO) con contenedor subyacente
- **Insert/erase en ambos extremos?** → `std::deque`

### Cache Locality y Rendimiento Real

**Teoría:** Ambos contenedores tienen complejidad similar (O(log n) búsqueda)  
**Realidad:** Vector es **1.6x más rápido** que deque en este módulo

Por qué?

1. **CPU Cache (L1/L2/L3):**
   - Vector: Memoria contigua → prefetch óptimo → cache hits
   - Deque: Bloques fragmentados → saltos entre bloques → cache misses

2. **Con 3000 elementos:**
   - Vector: ~1ms
   - Deque: ~1.6ms
   - List: ~10+ segundos (❌ búsqueda lineal O(n))

**Lección:** El contenedor "teóricamente correcto" no siempre es el más rápido. Mide, no asumas.

Para más detalles sobre Vector vs Deque vs List, ver: [readme-ex02.md](readme-ex02.md)

### Validación de entrada: Strings y Parsing

Módulo 09 requiere parsear input de múltiples formatos:

```
ex00: "date | value"  → Strings, floats, fechas válidas
ex01: "8 9 * 9 - ..."  → Tokens, números, operadores
ex02: "3 5 9 7 4"     → Enteros positivos
```

**Técnicas C++98 para parsing:**

```cpp
// Parsing strings (ex00, ex01)
std::istringstream iss(line);
std::string token;
iss >> token;  // Lee hasta espacio/newline

// Validación de números
double val;
if (iss >> val && iss.eof())  // Verifica parseo exitoso y fin
    // Es un número válido
else
    // No es un número

// Validación de fechas (ex00)
int y, m, d;
if (iss >> y >> dash1 >> m >> dash2 >> d)
    // Y luego verificar con std::tm + mktime()
```

---

## Resumen por ejercicios

### ex00 — Bitcoin Exchange ✅

**Contenedor usado:** `std::map<std::string, double>`

**Descripción:** Lee un CSV histórico de precios de Bitcoin y evalúa un portafolio de transacciones.

**Concepto clave:** 
- `lower_bound()` para encontrar la fecha más cercana ≤ a la buscada
- Validación de fechas con `std::tm` + `mktime()`
- Manejo de excepciones para entrada malformada

**Complejidad:**
- Carga CSV: O(n log n) (n líneas, cada insert es O(log n))
- Por cada línea de entrada: O(log n) búsqueda
- Total: O(n log n + m log n) donde n = líneas DB, m = líneas input

**Output esperado:**
```
2011-01-03 => 3 = 0.9
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
```

---

### ex01 — RPN (Reverse Polish Notation) ✅

**Contenedores usados:** `std::stack<double>`, `std::set<std::string>`

**Descripción:** Evalúa expresiones en notación polaca inversa (postfija).

**Concepto clave:**
- Stack LIFO para acumular operandos
- Cuando llega un operador, pop 2 elementos, aplica operación, push resultado
- Set para validación rápida de operadores

**Algoritmo RPN:**
```
Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"
Stack operaciones:
  8       → [8]
  9       → [8, 9]
  *       → [72]           (8*9)
  9       → [72, 9]
  -       → [63]           (72-9)
  ... continúa ...
Result: 42
```

**Validación:**
- El stack debe tener exactamente 1 elemento al final
- Si un operador llega y hay < 2 operandos → Error
- División por cero → Error

**Output esperado:**
```
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
./RPN "(1 + 1)"
Error: bad format
```

---

### ex02 — PmergeMe (Merge-Insertion Sort) ✅

**Contenedores usados:** `std::vector<int>`, `std::deque<int>`

**Descripción:** Implementa el algoritmo Ford-Johnson para ordenar con mínimas comparaciones.

**Concepto clave:** 
- **Ford-Johnson Algorithm:** Pairing → recursive sort → inserción por Jacobsthal order
- **Jacobsthal Sequence:** Minimiza comparaciones en inserciones binarias
- **Memoización:** Caché estático de números de Jacobsthal

**Algoritmo Ford-Johnson:**
1. **Pairing:** Agrupa elementos en pares, mayor → main chain, menor → pending
2. **Recursión:** Ordena main chain recursivamente
3. **Inserción:** Inserta pending en main chain usando orden de Jacobsthal

**Orden de Jacobsthal:**
Para 3 elementos pending, orden = [1, 3, 2]
- Inserta pending[0]
- Inserta pending[2]
- Inserta pending[1]
Esto minimiza búsquedas binarias porque insertas primero los cercanos, luego rellenas huecos.

**Rendimiento comparativo (3000 elementos):**
- Vector: ~1.041 ms ✅ (cache friendly)
- Deque: ~1.655 ms (1.6x más lento)
- List: ~10+ segundos (❌ búsqueda O(n))

**Output esperado:**
```
./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector<int> : 0.00031 us
Time to process a range of 5 elements with std::deque<int> : 0.00042 us
```

Para análisis detallado de Vector vs Deque, ver: [readme-ex02.md](readme-ex02.md)

---

## Restricción de contenedores: Cómo funciona

**Módulo 09 obliga a usar 4 contenedores distintos:**

```
ex00: std::map           ✅
ex01: std::stack + std::set  ✅
ex02: std::vector + std::deque  ✅
```

**Total: 5 contenedores usados (map, stack, set, vector, deque)**

Si intentas reutilizar (ej: usar stack en ex02), obtienes **-42** en calificación.

---

## Errores comunes evitados

### ❌ ex00
- Usar `std::vector` con búsqueda lineal en lugar de `std::map`
- No manejar fechas inválidas (Feb 30, etc)
- Usar `upper_bound` en lugar de `lower_bound` (encuentra la fecha correcta)

### ❌ ex01
- No limpiar stack entre ejecuciones (state pollution)
- Pasar strings por valor en lugar de const reference
- Usar punteros en lugar de referencias para parámetros de salida

### ❌ ex02
- Usar `std::list` (100-200x más lento)
- No cachear números de Jacobsthal (recalcula cada vez)
- Confundir `lower_bound` con búsqueda binaria en deque (implícito)

---

## Compilación y testing

**Build y test ex00:**
```bash
cd ex00
make
./btc
./btc input.txt
./btc tests/input
```

**Build y test ex01:**
```bash
cd ex01
make
./RPN "1 2 +"
./RPN "8 9 * 9 - 9 - 9 - 9 - 4 - 1 +"
./RPN "(1 + 1)"  # Error esperado
```

**Build y test ex02:**
```bash
cd ex02
make
./PmergeMe 3 5 9 7 4
./PmergeMe 1000 500 250 125 62 31 15 7
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`  # 3000 random
```

---

## Referencia rápida: Cuando usar cada contenedor

| Necesidad | Contenedor | Razón |
|-----------|-----------|-------|
| Buscar por clave O(log n) | `map` | Árbol rojo-negro ordenado |
| Stack/LIFO operations | `stack` | Interfaz simple, O(1) |
| Validar pertenencia O(log n) | `set` | Búsqueda rápida, únicos |
| Acceso random + insert rápido en medio | `vector` | Cache friendly + lower_bound |
| Insert/erase en ambos extremos | `deque` | Bloques, O(1) ambos lados |
| Insert/erase O(1) frecuente en medio | `list` | ❌ NUNCA si necesitas búsqueda binaria |

---

## Conclusión

Módulo 09 enseña que:
1. **Conocer múltiples contenedores es crítico** (cada uno tiene un nicho)
2. **La teoría ≠ práctica** (Vector beat Deque por cache, no por complejidad)
3. **Ford-Johnson es fascinante** (optimización matemática en sorting)
4. **Las restricciones fuerzan aprendizaje** (no puedes usar siempre el mismo contenedor)

✅ **Status:** Todo implementado, testado, y listo para evaluación.

---

## 📋 Preparación para la presentación

### Conceptos clave a explicar

#### 1. Maps ordenados y búsqueda binaria

**`std::map` es un árbol rojo-negro ordenado:**

```cpp
std::map<std::string, double> prices;
prices["2011-01-03"] = 0.3;
prices["2011-01-09"] = 0.32;
prices["2012-01-11"] = 7.1;
```

Las claves se mantienen **automáticamente ordenadas** (lexicográficamente para strings).

**Ventaja:** `lower_bound()` puede hacer **búsqueda binaria** directamente:

```cpp
auto it = prices.lower_bound("2011-01-05");
// it apunta a "2011-01-09" (primera >= "2011-01-05")

if (it->first != "2011-01-05")
    --it;  // Retrocede a "2011-01-03" (la más cercana inferior)
```

**Complejidad:** O(log n) en lugar de O(n)

---

#### 2. Lower_bound en detalle

`lower_bound(key)` retorna iterador al **primer elemento cuya clave es >= que el parámetro**.

**Ejemplo con dates:**
```
Dates en DB: ["2011-01-01", "2011-01-03", "2011-01-09"]

lower_bound("2011-01-05"):
  Busca: ¿Primer date >= "2011-01-05"?
  Respuesta: "2011-01-09" ✅
  
  ¿Es exacta? No ("2011-01-09" != "2011-01-05")
  ¿Hay anterior? Sí
  → Retrocede a "2011-01-03" ✅ (la más cercana inferior)
```

**Por qué C++ permite esto:**
- Maps están ordenados por clave
- Lower_bound aprovecha esta propiedad con búsqueda binaria
- O(log n) garantizado

---

#### 3. Por qué Maps vs Vectors en ex00

| Aspecto | Map | Vector |
|--------|-----|--------|
| **Inserción ordenada** | Automática (árbol) | Manual (mantener sorted) |
| **Búsqueda binaria** | `lower_bound()` directo | Requiere conversión a índices |
| **Uso de memoria** | Árbol + punteros | Contigua |
| **Complejidad búsqueda** | O(log n) | O(log n) pero más constantes |
| **Caché locality** | ❌ Peor (árbol disperso) | ✅ Mejor (contigua) |

**Respuesta para el evaluador:**
> "I chose `std::map` because dates need to be sorted automatically, and `lower_bound()` gives O(log n) direct binary search on the keys without manual indexing. The trade-off (less cache-friendly than vector) is acceptable for code clarity."

---

#### 4. Diferencia práctica: Map vs Vector+lower_bound

Ambos tienen O(log n), pero:

**Map:**
```cpp
std::map<std::string, double> prices;
auto it = prices.lower_bound("2011-01-05");  // O(log n)
if (it->first != "2011-01-05") --it;
double price = it->second;
```

**Vector (si quisieras):**
```cpp
std::vector<std::pair<std::string, double>> prices;
std::sort(prices.begin(), prices.end());  // Pre-sort O(n log n)
auto it = std::lower_bound(prices.begin(), prices.end(), 
                            std::make_pair("2011-01-05", 0.0),
                            compare_by_first);  // O(log n)
```

**Map es más limpio porque:**
- Mantiene datos ordenados automáticamente
- No necesitas comparadores custom
- Intención clara: "este es un diccionario ordenado"

---

### Preguntas frecuentes del evaluador

**P: "Why did you use map and not vector for ex00?"**

A: "Because dates must be sorted automatically by the container, and `std::map` provides O(log n) `lower_bound()` search on keys without manual sorting. For 2000+ dates, this is cleaner and correct."

**P: "What is lower_bound and why does it work for finding the closest lower date?"**

A: "`lower_bound(date)` returns an iterator to the first element >= date. Since map is sorted, if the returned element != date, I decrement the iterator to get the closest lower date. This guarantees O(log n) complexity."

**P: "Why is Vector faster than Deque in ex02?"**

A: "Cache locality. Vector stores data contiguously in RAM, so the CPU prefetches nearby memory into cache hits. Deque fragments data into blocks, causing cache misses. With 3000 elements and many `lower_bound()` calls, Vector is ~1.6x faster."

**P: "Can you explain the Ford-Johnson algorithm?"**

A: "It pairs elements → larger goes to main chain, smaller to pending. Recursively sort main chain. Insert pending elements using Jacobsthal sequence order to minimize comparisons in binary search. It's theoretically optimal for number of comparisons."

**P: "Why two containers in ex02?"**

A: "To compare performance. Vector (cache-friendly) vs Deque (alternative sequential container). Both use O(log n) binary search, but real-world performance differs due to memory architecture."

---

### Testing script para la presentación

```bash
# ex00: Probar con archivo real
cd ex00
make clean && make
./btc tests/input

# ex01: Probar casos del spec
cd ../ex01
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  # Should output: 42
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"  # Should output: 15

# ex02: Probar rendimiento
cd ../ex02
./PmergeMe 3 5 9 7 4  # Small test
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`  # Large test: compare times
```

---

### Respuestas pre-preparadas

**Evaluador:** "Explain why you chose std::map for ex00"

**Tu respuesta:**
> "I chose `std::map<std::string, double>` because:
> 1. Dates are naturally ordered lexicographically
> 2. Map maintains this ordering automatically (red-black tree)
> 3. `lower_bound()` leverages this ordering for O(log n) binary search
> 4. For finding the closest lower date, I use: if the returned date != target, decrement the iterator
> 5. This is cleaner than manually maintaining a sorted vector"

**Evaluador:** "Why is Vector faster than Deque in ex02?"

**Tu respuesta:**
> "Both have O(log n) theoretical complexity, but Vector is 1.6x faster (~1.04ms vs 1.65ms for 3000 elements):
> - Vector: Contiguous memory → CPU cache prefetch → cache hits
> - Deque: Fragmented blocks → jumps between blocks → cache misses
> - When you do 1000+ `lower_bound()` calls, these miss costs accumulate
> - This shows that asymptotic complexity ≠ real performance"

---

✅ **Status:** Completamente preparado para la presentación.
