const int RedLedPin = 12;
const int GreenLedPin = 13;
const int BlueLedPin = 11;

const int sensorRead = A1;

int RedLedTriggerList[] = {401, 1000};
int GreenLedTriggerList[] = {201, 400};
int BlueLedTriggerList[] = {20, 200};

int MainTriggerList[] = { RedLedTriggerList[0], RedLedTriggerList[1], BlueLedTriggerList[0], BlueLedTriggerList[1], GreenLedTriggerList[0], GreenLedTriggerList[1] };
int PinList[] = { RedLedPin, BlueLedPin, GreenLedPin };

double weight;
double analogValue;

void setup()
{
  Serial.begin(9600);

  analogReadResolution(12);
  
  pinMode(RedLedPin, OUTPUT);
  pinMode(BlueLedPin, OUTPUT);
  pinMode(GreenLedPin, OUTPUT);
}

double Calculate(double number){
  number = (number*-.113) + 156 + (number*number)*.0000823;
  return number;
}

void loop()
{
  analogValue = analogRead(sensorRead);
  weight = Calculate(analogValue);

  Serial.println("Analog Value");
  Serial.println(analogValue);
  Serial.println("Gram Weight");
  Serial.println(weight);
  
  for (int i = 0, f = 0; i < 6; i += 2, f++) {
    if (MainTriggerList[i] <= weight && weight <= MainTriggerList[i + 1]) 
    {
        digitalWrite(PinList[f], HIGH);
    }
    else
    {
        digitalWrite(PinList[f], LOW);
    }
  }
  delay(500);
}
