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
