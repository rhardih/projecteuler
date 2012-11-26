/**
 * In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
 *
 * High Card: Highest value card.
 * One Pair: Two cards of the same value.
 * Two Pairs: Two different pairs.
 * Three of a Kind: Three cards of the same value.
 * Straight: All cards are consecutive values.
 * Flush: All cards of the same suit.
 * Full House: Three of a kind and a pair.
 * Four of a Kind: Four cards of the same value.
 * Straight Flush: All cards are consecutive values of same suit.
 * Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 * The cards are valued in the order:
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 * 
 * If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
 * 
 * Consider the following five hands dealt to two players:
 *
 * Hand   Player 1            Player 2              Winner
 * 1      5H 5C 6S 7S KD      2C 3S 8S 8D TD        Player 2
 *        Pair of Fives       Pair of Eights
 * 2      5D 8C 9S JS AC      2C 5C 7D 8S QH        Player 1
 *        Highest card Ace    Highest card Queen
 * 3      2D 9C AS AH AC      3D 6D 7D TD QD        Player 2
 *        Three Aces          Flush with Diamonds
 *        4D 6S 9H QH QC      3D 6D 7H QD QS
 * 4      Pair of Queens      Pair of Queens        Player 1
 *        Highest card Nine   Highest card Seven
 *        2H 2D 4C 4D 4S      3C 3D 3S 9S 9D
 * 5      Full House          Full House            Player 1
 *        With Three Fours    with Three Threes
 *
 * The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
 *
 * How many hands does Player 1 win?
 */

#include <stdio.h>
#include <stdlib.h>

enum suit { DIAMONDS, HEARTS, CLUBS, SPADES };

struct card {
  int value;
  enum suit suit;
};

int card_value(char c) {
  int value;

  switch(c) {
    case '2':
      value = 2;
      break;
    case '3':
      value = 3;
      break;
    case '4':
      value = 4;
      break;
    case '5':
      value = 5;
      break;
    case '6':
      value = 6;
      break;
    case '7':
      value = 7;
      break;
    case '8':
      value = 8;
      break;
    case '9':
      value = 9;
      break;
    case 'T':
      value = 10;
      break;
    case 'J':
      value = 11;
      break;
    case 'Q':
      value = 12;
      break;
    case 'K':
      value = 13;
      break;
    case 'A':
      value = 14;
      break;
    default:
      break;
  }

  return value;
};

enum suit card_suit(char c) {
  enum suit s;

  switch(c) {
    case 'D':
      s = DIAMONDS;
      break;
    case 'H':
      s = HEARTS;
      break;
    case 'C':
      s = CLUBS;
      break;
    case 'S':
      s = SPADES;
      break;
    default:
      break;
  }

  return s;
}

struct card new_card(char *s) {
  struct card c;
  c.value = card_value(s[0]);
  c.suit = card_suit(s[1]);

  return c;
}

struct hand {
  struct card cards[5];
};

int compare_cards (const void * a, const void * b)
{
  struct card c0 = *(struct card *)a;
  struct card c1 = *(struct card *)b;
  return (c0.value - c1.value);
}

int cards_sum(struct hand h) {
  return h.cards[0].value +
    h.cards[1].value +
    h.cards[2].value +
    h.cards[3].value +
    h.cards[4].value;
}

int pair(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);
  int value = 0, i, j;
  for(i = 0; i < 4; i++) {
    if(h.cards[i].value == h.cards[i + 1].value)
      value = h.cards[i].value;
  }
  return value;
}

int two_pairs(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);

  int pair0 = 0;
  int pair1 = pair(h); // Finds the last pair

  if(pair1) {
    if (h.cards[0].value == h.cards[1].value ||
        h.cards[0].value == h.cards[2].value)
    {
      pair0 = h.cards[0].value;
    }
    else if (h.cards[1].value == h.cards[2].value)
    {
      pair0 = h.cards[1].value;
    }

    if (pair0)
    {
      pair0 > pair1 ? (pair0 *= 100) : (pair1 *= 100);
      return pair0 + pair1;
    }
  }

  return 0;
}

int three_of_a_kind(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);
  int value = 0, i;
  for(i = 0; i < 3; i++) {
    if(h.cards[i].value == h.cards[i + 1].value &&
        h.cards[i].value == h.cards[i + 2].value)
      value = h.cards[i].value;
  }
  return value;
}

int straight(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);
  int sum = h.cards[0].value, i;
  for (i = 1; i < 5; i++) {
    if(h.cards[i].value != h.cards[i - 1].value + 1)
      return 0;
    else
      sum += h.cards[i].value;
  }
  return sum;
}

int flush(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);
  int sum = h.cards[0].value, i;
  for(i = 1; i < 5; i++) {
    if(h.cards[i].suit != h.cards[i - 1].suit)
      return 0;
    else
      sum += h.cards[i].value;
  }
  return sum;
}

int full_house(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);
  int sum = 0;
  int t = three_of_a_kind(h), p = 0;
  if (t)
  {
    int i;
    for (i = 1; i < 5; i++)
    {
      if(h.cards[i].value == t)
        continue;
      else if (h.cards[i].value == h.cards[i - 1].value)
        p = h.cards[i].value;
    }

    if (p)
    {
      sum = p + t * 100;
    }
  }
  return sum;
}

int four_of_a_kind(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);
  int sum = 0;
  if (h.cards[0].value == h.cards[3].value ||
      h.cards[1].value == h.cards[4].value)
    sum = h.cards[1].value;
  return sum;
}

int straight_flush(struct hand h) {
  int s = straight(h);
  int f = flush(h);
  int sum = 0;

  if (s && f) {
    sum = s;
  }

  return sum;
}

int royal_flush(struct hand h) {
  int sf = straight_flush(h);
  int sum = 0;

  if(sf && h.cards[0].value == 10) {
    sum = sf;
  }

  return sum;
}

int rank(struct hand h) {
  qsort(h.cards, 5, sizeof(struct card), compare_cards);

  int value = 0;
  int tmp = 0;
  int offset = 14 * 14 * 14 * 14 * 14;

  if(tmp = royal_flush(h)) // 60
    value = tmp + offset + 3034;
  else if(tmp = straight_flush(h)) // 20 - 60
    value = tmp + offset + 2974;
  else if(tmp = four_of_a_kind(h)) // 2 - 14
    value = tmp + offset + 2960;
  else if(tmp = full_house(h)) // 203 - 1413
    value = tmp + offset + 1547;
  else if(tmp = flush(h)) // 20 - 60
    value = tmp + offset + 1487;
  else if(tmp = straight(h)) // 20 - 60
    value = tmp + offset + 1427;
  else if(tmp = three_of_a_kind(h)) // 2 - 14
    value = tmp + offset + 1413;
  else if(tmp = two_pairs(h)) // 302 - 1413
    value = tmp + offset;
  else if(tmp = pair(h)) // 2 - 14
    value = tmp + offset;
  else // 14^5
    value = h.cards[0].value +
      h.cards[1].value * 14 +
      h.cards[2].value * 14 * 14 +
      h.cards[3].value * 14 * 14 * 14 +
      h.cards[4].value * 14 * 14 * 14 * 14;

    /*printf("HIGH CARD: %d %d %d %d %d, value: %d\n",*/
        /*h.cards[0].value,*/
        /*h.cards[1].value,*/
        /*h.cards[2].value,*/
        /*h.cards[3].value,*/
        /*h.cards[4].value,*/
        /*value);*/

  return value;
}

void test() {
  struct card c0 = { 10, DIAMONDS };
  struct card c1 = { 11, DIAMONDS };
  struct card c2 = { 12, DIAMONDS };
  struct card c3 = { 13, DIAMONDS };
  struct card c4 = { 14, DIAMONDS };

  struct hand h0;
  h0.cards[0] = c0;
  h0.cards[1] = c1;
  h0.cards[2] = c2;
  h0.cards[3] = c3;
  h0.cards[4] = c4;

  struct card c5 = { 9, HEARTS };
  struct card c6 = { 10, HEARTS };
  struct card c7 = { 11, HEARTS };
  struct card c8 = { 12, HEARTS };
  struct card c9 = { 13, HEARTS };

  struct hand h1;
  h1.cards[0] = c5;
  h1.cards[1] = c6;
  h1.cards[2] = c7;
  h1.cards[3] = c8;
  h1.cards[4] = c9;

  printf("Rank h0: %d\n", rank(h0));
  printf("Rank h1: %d\n", rank(h1));

  /*printf("Pair h0: %d\n", pair(h0));*/
  /*printf("Two pairs h1: %d\n", two_pairs(h1));*/
  /*printf("Three of a kind h1: %d\n", three_of_a_kind(h1));*/
  /*printf("Straight h0: %d\n", straight(h0));*/
  /*printf("Flush h0: %d\n", flush(h0));*/
  /*printf("Flush h1: %d\n", flush(h1));*/
  /*printf("Full house h0: %d\n", full_house(h0));*/
  /*printf("Full house h1: %d\n", full_house(h1));*/
  /*printf("Four of a kind h0: %d\n", four_of_a_kind(h0));*/
  /*printf("Four of a kind h1: %d\n", four_of_a_kind(h1));*/
  /*printf("Straight flush h0: %d\n", straight_flush(h0));*/
  printf("Straight flush h1: %d\n", straight_flush(h1));
  printf("Royal flush h0: %d\n", royal_flush(h0));
}

int main(int argc, char const *argv[])
{

  char cards[10][3];
  int p1_wins = 0;
  while(scanf("%s %s %s %s %s %s %s %s %s %s\n",
        cards[0], cards[1], cards[2], cards[3], cards[4],
        cards[5], cards[6], cards[7], cards[8], cards[9] ) != EOF) {

    struct hand h1 = {
      new_card(cards[0]),
      new_card(cards[1]),
      new_card(cards[2]),
      new_card(cards[3]),
      new_card(cards[4])
    };

    struct hand h2 = {
      new_card(cards[5]),
      new_card(cards[6]),
      new_card(cards[7]),
      new_card(cards[8]),
      new_card(cards[9])
    };

    printf("%s %s %s %s %s vs. %s %s %s %s %s\n",
        cards[0], cards[1], cards[2], cards[3], cards[4],
        cards[5], cards[6], cards[7], cards[8], cards[9]);

    if(rank(h1) > rank(h2)) {
      printf("Player 1 wins.\n");
      p1_wins++;
    }
    else
    {
      printf("Player 2 wins.\n");
    }
  }

  printf("Player 1 wins %d times\n", p1_wins);
  return 0;
}
