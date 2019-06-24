#ifndef UFormaSpiskaSprPriceScheduleCFH                  
#define UFormaSpiskaSprPriceScheduleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPriceScheduleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPriceScheduleCF();                                                           
   ~TFormaSpiskaSprPriceScheduleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
