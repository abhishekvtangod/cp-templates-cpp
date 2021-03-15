//trie is matrix representation of trie data structure

//trie[k] represents list of links for the k-th node
//trie[k][m], node which represents son of k-th node using m-th character

struct trie{

	ll tr[1000006][28];

	ll root = 0;

	void init()
	{
		memset(tr,-1,sizeof(tr));
	}
	ll nxt = 1;

	void insert(string s)
	{
		ll node = root;
		
		for(ll i=0; i<s.size();i++)
		{
			ll q = s[i]-'a';
			
			if(tr[node][q] == -1)
			{
				tr[node][q] = nxt++;
			}
			
			node = tr[node][q];
		}
	}


	void solve()
	{
		init();
		ll n,q;cin>>n>>q;
		for(ll i=0;i<n;i++)
		{
			string s;cin>>s;
			insert(s);
		}
		
		
	}

	
}
