#ifndef UFormaSpiskaSprPriceCFH                  
#define UFormaSpiskaSprPriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPriceCF();                                                           
   ~TFormaSpiskaSprPriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
