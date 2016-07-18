/* Linear Probing  - Open Addressing or Closing Hashing 
	index = index % hashTableSize
	index = (index + 1) % hashTableSize
	index = (index + 2) % hashTableSize
	index = (index + 3) % hashTableSize
*/

string hashTable[21];
int hashTableSize = 21;


void insert(string s){
	
	int index = hashFunc(s);
	
	while(hashTable[index] != "")
		index = (index + 1)%hashTableSize;

	hashTable[index] = s;
}

bool search(string s){
	
	int index = hashFunc(s);
	
	while(hashTable[index] != s && hashTable[index]!= "")
		index = (index + 1)%hashTableSize;
		
	if(hashTable[index] == s)
		return true;
		
	return false;
}
