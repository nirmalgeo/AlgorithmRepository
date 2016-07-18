/* Separate Chaining - Open Hashing */
vector<string> hashTable[20];

int hashTableSize = 20;

void insert(string s){

	int index = hashFunc(s);
	
	hashTable[index].push_back(s);


}

bool search(string s){

	int index = hashFunc (s);
	
	for(size_t i=0; i < hashTable[index].size(); i++){
	
		if(hashTable[index][i] == s)
			return true;
	}

	return false;

}