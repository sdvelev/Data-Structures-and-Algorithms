// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* indexOne = head1;
    SinglyLinkedListNode* indexTwo = head2;
       
    while(indexOne && indexTwo){
        if(indexOne == indexTwo){
            return indexTwo->data;
        }
        indexOne = indexOne->next;
        
        if(!indexOne){
            indexOne = head1;
            indexTwo = indexTwo->next;
        }
    }
    
    return 0;
}
