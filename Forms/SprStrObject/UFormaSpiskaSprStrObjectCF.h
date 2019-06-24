#ifndef UFormaSpiskaSprStrObjectCFH                  
#define UFormaSpiskaSprStrObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprStrObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprStrObjectCF();                                                           
   ~TFormaSpiskaSprStrObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
