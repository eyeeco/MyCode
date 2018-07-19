/*
  设计一个扑克牌的21点
*/

public enum Suit{
    Club(0),Diamond(1),Heart(2),Spade(3);
    private int value;
    private Suit(int v){value = v;}
    public int getValue(){return value;}
    public static Suit getSuitFromValue(int value){ ... }
}

public class Deck<T extends Card>{
    private ArrayList<T> cards;
    private ine dealtIndex = 0;

    public void setDeckofCards(ArrayList<T> deckofcards){ ... }

    public void shuffle(){ ... }
    public in remainingCards(){
      return cads.size() - dealtIndex;
    }
    public T[] dealHand(int number){ ... }
    public T dealCard(){ ... }
}
