template <typename T>
void BubbleSortVector<T>::sort() {
// Lookup the bubble sort algorithm online.
//
// The algorithm is so-named "bubble sort" because
// lesser valued elements "bubble up" to the "top" (front)
// of the array/container/sequence.
//
// You'll have to perform a lot of swaps for the algorithm.
//
// You are free to write your own swap helper function
// if you so desire.
bool swapp = true;
//check if swaps was performed
	while(swapp){
		swapp = false;
		// reset condition
		for (size_t i = 0; i < this->size()-1; i++) {
			//ilerate through vector and swap if [i] > [i+]
			if ((*this)[i]>(*this)[i+1] ){
				(*this)[i] += (*this)[i+1];
				(*this)[i+1] = (*this)[i] - (*this)[i+1];
				(*this)[i] -=(*this)[i+1];
				swapp = true;
			}
		}
	}
}
