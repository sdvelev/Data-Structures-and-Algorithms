/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if(position == 0){
        SinglyLinkedListNode * toBegin = new SinglyLinkedListNode(data);
        toBegin->next = llist;
        llist = toBegin;
        return llist;
    }
    
    SinglyLinkedListNode * indexOne;
    SinglyLinkedListNode * indexTwo = llist;
    
    for(int i = 0; i < position; i++){
     //   if(indexTwo){
            indexOne = indexTwo;
            indexTwo = indexTwo->next;
    //    }
    }
    
    SinglyLinkedListNode * toPush = new SinglyLinkedListNode(data);
    toPush->next = indexTwo;
    indexOne->next = toPush;
    
    return llist;
}
