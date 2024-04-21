#include <SPI.h>          // Incluye la librería SPI para la comunicación SPI
#include <mcp_can.h>      // Incluye la librería para controlar el MCP2515

const int spiCSPin = 10;  // Pin CS del MCP2515 (Chip Select)
MCP_CAN can(spiCSPin);    // Instancia un objeto MCP_CAN con el pin CS especificado

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios
  
  // Inicia el MCP2515
  if(can.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) {
    Serial.println("MCP2515 Iniciado correctamente.");  // Imprime un mensaje si el MCP2515 se inicia correctamente
    can.setMode(MCP_NORMAL);  // Configura el MCP2515 en modo normal de operación
  } else {
    Serial.println("Error al iniciar MCP2515. Compruebe su conexión y configuración.");
    // Imprime un mensaje de error si hay un problema al iniciar el MCP2515
  }
}

void loop() {
  // Verificar si hay mensajes recibidos
  if(can.checkReceive() == CAN_MSGAVAIL) {
    // Leer el mensaje recibido
    unsigned char len;
    unsigned char buf[8];
    unsigned long canId;
    
    can.readMsgBuf(&len, buf);  // Lee el mensaje del buffer del MCP2515
    canId = can.getCanId();     // Obtiene la ID del mensaje recibido
    
    // Imprime la ID del mensaje recibido en formato hexadecimal
    Serial.print("Mensaje recibido desde ID: ");
    Serial.println(canId, HEX);
    Serial.print("Contenido: ");
    
    // Imprime el contenido del mensaje recibido
    for(int i = 0; i < len; i++) {
      Serial.print((char)buf[i]);  // Convierte y muestra cada byte del mensaje como un carácter
    }
    
    Serial.println();  // Imprime una nueva línea para mejorar la legibilidad
  }
}
