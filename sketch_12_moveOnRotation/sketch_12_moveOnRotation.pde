/* THIS SKETCH WORKS WITH sketch_05_rotaryDialHID */

int positionX = 0;

void setup()
{
  size(600,200);
  rectMode(CENTER);
}
void draw()
{
  background(128 , 108 , 255  );
  fill(249  ,244  ,78  );
  ellipse(positionX,height/2,50,50);
}
void keyPressed()
{
  if(key == 'a')
  {
    positionX +=10;
    if(positionX > width)
    {
      positionX = 0;
    }
  }
  else if (key == 'b')
  {
    positionX -=10;
    if(positionX <0)
    {
      positionX = width;
    }
  }
}
