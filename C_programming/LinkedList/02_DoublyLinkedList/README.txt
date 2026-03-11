// Professional production stlye
strcut dllnode
{
    int val;
    struct dll *next;
    struct dll *prev;
}

struct dll 
{
    struct *head; // head node address
    struct *tail; // last node address
    int size;     // count of node
}

// for operaion at end tail make O(n) to O(1).
// for node count same size makes O(n) to O(1).
    // size ++ for insert and size-- for del.

// use temp convention only if needed for readability.

