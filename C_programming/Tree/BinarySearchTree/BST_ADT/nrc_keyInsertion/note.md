## Maintain the naming consistency like 
# using currNode/lastNode just like lchild/rchild

## always free the node in a funtion if no more required
# example- duplicate found nothing to be done, free(newNode)

## always free the whole whether its linked list, tree etc.
# void freeList(), void freeTree().

### while looping 
# in tree like binary tree movement is zizag lchild/rchild,
# in that case like for <while curr != NULL> maintain another 
# lastNode = curr; to store the lastNode;