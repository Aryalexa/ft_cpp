El vector es más rápido que deque.
Es por **cache locality** y el costo de las operaciones en cada estructura.

## Vector vs Deque

| Aspecto | Vector | Deque |
|--------|--------|-------|
| **Memoria** | Contigua | Bloques/chunks (fragmentada) |
| `push_back()` | O(1) amortizado | O(1) amortizado |
| `insert()` en medio | O(n) copia contigua | O(n) + overhead de bloques |
| Acceso random | O(1), muy rápido (CPU cache friendly) | O(1), pero saltos entre bloques |
| `lower_bound()` | Búsqueda en memoria contigua | Saltos entre bloques (cache misses) |

---

## En tu Ford-Johnson Algorithm:

Haces muchos:
```cpp
std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), x);
main.insert(pos, x);
```

Con 3000 elementos, esto se repite cientos de veces.

---

## Por qué Vector es más rápido:

### 1. **CPU Cache (L1/L2/L3)**
- **Vector:** Acceso predecible a memoria contigua → cache hits frecuentes
- **Deque:** Salta entre bloques → cache misses frecuentes

### 2. **Insert overhead**
- **Vector:** Copia una vez de forma contigua
- **Deque:** Manipula múltiples bloques, más operaciones

### 3. **Lower_bound efficiency**
- **Vector:** Búsqueda binaria en memoria contigua = muy rápido
- **Deque:** Búsqueda binaria saltando bloques = más lento

---

## Regla de oro:

**Si necesitas acceso random y insert/erase en medio → Vector**  
**Si necesitas insert/erase en ambos extremos → Deque**

En tu caso, solo haces `push_back()` (extremo) y `insert()` en medio (con búsqueda), así que **vector gana claramente**. 

Con 3000 elementos, los cache misses del deque se acumulan y ves una diferencia notable. ✅

---

## Comparación: Vector vs Deque vs List

| Operación | Vector | Deque | List |
|-----------|--------|-------|------|
| `push_back()` | O(1) | O(1) | O(1) |
| Acceso `[i]` | O(1) | O(1) | **O(n)** ❌ |
| `lower_bound()` | O(log n) ✅ | O(log n) | **O(n)** ❌ |
| `insert(pos, x)` | O(n) | O(n) | O(1) |

---

## ¿Por qué NO usar List?

En tu Ford-Johnson Algorithm haces esto ~3000 veces:

```cpp
std::list<int>::iterator pos = std::lower_bound(main.begin(), main.end(), x);
main.insert(pos, x);
```

### Con List:
- `lower_bound()` recorre la lista **desde el inicio cada vez** → O(n)
- Total: O(n) × 3000 inserciones ≈ **O(n²)** = ~9 millones de operaciones
- **Tiempo estimado: 10+ segundos** ❌

### Con Vector:
- `lower_bound()` es búsqueda binaria → O(log n)
- Total: O(log n) × 3000 inserciones ≈ ~30,000 comparaciones
- **Tiempo real: ~1ms** ✅

**List sería 100-200x más lenta** porque no está optimizada para búsqueda binaria.

---

## Conclusión:

Para Ford-Johnson con búsqueda binaria + inserciones:
1. **Vector: Mejor** (cache friendly + búsqueda rápida)
2. **Deque: Alternativa válida** (~1.6x más lento)
3. **List: No viable** (búsqueda lineal = O(n²))