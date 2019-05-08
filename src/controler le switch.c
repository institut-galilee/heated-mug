int Relay = 2 ;            //le pin sur le quel brancher le switch


void setup() {
	Serial.begin (115200);
	pinMode(relay, OUTPUT);         //dériger le signal de sortie du pin
}


void loop () {
	digitalWrite ( Relay, HIGH);
	delay (5000);                          //temps moyen pour laisser la tasse chauffé
	digitalWrite (Relay, LOW);
	delay (NULL);
}