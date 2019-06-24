#ifndef UDMSprNumTelCFH                  
#define UDMSprNumTelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNumTelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNumTelCF();                                                           
   ~TDMSprNumTelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
