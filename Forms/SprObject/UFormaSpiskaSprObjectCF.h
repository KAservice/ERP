#ifndef UFormaSpiskaSprObjectCFH                  
#define UFormaSpiskaSprObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprObjectCF();                                                           
   ~TFormaSpiskaSprObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
