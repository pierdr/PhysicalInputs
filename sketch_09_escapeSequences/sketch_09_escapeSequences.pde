
void setup()
{
  
  size(512,512);
    println("Hello \n world");

    println("\n ---- \n");
    
    println("Hello \t world");
  textAlign(CENTER);
}
void draw()
{
  background(255);
  fill(0);
  text("Hello \n this is a new line \n\n \"this is a test for learning about quotes inside strings\" \n\n end... ",width/2,height/2);
}
