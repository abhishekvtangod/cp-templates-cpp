//trie is matrix representation of trie data structure

//trie[k] represents list of links for the k-th node
//trie[k][m], node which represents son of k-th node using m-th character

struct trie{

	int tr[1000006][28];

	int root = 0;

	void init()
	{
		memset(tr,-1,sizeof(tr));
	}
	int nxt = 1;

	void insert(string s)
	{
		int node = root;
		
		for(int i=0; i<s.size();i++)
		{
			int q = s[i]-'a';
			
			if(tr[node][q] == -1)
			{
				tr[node][q] = nxt++;
			}
			
			node = tr[node][q];
		}
	}
};
