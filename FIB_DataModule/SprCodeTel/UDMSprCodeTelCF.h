#ifndef UDMSprCodeTelCFH                  
#define UDMSprCodeTelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCodeTelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCodeTelCF();                                                           
   ~TDMSprCodeTelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
