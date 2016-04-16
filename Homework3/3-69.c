//A.
long trace(tree_ptr tp)
{
	long x;
	while(tp!=NULL)
	{
		x = tp->val;
		tp = tp->left;
	}
	return x;
}
/*
B. This function computes the most left node's value of a tree.
                  o
				 / \
				o   o
			   / \ / \
			  o  o o  o
			  ^
		      Like this.
*/