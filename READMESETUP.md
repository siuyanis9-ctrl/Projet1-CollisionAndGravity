# ============================================================
# COMPILATION GUIDE (LINUX & WINDOWS)
# ============================================================

## 1. PRE-REQUISITE
- All .cpp and .hpp files must be in the same folder.
- SDL2 must be installed on the system.
- For Windows: SDL2.dll must be in the project folder.

---

## 2. LINUX (Terminal)

**Command:**
```bash
g++ *.cpp -lSDL2 -o simulator
```

**Run:**
```bash
./simulator
```

---

## 3. WINDOWS (CMD / PowerShell / MinGW)

**Command:**
```bash
g++ *.cpp -lSDL2main -lSDL2 -o simulator.exe
```

**Run:**
```bash
simulator.exe
```

*Note: If your compiler doesn't find SDL2 automatically, use:*

```bash
g++ *.cpp -I"C:/PATH_TO_SDL2/include" -L"C:/PATH_TO_SDL2/lib" -lSDL2main -lSDL2 -o simulator.exe
```

---

## 4. TROUBLESHOOTING
- Error "Undefined reference": Ensure -lSDL2 flags are at the END of the command.
- Error "SDL.h missing": Check your include paths.
- Error "DLL missing" (Windows): Copy SDL2.dll next to your .exe.

# ============================================================
