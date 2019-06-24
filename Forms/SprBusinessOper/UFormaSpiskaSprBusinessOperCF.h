#ifndef UFormaSpiskaSprBusinessOperCFH                  
#define UFormaSpiskaSprBusinessOperCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprBusinessOperCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprBusinessOperCF();                                                           
   ~TFormaSpiskaSprBusinessOperCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
