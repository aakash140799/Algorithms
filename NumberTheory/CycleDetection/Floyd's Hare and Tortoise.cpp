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
        2   Once we enter a cycle, we can exit a cycle because of propert 1)
        3   Since slow pointer and fast pointer are moving, hence both will reach the cycle eventuall
        4   Once both are in cycle, both will move in cycle only 2)
        5   Both pointer are moving at different speed, hence relative speed of pointer is not zero, hence once
            pointer will eventually reach other
*/