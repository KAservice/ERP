#ifndef UFormaSpiskaSprFactorCFH                  
#define UFormaSpiskaSprFactorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprFactorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprFactorCF();                                                           
   ~TFormaSpiskaSprFactorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
