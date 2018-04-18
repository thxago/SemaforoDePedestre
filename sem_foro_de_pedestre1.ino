void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop()
{
  int estadoDoDelay = 0;
  int estadoDoBotao = digitalRead(10);
  
  //Liga o semáforo verde do carro
  digitalWrite(11, HIGH);
  
  //Liga o semáforo vermelho do pedestre
  digitalWrite(8, HIGH);
  
  //Aguarda 3000 milisegundos como tempo minimo para
  //os carros passarem
  while(estadoDoDelay < 30000){
    if(estadoDoBotao == LOW){
    	estadoDoBotao = digitalRead(10);
    }
    estadoDoDelay += 1;
  }
  
  //Verifica se o botao ja foi precionado
  //caso sim, nao entra na condicao
  //caso nao, espera o botao ser precionado
  while(estadoDoBotao == LOW){
  	estadoDoBotao = digitalRead(10);
  }
  
  //Momento de deixar os pedestres passarem
  while(estadoDoBotao == HIGH){
	estadoDoBotao = LOW;
      
    //Desliga o semáforo verde do carro
    digitalWrite(11, LOW);

    //Liga o semáforo amarelo do carro
    digitalWrite(12, HIGH);

    //Aguarda 2000 milisegundos
    delay(2000);

    //Desliga o semáforo amarelo do carro
    digitalWrite(12, LOW);
    
    //Liga o semáforo vermelho do carro
    digitalWrite(13, HIGH);
    
    //Aguarda 1000 milisegundos
    delay(1000);
    
    //Desliga o semáforo vermelho do pedestre
    digitalWrite(8, LOW);

    //Liga o semáforo verde do pedestre
    digitalWrite(9, HIGH);

    //Aguarda 3000 milisegundos
    delay(3000);

    //Desliga o semáforo verde do pedestre
    digitalWrite(9, LOW);

    //Pisca o semáforo vermelho do pedestre 3 vezes
    //a cada 1000 milissegundos
    int pisca = 0;
    while(pisca < 3){
      //Em cada 1000 milissegundo é verificado se o botao
      //ja foi pressionado
      if(estadoDoBotao == LOW){
        estadoDoBotao = digitalRead(10);
      }
      digitalWrite(8, HIGH);
      delay(1000);
      if(estadoDoBotao == LOW){
        estadoDoBotao = digitalRead(10);
      }
      digitalWrite(8, LOW);
      delay(1000);
      if(estadoDoBotao == LOW){
        estadoDoBotao = digitalRead(10);
      }
      pisca += 1;
    }

    //Liga o semáforo vermelho do pedestre
    digitalWrite(8, HIGH);

    //Aguarda 1000 milisegundos
    delay(1000);

    //Desliga o semáforo vermelho do carro
    digitalWrite(13, LOW);
    
    //Liga o semáforo verde do carro
  	digitalWrite(11, HIGH);
    
    //se o botao foi pressionado, aguarda o tempo minimo
    // para os carros passarem
    if(estadoDoBotao == HIGH){
      delay(3000);
    }
  }
}