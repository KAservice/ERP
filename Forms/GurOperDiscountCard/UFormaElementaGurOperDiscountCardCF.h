#ifndef UFormaElementaGurOperDiscountCardCFH                  
#define UFormaElementaGurOperDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaGurOperDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaGurOperDiscountCardCF();                                                           
   ~TFormaElementaGurOperDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
