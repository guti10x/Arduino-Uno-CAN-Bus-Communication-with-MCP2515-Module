#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 10;  // Pin CS del MCP2515
MCP_CAN can(spiCSPin);

void setup() {
  Serial.begin(9600);
  
  if(can.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) {
    Serial.println("MCP2515 Iniciado correctamente.");
    can.setMode(MCP_NORMAL);
  } else {
    Serial.println("Error al iniciar MCP2515. Compruebe su conexión y configuración.");
  }
}

void loop() {
  // Verificar si hay mensajes recibidos
  if(can.checkReceive() == CAN_MSGAVAIL) {
    // Leer el mensaje recibido
    unsigned char len;
    unsigned char buf[8];
    unsigned long canId;
    
    can.readMsgBuf(&len, buf);
    canId = can.getCanId();
    
    Serial.print("Mensaje recibido desde ID: ");
    Serial.println(canId, HEX);
    Serial.print("Contenido: ");
    
    for(int i = 0; i < len; i++) {
      Serial.print((char)buf[i]);
    }
    
    Serial.println();
  }
}
