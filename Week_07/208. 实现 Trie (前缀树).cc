class Trie 
{
private:
    bool isEnd_; // 是否是字符串结束点
	Trie* arrNext_[26]; // 智能指针数组,下标为ch-'a'
public:
    /** Initialize your data structure here. */
    Trie() 
    {
	    isEnd_ = false;
		memset(arrNext_,0,sizeof(arrNext_));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        auto node = this; // 根节点供外面使用,根节点也是普通节点
		for (auto ch:word)
		{
		    if (!node->arrNext_[ch -'a'])
			{
			    node->arrNext_[ch - 'a']= new Trie();
			}
			node = node->arrNext_[ch - 'a'];
		}
		node->isEnd_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = this;
		for (auto ch:word)
		{
		    node = node->arrNext_[ch-'a'];
			if (!node)
			{
			    return false; // 未能找到
			}
		}
		return node->isEnd_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        auto node = this;
		for (auto ch:prefix)
		{
		    node = node->arrNext_[ch -'a'];
			if (!node)
			{
			    return false; // 未能找到
			}
		}
	    return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */