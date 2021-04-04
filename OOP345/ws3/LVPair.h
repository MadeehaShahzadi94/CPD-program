#ifndef LVOair_H
#define LVPair_H
#include<iostream>
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
namespace sict {
	
	template<typename L,typename V>
		class LVPair {
			L label;
			V value;
		public:
			LVPair() {};
			LVPair(const L& l, const V& v) { label = l; value = v; }
			void display(std::ostream& os)const { os << label << " : " << value << std::endl; };
			V& getvalue() const {return value;}
			l& getlable() const {return label;}
			
		};
			
		template<typename L,typename V>
		std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
			pair.display(os);
			return os;
		}





		template<typename L,typename V>
		class SummableLVPair:public LVPair<L, V> {

			static	V invalue;
			static size_t width;
			
		public:
			
			
			
			SummableLVPair() {};
			SummableLVPair(const L& l, const V& v) : LVPair(const L& l, const V& v){
				if(width<l.size()){
					width=l.size();
				}
					
			}

			const V& getinitialValue(){return invalue;};

			V sum(const L& l,const V& sum)const{
				return (sum+this->getvalue());
			}
			
			
			void display(std::ostream& os)const{
					os.width(width)<<std::left;
					LVPair:display(os);
			}
		
		};

		template<typename L, typename V>
		size_t SummableLVPair<L, V>::width{ 0 };
		

		template<>
		int SummableLVPair<std::string,int>::invalue{0};

		template<>
		std::string SummableLVPair<std::string,std::string>::invalue{""};

		template<>
		std::string SummableLVPair<std::string, std::string>::sum(const std::string& l, const std::string& v) const {
			return (v + "," + LVPair<std::string, std::string>::getvalue());
		};









}






#endif // !LVOair_H

