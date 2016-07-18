/* Double Hashing 

	index = (index + 1 * indexH) % hashTableSize;
	index = (index + 2 * indexH) % hashTableSize;

*/


string hashTable[21];
int hashTableSize = 21;

void insert(string s){

	int index = hashFunc1(s);
	int indexH = hashFunc2(s);
	
	while(hashTable[index] != "")
		index = (index + indexH)%hashTableSize;
	
	hashTable[index] = s;

}

void search(string s){
	
	int index = hashFunc1(s);
	int indexH = hashFunc2(s);
	
	while(hashTable[index] != s && hashTable[index] != "")
		index = (index + indexH)%hashTableSize;
		
	if(hashTable[index] == s)
		return true;
		
	return false;
}