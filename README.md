# Comunicación CAN Bus entre dos Arduino con dos MCP2515

Este proyecto muestra cómo establecer comunicación a través del bus CAN (Controller Area Network) entre dos placas Arduino utilizando dos módulos MCP2515. El bus CAN es un protocolo de comunicación serial utilizado en aplicaciones industriales y automotrices que requieren una alta confiabilidad y una velocidad de transmisión moderada.

## Esquema de conexiones:
![a61bda7ea69d0927d32fc2bce608ccd74cd039e1_2_1035x471](https://github.com/guti10x/Arduino-Uno-CAN-Bus-Communication-with-MCP2515-Module/assets/82153822/95fdf590-1b63-4889-aad1-077641809985)

##Explicación de las funcionalidades de cada pin

- **VCC (Voltaje de Alimentación):** Este pin proporciona el voltaje de alimentación necesario para el funcionamiento del MCP2515.

- **GND (Tierra):** Este pin es el punto de referencia común de voltaje para el circuito.

- **CS (Chip Select):** Controla el inicio y la finalización de la comunicación SPI. Se activa (bajo) por el microprocesador para iniciar la comunicación.

- **SO (Serial Output):** Envia datos en serie desde el MCP2515 al microprocesador.

- **SI (Serial Input):** Recibe datos en serie del microprocesador al MCP2515.

- **SCK (Serial Clock):** Sincroniza la transferencia de datos entre el microprocesador y el MCP2515 durante la comunicación SPI.

- **INT (Interrupción):** Notifica al microprocesador sobre eventos importantes en el MCP2515, como la recepción de un mensaje CAN o la detección de un error de comunicación.

## Bibliotecas necesarias
Para este proyecto, se utilizan las siguientes bibliotecas:
```cpp
#include <SPI.h>
#include <mcp_can.h>
```
- [`SPI`](https://github.com/PaulStoffregen/SPI): Esta biblioteca permite la comunicación SPI entre Arduino y los módulos MCP2515.
- [`mcp_can`](https://github.com/coryjfowler/MCP_CAN_lib): Esta biblioteca proporciona una interfaz fácil de usar para comunicarse con los módulos MCP2515 a través del protocolo SPI.
