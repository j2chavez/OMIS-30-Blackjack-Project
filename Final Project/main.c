//
//  main.c
//  May 25
//
//  Created by John Chavez on 5/25/18.
//  Copyright © 2018 John Chavez. All rights reserved.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int handValue=0;

void printArray(int a[],int size);
int aceChecker(int aces);

int main(void){
 srand(time(NULL));
    
    // Creates a deck of 52 cards.
    int deck[52];
    int i;
    for(i=0;i<52;i++){
        deck[i]=i;
    }
    
    //Function I made to print Arrays
    printArray(deck,52);
    
    // Shuffles the deck.
    int shuffledDeck[52]={0};
    int randomSpace,x=0;
    while(x<52){
        randomSpace=rand()%52;
        if(shuffledDeck[randomSpace]==0){
            shuffledDeck[randomSpace]=deck[x];
            x++;
        }
    }
    
    //Prints shuffled deck
    printArray(shuffledDeck,52);
    
    //Draws 2 cards from the top of the deck to create your hand.
    int xx=0,yourHand[10]={0};
    while(xx<2){
        yourHand[xx]=shuffledDeck[xx];
        xx++;
    }
    printArray(yourHand,2);
    
    //Defines two variables: (1) the size of your hand, which increments if you Hit, and (2) gameOver, which becomes 1 if you Stay.
    int sizeOfHand=2;
    int gameOver=0;
    
    //Value of your hand.
    int c=0,v=0,aces=0;
    while(c<sizeOfHand){
        v=((yourHand[c]/4)+1);
        if(v==1){
            aces++;
        }
        if(v>10) v=10;
        printf("%d.\n",v);
        handValue=v+handValue;
        c++;
    }
    printf("The value of your hand is %d.\n\n",handValue);
    
    // Calls a function that asks the player whether they want their ace(s) to count as 1 or 11.
    if(aces>0){
        aceChecker(aces);
        aces=0;
    }
    
    // Choosing to hit or stay.
    while(gameOver==0){
        char entry;
        printf("Would you like to hit or stay?\nFor hit enter H, for stay enter S. >>>");
        scanf(" %c",&entry);
        printf("\n");
    
    // Changes hand value based on hit/stay decision.
        
        // Player chooses to Stay
        if(entry=='s'||entry=='S'){
            gameOver=1;
            printf("You stayed. Your final hand value is %d.\n",handValue);
        }
        
        // Player chooses to Hit
        if(entry=='h'||entry=='H'){
            v=0;
            sizeOfHand++;
            printf("Card: %d.\n",shuffledDeck[sizeOfHand]);
            v=((shuffledDeck[sizeOfHand]/4)+1);
            if(v>10) v=10;
            if(v==1){
                aces++;
            }
            if(aces>0){
                aceChecker(aces);
                aces=0;
            }
            printf("Value: %d.\n",v);
            handValue=handValue+v;
            printf("Your hand value is now %d.\n\n",handValue);
            printf("\n");
            entry='x';
        }
        if(handValue>21){
            printf("You've busted! Your hand is worth %d.\n",handValue);
                gameOver=1;
        }
    }
    return(0);
}

// Definition of a function that prints an Array.
void printArray(int a[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");
}

//Definition of "ace protocol" function
int aceChecker(int aces){
    int i;
    printf("You've been dealt %d ace(s).\n",aces);
    for(i=0;i<aces;i++){
        int repeatNeeded = 1;
        char aceChange;
        printf("Would you like your Ace to count as an 11 rather than a 1?\nEnter Y for Yes or N for No >>");
        while(repeatNeeded == 1){
                scanf(" %c",&aceChange);
                if((aceChange=='y')||(aceChange=='Y')){
                    handValue=handValue+10;
                    repeatNeeded=0;
                }
                if((aceChange=='n')||aceChange=='N'){
                    repeatNeeded=0;
                }
                if(repeatNeeded == 1){
                    printf("\nIncorrect entry, please try again. >>\n");
                }
            }
            printf("\nOk, your hand value is now %d.\n\n",handValue);
        }
    return(0);
}
