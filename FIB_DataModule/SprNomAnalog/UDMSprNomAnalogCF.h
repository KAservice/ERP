#ifndef UDMSprNomAnalogCFH                  
#define UDMSprNomAnalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNomAnalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNomAnalogCF();                                                           
   ~TDMSprNomAnalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
