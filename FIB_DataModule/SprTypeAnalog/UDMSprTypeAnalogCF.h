#ifndef UDMSprTypeAnalogCFH                  
#define UDMSprTypeAnalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprTypeAnalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprTypeAnalogCF();                                                           
   ~TDMSprTypeAnalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
