#ifndef UDMSprPriceScheduleCFH                  
#define UDMSprPriceScheduleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprPriceScheduleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprPriceScheduleCF();                                                           
   ~TDMSprPriceScheduleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
