# OS Programming Assignment 01: Report

## Part 2: Multi-file Build

### Q1. Explain `$(TARGET): $(OBJECTS)`

The executable depends on all object files. If an object file is newer than the executable, Make recompiles or relinks the program. The command links all object files directly.

With a library, the executable depends on `main.o` and the library. `-L` specifies the library directory and `-l` specifies the library name.

### Q2. What is a Git tag?

A Git tag is a fixed name pointing to a specific commit, commonly used to mark versions or releases.

A lightweight tag only points to a commit. An annotated tag also stores the tagger, date and message.

### Q3. Purpose of GitHub Release

A GitHub Release packages a tagged version with release notes. Binaries can be attached so users can download and run the exact build without compiling it.

## Part 3: Static Library

### Q1. Difference from multi-file build

The static build creates `libmyutils.a` from the library object files. `main.o` remains separate and is linked against the library using `-L` and `-l`.

### Q2. Purpose of `ar` and `ranlib`

`ar` creates the static library archive and stores object files inside it. `ranlib` creates the symbol index used by the linker.

### Q3. Are the functions present in `client_static`?

Yes. `nm` shows functions such as `mystrlen` with type `T`. This means their code is present in the executable because static linking copies the required library code into it.

## Part 4: Dynamic Library

### Q1. What is PIC?

Position-Independent Code is code that can execute correctly regardless of its memory load address. Shared libraries use PIC so they can be loaded at different addresses and their code can be shared.

### Q2. Why are static and dynamic clients different in size?

`client_static` contains the static library code and statically linked C library code, so it is much larger.

`client_dynamic` contains references to shared libraries, which are loaded at runtime, so it is much smaller.

### Q3. What is `LD_LIBRARY_PATH`?

`LD_LIBRARY_PATH` tells the dynamic loader which directories to search for shared libraries. It was necessary because `libmyutils.so` is stored in the project's `lib/` directory rather than a standard system library directory.

## Command Outputs

The project successfully produced:

- `bin/client`
- `bin/client_static`
- `bin/client_dynamic`
- `lib/libmyutils.a`
- `lib/libmyutils.so`

The following functions were verified:

- `mystrlen`
- `mystrcpy`
- `mystrncpy`
- `mystrcat`
- `wordCount`
- `mygrep`

Dynamic linking was verified using `ldd`, `nm -D`, and `readelf -d`.

