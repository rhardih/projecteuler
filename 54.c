/**
 * In the card game poker, a hand consists of five cards and are ranked,
 * from lowest to highest, in the following way:
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
 * If two players have the same ranked hands then the rank made up of the highest value wins;
 * for example, a pair of eights beats a pair of fives (see example 1 below).
 * But if two ranks tie, for example, both players have a pair of queens,
 * then highest cards in each hand are compared (see example 4 below); if the highest
 * cards tie then the next highest cards are compared, and so on.
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
 * The file, poker.txt, contains one-thousand random hands dealt to two players.
 * Each line of the file contains ten cards (separated by a single space): the first five are
 * Player 1's cards and the last five are Player 2's cards. You can assume that all hands are
 * valid (no invalid characters or repeated cards), each player's hand is in no specific order,
 * and in each hand there is a clear winner.
 *
 * How many hands does Player 1 win?
 *
 *
 * Notes:
 *
 * Current implementation does not consider A 2 3 4 5 to be a straight. It is not necessary
 * for this problem, since the input file, poker.txt, does not contain this straight amongst
 * it's 1000 sample hands.
 *
 * Representing a poker hand as a 26 bit number.
 *
 * First 13 bits holds the significant rank of the hand, last 13 bits
 * holds the high cards e.g. a pair,  4D 8C 4S 5H QD
 *
 * 0000000000100 0010001001000
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  DIAMONDS,
  HEARTS,
  CLUBS,
  SPADES
} suit_t;

typedef enum {
  HIGH_CARD,
  PAIR,
  TWO_PAIRS,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH,
  ROYAL_FLUSH
} rank_t;

typedef struct {
  int value;
  suit_t suit;
} card_t;

typedef struct {
  card_t cards[5];
  rank_t rank;
  int value;
} hand_t;

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
  }

  return value;
};

suit_t card_suit(char c) {
  suit_t s;

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

void print_hand(hand_t h) {
  int i;
  char stoc[4] = { 'D', 'H', 'C', 'S' };
  for (i = 0; i < 5; i++)
  {
    printf("%d%c ", h.cards[i].value, stoc[h.cards[i].suit]);
  }
}

int compare_cards (const void * a, const void * b)
{
  card_t c0 = *(card_t *)a;
  card_t c1 = *(card_t *)b;
  return (c0.value - c1.value);
}

int hand_value(hand_t h) {
  return (1 << h.cards[4].value - 2) |
         (1 << h.cards[3].value - 2) |
         (1 << h.cards[2].value - 2) |
         (1 << h.cards[1].value - 2) |
         (1 << h.cards[0].value - 2);
}

/**
 * Moves bit i of n, from the lower 13 bits
 * to the higher 13 bits.
 */
int move_bit(int n, int i) {
  n |= 1 << (13 + i);
  return n & ~(1 << i);
}

int pair(hand_t h) {
  int i;
  int value = 0;

  for(i = 0; i < 4; i++) {
    if(h.cards[i].value == h.cards[i + 1].value) {
      value = hand_value(h);
      value = move_bit(value, h.cards[i].value - 2);
      break;
    }
  }
  return value;
}

int two_pairs(hand_t h) {
  int i, prev_pair_val = 0, count = 0;
  int value = 0;

  for(i = 0; i < 4; i++) {
    if(h.cards[i].value == h.cards[i + 1].value &&
        h.cards[i].value != prev_pair_val)
    {
      if (!value) value = hand_value(h);
      value = move_bit(value, h.cards[i].value - 2);
      prev_pair_val = h.cards[i].value;
      count++;
    }
  }

  if(count == 1) value = 0;

  return value;
}

int three_of_a_kind(hand_t h) {
  int i, value = 0;
  for(i = 0; i < 3; i++) {
    if(h.cards[i].value == h.cards[i + 1].value &&
        h.cards[i].value == h.cards[i + 2].value) {
      value = hand_value(h);
      value = move_bit(value, h.cards[i].value - 2);
    }
  }
  return value;
}

int straight(hand_t h) {
  int i;
  for (i = 1; i < 5; i++) {
    if(h.cards[i].value != h.cards[i - 1].value + 1)
      return 0;
  }
  return hand_value(h);
}

int flush(hand_t h) {
  int i;
  for(i = 1; i < 5; i++) {
    if(h.cards[i].suit != h.cards[i - 1].suit)
      return 0;
  }
  return hand_value(h);
}

int full_house(hand_t h) {
  if(h.cards[0].value == h.cards[1].value &&
      h.cards[3].value == h.cards[4].value &&
      (h.cards[1].value == h.cards[2].value ||
       h.cards[2].value == h.cards[3].value))
    return hand_value(h);
  return 0;
}

int four_of_a_kind(hand_t h) {
  if (h.cards[0].value == h.cards[3].value ||
      h.cards[1].value == h.cards[4].value) {
    int value = hand_value(h);
    value = move_bit(value, h.cards[1].value - 2);
  }
  return 0;
}

int straight_flush(hand_t h) {
  if(straight(h)) {
    return flush(h);
  }
  return 0;
}

int royal_flush(hand_t h) {
  int value = straight_flush(h);
  if(value && h.cards[0].value == 10) {
    return value;
  }
  return 0 ;
}

card_t new_card(char *s) {
  card_t c;
  c.value = card_value(s[0]);
  c.suit = card_suit(s[1]);

  return c;
}

hand_t new_hand(char cards[5][3]) {
  hand_t h;
  int value, i;

  for (i = 0; i < 5; i += 1) {
    h.cards[i] = new_card(cards[i]);
  }

  qsort(h.cards, 5, sizeof(card_t), compare_cards);

  if(value = royal_flush(h))
    h.rank = ROYAL_FLUSH;
  else if(value = straight_flush(h))
    h.rank = STRAIGHT_FLUSH;
  else if(value = four_of_a_kind(h))
    h.rank = FOUR_OF_A_KIND;
  else if(value = full_house(h))
    h.rank = FULL_HOUSE;
  else if(value = flush(h))
    h.rank = FLUSH;
  else if(value = straight(h))
    h.rank = STRAIGHT;
  else if(value = three_of_a_kind(h))
    h.rank = THREE_OF_A_KIND;
  else if(value = two_pairs(h))
    h.rank = TWO_PAIRS;
  else if(value = pair(h))
    h.rank = PAIR;
  else
  {
    value = hand_value(h);
    h.rank = HIGH_CARD;
  }

  h.value = value;

  return h;
}

int winner(hand_t h0, hand_t h1) {
  if(h0.rank == h1.rank) {
    return h0.value > h1.value;
  }
  return h0.rank > h1.rank;
}

int main(int argc, char const *argv[])
{
  char cards[10][3];
  int p1_wins = 0;
  while(scanf("%s %s %s %s %s %s %s %s %s %s\n",
        cards[0], cards[1], cards[2], cards[3], cards[4],
        cards[5], cards[6], cards[7], cards[8], cards[9] ) != EOF) {

    hand_t h0 = new_hand(cards);
    hand_t h1 = new_hand(&cards[5]);

    if(winner(h0, h1)) p1_wins++;
  }

  printf("Player 1 wins %d times\n", p1_wins);
  return 0;
}
