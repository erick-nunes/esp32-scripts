 #include <WiFi.h>
 #include <DHT.h>

 #define DHTPIN 15
 #define DHTTYPE DHT11

 DHT dht(DHTPIN, DHTTYPE);

 float umi = 0;
 float temp = 0;

// CONEXÃO WIFI
  const char* ssid = "nome da rede";
  const char* password = "senha";
  
  void setup() {
  Serial.begin(115200);
  dht.begin();

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

  // Conexão com Wifi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi desconectou. Reconectanto Novamente ...");
    digitalWrite (LED_BUILTIN, LOW); // led desligado

    conecta_wifi();
  } 

  // Temperatura e Humidade
  umi = dht.readHumidity();
  temp = dht.readTemperature();
  
   if (isnan(umi) || isnan(temp)) {
    Serial.println("Falha de leitura");
  } else {
    Serial.print("Umidade: ");
    Serial.print(umi);
    Serial.print("%  Temperatura: ");
    Serial.print(temp);
    Serial.println("°C, ");
  }
  delay(20000);

}


