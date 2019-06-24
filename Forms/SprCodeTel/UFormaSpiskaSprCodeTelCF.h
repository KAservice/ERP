#ifndef UFormaSpiskaSprCodeTelCFH                  
#define UFormaSpiskaSprCodeTelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprCodeTelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprCodeTelCF();                                                           
   ~TFormaSpiskaSprCodeTelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
