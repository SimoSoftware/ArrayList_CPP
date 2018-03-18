#include <sstream>
#include <iostream>

using namespace std;

template<class T>
class ArrayList{
private:
	T*   array;
	T*   appo;
	int  elements;
	int  length;
	void estendi();
	void estendi(int dim);
	void estendi(int elements, int dim);
	bool trueRange(int fromIndex, int toIndex);
public:
	ArrayList();
	ArrayList(int initialCapacity);
	ArrayList(ArrayList<T>& ar);
	ArrayList(T* array, int dim);
	void          add(T element);
	void          add(int index, T element);
	void          add(ArrayList<T>& ar);
	void          add(T* array, int dim);
	void          clear();
	ArrayList<T>* clone();
	bool          contains(T element);
	void          ensureCapacity(int minCapacity);
	T             get(int index);
	int           indexOf(T element);
	bool          isEmpty();
	int           lastIndexOf(T element);
	T             remove(int index);
	bool          remove(T element);
	void          removeRange(int fromIndex, int toIndex); //from inclusive, to exclusive
	T             set(int index, T element);
	int           size();
	ArrayList<T>* subList(int fromIndex, int toIndex);
	T*            toArray();
	void          trimToSize();
	bool          equals(ArrayList<T>& a);
	string        to_string();
	friend bool operator==(const ArrayList<T>& lhs, const ArrayList<T>& rhs){
		if(lhs->elements == rhs->elements){
			for(int i=0; i<lhs->elements; i++)
				if(lhs->array[i] != rhs->array[i])
					return false;
			return true;
		}else return false;
	}
	friend bool operator!=(const ArrayList<T>& lhs, const ArrayList<T>& rhs){
		return !(lhs == rhs);
	}
};

template <class T>
void ArrayList<T>::estendi(){
	this->estendi(this->elements, 10);
}
template <class T>
void ArrayList<T>::estendi(int dim){
	this->estendi(this->elements, dim);
}
template <class T>
void ArrayList<T>::estendi(int elements, int dim){ //estendi tenendo solo tot elements
	this->appo = this->array;
	this->length += dim;
	this->array = new T[this->length];
	for(int i=0; i<elements; i++)
		this->array[i] = this->appo[i];
}
template <class T>
bool ArrayList<T>::trueRange(int fromIndex, int toIndex){
	if(fromIndex<this->elements && fromIndex >= 0
	  && toIndex<this->elements && toIndex >=0 && fromIndex<toIndex)
		return true;
	else return false;
}
template <class T>
ArrayList<T>::ArrayList(){
	this->array  = new T[10];
	this->length = 10;
	this->elements = 0;
}
template <class T>
ArrayList<T>::ArrayList(int initialCapacity){
	this->array = new T[initialCapacity];
	this->length = initialCapacity;
	this->elements = 0;
}
template <class T>
ArrayList<T>::ArrayList(ArrayList<T>& ar){
	ArrayList<T>* pippo = ar.clone();
	this->array = pippo->array;
	this->length = pippo->length;
	this->elements = pippo->elements;
}
template <class T>
ArrayList<T>::ArrayList(T* array, int dim) : ArrayList<T>::ArrayList(){
	this->add(array, dim);
}
template <class T>
void ArrayList<T>::add( T element ){
	this->ensureCapacity(this->elements+1);
	this->array[this->elements] = element;
	this->elements++;
}
template <class T>
void ArrayList<T>::add(int index, T element){
	if(index>=0 && index<=this->elements){
		if(index == this->elements)
			this->add(element);
		else{
			this->estendi(index, 10);
			this->array[index] = element;
			for(int i=index+1; i<this->elements+1; i++)
				this->array[i] = this->appo[i-1];
			this->elements++;
		}
	}
}
template <class T>
void ArrayList<T>::add(ArrayList<T>& ar){
	T* pippo = ar.toArray();
	this->add(pippo, ar.size());
}
template <class T>
void ArrayList<T>::add(T* array, int dim){
	this->ensureCapacity(this->elements+dim);
	for(int i=0; i<dim; i++)
		this->array[i+this->elements] = array[i];
	this->elements += dim;
}
template <class T>
void ArrayList<T>::clear(){
	this->elements = 0;
}
template <class T>
ArrayList<T>* ArrayList<T>::clone(){
	return this;
}
template <class T>
bool ArrayList<T>::contains(T element){
	for(int i=0; i<this->elements; i++)
		if(this->array[i]==element)
			return true;
	return false;
}
template <class T>
void ArrayList<T>::ensureCapacity(int minCapacity){
	if(this->length<minCapacity){
		this->estendi(minCapacity-this->length);
	}
}
template <class T>
T    ArrayList<T>::get(int index){
	return this->array[index];
}
template <class T>
int  ArrayList<T>::indexOf(T element){
	if(this->contains(element)){
		for(int i=0; i<this->elements; i++)
			if(this->array[i]==element)
				return i;
	}else return -1;
}
template <class T>
bool ArrayList<T>::isEmpty(){
	return (this->elements==0? true : false);
}
template <class T>
int  ArrayList<T>::lastIndexOf(T element){
	if(this->contains(element)){
		for(int i=this->elements-1; i>=0; i--)
			if(this->array[i]==element)
				return i;
	}else return -1;
}
template <class T>
T    ArrayList<T>::remove(int index){
	T appo;
	if(index<this->elements){
		appo = this->array[index];
		this->removeRange(index, index+1);
	}
	return appo;
}
template <class T>
bool ArrayList<T>::remove(T element){
	int i = this->indexOf(element);
	if(i == -1)
		return false;
	else{
	this->remove(i);
		return true;
	}
}
template <class T>
void ArrayList<T>::removeRange(int fromIndex, int toIndex){
	if(fromIndex<this->elements && toIndex<this->elements
	   && fromIndex>=0 && toIndex >=0 && fromIndex<toIndex){
		for(int i=fromIndex; i<this->elements-(toIndex-fromIndex); i++)
			this->array[i] = this->array[toIndex+i-fromIndex];
		this->elements -= toIndex-fromIndex;
	}
} //from inclusive, to exclusive
template <class T>
T    ArrayList<T>::set(int index, T element){
	T prev = this->array[index];
	this->array[index] = element;
	return prev;
}
template <class T>
int  ArrayList<T>::size(){
	return this->elements;
}
template <class T>
ArrayList<T>* ArrayList<T>::subList(int fromIndex, int toIndex){
	ArrayList<T>* a = new ArrayList<T>;
	if(this->trueRange(fromIndex, toIndex)){
		a->ensureCapacity(toIndex-fromIndex);
		for(int i=0; i<toIndex-fromIndex; i++){
			a->add(this->array[i+fromIndex]);
		}
	}
	return a;
}
template <class T>
T*   ArrayList<T>::toArray(){
	T* nArray = new T[this->elements];
	for(int i=0; i<this->elements; i++)
		nArray[i] = this->array[i];
	return nArray;
}
template <class T>
void ArrayList<T>::trimToSize(){
	if(this->elements!=this->length)
		this->estendi(this->elements-this->length);
}
template <class T>
bool ArrayList<T>::equals(ArrayList<T>& a){
	if(a.elements == this->elements){
		for(int i=0; i<this->elements; i++)
			if(this->array[i]!=a.array[i])
				return false;
		return true;
	}else return false;
}
template <class T>
string ArrayList<T>::to_string(){
	stringstream ss;
	ss << "Array = { ";
	for(int i=0; i<this->elements-1; i++)
		ss << this->array[i] << ", ";
	ss << this->array[this->elements-1] << " }";
	return ss.str();
}
