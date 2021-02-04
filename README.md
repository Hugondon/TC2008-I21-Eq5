# Proyecto Final SO: Uso de threads y locks 
## Integrantes del Equipo 5
| Nombre | Matrícula | Cuenta |
| ----------- | ----------- | ----------- |
| David Gaona  | A01369337  |[Speedsterbear](https://github.com/Speedsterbear)  |
| Jesús Morales| A01704366 | [Chucho23ale](https://github.com/Chucho23ale) |
| Job Hernández | A00571627 | [Jnhm](https://github.com/Jnhm) |
| Nicolas Becerra |A01704683  |[NicolasBecerraMachado](https://github.com/NicolasBecerraMachado)  |
| Hugo Pérez | A01337226 | [hugondon](https://github.com/Hugondon)  |
---
## Tareas
- [X] Pseudocódigo Ejercicios de Clase (7 y 8)
- [X] Pseudocódigo Ejercicio Propuesto
- [X] Implementación ejercicios de Clase (7 y 8)
- [X] Implementación ejercicio Propuesto
- [X] Manual de instalación/explicación
- [X] Video demostrativo
---
## Herramientas utilizadas
Instalar las siguientes herramientas a la discreción y neesidad del usuario.
### STM32CubeIDE
![stm32-cube-ide](https://user-images.githubusercontent.com/47252665/106367007-3465b880-6305-11eb-98c7-40b263969311.jpg)
- Utilizado como herramienta para la programación del microcontrolador de la familia STM32.
- Su documentación se puede encontrar [aquí.](https://www.st.com/en/development-tools/stm32cubeide.html#documentation)
### FreeRTOS
![freertos](https://user-images.githubusercontent.com/47252665/106366566-590c6100-6302-11eb-9a2c-a628cdd36abd.jpg)
- Sus recursos permiten llevar el concepto de múltiples threads y semáforos al mundo de los microcontroladores.
- Su documentación se puede encontrar [aquí.](https://www.freertos.org/Documentation/RTOS_book.html)
### Bluepill
![bluepill](https://user-images.githubusercontent.com/47252665/106808503-1616fa00-6630-11eb-9476-e1eb82aeda74.png)
- Tarjeta de desarrollo basada en el microcontrolador STM32F103C8T6. Se utilizará como plataforma para echar a andar un sistema con múltiples threads.
- La datasheet del microcontrolador se puede encontrar [aquí.](https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html#documentation)
- El esquemático de la tarjeta se puede encontrar [aquí.](https://github.com/dhylands/stm32-test/blob/master/board-STM32F103-Mini/STM32F103C8T6-Schematic.pdf)
### Processing
![processing_img](https://user-images.githubusercontent.com/47252665/106808357-e7991f00-662f-11eb-8038-75ab7a09e618.png)
- IDE basada en java que permite crear diferentes aplicaciones gráficas.
- De igual manera permite interactuar con puertos seriales, por lo cuál es perfecta para crear interfaces para microcontroladores.
- Descargar [aquí](https://processing.org/download/)
### Eltima Virtual PORT
![ELTIMA img](https://www.eltima.com/imgnew/products/product-info/i-win/winLargeVspdIcon@2x.png)
- Esta herramienta permite crear y enlazar puertos virtuales.
- Esta herramienta es excelente para probar los puertos seriales y así no tener la necesidad de utilizar un microcontrolador, aunque  en este caso nosotro si utilizamos uno.
- Descargar [aquí](https://www.eltima.com/vspd-post-download.html)

## Manual de Usuario
1. Descargar los diferentes softwares mencionados en Herramientas Utilizadas.
2. Realizar las conexiones de hardware como se muestran en el esquemático (Doc/sch_Proyecto.pdf).
3. Abrir el proyecto Proyecto_SO en el STM32CubeIDE y cargar el programa en la placa de desarrollo.
4. Conectar la placa con el microcontrolador programado a uno de los puertos USB de la computadora.
5. Verificar en cuál puertos se encuentra conectado el dispositivo (con ayuda del Administrador de Dispositivos)
6. Modificar la línea 19 (línea 10 en el código de test) del codigo de processing a:    
  `myPort = new Serial(this, puerto conectado al micro , 115200, 'N', 8, 1);`  
   ,donde puerto conectado al micro se tiene que reemplazar por algo con la nomenclatura COMx.
7. Correr el programa "interfaz" de Processing.
8. Utilizar los push buttons conectados a la placa para alternar entre problemas.

## Threads y Semáforos en FreeRTOS
- Creación de un thread (proceso).

  `osThreadDef(Task, TaskHandler, osPriorityNormal, 0, 128);`
  
  `TaskHandle = osThreadCreate(osThread(Task), NULL);`
  
En donde `Task` es la tarea relacionada al proceso, `TaskHandler` es la función Handler asociada a la tarea, `osPriorityNormal` es la prioridad asignada a la tarea (se puede elegir entre 7 opciones), el `128` es el espacio de RAM destinado a la tarea y `TaskHandle` es un apuntador a la primera posición de memoria del Handler.
  
- Creación de un semáforo

  `osSemaphoreDef(binarySem);`
  
  `binarySemHandle = osSemaphoreCreate(osSemaphore(binarySem), 1);`
  
En donde `binarySem` es la variable que funge como abstracción del Semáforo, y el `1` es el valor inicial para el semáforo (cabe destacar que no pueden inicializarse en 0).
  
- Equivalente a operación p()

  `osSemaphoreWait(binarySemHandle, osWaitForever);`
  
En donde `osWaitForever` es un Timeout a la operación v() para evitar deadlocks.
  
- Equivalente a operación v()

  `osSemaphoreRelease(binarySemHandle);`

---
## Problema propuesto
- Este problema esta inspirado en las mecanicas del famoso juego multijugador LoL(League of Legends), donde la sincronización de los jugadores es clave para conseguir la victoria.

Para derrotar al dragón de la Grieta del Invocador en el famosísimo League of Legends, es necesario que el jugador en jungla esté disponible para asegurarlo.
Tendrá que llamar a bot (a través de un ping de ayuda) para así ayudar a completar el objetivo.
De igual forma, para asegurar este objetivo es necesario que el área cerca del dragón esté despejada y esta solamente se encuentra en ese estado al estar jungla y bot ahí por 2 minutos.

Una vez que jungla y bot estén disponibles y hayan despejado el área, el dragón podrá ser asegurado.

Después de asegurarlo, ambos personajes dejarán de estar disponibles. 
El dragón volverá a estar en la Grieta del Invocador después de los reglamentarios 6 minutos de haber sido derrotado.

---
## Video Demostrativo

[Link al video](https://drive.google.com/drive/folders/1qpY7V7M-YAX1ldKsQ7_L6k8iIiCXulyH?usp=sharing)
[Link al video de YouTube](https://youtu.be/Hr0SjX6N1tY)
