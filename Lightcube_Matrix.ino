/*  Name: Calvin Tran
 *  Date: January 24, 2018
 *  Description: Creates three different patterns on a 4x4x4 LED light cube.
 */

// Create arrays to hold the different posts.
int posts[] = {A3, A2, A1, A0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};             // Anode pins in order they represent as posts
int postOuter[] = {A3, A2, A1, A0, 5, 9, 13, 12 ,11, 10, 6, 2};
int postInner[] = {3,4,7,8};

int pause = 125;

// A function to turn all the inner posts on.
void InnerHigh(){
  for (int i = 0; i <4; i++){
    digitalWrite(postInner[i], HIGH);
  }
}

// A function to turn all the outer posts on.
void OuterHigh(){
  for (int i = 0; i < 12; i++) {
    digitalWrite(postOuter[i], HIGH);
  }
}

// A function to turn all posts on.
void AllHigh(){
  for (int i = 0; i<16; i++){
    digitalWrite(posts[i],HIGH);
  }
}
void setup() {
  // put your setup code here, to run once:
  for (int next = 0; next < 16; next++)                          // sets all I/O used as outputs
  {
    pinMode(posts[next], OUTPUT);
  }
  pinMode(A4, OUTPUT);      //sets cathodes as outputs
  pinMode(A5, OUTPUT);
}

// A function to turn all the posts to off.
void Reset(){
  for (int i = 0; i < 16; i++) {
    digitalWrite(posts[i], LOW);
  }
}

// A function which turns on the correct cathodes for each corresponding layer.
void Layer(int layerNumber){
  if (layerNumber == 0){
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
    }
  else if (layerNumber == 1){
    digitalWrite(A4, LOW);
    digitalWrite(A5, HIGH);
    }
  else if (layerNumber == 2){
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
    }
  else if (layerNumber == 3){
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
    }
}

// Code for first pattern.
void PatternOne(){
  Layer(0);
  // Goes in a circle turning on all the LEDs in the outer posts.
  for (int i = 0; i<12; i++){
    digitalWrite(postOuter[i], HIGH);
    delay(70);
  }
  // Go up each layer with all the posts turned on.
  for (int i = 0; i<4; i++){
    Layer(i);
    delay(pause);
  }
  Reset();
  // Turn the inner posts on.
  InnerHigh();
  delay(60);
  // Go down the layers.
  for (int i = 3; i >= 0; i--){
    Layer(i);
    delay(pause);
  }
  Reset();
  // Turn the outer posts on.
  OuterHigh();
  // Go up each layer.
  delay(pause);
  for (int i = 1; i <= 3; i++){
    Layer(i);
    delay(pause);
  }
  Reset();
  // Turn inner posts on.
  InnerHigh();
  delay(pause);
  // Turn on the inner LEDs on layer 2 and 3.
  for (int i = 0; i < 50; i++) {
    for (int j = 2; j < 4; j++){
      Layer(j);
      delay(1);
    }
  }
  // Turn on the inner LEDs on layer 1,2, and 3.
  for (int i = 0; i < 50; i++) {
    for (int j = 1; j < 4; j++){
      Layer(j);
      delay(1);
    }
  }
  // Turn on the inner LEDs on all layers.
  for (int i = 0; i < 50; i ++) {
    for (int j = 0; j < 4; j++){
      Layer(j);
      delay(1);
    }
  }
  // Turn on all layers for inner LEDs and the entire bottom row.
  for (int i = 0; i < 25; i++) {
    Reset();
    for (int j = 3; j >-1; j--) {
      Layer(j);
      if (j == 3)
        InnerHigh();
      delay(1);
    }
    Reset();
    for (int k = 0; k<16; k++){
      digitalWrite(posts[k],HIGH);
    }
    delay(1);
  }
  // Turn on layers for all inner posts and the entire bottom two rows.
  for (int i = 0; i < 25; i++) {
    Reset();
    for (int j = 3; j >-1; j--) {
      Layer(j);
      if (j == 3)
        InnerHigh();
      delay(1);
    }
    Reset();
    for (int k = 0; k<16; k++){
      digitalWrite(posts[k],HIGH);
    }
    delay(1);
    Layer(1);
    delay(1);
  }  
  // Turn on layers for all inner posts and the entire bottom three rows.
  for (int i = 0; i < 25; i++) {
    Reset();
    for (int j = 3; j >-1; j--) {
      Layer(j);
      if (j == 3)
        InnerHigh();
      delay(1);
    }
    Reset();
    for (int k = 0; k<16; k++){
      digitalWrite(posts[k],HIGH);
    }
    delay(1);
    Layer(1);
    delay(1);
    Layer(2);
    delay(1);
  }  
  // Turn on every LED.
  for (int i = 0; i < 25; i++) {
    Layer(0);
    for (int j = 0; j < 16; j ++){
      digitalWrite(posts[j],HIGH);
    }
    for (int k = 1; k <=3; k++){
      Layer(k);
      delay(1);
    }
  }
  // Turn on layers for all inner posts and the entire bottom three rows.
  for (int i = 0; i < 25; i++) {
    Reset();
    for (int j = 3; j >-1; j--) {
      Layer(j);
      if (j == 3)
        InnerHigh();
      delay(1);
    }
    Reset();
    for (int i = 0; i<16; i++){
      digitalWrite(posts[i],HIGH);
    }
    delay(1);
    Layer(1);
    delay(1);
    Layer(2);
    delay(1);
  } 
  // Turn on layers for all inner posts and the entire bottom two rows.
  for (int i = 0; i < 25; i++) {
    Reset();
    for (int j = 3; j >-1; j--) {
      Layer(j);
      if (j == 3)
        InnerHigh();
      delay(1);
    }
    Reset();
    for (int i = 0; i<16; i++){
      digitalWrite(posts[i],HIGH);
    }
    delay(1);
    Layer(1);
    delay(1);
  }  
  // Turn on layers for all inner posts and the entire bottom row.
  for (int i = 0; i < 25; i++) {
    Reset();
    for (int j = 3; j >-1; j--) {
      Layer(j);
      if (j == 3)
        InnerHigh();
      delay(1);
    }
    Reset();
    for (int i = 0; i<16; i++){
      digitalWrite(posts[i],HIGH);
    }
    delay(1);
  }
  Reset();
  InnerHigh();
  // Turn on the inner posts on all layers.
  for (int i = 0; i < 50; i ++) {
    for (int j = 0; j < 4; j++){
      Layer(j);
      delay(1);
    }
  }
  // Turn on the inner posts on layer 1,2, and 3.
  for (int i = 0; i < 50; i++) {
    for (int j = 1; j < 4; j++){
      Layer(j);
      delay(1);
    }
  }
  // Turn on the inner posts on layer 2 and 3.
  for (int i = 0; i < 50; i++) {
    for (int j = 2; j < 4; j++){
      Layer(j);
      delay(1);
    }
  }
  Layer(3);
  delay(pause);
  Reset();
  delay(pause);
}

// A function to create an outer and inner loop.
void LoopInLoop(){
  // Turn on all outer posts and go through each layer.
  for (int i = 0; i <= 2; i++){
    OuterHigh();
    for (int i = 2; i >= 1; i--){
      Layer(i);
      delay(pause);
    }
    for (int i = 0; i <= 3; i++){
      Layer(i);
      delay(pause);
    }
  }
  // Call the StagesOfLoop() function to get the different frames of the loop.
  for (int i = 0; i <= 6; i ++){
    StagesOfLoop(2);
    StagesOfLoop(3);
    StagesOfLoop(4);
    StagesOfLoop(3);
    StagesOfLoop(2);
    StagesOfLoop(1);
  }
  Reset();
}

// A function that creates the different frames of the loop animation.
void StagesOfLoop(int stageNumber){
  for (int i = 0; i<50; i++){
    Reset();
    Layer(3-(stageNumber-1));
    OuterHigh();
    delay(1);
    Reset();
    Layer(stageNumber-1);
    InnerHigh();
    delay(1);
  }
}

// Function to turn on the posts in a rotating pattern.
void Rotations(){
    for (int i = 0; i <= 2; i++){
      // Cycle through the posts
      digitalWrite(postOuter[i], HIGH);
      digitalWrite(postOuter[i+3], HIGH);
      digitalWrite(postOuter[i+6], HIGH);
      digitalWrite(postOuter[i+9], HIGH);
      for (int j = 0; j <25; j++){
        // Go through each layer
        for (int k = 0; k <= 3; k++){
          Layer(k);
          delay(1);
        }
      }
        Reset();
  }
}

// Main loop
void loop() {
  // put your main code here, to run repeatedly:
  // 
  for (int i = 0; i <= 1; i++){
    PatternOne();
  }
  for (int i = 0; i <= 1; i++){
    LoopInLoop();
  }
  for (int i = 0; i <= 20; i++){
    Rotations();  
  } 
}
