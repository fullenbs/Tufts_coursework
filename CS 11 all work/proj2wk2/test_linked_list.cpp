//
//                       test_linked_list.cpp
//
//     A testing program that creates a CardLinkedList object and
//     tries the basic operations on it, using debug_print to report
//     on the internal state of all objects as it goes.
//
//                   Tufts University, Fall 2021 
//                        CS 11: Project 2
//
//    Modified by: Scott Fullenbaum
//

#include <iostream>
#include <fstream>
#include "Card.h"
#include "CardLinkedList.h"
#include "Deck.h"
using namespace std;

int main(int argc, char *argv[]){
    if (argc != 2){
        cerr << "THIS KIND OF DIDNT WORK" << endl;
    }
    /*************************************************************************/
    /*                    Testing for Card class                             */
    /*************************************************************************/
     cout << "Making card: value 33" << endl;
    Card c33(33);
    Card ctest(c33);
    //c33.debug_print();
    cout << endl;  // newline for viewing convenience
    
    /*************************************************************************/
    /*                    Testing for Linked List class                      */
    /*************************************************************************/
    cout << "Testing linked list" << endl;
    CardLinkedList ll;
    for (unsigned int i = 0; i < 4; i++){
        ll.add_card_at(i, i); //adds at end of list
    }
    ll.mystery();
    // ll.debug_print();
    // ll.add_card_at(0, 50); //tests adding card at beginning
    // ll.debug_print();
    // ll.add_card_at(5, 100); //tests adding card at middle
    // ll.debug_print();
    // ll.remove_card_at(0); //tests removing first card
    // ll.debug_print();
    // ll.remove_card_at(ll.num_cards()-1); //removes end card
    // ll.debug_print(); 
    // ll.remove_card_at(4); //removes card in middle
    // ll.debug_print();
    
    //tests getting card at any element
    // for (unsigned int i = 0; i < ll.num_cards(); i++){
    //     cout << i << " " << (ll.get_card_at(i)).value() << endl;
    // }    
    
    /*************************************************************************/
    /*                    Testing for Deck class                             */
    /*************************************************************************/
     Deck *test = new Deck(argv[1]); //makes deck from the file
    // test->debug_print();
    // 
    // Card temp = test->inspect_top_card(); //test for inspect_top_card
    // Card test_card(50);
    // cout << temp.value() << endl;
    // 
    // Card temp2 = test->draw_top_card(); //tests drawing top card
    // cout << temp2.value() << endl;
    // 
    // test->put_card_on_top(test_card); //tests putting card on top
    // cout << (test->inspect_top_card()).value() << endl;
    // 
     delete test;
    return 0;
}
