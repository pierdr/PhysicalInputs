
String stringToSearch = "";
ArrayList<String> dictionaryOfPossibleWords = new ArrayList<String>();

String dictionary[];

PFont bold;
PFont regular;

void setup()
{
  size(500,750);
  textAlign(CENTER);
  //READ MORE ABOUT FONT CUSTOMIZATION HERE: https://processing.org/reference/textFont_.html
  bold = createFont("Roboto-Black.ttf", 50);
  regular = createFont("Roboto-Regular.ttf",30);
  
  dictionary = loadStrings("dictionary.txt");
  
  if(dictionary.length == 0)
  {
    System.err.println("dictionary not loaded");
    exit();
  }
}

void draw()
{
  background(77,77,77);
  textFont(bold);
  text(stringToSearch,width/2,50);
  textFont(regular);
  for(int i = 0;i< dictionaryOfPossibleWords.size();i++)
  {
    
    text(dictionaryOfPossibleWords.get(i),width/2,100+ (i*40));
  }
}

void keyPressed(KeyEvent keyEvent)
{
  println(keyCode);
  
  //CHECK IF DELETE
  if(keyCode == 8)
  {
    stringToSearch = "";
    dictionaryOfPossibleWords.clear();
  }
  //CHECK THAT CODE IS ALPHANUMERIC
  if(keyCode <= 90 && keyCode >= 65)
  {
    stringToSearch = stringToSearch + key;
    if(stringToSearch.length() > 2)
    {
      String dictWord = "";
      dictionaryOfPossibleWords.clear();
      for(int i = 0;i<dictionary.length;i++)
      {
        dictWord = dictionary[i];
        
        if(dictWord.startsWith(stringToSearch))
        {
          dictionaryOfPossibleWords.add(dictWord);
        }
      }
    }
  }
}
