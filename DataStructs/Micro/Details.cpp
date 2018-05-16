#include "all.hpp"

namespace Details{
	#define V long
	#define K unsigned V
	//Deletes the old version of a pair or makes a new one if it doesn't exist
	void Axes::set(K key,V value){
		delete remove(key);
		insert(key,value);
	}
	
	void Axes::set(KVP<K,V> pair){
		set(pair.key,pair.value);
	}
	
	void Axes::init(K numaxes){
		for(unsigned long i=0;i<numaxes;i++){
			set(i,0);
		}
	}
	
	void Axes::transfer(Axes* other){
		KVP<K,V>* pair;
		while(pair=this->rmmin()){
			other->set(*pair);
			delete pair;
		}
	}
	
	//Populates the given object with default values for the keys found in this one if they're not already present
	void Axes::projection(Axes* other){
		Axes		axesa=Axes(),
				axesb=Axes();
		KVP<K,V>	*pair;
		long		*found;
		while(pair=this->rmmin()){
			axesa.set(*pair);
			found=other->remove(pair->key);
			if(found==NULL){
				axesb.set(pair->key,0);
			}else{
				axesb.set(pair->key,*found);
				delete found;
			}
			delete pair;
		}
		axesa.transfer(this);
		axesb.transfer(other);
	}
	
	void Axes::biprojection(Axes* other){
		this->projection(other);
		other->projection(this);
	}
	
	Axes* Axes::clone(){
		Axes	axesa=Axes(),
			*duplicate=new Axes();
		KVP<K,V>* pair;
		while(pair=this->rmmin()){
			axesa.set(*pair);
			duplicate->set(*pair);
			delete pair;
		}
		axesa.transfer(this);
		return duplicate;
	}
	
	//WARNING: The objects being operated upon must have the same keys present
	long Axes::compareTo(Axes* other){
		Axes		axesa=Axes(),
				axesb=Axes();
		KVP<K,V>	*paira,
				*pairb;
		long result=0;
		while(result==0
		&&(paira=this->rmmin())
		&&(pairb=other->rmmin())){
			axesa.set(*paira);
			axesb.set(*pairb);
			result=(paira->value)-(pairb->value);
			delete paira;
			delete pairb;
		}
		axesa.transfer(this);
		axesb.transfer(other);
		return result;
	}
	
	bool Axes::operator==(Axes& other){
		return this->compareTo(&other)==0;
	}
	
	bool Axes::operator!=(Axes& other){
		return this->compareTo(&other)!=0;
	}
	
	bool Axes::operator<(Axes& other){
		return this->compareTo(&other)<0;
	}
	
	bool Axes::operator<=(Axes& other){
		return this->compareTo(&other)<=0;
	}
	
	bool Axes::operator>(Axes& other){
		return this->compareTo(&other)>0;
	}
	
	bool Axes::operator>=(Axes& other){
		return this->compareTo(&other)>=0;
	}
	
	//WARNING: The objects being operated upon must have the same keys present
	Axes& Axes::operator+=(Axes& other){
		Axes		axesa=Axes(),
				axesb=Axes();
		KVP<K,V>	*paira,
				*pairb;
		while((paira=this->rmmin())
		&&(pairb=other.rmmin())){
			axesa.set(paira->key,(paira->value)+(pairb->value));
			axesb.set(*pairb);
			delete paira;
			delete pairb;
		}
		axesa.transfer(this);
		axesb.transfer(&other);
		return *this;
	}
	
	//WARNING: The objects being operated upon must have the same keys present
	Axes& Axes::operator-=(Axes& other){
		Axes		axesa=Axes(),
				axesb=Axes();
		KVP<K,V>	*paira,
				*pairb;
		while((paira=this->rmmin())
		&&(pairb=other.rmmin())){
			axesa.set(paira->key,(paira->value)-(pairb->value));
			axesb.set(*pairb);
			delete paira;
			delete pairb;
		}
		axesa.transfer(this);
		axesb.transfer(&other);
		return *this;
	}
	
	Axes::Axes(K numaxes):Linear::List<K,V>::List(){
		init(numaxes);
		return;
	}
	
	Axes::Axes():Axes(0){}
	
	Axes::~Axes(){}
	#undef K
	#undef V
	
	Number::Number(long value):value(value){}
	Number::Number():value(0){}
		
	Number::~Number(){
		value=0;
		return;
	}
	
	Jump::Jump(ExecBlocks::Instruction* target):target(target){}
	Jump::Jump():target(NULL){}
	
	Jump::~Jump(){
		target=NULL;
		return;
	}
}
