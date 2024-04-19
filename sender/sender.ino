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
  // Crear el mensaje a enviar
  unsigned char msgData[] = {'D', 'A', 'N', 'I', ' ', 'F', 'E', 'O', 'O', 'O', 'O'};
  unsigned char len = sizeof(msgData) / sizeof(msgData[0]);
  
  // Enviar el mensaje
  can.sendMsgBuf(0x123, 0, len, msgData);
  
  // Mostrar el mensaje que se está enviando
  Serial.print("Enviando mensaje: ");
  for(int i = 0; i < len; i++) {
    Serial.print((char)msgData[i]);
  }
  Serial.println();
  
  delay(1000);  // Esperar un segundo antes de enviar el próximo mensaje
}
