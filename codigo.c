#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8
#define SUBE 4
#define BAJA 3
#define RESET 5
#define UNIDAD A4
#define DECENA A5
#define APAGADOS 0
#define TIMEDISPLAYON 10


int countDigit=0;
int sube=1;
int subePrevia=1;
int baja=1;
int bajaPrevia=1;
int reset=1;
int resetPrevia=1;
void setup()
{
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  digitalWrite(UNIDAD,0);
  digitalWrite(DECENA,0);
  printDigit(0);
  
}

void loop()
{
  	int pressed = keypressed();
	if(pressed==SUBE)
    {
      countDigit++;
      if(countDigit>99)
        countDigit=0;
    }
  	else if(pressed==BAJA)
    {
      countDigit--;
      if(countDigit<0)
      countDigit=99;

    }
   	else if(pressed==RESET)
    {
     countDigit=0;
    }
	
  	printCount(countDigit);
 
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
	printDigit(count/10);
  	prendeDigito(DECENA);
    prendeDigito(APAGADOS);
 	printDigit(count - 10*((int)count/10));
  	prendeDigito(UNIDAD); 
}

int keypressed(void)
{ 
	
  	sube = digitalRead(SUBE); // devuelve 0 si presiono, 1 si no presiono
  	baja = digitalRead(BAJA);
	reset = digitalRead(RESET);
  	if (sube== 1)     // si no presione SUBE
      subePrevia =1; //entonces antes tampoco estaba presionada
    if (baja)
      bajaPrevia =1;
  	if(reset)
      resetPrevia =1;
  
    	
  		if(sube==0 && sube != subePrevia)
        {
          subePrevia = sube;
  		  return SUBE;
        }
  
    	if(baja==0 && baja != bajaPrevia)
        {
          bajaPrevia = baja;
  		  return BAJA;
        }
  
      	if(reset==0 && reset != resetPrevia)
        {
          resetPrevia = reset;
  		  return RESET;
        }
 return 0; //o no presione ninguna tecla, o presione una que estaba presionada
 
}
  
      