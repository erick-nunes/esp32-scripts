 #include <WiFi.h>

  const char* ssid = "Nome da rede";
  const char* password = "Senha";
  
  void setup() {
  Serial.begin(115200);

  WiFi.setHostname("DrinkCoin");

  pinMode(LED_BUILTIN, OUTPUT); // Led azul da placa
  
  conecta_wifi();

  delay(10);

}

void conecta_wifi() {
    
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
    digitalWrite (LED_BUILTIN, LOW); // led desligado
  }
  Serial.println("");
  Serial.println("Conectado ao Wi-Fi!");
  digitalWrite (LED_BUILTIN, HIGH); // liga led da placa
  Serial.println("");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    
    Serial.println("Wifi desconectou. Reconectanto Novamente ...");
    digitalWrite (LED_BUILTIN, LOW); // led desligado

    conecta_wifi();

  } 
}


