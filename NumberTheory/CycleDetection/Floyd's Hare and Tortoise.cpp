/*
    Algorithm : Floyd's Hare and Tortoise Algorithm
    Floyd's algorithm solves Cycle Detection Problem using O(1) space only.

    Theory:
        Floyd's algorithm maintains two pointers only, which moves through the sequence at different speed.
        Floyd's algorithm gurantees that if there exits a cycle in sequence, both pointer will eventually
        point to same value. Then, using the distance travelled by each pointer, we can find the entry point
        of cycle, and its length.

        To prove that one pointer will eventually meet, let us foucs on few points
        1   From one state, we can move to only one other state.
        2   Once we enter a cycle, we can exit a cycle because of propert 1).
        3   Since slow pointer and fast pointer are moving, hence both will reach the cycle eventually.
        4   Once both are in cycle, both will move in cycle only 2).
        5   Both pointer are moving at different speed, hence relative speed of pointer is not zero, hence one
            pointer will eventually reach other.

    Algorithm:
        let mu be length of linear section before entering cycle
            lam be length of cycle

        First phase:
            slow pointer(tortoise) moves at speed 1.
            fast pointer(hare) moves at speed 2.

        Second phase:
            tortoise reachs first step of cycle.
            Hare reachs mu+1 th step of cycle.
            both keep moving at same speed.

        Third phase:
            Hare and tortoise meet at lam-mu+1 th step of cycle.
            Set Tortoise to starting position.
            Tortoise and Hare both move at speed 1.

        Fourth phase:
            when tortoise tarvels mu distance,
            hare travels mu+lam-mu distacen,
            hence both point to same value,
            which is entry point of cycle.

        fifth phase:
            tortoise remain still
            Hare moves at speed 1.

            When Hare meets tortoise again,
            we know length of cycle.

    Analysis:
        Time Complexity : O(mu + lam)
        Space Complexity : O(1)

    e.g:
    let sequence be
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 5

    mu = 4
    lam = 6

    First phase:
        hare moves at speed 2, tortoise moves at speed 1
        hare = 1, tortoise = 1
        hare = 3, tortoise = 2
        hare = 5, tortoise = 3
        hare = 7, tortoise = 4
        hare = 9, tortoise = 5


    Second phase:
        since 5 is the starting point of cycle,
        at this point, hare is at 5th step i.e 9,
                    tortoise is at 1st step i.e 5

        Hare moves at speed 2, tortoise moves at speed 1
        hare = 9, tortoise = 5
        hare = 5, tortoise = 6
        hare = 7, tortoise = 7

    Third phase:
        Hare and tortoise meet at 3nd step
        both move at same speed
        hare = 7, tortoise = 1
        hare = 8, tortoise = 2
        hare = 9, tortoise = 3,
        hare = 10, tortoise = 4,
        hare = 5, tortoise = 5
        since hare and tortoise meet again after 5 steps, we
        know mu = 4

    Fourth phase:
        hare moves at speed 1
        hare = 6, tortoise = 5
        hare = 7, tortoise = 5
        hare = 8, tortoise = 5
        hare = 9, tortoise = 5
        hare = 10, tortoise = 5
        hare = 5, tortoise = 5
        since hare meet after 6, steps, we
        know lam = 6
*/
#include <iostream>
using namespace std;
int func(int x)
{
    // you can chose your own function
    return x+1 <= 10 ? x+1 : 5;
}

int main()
{
    int x0;
    cin >> x0;

    int tortoise = x0;
    int hare = x0;
    int lam, mu;

    // phase one
    do{
        tortoise = func(tortoise);
        hare = func(func(hare));
    }while(tortoise != hare);


    // phase three
    mu = 0;
    tortoise = x0;
    while(tortoise != hare){
        tortoise = func(tortoise);
        hare = func(hare);
        mu++;
    }

    // phase four
    lam = 1;
    hare = func(hare);
    while(hare != tortoise){
        hare = func(hare);
        lam++;
    }

    cout << "length of cycle : " << lam << "\n";
    cout << "length of linear cycle : " << mu << "\n";
}
