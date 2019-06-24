#ifndef UDMSprNomPropertiesValueCFH                  
#define UDMSprNomPropertiesValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNomPropertiesValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNomPropertiesValueCF();                                                           
   ~TDMSprNomPropertiesValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
