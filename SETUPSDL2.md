# ============================================================
# SDL2 INSTALLATION QUICK GUIDE
# ============================================================

## --- LINUX (Debian/Ubuntu/WSL) ---

Run this command in your terminal:

```bash
sudo apt-get update && sudo apt-get install libsdl2-dev
```

---

## --- WINDOWS (MinGW) ---

1. Go to: https://github.com/libsdl-org/SDL/releases  
2. Download: "SDL2-devel-2.x.x-mingw.tar.gz" (or .zip).  
3. Extract it (e.g., to C:\SDL2).  
4. Copy "SDL2.dll" from C:\SDL2\x86_64-w64-mingw32\bin to your project folder.  
5. (Optional) Add the 'bin' folder to your System Environment PATH.

---

## --- WINDOWS (Visual Studio) ---

1. Download: "SDL2-devel-2.x.x-VC.zip".  
2. Extract it (e.g., to C:\SDL2).  
3. In VS Project Properties:
   - VC++ Directories -> Include: Add C:\SDL2\include
   - VC++ Directories -> Lib: Add C:\SDL2\lib\x64
   - Linker -> Input -> Additional Dependencies: Add SDL2.lib; SDL2main.lib;
4. Copy "SDL2.dll" next to your main.cpp.

# ============================================================
