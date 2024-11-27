//**Array**//
int LED[4] = { A1, A2, A3, A4 };
const int botao[4] = { 2, 3, 4, 5 };
int armazena_Sequencia[9] = {};

//**Portas do display de 7 segmentos**//
const int a = 6;
const int b = 7;
const int c = 8;
const int d = 9;
const int e = 10;
const int f = 11;
const int g = 12;

//**Variáveis**//
int numero_aleatorio;
int nivel;
int botao_Apertado;
int comparaSequencia = 0;
bool status_de_partida = true;

//**Funções**//
void sequencia(int nivel);
void mostrarSequencia();
void inicializa();
bool confereJogada();
void mostrarNivel(int nivel);


void setup() {

  randomSeed(analogRead(0));

  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);

  pinMode(botao[0], INPUT_PULLUP);
  pinMode(botao[1], INPUT_PULLUP);
  pinMode(botao[2], INPUT_PULLUP);
  pinMode(botao[3], INPUT_PULLUP);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  Serial.begin(9600);

  inicializa();
  nivel = 0;
}

void loop() {

  sequencia(nivel);
  mostrarSequencia();
  
  if (confereJogada()) {
    
    nivel++;
    
    if (nivel == 9) {
      
      nivel = 0;
    } else {
      
      mostrarNivel(nivel);
    }
  } else {
     int i;
    while(i < 4){
      
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], HIGH);
      delay(500);
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
      i++;
    } 

    nivel = 0; 
    comparaSequencia = 0;
    status_de_partida = true; 
    mostrarNivel(nivel);

  }
}

/* Incializa a sequência inicial */

void inicializa() {

  int i = 0;

  while (i < 4) {

    digitalWrite(LED[i], HIGH);
    delay(500);
    digitalWrite(LED[i], LOW);
    delay(500);
    i++;
  }

  delay(500);
}

/* Incializa uma sequência aleatória */

void sequencia(int nivel) {
 
  for (int i = 0; i < nivel; i++) {

    int sequencia = random(4);
    armazena_Sequencia[i] = sequencia;
   
   
  }
}

/Mostra a sequência aleatória/

void mostrarSequencia() {

  for (int i = 0; i < nivel; i++) {

    digitalWrite(LED[armazena_Sequencia[i]], HIGH);
    delay(500);
    digitalWrite(LED[armazena_Sequencia[i]], LOW);
    delay(500);
  }
  delay(500);
}

/Confere se o jogador realizou a jogada e se a mesma condiz com o led que foi acesso/

bool confereJogada() {

  for (int i = 0; i < nivel; i++) {

    bool jogou = false;

    while (!jogou) {

      for (int i = 0; i < 4; i++) {

        if (digitalRead(botao[i]) == HIGH) {

          botao_Apertado = i;
          digitalWrite(LED[i], HIGH);
          delay(500);
          digitalWrite(LED[i], LOW);
          delay(500);
          jogou = true;
        }
      }
    }

    if (armazena_Sequencia[comparaSequencia] != botao_Apertado) {

      status_de_partida = false;
      break;
    }
    comparaSequencia++;
  }
  comparaSequencia = 0;
  /Retorna a situação da partida, se o jogador acertou ou não a sequência/
  return status_de_partida;
}



/Função que mostra o display de 7 segmentos/
/Funcionalidade: Mostrar o nível que está o jogo/

void mostrarNivel(int nivel) {

  if (nivel == 0) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    //digitalWrite(g, HIGH);
    delay(2000);
  }

  if (nivel == 1) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    delay(2000);
  }
  if (nivel == 2) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    delay(2000);
  }

  if (nivel == 3) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    delay(2000);
  }

  if (nivel == 4) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(2000);
  }

  if (nivel == 5) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(2000);
  }

  if (nivel == 6) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(2000);
  }

  if (nivel == 7) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    delay(2000);
  }

  if (nivel == 8) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(2000);
  }

  if (nivel == 9) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    delay(2000);
  }
}