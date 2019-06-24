#ifndef UFormaSpiskaSprNumTelCFH                  
#define UFormaSpiskaSprNumTelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprNumTelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprNumTelCF();                                                           
   ~TFormaSpiskaSprNumTelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
