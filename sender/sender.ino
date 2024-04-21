#include <SPI.h>          // Incluye la librería SPI para la comunicación SPI
#include <mcp_can.h>      // Incluye la librería para controlar el MCP2515

const int spiCSPin = 10;  // Pin CS del MCP2515 (Chip Select)
MCP_CAN can(spiCSPin);    // Instancia un objeto MCP_CAN con el pin CS especificado
// No hace falta que asociemos los otros pines del MCP porque están en los pines predeterminados del Arduino, si decidieramos
// cambiarlos a otros pines del Arduino, sí que tendríamos que asociarlos manualmente.

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
  // Crear el mensaje a enviar
  unsigned char msgData[] = {'H', 'E', 'L', 'L', 'O', '', 'W', 'O', 'R', 'L', 'D'};
  unsigned char len = sizeof(msgData) / sizeof(msgData[0]);  // Calcula la longitud del mensaje
  
  // Enviar el mensaje a través del bus CAN
  can.sendMsgBuf(0x123, 0, len, msgData);
  
  // Mostrar el mensaje que se está enviando por la comunicación serial
  Serial.print("Enviando mensaje: ");
  for(int i = 0; i < len; i++) {
    Serial.print((char)msgData[i]);  // Imprime cada carácter del mensaje
  }
  Serial.println();  // Imprime una nueva línea al final para mejorar la legibilidad
  
  delay(1000);  // Esperar un segundo antes de enviar el próximo mensaje
}

