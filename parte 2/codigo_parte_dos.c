#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8
#define SUBE 2
#define UNIDAD A4
#define DECENA A5
#define APAGADOS 0
#define TIMEDISPLAYON 10

int countDigit = 0;
int sube = 1;
int subePrevia = 1;
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  digitalWrite(UNIDAD, 0);
  digitalWrite(DECENA, 0);
  printDigit(0);
  Serial.begin(9600);
}

void loop()
{
  int pressed = keypressed();
  if (pressed == SUBE)
  {
    countDigit++;    
    countDigit++;
    countDigit++;

    if (countDigit > 99)
      countDigit = 0;
  }
  
  if (pressed != SUBE)
  {
    if (esPrimo(countDigit) == true)
    { 
      Serial.println(countDigit);
      Serial.println("Es primo");
      delay(1000);
    }
  }
}

bool esPrimo(int countDigit)
{
  if (countDigit <= 1)
  {
    return false;
  }

  for (int i = 2; i <= countDigit / 2; i++)
  {
    if (countDigit % i == 0)
    {
      return false;
    }
  }

  return true;
}

void printDigit(int digit)
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  switch (digit)
  {
  case 1:
  {
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    break;
  }
  case 2:
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(G, HIGH);
    break;
  }

  case 3:
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(G, HIGH);
    break;
  }
  case 4:
  {
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  }

  case 5:
  {
    digitalWrite(A, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  }
  case 6:
  {
    digitalWrite(A, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  }

  case 7:
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    break;
  }
  case 8:
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  }
  case 9:
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  }

  case 0:
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    break;
  }
  }
}

void prendeDigito(int digito)
{
  if (digito == UNIDAD)
  {
    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, HIGH);
    delay(TIMEDISPLAYON);
  }
  else if (digito == DECENA)
  {
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, LOW);
    delay(TIMEDISPLAYON);
  }
  else
  {
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, HIGH);
  }
}

void printCount(int count)
{
  prendeDigito(APAGADOS);
  printDigit(count / 10);
  prendeDigito(DECENA);
  prendeDigito(APAGADOS);
  printDigit(count - 10 * ((int)count / 10));
  prendeDigito(UNIDAD);
}

int keypressed(void)
{

  sube = digitalRead(SUBE); // devuelve 0 si presiono, 1 si no presiono
  if (sube == 1)            // si no presione SUBE
    subePrevia = 1;         // entonces antes tampoco estaba presionada

  if (sube == 0 && sube != subePrevia)
  {
    subePrevia = sube;
    return SUBE;
  }

  return 0; // o no presione ninguna tecla, o presione una que estaba presionada
}
