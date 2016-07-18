/* Famous hash functions for strings */


/* djb2 hash function */
int hashFunc(string const& s){
	unsigned long hash = 5381;
	
	for(auto &c: s)
		hash = (hash << 5)  + hash + c ; /* hash *33 + c */

	return hash;
}	


/* sdbm hash function */
int hashFunc(string const& s){
	unsigned long hash = 0;
	
	for(auto &c: s)
		hash = (hash << 6) + (hash << 16) - hash +  c; /* hash * 65599 + c */
		
	return hash;
}

