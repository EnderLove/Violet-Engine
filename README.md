# Violet Engine

A 2D/3D Graphics Engine written in C++.

## Cloning the Repository
This project uses Git submodules for external libraries, so you must clone the repository recursively to pull down the dependencies.

Run this command in your terminal:

```bash
git clone --recursive https://github.com/YourUsername/VioletEngine.git
```

If you already cloned the project normally and are missing the dependencies, run:

```bash
git submodule update --init --recursive
```
---
## Windows Setup
Prerequisites: * Visual Studio 2022 (with "Desktop development with C++" workload installed).

### Build Instructions:

- Open the project folder.

- Double-click the GenerateProjects.bat file (or whatever your .bat is named). This will use Premake to generate the Visual Studio solution files.

- Open Violet.sln in Visual Studio.

- In the Solution Explorer, right-click the Sandbox project and select Set as Startup Project.

- Press F5 or hit the Local Windows Debugger button at the top to compile and run.

---
### Linux Setup
Prerequisites: * make, gcc/clang, and standard build essentials installed on your system.

You may also need the Premake5 binary installed globally depending on your setup.

### Build Instructions:

- Open your terminal in the project root.

- The first time you pull the project, you need to grant execution permissions to the generation script:

```bash
chmod +x generate.sh
```
Run the script to generate the Linux Makefiles:
```bash
./generate.sh
```
Compile the engine and client application:
```bash
make
```
Run the app:
```bash
./bin/Debug-linux-x64/Sandbox/Sandbox
```
