/* Quadtratic Probing
	index = index % hashTableSize
	index = (index + 1^2) % hashTableSize
	index = (index + 2^2) % hashTableSize
	index = (index + 3^2) % hashTableSize
 */

string hashTable[21];
int hashTableSize = 21;

void insert(string s){

	int index = hashFunc(s);
	int h = 1;
	
	while(hashTable[index] != ""){
		index = (index + h*h)%hashTableSize;
		h++;
	}
	
	hashTable[index] = s;

}

void search(string s){

	int index = hashFunc(s);
	
	int h = 1;
	
	while(hashTable[index] != s && hashTable[index] != ""){
		index = (index + h*h)%hashTableSize;
		h++;
	}
	
	if(hashTable[index] == s)
		return true;
	
	return false;
}