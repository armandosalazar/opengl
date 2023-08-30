`cd build && cmake .. && make && ./build && cd ..`

## GLFW
* GLFW es una biblioteca de código abierto que permite crear y administrar ventanas con OpenGL.

## Instalación
* Para instalar GLFW en Linux, abra una terminal y ejecute el siguiente comando:
```
sudo apt-get install libglfw3
```
* Para instalar GLFW en Windows, descargue el binario de la página de descargas de GLFW y descomprímalo en un directorio de su elección.
* Para instalar GLFW en Mac OS X, descargue el binario de la página de descargas de GLFW y descomprímalo en un directorio de su elección o use Homebrew y ejecute el siguiente comando:
```
brew install glfw3
```

## Compilación
* Para compilar el programa, abra una terminal y ejecute el siguiente comando:
```
g++ -o main main.cpp -lGL -lglfw -lGLEW
```
* Para ejecutar el programa, ejecute el siguiente comando:
```
./main
```
