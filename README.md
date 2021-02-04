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
- [ ] Pseudocódigo Ejercicio Propuesto
- [X] Implementación ejercicios de Clase (7 y 8)
- [ ] Implementación ejercicio Propuesto
- [ ] Manual de instalación/explicación
- [ ] Video demostrativo
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
- Descargar en : https://processing.org/download/
### Eltima Virtual PORT
![ELTIMA img](https://www.eltima.com/imgnew/products/product-info/i-win/winLargeVspdIcon@2x.png)
- Esta herramienta permite crear y enlazar puertos virtuales.
- Esta herramienta es excelente para probar los puertos seriales y así no tener la necesidad de utilizar un microcontrolador, aunque  en este caso nosotro si utilizamos uno.
- Descargar en :  https://www.eltima.com/vspd-post-download.html

## Manual de Usuario
- Conectar el microcontrolador programado a uno de los puertos USB de la computadora.
- Modificar la línea 19 del codigo de processing a:    myPort = new Serial(this, puerto conectado al micro , 115200, 'N', 8, 1);   donde puerto conectado al micro se tiene que reemplazar por "puerto conectado al micro".

