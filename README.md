# Comunicación CAN Bus entre dos Arduino con dos MCP2515

Este proyecto muestra cómo establecer comunicación a través del bus CAN (Controller Area Network) entre dos placas Arduino utilizando dos módulos MCP2515. El bus CAN es un protocolo de comunicación serial utilizado en aplicaciones industriales y automotrices que requieren una alta confiabilidad y una velocidad de transmisión moderada.

## Esquema de conexiones:
![a61bda7ea69d0927d32fc2bce608ccd74cd039e1_2_1035x471](https://github.com/guti10x/Arduino-Uno-CAN-Bus-Communication-with-MCP2515-Module/assets/82153822/95fdf590-1b63-4889-aad1-077641809985)

## Explicación de las funcionalidades de cada pin

- **VCC (Voltaje de Alimentación):** Es el encargado de proporcionar voltaje al MCP2515.

- **GND (Tierra):** Es el punto de referencia para medir los voltajes en relación con otros puntos del circuito.

- **CS (Chip Select):** Establece el inicio y la finalización de la comunicación SPI. Puede estar activo (bajo) o desactivado (alto). Es el microprocesador quien activa el pin CS si quiere enviar o recibir información.

- **SO (Serial Output):** Es el pin encargado de enviar datos en serie al microprocesador.

- **SI (Serial Input):** Es el pin encargado de recibir datos en serie del microprocesador.

- **SCK (Serial Clock):** Es el pin encargado de sincronizar la transferencia de datos entre el micro y el MCP2515. Cuando se inicia la comunicación, el microprocesador genera un tren de pulsos de reloj a través de este pin para sincronizar la transferencia.

- **INT (Interrupción):** Notifica al microprocesador sobre eventos importantes que han ocurrido dentro del MCP2515, como la recepción de un mensaje CAN, la detección de un error de comunicación, etc. El MCP2515 genera una interrupción en el pin INT cuando detecta estos eventos. Esta interrupción interrumpe la ejecución normal del microprocesador para alertarlo sobre la ocurrencia del evento. Posteriormente, el microprocesador puede decidir cómo responder a esta notificación.

## Bibliotecas necesarias
Para este proyecto, se utilizan las siguientes bibliotecas:
```cpp
#include <SPI.h>
#include <mcp_can.h>
```
- [`SPI`](https://github.com/PaulStoffregen/SPI): Esta biblioteca permite la comunicación SPI entre Arduino y los módulos MCP2515.
- [`mcp_can`](https://github.com/coryjfowler/MCP_CAN_lib): Esta biblioteca proporciona una interfaz fácil de usar para comunicarse con los módulos MCP2515 a través del protocolo SPI.
