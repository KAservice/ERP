#ifndef UFormaSpiskaSprModCFH                  
#define UFormaSpiskaSprModCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprModCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprModCF();                                                           
   ~TFormaSpiskaSprModCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
